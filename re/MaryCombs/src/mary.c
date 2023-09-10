#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>


__attribute__((constructor)) void ignore_me() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}

void times_up(int signum){ 
  printf("\n<<< You ran out of time.\n");
  exit(-1);
}


void logo() {
    printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf("MMMWNXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXWMMMMWXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXNWMMM\n");
    printf("MMWKk                               x0WMMW0x                              xkKWMM\n");
    printf("MMW0                                 ONWWNO                                 0WMM\n");
    printf("MMW0              xkkkx              ONWWNO                                 0WMM\n");
    printf("MMW0             x0NWNXk             ONWWNO                                 0WMM\n");
    printf("MMW0             xKWMMNO             ONWWNO                                 0WMM\n");
    printf("MMW0             xKWMMNO             ONWWNO                                 0WMM\n");
    printf("MMW0      xxxxxxxkXWMMNOxxxxxxx      ONWWNO      xxxxxxxxxxxxxxxxxxxxx      0WMM\n");
    printf("MMW0     kKXXXXXXNWMMMWNXXXXXXXOx    ONWWNO    xOXXXXXXXXXXXXXXXXXXXXKk     0WMM\n");
    printf("MMW0     ONWMMMMMMMMMMMMMMMMMMWKx    ONWWNO    xKWMMMMMMMMMMMMMMMMMWWNO     0WMM\n");
    printf("MMW0     x000KKKKKNMMMWXKKKKK00k     ONWWNO     k0KKKKKKKKKKKKKKKKK000x     0WMM\n");
    printf("MMW0             xKWMMNO             ONWWNO                                 0WMM\n");
    printf("MMW0             xKWMMNO             ONWWNO                                 0WMM\n");
    printf("MMW0             xKWMMNO             ONWWNO                                 0WMM\n");
    printf("MMW0             xOXXXKk             ONWWNO                                 0WMM\n");
    printf("MMW0                xx               ONWWNO                                 0WMM\n");
    printf("MMW0x                                ONWWNO                                x0WMM\n");
    printf("MMWXOkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkKWMMWKkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOXWMM\n");
    printf("MMMMWWNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWMMMMWWNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWWMMMM\n");
    printf("MMMWXK0KK00000000KKKKKKKKKK000000KKKKNMMMMNKKKK0KKKKKKKKKKKKKKKKK0000KKKK0KXWMMM\n");
    printf("MMWKx                                ONMWNO                                xKWMM\n");
    printf("MMW0                                 ONWWNO                                 0WMM\n");
    printf("MMW0                                 ONWWNO             xkOOOk              0WMM\n");
    printf("MMW0         kOkx        xOkx        ONWWNO             kNWWWKx             0WMM\n");
    printf("MMW0       x0NWNKkx    k0NWNKk       ONWWNO             kXWWWKx             0WMM\n");
    printf("MMW0       kKWMMMNKkxk0NWMMWXO       ONWWNO             xkOOOx              0WMM\n");
    printf("MMW0        xOXWMMMNXNWMMWX0x        ONWWNO     xkkkkkkkkkkkkkkkkkkkkx      0WMM\n");
    printf("MMW0          xOXWMMMMMMN0x          ONWWNO    x0NWWWWWWWWWNNNWWWWWNNXk     0WMM\n");
    printf("MMW0           xKWMMMMMWXOx          ONWWNO    xKWWWWWWMMMMMMMMMMMWWWNO     0WMM\n");
    printf("MMW0         x0XWMMWWWMMMNKkx        ONWWNO     kOOOOOOOOOOOOOOOOOOOOOx     0WMM\n");
    printf("MMW0       x0XWMMWN0kOKWMMMNKk       ONWWNO              xxxx               0WMM\n");
    printf("MMW0       kKWWWN0x   xOXWWWNO       ONWWNO             kKNNX0x             0WMM\n");
    printf("MMW0        xOK0x       xO00k        ONWWNO             ONWWWKx             0WMM\n");
    printf("MMW0                                 ONWWNO             x0KK0O              0WMM\n");
    printf("MMW0                                 ONWWNO                                 0WMM\n");
    printf("MMWKx                                ONMMNO                                x0WMM\n");
    printf("MMMNKOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0XWMMWX0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0NMMM\n");
    printf("MMMMMWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMM\n");
    printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("           Wherever there is a number, there is beauty.— Proclus               \n");
    printf("--------------------------------------------------------------------------------\n");

}

int problem(int a, int b, int t1, int r) {
    switch (t1 % 10) {
        case 0:
            return a - b + t1 + r;
        case 1:
            return a + b + t1 - r;
        case 2:
            return a - b - t1 + r;
        case 3:
            return a - b + t1 - r;
        case 4:
            return a + b - t1 - r;
        case 5:
            return a * b + t1 + r;
        case 6:
            return a + b * t1 + r;
        case 7:
            return a + b + t1 * r;
        case 8:
            return a * b * t1 + r;
        default:
            return a + b + t1 + r;
    }
}

void check(int n1, int n2, int t1) {
    int r;
    printf("Random 1 >>> %i\n", n1);
    printf("Random 2 >>> %i\n", n2);
    printf("Your Response >>> ");
    scanf("%i", &r);
    if (problem(n1, n2, t1, r) != 1337) {
        printf("<<< Incorrect. Exiting\n");
        exit(0);
    } else {
        printf("<<< Correct. Continuing\n");
    }
}


void math_is_fun() {
    srand(time(NULL));

    for (int i = 1; i < 100; i++) {
        int n1 = rand();
        int n2 = rand();
        check(n1, n2, i);
    }
    system("cat flag.txt");
}

int main(int argc, char* argv[]) {
    signal(SIGALRM,times_up); 
    alarm(30);
    logo();
    math_is_fun();
}
