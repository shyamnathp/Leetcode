//
// Created by shyamnath on 5/4/21.
//
#include <iostream>
#include <vector>

void plusOne(std::vector<int>& digits)
{
    for (auto i = digits.end()-1; i>=digits.begin(); --i)
    {
        if (*i ==9)
        {
            *i = 0;
            if(i == digits.begin())
            {
                digits.insert(digits.begin(), 1);
            }
        }
        else
        {
            *i += 1;
            break;
        }
    }
}

int main()
{
    std::vector<int> digits = {9, 9, 9, 9};
    plusOne(digits);
    int test = 0;
}

