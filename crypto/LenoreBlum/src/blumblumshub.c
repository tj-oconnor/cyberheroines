#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


// Function to check if a number is prime
bool is_prime(uint64_t num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (uint64_t i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to find a prime number congruent to 3 modulo 4
uint64_t find_prime_congruent_to_3_mod_4(uint64_t start) {
    while (true) {
        if (is_prime(start) && (start % 4 == 3)) {
            return start;
        }
        start++;
    }
}


uint64_t bbs(uint64_t p, uint64_t q, uint64_t s) {
    uint64_t N = p * q;
    uint64_t x = (s * s) % N;  // Compute x_i = x_(i-1)^2 % N

    uint64_t result = 0;
    for (int i = 0; i < 63; i++) {
        x = (x * x) % N;  // Compute the next x_i
        result |= (x & 1) << i;  // Extract the LSB and set the corresponding bit in the result
    }

    return result;
}


void print_file(const char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Read and print the contents of the file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);
}


int main() {
    printf("Lets play a little game.\nI give you a seed, and you guess my random number.\nWould you like to play? Y/N >>> ");
    char choice = 'n';
    scanf("%c", &choice);
    if (choice != 'y') {
        return 0;
    }

    while (1) {
        srand(time(NULL));  // Seed the random number generator with the current time
        uint64_t min_value = rand() % 65000;
        uint64_t p = find_prime_congruent_to_3_mod_4(min_value);
        uint64_t q = find_prime_congruent_to_3_mod_4(p + 1);
        uint64_t s = min_value * 1337;    // Replace with your chosen seed value

        printf("Here is my seed: %lld\nCan you guess my random number? >>> ", s);
        uint64_t input = 0;
        scanf("%ld", &input);
        uint64_t random_value = bbs(p, q, s);

        if (input == random_value) {
            printf("Great job! Here's your prize:\n");
            print_file("flag.txt");
            return 0;
        }
        else {
            printf("Incorrect. My random number was %lld\n", random_value);
        }
    }
    return 0;
}
