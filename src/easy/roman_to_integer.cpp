//
// Created by shyamnath on 5/2/21.
//
#include <map>
#include <iostream>
#include <string_view>
#include <iterator>
#include <vector>

const std::map<char, int> symbolValue = {{'I', 1},
                                         {'V', 5},
                                         {'X', 10},
                                         {'L', 50},
                                         {'C', 100},
                                         {'D', 500},
                                         {'M', 1000}};

template<class Type, class Next>
bool is_one_of(const Type& needle, const Next& next)
{return needle==next;}

template<class Type, class Next, class ... Rest>
bool is_one_of(const Type& needle, const Next& next, Rest... haystack)
{return needle==next || is_one_of(needle, haystack...);}

int toInteger(std::string_view s)
{
    int num = 0;
    auto c = s.data();
    for(int i=0; i<s.size(); ++i)
    {
        if(is_one_of(*c, 'I', 'X', 'C') && i!=(s.size()-1))
        {
            if (*c == 'I' && is_one_of(*(std::next(c)), 'V', 'X'))
            {
                ++i;
                num = num + symbolValue.at(*(std::next(c))) - symbolValue.at(*c);
                c = std::next(c, 2);
                continue;
            }
            else if (*c == 'X' && is_one_of(*(std::next(c)), 'L', 'C'))
            {
                ++i;
                num = num + symbolValue.at(*(std::next(c))) - symbolValue.at(*c);
                c = std::next(c, 2);
                continue;
            }
            else if (*c == 'C' && is_one_of(*(std::next(c)), 'D', 'M'))
            {
                ++i;
                num = num + symbolValue.at(*(std::next(c))) - symbolValue.at(*c);
                c = std::next(c, 2);
                continue;
            }
        }

        num += symbolValue.at(*c);
        c = std::next(c);
    }
    return num;
}

 int main()
 {
    std::string s="LVIII";
    auto i = toInteger(s);
    std::cout<<i;
 }
