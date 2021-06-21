//
// Created by shyamnath on 5/15/21.
//
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string test = "abc    ";
    test.erase(std::remove(test.begin(), test.end(), ' '), test.end());
    int test1 = 1;
}
