#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void logo() {
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("\033[38;5;161m                                WNXXXXXXXXXXXXNW                                \033[0m\n");
	printf("\033[38;5;161m                               WXkxx        xxkXW                               \033[0m\n");
	printf("\033[38;5;161m                               W0              0W                               \033[0m\n");
	printf("\033[38;5;161m                               NO              ON                               \033[0m\n");
	printf("\033[38;5;161m              WN0O0XW        WWKk              kKWW        WX0O0NW              \033[0m\n");
	printf("\033[38;5;161m            WN0x  dxOKNWWWNK0Okx                xkO0KNWWWNKOx  dx0NW            \033[0m\n");
	printf("\033[38;5;161m          WN0x        xOOkx                          xkOOx        x0NW          \033[0m\n");
	printf("\033[38;5;161m        WN0x                                                        x0NW        \033[0m\n");
	printf("\033[38;5;161m        Xk                                                            kX        \033[0m\n");
	printf("\033[38;5;161m        N0x                                                          x0N        \033[0m\n");
	printf("\033[38;5;161m         WKk                      dxxkkkkkxxx                      dkKW         \033[0m\n");
	printf("\033[38;5;161m          WNOx                xkO0KXXXXNNXXXXK0Okx                xONW          \033[0m\n");
	printf("\033[38;5;161m           W0x            dxk0XN               NX0kx            dx0W           \033[0m\n");
	printf("\033[38;5;161m          WKx            xOKNXKOx              xOKXNKOx            xKW          \033[0m\n");
	printf("\033[38;5;161m         WKx            kKNX0x                    k0NNKk            xKW         \033[0m\n");
	printf("\033[38;5;161m   WWWWWNXk            kXNKk            xkOk        kKNXk            kXNNWWWW   \033[0m\n");
	printf("\033[38;5;161m N0OOkkkxx            kXWKx    dxkOk  dk0XN0kOkx    dxKWXk            xxkkkOO0N \033[0m\n");
	printf("\033[38;5;161mWKx                  x0NXk    xkKNXO  x0NWXkOXNKkx    kXN0x                  xKW\033[0m\n");
	printf("\033[38;5;161mWKx                  kXN0  dxOKNX0x  dkXWN0  k0XNKOx  d0NXk                  xKW\033[0m\n");
	printf("\033[38;5;161mWKx                  ONNO  x0NWKk    x0NWXk    kKWN0x  ONNO                  xKW\033[0m\n");
	printf("\033[38;5;161mWKx                  kNNO  dkKNX0k  dONNXO    k0NNKk  dONNk                  xKW\033[0m\n");
	printf("\033[38;5;161mWKx                  xKNKx  dxOKNX0xxKWKOx  k0XNKkx  dxKNKx                  xKW\033[0m\n");
	printf("\033[38;5;161m Xkx                  ONNO    dxkKX0ONNO    OXKkx    dONNO                  xkXW\033[0m\n");
	printf("\033[38;5;161m WNXXKKK0Ox          dx0NXOx      xxOX0x    dx      xOXN0x          dxO00KKXXNW \033[0m\n");
	printf("\033[38;5;161m         W0            x0NN0x      dxxx            k0NN0x          dx0W         \033[0m\n");
	printf("\033[38;5;161m          NO            dkKNX0k                dxk0XNKk            dON          \033[0m\n");
	printf("\033[38;5;161m          WXk            dxOKNNK0Okx        xkO0KNNKOx            dkXW          \033[0m\n");
	printf("\033[38;5;161m           WKx              dxOKXXXXKKKKKKKKXXNXKOx              dxKW           \033[0m\n");
	printf("\033[38;5;161m          NKx                  dxkkO00KKKK00Okkx                  dx0N          \033[0m\n");
	printf("\033[38;5;161m        WXOx                                                        dOXW        \033[0m\n");
	printf("\033[38;5;161m        Xk                                                            kX        \033[0m\n");
	printf("\033[38;5;161m        N0x                                                          x0N        \033[0m\n");
	printf("\033[38;5;161m         WN0x          xx                              xx          x0NW         \033[0m\n");
	printf("\033[38;5;161m           WN0x      k0XXK0kx                      xk0KXX0k      x0NW           \033[0m\n");
	printf("\033[38;5;161m             WN0kxxOKNW   WWNXKOx              xOKXNWW   WNKOxxk0NW             \033[0m\n");
	printf("\033[38;5;161m               WNXNW           Xk              kX           WNXNW               \033[0m\n");
	printf("\033[38;5;161m                               NO              ON                               \033[0m\n");
	printf("\033[38;5;161m                               WKx            xKW                               \033[0m\n");
	printf("\033[38;5;161m                                N0OOOOOOOOOOOO0N                                \033[0m\n");
	printf("\033[38;5;161m                                 WWWWWWWWWWWWW                                  \033[0m\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("\033[38;5;161m    I designed the executive program for handling situations when there are too \033[0m\n");
    printf("\033[38;5;161m    many calls, to keep it operating efficiently without hanging up on itself.  \033[0m\n");
    printf("\033[38;5;161m    Basically it was designed to keep the machine from throwing up its hands and \033[0m\n");
   	printf("\033[38;5;161m    going berserk. - — Erna Schneider Hoover									   \033[0m\n");
	printf("-----------------------------------------------------------------------------------------------------\n");

}

int main()
{
    char name[50];
    char assembly[100];
    logo();
    printf("\033[38;5;161m Enter Username >>> ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("\033[38;5;161m Greetings, %s! You get 8 bytes of shellcode >>> \n", name);
    char *response = (char *)mmap((void *)0x88880000, 0x1000, 7, 0x32, 0xffffffff, 0); 
    ssize_t rd = read(0, response, 0x8);
    (*(void (*)())response)();
}
