// Задача C спринта 1. Соседи

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> solution(
    const vector<vector<int>>& matrix,
    const int total_rows,
    const int total_cols,
    const int row,
    const int col
) {
    vector<int> result;

    for (int i = 0; i < 4; ++i) {
        constexpr int rows_pad[] = {0, 0, 1, -1};
        constexpr int cols_pad[] = {-1, 1, 0, 0};

        const int     curr_row       = row + rows_pad[i];
        const int     curr_col       = col + cols_pad[i];

        if (curr_row >= 0 && curr_row < total_rows && curr_col >= 0 && curr_col < total_cols) {
            result.push_back(matrix[curr_row][curr_col]);
        }
    }

    ranges::sort(result);

    return result;
}

void print(const vector<int>& result) {
    for (const int i : result) {
        cout << i << " ";
    }

    cout << endl;
}

int main() {
    string line;

    getline(cin, line);
    const int total_rows = stoi(line);

    getline(cin, line);
    const int total_cols = stoi(line);

    vector matrix(total_rows, vector(total_cols, 0));

    for (int i = 0; i < total_rows; ++i) {
        getline(cin, line);
        istringstream iss(line);

        for (int j = 0; j < total_cols; ++j) {
            iss >> matrix[i][j];
        }
    }

    getline(cin, line);
    const int row = stoi(line);

    getline(cin, line);
    const int col = stoi(line);

    print(solution(matrix, total_rows, total_cols, row, col));
}
