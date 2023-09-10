#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
  char passwd[23];
  char buf[23];
  printf("                                                                                \n");
  printf("   WXKXNW                                                                       \n");
  printf("  W0xddkX               WWWWWWWW                                                \n");
  printf("  NOdddxKWWNNXXXXKKKK000OOOOOOOOO00KXXNWWW                                      \n");
  printf("  NOdddxKWXkxxxddddddddddddddddddddddxxkOO0XNWW                                 \n");
  printf("  WOdddxKWKxddddddddddddddddddddddddddddddddxk0KXNNWW                           \n");
  printf("  WOdddxKWKxdddddddddddddddddddddddddddddddddddddxkkOO00KKKKKKKKKKKKKKKKKKKXW   \n");
  printf("  NOdddxKWKxdddddddddddddddddddddddddddxxkkkkxdddddddddddddddddddddddddddddx0W  \n");
  printf("  NOdddxKWKxddddddddddddddddddddddddk0KNNNWWNNX0kxddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxddddddddddddddddddddddkKNW         WWKkdddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxdddddddddddddddddddddkXW  WNKK00KNW  WXkddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxddddddddddddddddddddx0W  WKxdddddxKW  W0xdddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxddddddddddddddddddddxKW  W0ddddddd0W  WKxdddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxdddddddddddddddddddddON  WN0kkxxk0N   NOddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxdddddddddddddddddddddx0NW  WWWNNWW  WN0xddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxdddddddddddddddddddddddkKNW       WNKkxdddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxdddddddddddddddddddddddddxOXWW  WXOxddddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxddddddddddddddddddddddddddd0WW  W0ddddddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxdddddddddddddddddddddddxxxxKWW  WKxxxxddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxddddddddddddddddddddddOXXXNW     WNXXXOdddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxdddddddddddddddddddddd0W             W0dddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxddddddddddddddddddddddk0KKKNW   WNKKK0kdddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxddddddddddddddddddddddddddd0NW  W0xdddddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKxdddddddddddddddddddddddddddk00000kddddddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWKkxxxxxkkkOOOO000000000OOkkxddddddddddddddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKWNXXXNNNWWWWW            WWNNXK00OkxdddddddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKW                                WNXKOkxxddddddddddddddddddddddddddON  \n");
  printf("  NOdddxKW                                     WNXKK00OOkkkkkkkkkkkkkkkkkkkOXW  \n");
  printf("  NOdddxKW                                             WWWWWWWWWWWWWWWWWWWWW    \n");
  printf("  NOdddxKW                                                                      \n");
  printf("  NOdddxKW                                                                      \n");
  printf("  NOdddxKW                                                                      \n");
  printf("  NOdddxKW                                                                      \n");
  printf("  NOdddxKW                                                                      \n");
  printf("  WOdddxKW                                                                      \n");
  printf("  NOdddxKW                                                                      \n");
  printf("  NOdddxKW                                                                      \n");
  printf("  WKkkkOX                                                                       \n");
  printf("   WWWWW                                                                        \n");
  printf("                                                                                \n");
  printf("                                                                                \n");
  printf("\n\n            Leaders of the future will have to be visionary                 \n");
  printf("                        and be able to bring people in                          \n");
  printf("\n\n00000000000000000000000000000000000000000000000000000000000000000000000000000000");
  printf("\n\n Please submit the flag >>> ");
  fflush(0);
  read(0, buf, 23);
  passwd[0]='c';
  passwd[1]='h';
  passwd[2]='c';
  passwd[3]='t';
  passwd[4]='f';
  passwd[5]='{';
  passwd[6]='b';
  passwd[7]='_';
  passwd[8]='A';
  passwd[9]='_';
  passwd[10]='V';
  passwd[11]='1';
  passwd[12]='s';
  passwd[13]='1';
  passwd[14]='0';
  passwd[15]='N';
  passwd[16]='A';
  passwd[17]='r';
  passwd[18]='Y';
  passwd[19]='_';
  passwd[20]='2';
  passwd[21]='}';
  passwd[22]='\0';
;

  if (strncmp(buf, passwd,22) == 0)
  {
    printf(" <<< Access Grant, here is the flag: %s\n", passwd);
  }
  else
  {
    printf(" <<< Keep trying and believe in yourself.");
  }
}
