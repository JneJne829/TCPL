#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE] = {0};
int bufp = 0;

int getch(void){
    return (bufp > 0)? buf[--bufp] : getchar();
}
void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch : too many characters\n");
    else
        buf[bufp++] = c;
}
