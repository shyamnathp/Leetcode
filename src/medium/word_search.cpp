//
// Created by shyamnath on 5/15/21.
//
#include <iostream>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<char>>& board, std::string_view word, std::vector<std::vector<bool>>& visited, int row, int column, int index)
{
    bool result = false;
    char c;

    if (c = board[row][column], word[index] != c)
        return false;

    if(index = word.size() - 1 )
        return true;

    board[row][column] = '*';

    if((row<board.size()-1))
        result = dfs(board, word, visited, row+1, column, index + 1);
    if(!result && row>0)
        result = dfs(board, word, visited, row-1, column, index + 1);
    if (!result && (column<board[0].size()-1))
        result = dfs(board, word, visited, row, column+1, index + 1);
    if (!result && (column>0))
        result = dfs(board, word, visited, row, column-1, index + 1);

    board[row][column] = c;

    return result;

}

int main() {
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::string word = "ABCCED";
    std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
    int start_row = 0, start_column = 0, index = 0;
    int M,N,i,j,sLen = word.size();
    if( (M=board.size()) && (N=board[0].size()) && sLen)
    {
        for(i=0; i<M; ++i)
            for(j=0; j<N; ++j)
                if(dfs(board, word, visited, start_row, start_column, index)) return true;
    }

    return false;

}
