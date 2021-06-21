//
// Created by shyamnath on 5/28/21.
//
#include <iostream>
#include <string>
#include <vector>

int lcs(const std::string& X, const std::string& Y)
{
    int x=X.size();
    int y=Y.size();
    std::vector<std::vector<int>> dp(y+1, std::vector<int>(x+1, 0));

    int largest =0;
    for(int row=1; row<y+1; ++row)
    {
        for(int column=1; column<x+1; ++column)
        {
            if(X[column-1] == Y[row-1])
                dp[row][column] = dp[row-1][column-1] + 1;
            else
                dp[row][column] = std::max(dp[row-1][column], dp[row][column-1]);

            if (dp[row][column]>largest)
                largest = dp[row][column];
        }
    }

    return largest;
}

#include <vector>


int main()
{
    std::string X = "GBCDE";
    std::string Y = "KBCDF";
    int largest = lcs(X, Y);
    std::cout<<largest;
}