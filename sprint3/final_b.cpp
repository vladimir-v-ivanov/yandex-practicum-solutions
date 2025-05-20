// Финальная задача B спринта 3. Эффективная быстрая сортировка

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <random>
#include <tuple>
#include <vector>

using namespace std;

int get_pivot(const int left, const int right) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(left, right);

    return dis(gen);
}

bool compare(const tuple<string, int, int>& first, const tuple<string, int, int>& second) {
    if (get<1>(first) > get<1>(second)) {
        return true;
    }

    if (get<1>(first) == get<1>(second) && get<2>(first) < get<2>(second)) {
        return true;
    }

    if (get<1>(first) == get<1>(second) && get<2>(first) == get<2>(second) && get<0>(first) < get<0>(second)) {
        return true;
    }

    return false;
}

void solution(vector<tuple<string, int, int>>& students, const int left, const int right) {
    const tuple<string, int, int> pivot = students[left + (right - left) / 2];
    int i = left;
    int j = right;

    while (i < j) {
        if (compare(students[i], pivot)) {
            i++;
            continue;
        }

        if (compare(pivot, students[j])) {
            j--;
            continue;
        }

        swap(students[i], students[j]);
        i++;
        j--;
    }

    if (right - left < 2) {
        return;
    }

    solution(students, left, i);
    solution(students, j, right);
}

void print(const vector<tuple<string, int, int>>& students) {
    for (const auto& student : students) {
        cout << get<0>(student) << "\n";
    }
}

int main() {
    int len;
    cin >> len;
    vector<tuple<string, int, int>> students;

    students.resize(len);

    for (int i = 0; i < len; i++) {
        string name;
        int num1, num2;

        cin >> name >> num1 >> num2;
        students[i] = make_tuple(name, num1, num2);
    }

    solution(students, 0, len - 1);
    print(students);
}
