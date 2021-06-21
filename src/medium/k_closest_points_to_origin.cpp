//
// Created by shyamnath on 5/30/21.
//
//
// given a number n, find the number of ways in staircase from bottom to top with either 1 or 2 steps.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void findKClosestPoints(std::vector<std::vector<int>>& points, int k)
{
    std::partial_sort(points.begin(), points.begin() + k, points.end(), [](const auto& point1, const auto& point2){
        return (point1[0]*point1[0] + point1[1]*point1[1]) < (point2[0]*point2[0] + point2[1]*point2[1]);});
}


int main()
{
    std::vector<std::vector<int>> points = {{3,3},{5,-1},{-2,4}, {5, 15}};
    findKClosestPoints(points, 2);
}