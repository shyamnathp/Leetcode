//
// Created by shyamnath on 5/30/21.
//
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int maxSubArray(const std::vector<int>& numbers)
{
    std::vector<int> dp(numbers.size()+1, INT32_MIN);
    dp[0] = numbers[0];

    for(int i=1; i<numbers.size();++i)
    {
        int tempSum = INT32_MIN;
        for(int j=0; j<i; ++j)
        {
            tempSum = std::max(tempSum, std::accumulate(numbers.begin()+j, numbers.begin()+i+1, 0));
        }

        dp[i] = std::max(dp[i-1], tempSum);
    }

    return dp[numbers.size() - 1];

}

int main()
{
std::vector<int> numbers = {-2, -3, 4, -1, -2, 1, 5, -3, 11};
int sum = maxSubArray(numbers);
int test = 1;
}