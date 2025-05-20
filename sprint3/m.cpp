#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Основная функция для поиска медианы двух отсортированных массивов
double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    // Гарантируем, что nums1 всегда меньше или равен nums2 (по размеру)
    const vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
    const vector<int>& B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

    int m = A.size(); // Длина меньшего массива
    int n = B.size(); // Длина большего массива

    int low = 0, high = m;

    while (low <= high) {
        // i и j —— индексы разделения массивов A и B
        int i = (low + high) / 2;
        int j = (m + n + 1) / 2 - i;

        // Левая и правая части раздела в A
        int Aleft = (i == 0) ? INT_MIN : A[i - 1];
        int Aright = (i == m) ? INT_MAX : A[i];

        // Левая и правая части раздела в B
        int Bleft = (j == 0) ? INT_MIN : B[j - 1];
        int Bright = (j == n) ? INT_MAX : B[j];

        // Если разделение корректно
        if (Aleft <= Bright && Bleft <= Aright) {
            if ((m + n) % 2 == 0) { // Если общее количество элементов четное
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else { // Если количество элементов нечетное
                return max(Aleft, Bleft);
            }
        } else if (Aleft > Bright) { // Сужаем поиск влево
            high = i - 1;
        } else { // Сужаем поиск вправо
            low = i + 1;
        }
    }

    throw runtime_error("Unable to find median due to invalid input.");
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n);
    vector<int> nums2(m);

    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> nums2[i];
    }

    double result = findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    return 0;
}
