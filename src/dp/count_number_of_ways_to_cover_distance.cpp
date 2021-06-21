//
// Created by shyamnath on 5/29/21.
//
#include <iostream>
#include <vector>
#include <string>

int count(int n)
{
    std::vector<int> dp(n+1,0);

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int j=3; j<=n;++j)
    {
        for(const auto& i: {1, 2, 3})
        {
            dp[j] += dp[j-i];
        }
    }

    return dp[n];
}


int main()
{
int n = 4;
int num = count(n);
int test = 1;
}