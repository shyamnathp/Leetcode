//
// Created by shyamnath on 5/31/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::vector<int>> intervals = {{1,8},{4,6},{8,10},{15,18}};
    std::vector<std::vector<int>> mergedintervals;

    std::sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2){
        return interval1[0] < interval2[0];
    });

    auto first = intervals[0][0];
    auto end = intervals[0][1];

    for(int i=1; i<intervals.size();++i)
    {
        if (end >= intervals[i][0])
        {
            if(end < intervals[i][1])
                end = intervals[i][1];
        }
        else
        {
            mergedintervals.emplace_back(std::vector<int>({first, end}));
            first = intervals[i][0];
            end = intervals[i][1];
        }
    }

    mergedintervals.emplace_back(std::vector<int>({first, end}));

    int test = 1;
}

