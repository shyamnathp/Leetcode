//
// Created by shyamnath on 5/29/21.
//
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums = {2,0,2,1,1,0};

    std::vector<int>::iterator first = nums.begin();
    for(const auto& i: {0, 1, 2})
    {
        std::partition(first, nums.end(), [&i](const auto& num){return num == i;});
        first = std::upper_bound(first, nums.end(), i);
    }

    int test = 1;

}

