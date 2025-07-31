#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string main;
    getline(cin, main);

    int num;
    cin >> num;

    unordered_map<int, string> map;

    for (int i = 0; i < num; i++) {
        string str;
        int key;
        cin >> str >> key;

        map.insert(make_pair(key, str));
    }

    int i;

    for (i = 0; i < main.length(); i++) {
        if (map.contains(i)) {
            cout << map[i];
        }

        cout << main[i];
    }

    if (map.contains(i)) {
        cout << map[i];
    }

    cout << endl;
}
