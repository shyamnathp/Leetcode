//
// Created by shyamnath on 5/29/21.
//
#include <vector>
#include <algorithm>
#include <map>

int main()
{
   std::vector<std::vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
   std::vector<std::pair<int, int>> zeroPositions;

   int rowSize = matrix.size();
    int columnSize;
   if(!matrix.empty())
       columnSize = matrix[0].size();

   for(int i=0; i<matrix.size(); ++i)
   {
       std::vector<int>::iterator first = matrix[i].begin();
       while (first <= matrix[i].end())
       {
           auto pos = std::find(first, matrix[i].end(), 0);
           if (pos != matrix[i].end())
           {
               int j = std::distance(matrix[i].begin(), pos);
               zeroPositions.emplace_back(std::make_pair(i, j));
           }
           first = pos+1;
       }
   }

   for(const auto& [i, j]: zeroPositions)
   {
       matrix[i] = std::move(std::vector<int>(columnSize, 0));

       for(int k =0; k<matrix.size();++k)
           matrix[k][j] = 0;
   }

   int test =1;
}