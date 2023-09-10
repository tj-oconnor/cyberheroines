#include <Python.h>
#include <stdio.h>
#include <Python.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ANSI escape codes for pink color
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"

__attribute__((constructor)) void ignore_me() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}

void logo() {
    printf(ANSI_COLOR_MAGENTA"--------------------------------------------------------------------------------\n");
    printf(ANSI_COLOR_MAGENTA "                                                                                \n");
    printf(ANSI_COLOR_MAGENTA "                             WWWWNNXXXXXXXXXXNNWWW                              \n");
    printf(ANSI_COLOR_MAGENTA "                        WWNXK0OkkxxxxddddddxxxxkkO0KXNWW                        \n");
    printf(ANSI_COLOR_MAGENTA "                    WWXK0kxddddddddddddddddddddddddddxk0KXWW                    \n");
    printf(ANSI_COLOR_MAGENTA "                 WWX0kxddddddddddddddddddddddddddddddddddxk0XWW                 \n");
    printf(ANSI_COLOR_MAGENTA "               WX0kxddddddddddddddddddddddddddddddddddddddddxk0XW               \n");
    printf(ANSI_COLOR_MAGENTA "             WXOxddddddddddddddddddddddddddddddddddddddddddddddxOXW             \n");
    printf(ANSI_COLOR_MAGENTA "           WXOxdddddddddddddddddddddddxxxxdddddddddddddddddddddddxOXW           \n");
    printf(ANSI_COLOR_MAGENTA "          N0xdddddddddddddddddddxk0KKXXXXXXKK0kxdddddddddddddddddddx0N          \n");
    printf(ANSI_COLOR_MAGENTA "        WXkddddddddddddddddddxOKNW            WNKOxddddddddddddddddddkXW        \n");
    printf(ANSI_COLOR_MAGENTA "       WKxdddddddddddddddddxOXWW                 WXOxdddddddddddddddddxKW       \n");
    printf(ANSI_COLOR_MAGENTA "      W0xdddddddddddddddddkKW        WWWWWW        WKkdddddddddddddddddx0W      \n");
    printf(ANSI_COLOR_MAGENTA "     W0xdddddddddddddddddxKW      WX0OkkkkO0XW      WKkdddddddddddddddddx0W     \n");
    printf(ANSI_COLOR_MAGENTA "    WKxdddddddddddddddddx0W     WNOxddddddddxON      W0xdddddddddddddddddxKW    \n");
    printf(ANSI_COLOR_MAGENTA "   WXkddddddddddddddddddkXWW   WNOddddddddddddON      XkddddddddddddddddddkN    \n");
    printf(ANSI_COLOR_MAGENTA "   W0xddddddddddddddddddxO000000OxddddddddddddkXW     Xkddddddddddddddddddx0W   \n");
    printf(ANSI_COLOR_MAGENTA "   NkdddddddddddddddddddddddddddddddddddddddddON      XkdddddddddddddddddddON   \n");
    printf(ANSI_COLOR_MAGENTA "   XxdddddddddddddddddddddddddddddddddddddddxOXW     W0xdddddddddddddddddddxX   \n");
    printf(ANSI_COLOR_MAGENTA "  WKxdddddddddddddddddddddddddddddddddddddk0XW      WXkddddddddddddddddddddxKW  \n");
    printf(ANSI_COLOR_MAGENTA "  W0xdddddddddddddddddddddddddddddddddxO0KNW       WKkdddddddddddddddddddddd0W  \n");
    printf(ANSI_COLOR_MAGENTA "  W0xddddddddddddddddddddddddddddddddkKW         WXOxddddddddddddddddddddddx0W  \n");
    printf(ANSI_COLOR_MAGENTA "  WKxdddddddddddddddddddddddddddddddONW       WNKOxddddddddddddddddddddddddxKW  \n");
    printf(ANSI_COLOR_MAGENTA "   XkddddddddddddddddddddddddddddddkXW      WX0kdddddddddddddddddddddddddddkX   \n");
    printf(ANSI_COLOR_MAGENTA "   NOdddddddddddddddddddddddddddddd0W      WKkdddddddddddddddddddddddddddddON   \n");
    printf(ANSI_COLOR_MAGENTA "   WKxdddddddddddddddddddddddddddddkKKKXXKKKOdddddddddddddddddddddddddddddxKW   \n");
    printf(ANSI_COLOR_MAGENTA "    N0xddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddx0N    \n");
    printf(ANSI_COLOR_MAGENTA "     NOddddddddddddddddddddddddddddxkkkkkkkkxddddddddddddddddddddddddddddON     \n");
    printf(ANSI_COLOR_MAGENTA "     WXkddddddddddddddddddddddddddd0NWWWWWWN0dddddddddddddddddddddddddddkXW     \n");
    printf(ANSI_COLOR_MAGENTA "      WXkdddddddddddddddddddddddddd0W      W0ddddddddddddddddddddddddddOXW      \n");
    printf(ANSI_COLOR_MAGENTA "       WNOxdddddddddddddddddddddddd0W      W0ddddddddddddddddddddddddxONW       \n");
    printf(ANSI_COLOR_MAGENTA "         WKkdddddddddddddddddddddddOXXXXXXXXOdddddddddddddddddddddddkKW         \n");
    printf(ANSI_COLOR_MAGENTA "          WXOxddddddddddddddddddddddxxxxxxxxddddddddddddddddddddddxOXW          \n");
    printf(ANSI_COLOR_MAGENTA "            WXOxddddddddddddddddddddddddddddddddddddddddddddddddxOXW            \n");
    printf(ANSI_COLOR_MAGENTA "              WX0kddddddddddddddddddddddddddddddddddddddddddddk0XW              \n");
    printf(ANSI_COLOR_MAGENTA "                WNKOxddddddddddddddddddddddddddddddddddddddxOKNW                \n");
    printf(ANSI_COLOR_MAGENTA "                   WNK0kxddddddddddddddddddddddddddddddxk0KNW                   \n");
    printf(ANSI_COLOR_MAGENTA "                      WWNK0OkxxddddddddddddddddddxxkO0KNWW                      \n");
    printf(ANSI_COLOR_MAGENTA "                           WWNXKK00OOOOOOOOOO00KKXNWW                           \n");
    printf(ANSI_COLOR_MAGENTA "                                     WWWWWW                                     \n");
    printf(ANSI_COLOR_MAGENTA "                                                                                \n");
    printf(ANSI_COLOR_MAGENTA "--------------------------------------------------------------------------------\n");
    printf(ANSI_COLOR_MAGENTA " I would like to be remembered as someone who was not afraid to do what         \n");
    printf(ANSI_COLOR_MAGENTA " she wanted to do, and as someone who took risks along the way in order to      \n");
    printf(ANSI_COLOR_MAGENTA " achieve her goals. - Dr. Sally Ride                                            \n"); 
    printf(ANSI_COLOR_MAGENTA "--------------------------------------------------------------------------------\n");

}
int main(int argc, char *argv[]) {
    logo();
    Py_Initialize();
    const char *python_script = 
        "def main():\n"
        "    superhero_name = input(\"Who is your hero >>> \")\n" 
        "    print(\"Your hero name is:\", superhero_name)\n"
        "\n"
        "if __name__ == \"__main__\":\n"
        "    main()\n";

    PyRun_SimpleString(python_script);
    Py_Finalize();
    return 0;
}
