//
// Created by shyamnath on 5/8/21.
//
#include <iostream>
#include <vector>

void find_subsets(std::vector<int> nums, int j, std::vector<int> subset, std::vector<std::vector<int>>& subsets)
{
    subsets.emplace_back(subset);
    for(auto i=j; j<nums.size(); ++j)
    {
        subset.push_back(nums[j]);
        find_subsets(nums, j+1, subset, subsets);
        subset.pop_back();
    }
}

int main()
{
    std::vector<int> nums = {1,2,3};
    std::vector<int> subset;
    std::vector<std::vector<int>> subsets = {{}};
    find_subsets(nums, 0, subset, subsets);
    int test = 1;
}