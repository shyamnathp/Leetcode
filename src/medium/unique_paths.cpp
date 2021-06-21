//
// Created by shyamnath on 5/15/21.
//
#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> directions= {{1,0}, {0,1}};

void dfs(int m, int n, int i, int j, int& count)
{
    if(i == (m-1) and j == (n-1)) {
        ++count;
        return;
    }

    //visited[i][j] = true;

    for(const auto& [row_add, column_add]: directions)
    {
        auto new_row = i + row_add;
        auto new_column = j + column_add;
        if((new_row>=0 and new_row<m))
            if((new_column>=0) and (new_column<n))
//              if (!visited[new_row][new_column])
                dfs(m, n, new_row, new_column, count);
    }

}


int main()
{
int m=23, n=12;
int count = 0;
//std::vector<std::vector<bool>> visited(m , std::vector<bool>(n, false));

dfs(m, n, 0, 0, count);
int test = 0;
}