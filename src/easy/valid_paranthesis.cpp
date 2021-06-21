//
// Created by shyamnath on 5/2/21.
//

#include <string>
#include <string_view>
#include <stack>
#include <iostream>
#include <vector>
#include <map>

//template<class T, class Next, class... Rest>
//auto brakcet_check(T b, Next bNext, Rest... bRest)
//{
//    return b==bNext || brakcet_check(b, bRest...);
//}

std::map<char, char> findOpeningBracket= {{'}','{'}, {')', '('}, {']', '['}};

template<class Type, class Next>
bool is_one_of(const Type& needle, const Next& next)
{return needle==next;}

template<class Type, class Next, class ... Rest>
bool is_one_of(const Type& needle, const Next& next, Rest... haystack)
{return needle==next || is_one_of(needle, haystack...);}


bool check_paranthesis(std::string_view c)
{
    std::stack<char> brackets;
    int opening=0, closing =0;
    for(const auto& brakcet: c)
    {
        if(is_one_of(brakcet, '{', '(', '['))
        {
            //push to stack
            ++opening;
            brackets.push(brakcet);
        }
        else
        {
            //pop from stack and check
            ++closing;

            if (closing > opening)
                return false;

            char c = brackets.top();
            brackets.pop();

            if (c != findOpeningBracket[brakcet])
            {
                return false;
            }
        }
    }

    if (opening == closing)
        return true;
    return false;
}



int main()
{
    std::string s = ")(";
    if (check_paranthesis(s))
        std::cout<<"True";
    else
        std::cout<<"False";
}

