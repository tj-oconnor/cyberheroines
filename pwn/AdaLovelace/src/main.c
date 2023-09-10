#define _GNU_SOURCE
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/personality.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * @file ctf_challenge.c
 * @brief CTF Challenge: Memory manipulation.
 *
 * This program provides an interface to allocate, free, and write to memory.
 * The objective is to manipulate a global variable to read the contents of
 * ./flag.txt.
 */

#define MAX_CHUNKS 10
#define VULN 1
#define MAX_PROG_LEN 50

#if defined(__x86_64__) || defined(_M_X64)
#define MALLOC_ALIGNMENT (2 * sizeof(size_t)) // 16 bytes on 64-bit
#elif defined(__i386__) || defined(_M_IX86)
#define MALLOC_ALIGNMENT (2 * sizeof(size_t)) // 8 bytes on 32-bit
#else
#error "Unsupported platform"
#endif

/// Structure representing memory chunks
typedef struct {
    void *ptr;
    size_t size;
} MemoryChunk;

/// Global chunks list
MemoryChunk chunks[MAX_CHUNKS] = {0};

/// Zero-initialized global variable
char check_var[8] __attribute__((aligned(MALLOC_ALIGNMENT))) = {0};

/**
 * @brief Allocates a memory chunk of a specified size.
 *
 * @param size The size of memory to be allocated.
 */
void allocate_cmd(size_t size) {
    for (int i = 0; i < MAX_CHUNKS; i++) {
        if (chunks[i].ptr == NULL) {
            chunks[i].ptr = malloc(size);
            chunks[i].size = size;
            return;
        }
    }
    printf("Max number of chunks reached!\n");
}

/**
 * @brief Frees a specified chunk of memory.
 *
 * @param idx The index of the chunk to free.
 */
void delete_cmd(int idx) {
    if (idx < 0 || idx >= MAX_CHUNKS || chunks[idx].ptr == NULL) {
        printf("Invalid chunk index!\n");
        return;
    }
    free(chunks[idx].ptr);
#if (0 == VULN)
    // Without this, the fill command can write to free'd memory
    chunks[idx].ptr = NULL;
    chunks[idx].size = 0;
#endif
}

/**
 * @brief Converts a single hex character to its integer value.
 *
 * @param hex The hex character.
 * @return The integer value of the hex character.
 */
int hex_char_to_int(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
    return -1; // Invalid hex char
}

/**
 * @brief Decodes a hexadecimal string into its byte representation.
 *
 * @param hex The hex string.
 * @param bytes The output byte buffer.
 * @return The length of the decoded byte sequence.
 */
int decode_hex(const char *hex, char *bytes) {
    int len = strlen(hex);
    if (len % 2 != 0) {
        // Invalid hex string length
        return -1;
    }

    int byteLen = 0;
    for (int i = 0; i < len; i += 2) {
        int upper = hex_char_to_int(hex[i]);
        int lower = hex_char_to_int(hex[i + 1]);
        if (0 > upper || 0 > lower) {
            return -1;
        }
        char byte = (upper << 4) + lower;
        bytes[byteLen++] = byte;
    }

    return byteLen;
}

/**
 * @brief Writes data to a previously allocated chunk.
 *
 * @param idx The index of the chunk.
 * @param hex_data The data to write in hexadecimal format.
 */
void fill_cmd(int idx, const char *hex_data) {
    if (idx < 0 || idx >= MAX_CHUNKS || NULL == chunks[idx].ptr) {
        printf("Invalid chunk index.\n");
        return;
    }

    char decoded_data[256];
    int len = decode_hex(hex_data, decoded_data);

    if (len < 0 || len > chunks[idx].size) {
        printf("Invalid data or exceeds chunk size.\n");
        return;
    }

    memcpy(chunks[idx].ptr, decoded_data, len);
}

/**
 * @brief Checks the global variable and potentially reads the flag.
 */
void check_flag() {
    if (strcmp(check_var, "flag") == 0) {
        FILE *f = fopen("./flag.txt", "r");
        if (f) {
            char flag[256];
            if (0 < fgets(flag, sizeof(flag), f)) {
                printf("%s\n", flag);
            }
            fclose(f);
        }
    }
}

/**
 * @brief Signal handler for SIGALRM.
 *
 * Terminates the program gracefully.
 */
void alarm_handler(int signum) {
    (void)signum; // Unused parameter
    printf("Timeout! Program terminated.\n");
    exit(0);
}

static char ALLOCATE_CMD_FMT[] = "A%u%n";
static char FILL_CMD_FMT[] = "F%1u%20[0-9a-f]%n";
static char DELETE_CMD_FMT[] = "D%1u%n";

/**
 * @brief Parses and executes the given command sequence.
 *
 * @param input The command sequence.
 */
int parse_and_execute(const char *input) {
    int return_code = EXIT_FAILURE;
    int position = 0;
    int len = strlen(input);
    while (position < len) {
        int bytesRead = 0;

        uint32_t param1 = 0;
        char param2[32] = {0};

        if (sscanf(input + position, ALLOCATE_CMD_FMT, &param1, &bytesRead) ==
            1) {
            allocate_cmd(param1);
        } else if (sscanf(input + position, FILL_CMD_FMT, &param1, param2,
                          &bytesRead) == 2) {
            fill_cmd(param1, param2);
        } else if (sscanf(input + position, DELETE_CMD_FMT, &param1,
                          &bytesRead) == 1) {
            delete_cmd(param1);
        } else if ('\n' == input[position]) {
            bytesRead = 1;
        } else {
            printf("Unrecognized command at index %d: %c\n", position,
                   input[position]);
            goto parse_and_execute_end;
        }
        position += bytesRead;
    }

    return_code = EXIT_SUCCESS;
parse_and_execute_end:
    return return_code;
}

/**
 * @brief Spawns a child process and disables ASLR for the child.
 *
 * This function uses the fork-exec model to spawn a child process with
 * Address Space Layout Randomization (ASLR) disabled via the personality
 * system call. After spawning the child, the parent process waits for
 * the child to finish execution.
 *
 * The child process is invoked with the same program name as the current
 * process and an additional argument "child".
 *
 * @param argv The argument vector, typically the one received by main().
 *             Only the first element (program name) is used.
 *
 * @return Returns EXIT_FAILURE on error conditions.
 *         For the parent process, it returns the exit status of the child.
 *         For the child process, if execv fails, it returns EXIT_FAILURE;
 *         otherwise, this function does not return for the child process
 *         as execv replaces the process image.
 */
int disable_aslr(char **argv) {
    int return_code = EXIT_FAILURE;

    if (personality(ADDR_NO_RANDOMIZE) == -1) {
        goto disable_aslr_end;
    }

    int fork_result = fork();
    if (0 > fork_result) {
        goto disable_aslr_end;
    }

    if (0 != fork_result) {
        wait(&return_code);
        goto disable_aslr_end;
    }

    char *argv_new[3] = {0};
    argv_new[0] = argv[0];
    argv_new[1] = "child";

    return_code = execv(argv_new[0], argv_new);

disable_aslr_end:
    return return_code;
}

void set_timeout() {
    // Setup timer
    struct itimerval timer;
    timer.it_value.tv_sec = 2; // seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    signal(SIGALRM, alarm_handler);
}

void print_hints() {
    printf("Overwrite the value at %p so it's 'flag'\n", check_var);
    volatile void **mptr = malloc(8);
    free(mptr);
    printf("Your super secret xor key is %p\n", *mptr);
    mptr = NULL;
}

int main(int argc, char **argv) {
    int return_code = EXIT_FAILURE;

    // Turn off ASLR
    if (1 == argc) {
        return_code = disable_aslr(argv);
        goto main_end;
    }

    set_timeout();

    // Don't buffer stdout
    setvbuf(stdout, NULL, _IONBF, 0);

    // Leak some data about the program
    print_hints();

    // Read the program
    char input[MAX_PROG_LEN] = {0};
    printf("Enter your program:\n");
    if (0 >= read(0, input, sizeof(input) - 1)) {
        goto main_end;
    }

    // Execute
    if (EXIT_SUCCESS == parse_and_execute(input)) {
        // Check win condition
        check_flag();
    }

    return_code = EXIT_SUCCESS;
main_end:
    return return_code;
}
