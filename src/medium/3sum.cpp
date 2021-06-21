//
// Created by shyamnath on 5/20/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> triplets;
    std::sort(nums.begin(), nums.end());

    for(std::size_t i=0; i<nums.size()-2; ++i)
    {
        if(i == 0 || (nums[i] != nums[i-1]))
        {

            int lo = i + 1, hi = nums.size() - 1, sum = 0-nums[i];

            while(lo < hi)
            {
                // std::cout<<"inside loop";
                if(nums[lo] + nums[hi] == sum)
                {
                    triplets.emplace_back(std::vector<int>({nums[i], nums[lo], nums[hi]}));
                    while(lo < hi and nums[lo] == nums[lo+1]) lo++;
                    while(lo < hi and nums[hi] == nums[hi-1]) hi--;
                    ++lo, --hi;
                }
                else if (nums[lo] + nums[hi] < sum)
                    ++lo;
                else
                    --hi;

            }
        }

    }
    int test = 0;
}
