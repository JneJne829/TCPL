#include<stdio.h>
#include <ctype.h>
 /* atof: convert string s to double */
double atof(char s[])  {
    double val, power, pro2;
    int i, sign, sign2, pro;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    sign2 = (s[i] == '-') ? 0 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for(pro = 0; isdigit(s[i]); i++)
        pro = 10 * pro + (s[i] - '0');
    for(pro2 = 1; pro > 0; pro--)
        if(sign2)
            pro2 *= 10;
        else
            pro2 /= 10;
    return sign * ((val / power) *  pro2);
 }
 int main(){
    printf("%lf\n",atof("3.14E1"));
 }