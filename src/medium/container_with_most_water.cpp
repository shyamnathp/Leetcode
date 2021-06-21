//
// Created by shyamnath on 5/6/21.
//
#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    int i = 0;
    int j = height.size()-1;
    int max_area = 0;
    while(i<j)
    {
        int area = std::min(height[i], height[j]) * (j-i);
        max_area = std::max(max_area, area);
        if(height[i] < height[j])
            ++i;
        else
            --j;
    }
    std::cout<<max_area;
}

