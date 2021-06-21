//
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//
//You must write an algorithm that runs in O(n) time and without using the division operation.
//
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

std::vector<int> products(const std::vector<int>& numbers)
{
    int product = 1;
    std::for_each(numbers.begin(), numbers.end(), [&product](const auto& number){product *= number;});
    std::vector<int> answer(numbers.size(), 0);

    if (product==0)
    {
        int prod = 1;
        int position = 0;
        int numberOfZeros = 0;
        for(int i=0; i<numbers.size(); ++i)
        {
            if(numbers[i] !=0) {
                prod *= numbers[i];
            }
            else {
                position = i;
                numberOfZeros += 1;

                if (numberOfZeros>1) {
                    break;
                }
            }
        }
        if (numberOfZeros != 2)
            answer[position] = prod;
        return answer;
    }

    std::transform(numbers.begin(), numbers.end(), answer.begin(),[product](const auto& number){return product/number;});
    return answer;
}

int main()
{
    std::vector<int> nums = {0, 0};
    auto answer = products(nums);
    int test = 1;
}