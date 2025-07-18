#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int str_to_int(string str) {
    const size_t len = str.length();

    if (const size_t pos = str.find('.'); pos != string::npos) {
        str.insert(len, 2 - (len - pos - 1), '0');
        str.erase(pos, 1);
    }
    else {
        str.insert(len, 2, '0');
    }

    return atoi(str.c_str());
}

int main() {
    int classes_num;
    cin >> classes_num;

    vector<pair<string, string>> schedule;
    schedule.reserve(classes_num);

    for (int i = 0; i < classes_num; i++) {
        string start, end;
        cin >> start >> end;

        schedule.emplace_back(start, end);
    }

    ranges::sort(schedule, [](const auto& a, const auto& b) {
        return a.second == b.second ? str_to_int(a.first) < str_to_int(b.first) : str_to_int(a.second) < str_to_int(b.second);
    });

    int                          last_end = -1;
    int                          total    = 0;
    vector<pair<string, string>> result;

    for (const auto& [start, end] : schedule) {
        if (last_end <= str_to_int(start)) {
            total++;
            result.emplace_back(start, end);
            last_end = str_to_int(end);
        }
    }

    cout << total << endl;

    for (const auto& [start, end] : result) {
        cout << start << " " << end << endl;
    }
}
