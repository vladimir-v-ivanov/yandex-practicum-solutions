#include <iostream>

using namespace std;

int solution(const int height) {
    if (height <= 0) {
        return 1;
    }

    int result = 0;

    for (int i = 0; i < height; i++) {
        result += solution(i) * solution(height - i - 1);
    }

    return result;
}

int main() {
    int height;
    cin >> height;

    cout << solution(height) << endl;
}
