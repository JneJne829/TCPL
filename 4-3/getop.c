#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

int getop(char s[]){
    int i, c;
    while(((c = s[0] = getch()) == ' ') || (c == '\t'))
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    
    i = 0;
    if(isdigit(c))
        while(isdigit(c = s[++i] = getch()))
        ;
    if(c == '.')
        while(isdigit(c = s[++i] = getch()))
        ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}