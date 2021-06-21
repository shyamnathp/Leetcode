//
// Created by shyamnath on 5/29/21.
//
#include <iostream>
#include <string>
#include <stack>

int calculate(const std::string& s)
{
    int result =0, number=0;
    int sign =1;
    std::stack<int> residue;

    for(int i=0; i<=s.size();++i)
    {
        if(isdigit(s[i]))
        {
            number = number*10+s[i]-'0';
        }
        else if (s[i] == '+')
        {
            result += sign * number;
            number=0;
            sign=1;
        }
        else if (s[i] == '-')
        {
            result += sign* number;
            number=0;
            sign=-1;
        }
        else if (s[i] == '(')
        {
            residue.push(result);
            residue.push(sign);
        }
        else if (s[i] == ')')
        {
            result +=sign*number;
            number=0;
            result *= residue.top();
            residue.pop();
            result += residue.top();
            residue.pop();
        }
    }

    if(number != 0)
        result +=sign*number;

    return result;
}

int main()
{
    std::string s = "(1+(4+5+2)-3)+(6+8)";
    int c = calculate(s);
    int test = 1;
}