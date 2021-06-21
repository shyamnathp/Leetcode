//
// Created by shyamnath on 5/1/21.
//

#include <string>
#include <iostream>
#include <functional>

int strStr(std::string haystack, std::string needle) {

    if (haystack.empty() and needle.empty())
        return 0;

    auto pos = std::search(haystack.begin(), haystack.end(), std::boyer_moore_searcher(needle.begin(), needle.end()));

    if(pos == haystack.end())
        return -1;
    else
        return std::distance(haystack.begin(), pos);

}

int main()
{
    std::string haystack = "hello";
    std::string needle = "ll";
    auto test = strStr(haystack, needle);
    std::cout<<test;
    return 0;
}
