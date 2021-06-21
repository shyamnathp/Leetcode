#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>
#include <map>

bool check_brackets(std::string_view para)
{
    if((para[0]==')') or (para[para.size()-1]=='('))
        return false;

    std::map<char, int> counter;
    counter.insert({'(', 0});
    counter.insert({')', 0});

    for(const auto& bracket: para)
    {
        if (bracket == '(')
            ++counter['('];
        else
            ++counter[')'];

        if(counter[')'] > counter['('])
            return false;
    }

    return true;
}

int main()
{
    int n = 1;
    std::vector<char> paranthesis(2*n);
    std::string para="";

    for(int i=0; i<n; ++i)
        para += '(';
    for(int i=n; i<2*n; ++i)
        para += ')';


    while(std::next_permutation(para.begin(), para.end()))
    {
        //std::cout<<para<<"\n";
        auto value = check_brackets(para);
    }
}