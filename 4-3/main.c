#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);
void push(double);
double pop(void);

int main(){
    int type;
    double pop2;
    char s[MAXOP];
    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER :
                push(atof(s));
                break;
            case '+' :
                push(pop() + pop());
                break;
            case '-' :
                pop2 = pop();
                push(pop() - pop2);
                break;
            case '*' :
                push(pop() * pop());
                break;
            case '/' :
                pop2 = pop();
                if(pop2 != 0.0)
                    push(pop() - pop2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n' :
                printf("\t%.8g\n", pop());   
                break;
            default :
                printf("error: unknown command '%c' (%d)\n", s[0], s[0]);
                break;
        }
    }
    return 0;
}