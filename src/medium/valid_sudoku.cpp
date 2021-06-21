//
// Created by shyamnath on 5/8/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef std::vector<std::vector<char>> sudoku;

inline std::map<char, bool> get_visited_map()
{
    return {{1, false},
            {2, false},
            {3, false},
            {4, false},
            {5, false},
            {6, false},
            {7, false},
            {8, false},
            {9, false}};
}


bool check_rows(const sudoku& board) {
    for (auto row: board)
    {
        std::sort(row.begin(), row.end(), std::greater<char>());
        auto it = std::adjacent_find(row.begin(), row.end());
        if (*it != '.')
            return false;
    }
    return true;
}

bool check_columns(const sudoku& board) {
    int columns = board[0].size();
    for(int i=0; i<columns; ++i)
    {
        auto visited = get_visited_map();
        for(const auto& rows: board)
        {
            int value = rows[i];
            if (value == '.')
                continue;

            if(not visited[value])
                visited[value] = true;
            else
                return false;
        }
    }
    return true;
}

bool check_sub_boxes(const sudoku& board) {
    std::vector<std::pair<int, int>> range_columns= {{0, 0}, {0, 3}, {0, 6},  {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
    for (auto [i,j]: range_columns)
    {
        auto visited = get_visited_map();
        for(int i1=i; i1<(i+3); ++i1)
        {
            for(int j1=j; j1<(j+3); ++j1)
            {
                int value = board[i1][j1];
                if (value == '.')
                    continue;

                if(not visited[value])
                    visited[value] = true;
                else
                    return false;
            }
        }
    }
    return true;
}

template <typename T>
bool check_validity(T&& board)
{
    bool a = check_rows(std::forward<T>(board));
    if(not a)
        return false;
    bool b = check_columns(std::forward<T>(board));
    if(not b)
        return false;
    bool c = check_sub_boxes(std::forward<T>(board));
    if(not c)
        return false;
    return true;
}


int main()
{
    sudoku board ={{'.','8','7','6','5','4','3','2','1'},{'2','.','.','.','.','.','.','.','.'},{'3','.','.','.','.','.','.','.','.'},{'4','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','.','.'},{'6','.','.','.','.','.','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'8','.','.','.','.','.','.','.','.'},{'9','.','.','.','.','.','.','.','.'}};

    if (check_validity(board))
        std::cout<<"True";
    else
        std::cout<<"False";

}