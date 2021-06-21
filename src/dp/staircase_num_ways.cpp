//
// given a number n, find the number of ways in staircase from bottom to top with either 1 or 2 steps.
//
#include <iostream>
#include <vector>
#include <string>

int numWays(int num) {

    std::vector<int> dp(num+1, 0);
    dp[0]=1;
    dp[1]=1;

    for (int i = 2; i <= num; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[num];
}

int main()
{
    int num = 9;
    int count = numWays(num) + 1;
    int test = 1;
}