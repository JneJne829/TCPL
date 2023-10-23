#include <stdio.h>

#define MAXOP 100

int sp = 0;
double val[MAXOP] = {0};

void push(double f){
    if(sp<100)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
double pop(void){
    if(sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
        return 0.0;
}