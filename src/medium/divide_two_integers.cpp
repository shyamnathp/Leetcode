//
// Created by shyamnath on 5/21/21.
//
#include <iostream>
#include <cstdlib>

int main()
{
    int dividend = -2147483648;
    int divisor =  -1;
    int sign;

    if((dividend>0 and divisor>0) or (dividend<0 and divisor<0))
        sign = 1;
    else
        sign=-1;

    unsigned int new_dividend;
    new_dividend = (dividend < 0)?-dividend:dividend;

    unsigned int new_divisor = (divisor < 0)?-divisor:divisor;
    unsigned int quotient = 0;
    while (new_dividend >= new_divisor) {
        new_dividend -= new_divisor;
        ++quotient;
    }

    return sign * quotient;
}
