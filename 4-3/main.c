#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MATH 'n'
#define Var -10

int getop(char s[]);
void push(double);
double pop(void);
void clear(void);
double mathfnc(char s[]);

int main(){
    int type, now;
    double pop1, pop2, v = 0, variable[26] = {0.0};
    char s[MAXOP];
    while((type = getop(s)) != EOF){
        switch(type){
            case Var :
                push(variable[s[0] - 'A']);
                now = s[0];
                break;
            case NUMBER :
                push(atof(s));
                break;
            case MATH :
                pop1 = mathfnc(s);
                push(pop1);
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
                    push(pop() / pop2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%' :
                pop2 = pop();
                if(pop2 != 0)
                    push(fmod(pop(), pop2));
                else
                    printf("error: zero divisor\n");
                break;
            case '?' :
                pop1 = pop();
                printf("\t%.8g\n",pop1);
                push(pop1);
                break;
            case 'd' :
                pop1 = pop();
                push(pop1);
                push(pop1);
                break;
            case 's' :
                pop1 = pop();
                pop2 = pop();
                push(pop1);
                push(pop2);
                break;
            case 'c' :
                clear();
                break;
            case 'v' :
                push(v);
                break;
            case '\n' :
                v = pop();
                printf("\t%.8g\n", v);   
                break;
            case '=' :
                if (now >= 'A' && now <= 'Z'){               
                    pop1 = pop();
                    if(pop1 == variable[now - 'A'])
                        pop1 = pop();
                    else
                        pop();
                    variable[now - 'A'] = pop1;
                }else
                    printf("error: invalid assignment ( %c , %d )\n",now,now);
                
                break;
            default :
                printf("error: unknown command '%c' (%d)\n", s[0], s[0]);
                break;
        }
    }
    return 0;
}
double mathfnc(char s[]){
    double pop2;
    if(strcmp(s, "sin") == 0)
        return sin(pop());
    else if(strcmp(s, "cos") == 0)
        return cos(pop());
    else if(strcmp(s, "exp") == 0)
        return exp(pop());
    else if(strcmp(s, "pow") == 0){
        pop2 = pop();
        return pow(pop(), pop2);
    }
    else{
        printf("error: %s not supported\n", s);
        return -1;
    }
}