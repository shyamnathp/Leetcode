//
// Created by shyamnath on 6/4/21.
//

#include <vector>
#include <string>
#include <string_view>

bool ifPalindrome(std::string_view word)
{
    std::size_t size = word.size();
    std::vector<std::vector<int>> dp(word.size(), std::vector<int>(word.size(), 0));
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            if (i==j)
            {
                dp[i][j]= true;
            }
        }
    }

    for(int i=size-1; i>=0; --i)
    {
        for(int j=i+1; j<size; ++j)
        {
            if(j-i == 1)
                dp[i][j] = (word[i] == word[j]);
            else
            {
                dp[i][j] = ((word[i]==word[j]) and dp[i+1][j-1]);
            }
        }
    }

    int test = 1;
}

int main()
{
    std::string word = "malayala";
    auto verdict = ifPalindrome(word);
    int test = 1;
}
