/*
-- ПРИНЦИП РАБОТЫ --
Хеш таблица представляет собой класс с массивом корзин. Размер массива корзин равен количеству входных данных, то есть количеству команд.
Возможно это не самый оптимальный способ, но за что еще можно зацепиться, так чтобы в процессе не изменять размер хеш таблицы, я не нашел.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Временная сложность в среднем должна быть O(1), так как используется достаточно эффективный способ вычисления размера корзины,
по ближайшему простому числу от требуемого размера. Соответственно теоретически должно быть минимальное число коллизий.
В худшем случае возможна сложность O(N), так как используется метод цепочек для коллизий, и в этом случае используется цикл
по всем элементам корзины.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Пространственная сложность равна размеру входных данных O(n), так как дополнительные массивы для временного хранения
не используются.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Даже не знаю что тут написать, логика получилась довольно простая, какого то сложного алгоритма тут нет.

Отчет: https://contest.yandex.ru/contest/24414/run-report/133563114/
*/

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <cmath>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Salary {
    int key;
    int value;
    Salary* next;
};

class HashMap {
    vector<Salary*> buckets;

public:
    explicit HashMap(const int size) {
        buckets.resize(nextPrime(size), nullptr);
    }

    void put(const int key, const int value) {
        if (const int bucketNumber = getBucketNumber(key); buckets[bucketNumber] == nullptr) {
            buckets[bucketNumber] = new Salary{key, value, nullptr};
        }
        else {
            Salary* current = buckets[bucketNumber];
            Salary* previous = nullptr;

            do {
                if (current->key == key) {
                    current->value = value;

                    return;
                }

                previous = current;
                current = current->next;
            }
            while (current != nullptr);

            previous->next = new Salary{key, value, nullptr};
        }
    }

    [[nodiscard]] optional<int> get(const int key) const {
        const int bucketNumber = getBucketNumber(key);

        if (buckets[bucketNumber] == nullptr) {
            return nullopt;
        }

        Salary* current = buckets[bucketNumber];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }

            current = current->next;
        }

        return nullopt;
    }

    optional<int> remove(const int key) {
        const int bucketNumber = getBucketNumber(key);

        if (buckets[bucketNumber] == nullptr) {
            return nullopt;
        }

        Salary* current = buckets[bucketNumber];
        Salary* previous = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                const int value = current->value;

                if (previous == nullptr) {
                    buckets[bucketNumber] = current->next;
                }
                else {
                    previous->next = current->next;
                }

                delete current;
                return value;
            }

            previous = current;

            current = current->next;
        }

        return nullopt;
    }

    int getBucketNumber(const int key) const {
        return abs(key) % buckets.size();
    }

private:
    // Функции для поиска ближайшего простого числа я нашел в интернете, так как вычисление самого числа
    // не является сутью задачи
    static bool isPrime(const int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;

        for (int i = 3; i <= sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }

        return true;
    }

    static int nextPrime(const int num) {
        int next = num + 1;

        while (!isPrime(next)) {
            next++;
        }

        return next;
    }
};

#ifndef REMOTE_JUDGE
int main() {
    string line, word;
    getline(cin, line);
    const int num = stoi(line);
    HashMap hashMap(num);

    for (int i = 0; i < num; i++) {
        getline(cin, line);
        stringstream ss(line);
        int key, value;

        ss >> word;
        ss >> key;

        if (word == "get") {
            if (optional<int> val = hashMap.get(key); val == nullopt) {
                cout << "None" << endl;
            }
            else {
                cout << *val << endl;
            }
        }

        if (word == "put") {
            ss >> value;

            hashMap.put(key, value);
        }

        if (word == "delete") {
            if (optional<int> val = hashMap.remove(key); val == nullopt) {
                cout << "None" << endl;
            }
            else {
                cout << *val << endl;
            }
        }
    }
}
