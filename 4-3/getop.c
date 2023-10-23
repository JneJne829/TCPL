#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUMBER '0'
#define MATH 'n'
#define Var -10

int getch(void);
void ungetch(int);

int getop(char s[]){
    int i, c;
    while(((c = s[0] = getch()) == ' ') || (c == '\t'))
        ;
    s[1] = '\0';
    i = 0;
    if(islower(c) != 0){
        while(islower(c = s[++i] = getch()))
            ;
        s[i] = '\0';
        if(c != EOF)
            ungetch(c);
        if(strlen(s) > 1)
            return MATH;
        else
            return s[0];
    }
    
    if(!isdigit(c) && c != '.' && c!= '-'){
        if(c >= 'A' && c <= 'Z')
            return Var;
        else
            return c;
    }

    if(c == '-')
        if(isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else{
            if(c != EOF)
                ungetch(c);
            return '-';
        }
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