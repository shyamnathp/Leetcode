//
// Created by shyamnath on 5/17/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    std::string text1="abcde";
    std::string text2="abfc";

    std::vector<int> dp(text2.size(), 0);

    if(text1.find(text2[0]) != std::string::npos)
        dp[0] = 1;
    else
        return 0;

    for(int i=1; i<text2.size(); ++i)
    {
        for(int j=0; j<i;++j)
        {
            if(j + dp[i-1] < i + 1)
            {
                auto pos = std::search(text1.begin(), text1.end(), std::boyer_moore_searcher(text2.begin() + j, text2.begin() + dp[i-1] + 1));
                if(pos != text1.end())
                    dp[i] = dp[i-1] + 1;
                else
                    dp[i] = dp[i-1];
            }
        }
    }

    int test = 0;

}

