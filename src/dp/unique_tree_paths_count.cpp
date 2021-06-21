//
// Created by shyamnath on 6/11/21.
//Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
//

#include <vector>
#include <iostream>

int main()
{
    int n=4;
    std::vector<int> dp(n+1, 0);
    dp[0] = 1, dp[1]=1;
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    std::cout<<dp[n];
}
