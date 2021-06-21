//
// Created by shyamnath on 5/6/21.
//
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <charconv>

std::map<int, std::string> phone = {{2, "abc"},
                                    {3, "def"},
                                    {4, "ghi"},
                                    {5, "jhi"},
                                    {6, "mno"},
                                    {7, "pqrs"},
                                    {8, "tuv"},
                                    {9, "wxyz"}};

void combinations(int num, char c, std::string words, std::vector<std::string>& output)
{
    words = c + words;

    if(num == 0){
        output.emplace_back(words);
        return;
    }

    int digit = num % 10;

    if(digit != 1 or digit!=0)
    {
        for(char letter: phone[digit])
        {
            combinations(num/10, letter, words, output);
//            words = words + letter;
        }

    }
}

int main() {
    std::string digits = "2";
    int num = 0;
    std::from_chars(digits.data(), digits.data() + digits.size(), num);
    std::string words = "";
    char c = '\0';
    std::vector<std::string> output;
    combinations(num, c, words, output);
    int test = 1;
}
