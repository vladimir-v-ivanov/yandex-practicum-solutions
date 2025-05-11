// Задача A спринта 2. Мониторинг

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>& solution(const int rows, const int cols, vector<vector<int>>& matrix) {
    for (int i = 0; i < max(rows, cols); i++) {
        for (int j = i + 1; j < max(rows, cols); j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    return matrix;
}

void print(const int rows, const int cols, vector<vector<int>>& matrix) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << "\n";
    }
}

int main() {
    string line;

    getline(cin, line);
    const int rows = stoi(line);
    getline(cin, line);
    const int cols = stoi(line);

    vector matrix(max(rows, cols), vector(max(rows, cols), 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    print(rows, cols, solution(rows, cols, matrix));
}
