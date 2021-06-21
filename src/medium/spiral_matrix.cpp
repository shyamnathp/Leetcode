//
// Created by shyamnath on 6/3/21.
//
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> matrix =//{{1,2},{3,4}};
            {{1, 1, 1, 1, 1, 1, 1},
    {1, 2, 2, 2, 2, 2, 1},
    {1, 2, 3, 3, 3, 2, 1},
    {1, 2, 2, 2, 2, 2, 1},
    {1, 1, 1, 1, 1, 1, 1}};

    int rowSize = matrix.size();
    int columnSize = matrix[0].size();
    std::vector<int> results;

    int rowRight = rowSize-1, rowLeft=0, columnLeft = 0, columnRight = columnSize-1;
    while(rowLeft<=rowRight and columnLeft<=columnRight)
    {
        int row = rowLeft;
        int column = columnLeft;

        //forward iteration
        while(column<=columnRight)
        {
            results.emplace_back(matrix[row][column]);
            ++column;
        }

        rowLeft = rowLeft+1;
        --column;
        ++row;

        while (row<=rowRight)
        {
            results.emplace_back(matrix[row][column]);
            ++row;
        }

        columnRight=columnRight-1;
        --row;
        --column;

        //reverse iteration
        while (column >= columnLeft) {
            results.emplace_back(matrix[row][column]);
            --column;
        }

        rowRight = rowRight-1;
        ++column;
        --row;


        while (row>rowLeft)
        {
            results.emplace_back(matrix[row][column]);
            --row;
        }

        columnLeft = columnLeft + 1;

    }

    int test = 1;

}

