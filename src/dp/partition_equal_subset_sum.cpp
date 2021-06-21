//
// Created by shyamnath on 5/31/21.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

bool ifPartitionSum(const std::vector<int>& values, int a, int b, int i)
{
    static std::unordered_map<std::string, int> dp;

    if(a==0 and b==0)
        return true;

    if(a<0 or b<0 or (i==values.size()))
        return false;

    std::string hash = std::to_string(a) + 'a' + std::to_string(b) + 'b' + std::to_string(i);

    if (dp.find(hash) != dp.end())
        return dp[hash];

    dp[hash] = ifPartitionSum(values, a - values[i], b, i+1) || ifPartitionSum(values, a, b - values[i], i+1);

    return dp[hash];
}


int main()
{
std::vector<int> values = {1,1,2,5,5,5,5};
int sum = std::accumulate(values.begin(), values.end(), 0);

if (sum % 2 == 0) {
    if(ifPartitionSum(values, sum / 2, sum / 2, 0))
        std::cout<<"True";
    else
        std::cout<<"False";
}
else
     std::cout<<"False";
}
