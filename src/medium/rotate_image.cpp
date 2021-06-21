//
// Created by shyamnath on 5/12/21.
//
#include <iostream>
#include <vector>

void rotate( std::vector<std::vector<int>>& matrix)
{
 //find transpose
for(int i=0; i<matrix.size(); ++i)
{
 for(int j=i; j<matrix.size();++j)
 {
     auto tmp = matrix[i][j];
     matrix[i][j] = matrix[j][i];
     matrix[j][i] = tmp;
 }
}

for(auto& rows: matrix)
{
    std::reverse(rows.begin(), rows.end());
}
}

int main()
{
    std::vector<std::vector<int>> matrix = {{5,1,9,11}, {2,4,8,10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix);
    int test = 0;
}