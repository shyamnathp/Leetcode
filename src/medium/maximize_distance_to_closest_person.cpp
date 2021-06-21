//
// Created by shyamnath on 5/30/21.
//
#include <iostream>
#include <vector>

int findMax(const std::vector<int>& seats)
{   int largest = INT32_MIN;

    std::vector<int> left(seats.size(), seats.size());
    std::vector<int> right(seats.size(), seats.size());
    for(int i=0; i<seats.size(); ++i)
    {
        if(seats[i] == 1) {
            left[i] = 0;
        }
        else if(i>0)
        {
            left[i] = left[i-1] + 1;
        }
    }

    for(int j=seats.size()-1; j>=0; --j)
    {
        if(seats[j] == 1) {
            right[j] = 0;
        }
        else if (j<seats.size()-1)
        {
            right[j] = right[j+1]+1;
        }
    }

    int maxDistance;
    maxDistance = std::min(left[0], right[0]);
    for(int i=1; i<seats.size(); ++i)
    {
        int tempMin = std::min(left[i], right[i]);
        if (tempMin > maxDistance)
        {
            maxDistance = tempMin;
        }
    }

    return maxDistance;

}


int main()
{
    std::vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
    int maxDistance = findMax(seats);
    int test = 1;
}
