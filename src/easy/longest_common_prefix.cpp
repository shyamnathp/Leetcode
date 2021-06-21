//
// Created by shyamnath on 5/2/21.
//

#include <string>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

std::string pairCommon(std::string_view common, std::string_view nextString)
{
    std::string newCommon = "";
    int i;
    for(i = 0; i<common.size();++i) {
        if (common[i] != nextString[i])
        {
            if(i == 0)
                return "";
            newCommon = common.substr(0, i);
            break;
        }
    }
    if(i == common.size())
    {
        newCommon = common;
    }
    return newCommon;
}

std::string findCommonPrefix(std::vector<std::string>& strs)
{
    std::ranges::sort(strs, [](auto& s1, auto& s2){return s1.size() < s2.size();});
    std::string common = strs[0];
    for(int i=1; i<strs.size(); ++i)
    {
        common = pairCommon(common, strs[i]);
        if (common.empty())
            return "";
    }
    return common;
}

int main()
{
    std::vector<std::string> strs = {"a", "b"};
    std::string common = findCommonPrefix(strs);
    std::cout<<common;
}
