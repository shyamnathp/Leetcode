//
// Created by shyamnath on 5/15/21.
//
#include <vector>

int main()
{
    std::vector<std::vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    int m = board.size(), n = board[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int count = 0;
            for(int I=std::max(0, i-1); I<std::min(m, i+2); ++I)
            {
                for(int J=std::max(0, i-1); J<std::min(m, i+2); ++J)
                {
                    count += board[I][J];
                }
            }
            if((count == 3) or (count - board[i][j] == 3))
                board[i][j] |= 2;
        }
    }

    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;

}