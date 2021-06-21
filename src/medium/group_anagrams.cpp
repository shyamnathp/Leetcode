//
// Created by shyamnath on 5/15/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> results;
    std::vector<bool> visited(strs.size(), false);

    for(int i=0; i<strs.size();++i)
    {
        if (not visited[i])
        {
            visited[i] = true;
        }
        else
            continue;

        auto temp = strs[i];
        std::vector<std::string> subResults;
        subResults.emplace_back(temp);
        std::sort(temp.begin(), temp.end());

        do
        {   auto it = strs.begin() + i;
            while (it != strs.end())
            {
                it = std::find(it+1, strs.end(), temp);
                if(it != strs.end()) {
                    visited[std::distance(strs.begin(), it)] = true;
                    subResults.emplace_back(temp);
                }
            }
        }while(std::next_permutation(temp.begin(), temp.end()));

        if(not subResults.empty())
            results.emplace_back(subResults);
    }
    int test = 0;
}