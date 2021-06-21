//
// Created by shyamnath on 5/15/21.
//
#include <iostream>
#include <vector>
#include <string>

void countandsay(int index, int n, std::vector<std::string>& sequences)
{
    if(index == n)
        return;

    std::string previous = sequences[index-1];
    std::string next = "";
    for(int i=0; i<previous.size(); ++i)
    {
        int count = 1;
        while(previous[i]==previous[i+1])
        {
            ++count; ++i;
        }
        next += std::to_string(count);
        next += previous[i-1] + std::to_string(count);
    }
    sequences.emplace_back(next);
    countandsay(index+1, n, sequences);
}

int main()
{
int n = 5;
std::vector<std::string> sequences = {"1", "11", "12", "1211"};
countandsay(4, n, sequences);
int t =1;
}
