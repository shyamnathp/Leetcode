//
// Created by shyamnath on 5/2/21.
//
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums1 = {1}; int m =1;
    std::vector<int> nums2 = {}; int n = 0;

    std::copy(nums2.begin(), nums2.begin()+n, nums1.begin()+m);
    std::inplace_merge(nums1.begin(), nums1.begin()+m, nums1.end());
    auto test = 0;

}
