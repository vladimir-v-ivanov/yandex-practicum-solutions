// Финальная задача A спринта 3. Поиск в сломанном массиве

#include <vector>
#include "solution.h"

int broken_search(const std::vector<int>& vec, int k) {
    int i = 0;
    int j = static_cast<int>(vec.size()) - 1;

    while (i <= j) {
        const int mid = i + (j - i) / 2;

        if (vec[mid] == k) {
            return mid;
        }

        // После разбиения на две части, хотя бы одна из частей должна быть отсортирована
        // Проверяем, какая часть отсортирована и находится ли искомое значение в ней

        if (vec[i] <= vec[mid]) {
            if (k >= vec[i] && k <= vec[mid]) {
                j = mid - 1;
                continue;
            }

            i = mid + 1;
            continue;
        }

        if (k >= vec[mid] && k <= vec[i]) {
            i = mid + 1;
            continue;
        }

        j = mid - 1;
    }

    return -1;
}
