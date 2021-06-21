//
// Created by shyamnath on 5/28/21.
//
#include <vector>

int ifSubsetSum(int sum, const std::vector<int>& values, int ourSum, int i)
{
    if (sum ==ourSum)
        return true;

    if (i==(values.size()-1))
        return false;

    ifSubsetSum(sum, values, ourSum + values[i], i+1) or ifSubsetSum(sum, values, ourSum, i+1);
}

bool ifSubSetSum(int sum, const std::vector<int>& values, int i)
{
    if (sum == 0)
        return true;

    if (sum < 0 or i==(values.size()))
        return false;

    bool exists = ifSubSetSum(sum-values[i], values, i+1) || ifSubSetSum(sum, values, i+1);

    return exists;
}



int main()
{
    std::vector<int> values = {3, 34, 4, 12, 5, 2};
    int sum = 13;

    bool exists = ifSubSetSum(sum, values,0);
    int test = 1;
}