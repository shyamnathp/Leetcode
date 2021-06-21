//
// Created by shyamnath on 5/29/21.
//
#include <iostream>
#include <vector>

int search(const std::vector<int>& nums, int target, int left, int right, int& foundLocation) {

    static int topsize=nums.size()+1;

    if(left>=right)
        return topsize;
    else if (left == right)
    {
        if (nums[left] == target)
            foundLocation=left;
    }

    auto mid = (left + right + 1)/2;

    if (nums[left] == target)
        foundLocation=left;
    else if (nums[right] == target)
        foundLocation=right;

    if (right-left == 1)
    {
        if(nums[right] < nums[left])
            return right;
        else
            return topsize;
    }

    int leftMismatch = search(nums, target, left, mid, foundLocation);
    int rightMismatch = search(nums, target, mid, right, foundLocation);

    if (leftMismatch==topsize && rightMismatch==topsize)
        return topsize;
    else if (leftMismatch==topsize)
        return rightMismatch;
    else
        return leftMismatch;

}

int main()
{
    std::vector<int> nums = {4,5,0,1,2,3};
    int target =2;
    int foundLocation = nums.size()+1;

    int match = search(nums, target, 0, nums.size()-1, foundLocation);
    int test = 1;
}
