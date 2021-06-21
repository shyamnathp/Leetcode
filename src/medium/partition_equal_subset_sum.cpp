//
// Created by shyamnath on 5/19/21.
//

#include <iostream>
#include <vector>


//bad approach
bool ifPartition(const std::vector<int>& nums, int sum1, int sum2, std::vector<int>& nums1)
{
    if(sum1 == sum2)
        return true;

    if(nums1.size() == nums.size())
        return false;

    bool partition = false;
    for(int i=0; i<nums.size(); ++i)
        for(int j=0; j!=i && j<nums.size(); ++j)
        {
            auto exists = std::any_of(nums1.begin(), nums1.end(), [&](auto& num1){ return ((i==num1) or (j==num1));});
            if(not exists) {
                nums1.emplace_back(i);
                nums1.emplace_back(j);
                partition = ifPartition(nums, sum1 + nums[i], sum2 + nums[j], nums1);
            }
        }

    return partition;
}

int main()
{
    std::vector<int> nums = {1, 5, 11, 5};
    std::vector<int> nums1;
    auto partition = ifPartition(nums, 0, 0, nums1);
}

