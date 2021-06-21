//
// Created by shyamnath on 5/13/21.
//
#include <iostream>
#include <string>
#include <string_view>

bool checkPalindrome(std::string_view palindrome)
{
 return std::equal(palindrome.begin(), palindrome.begin() + palindrome.size()/2, palindrome.rbegin());
}

int main()
{
 std::string palindrome =  "malayalam";
 auto isPalindrome = checkPalindrome(palindrome);
 int test = 0;
}
