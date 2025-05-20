/*
-- ПРИНЦИП РАБОТЫ --
Во время сканирования строк алгоритм создает многомерный массив (хеш таблицу), в которой для каждого слова записывается
сколько раз оно встречается в каждом документе.
Структура следующая search_index[word][document_number] = count.

Далее при поиске создается массив релевантности, в котором в качестве ключа идет номер документа, а в качестве значения
число - оценка релевантности.
Число релевантности складывается из количества слов из документа, которые соответствуют словам из запроса.
Далее этот массив сортируется в соответствии с условиями задачи и выводится.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Временная сложность для всего алгоритма поиска в среднем случае будет O(n * m * k log k), где
m - количество документов
n - количество слов
k - количество слов подходящих под условия поиска в массиве result, а k log k это время сортировки массива в vector.

В худшем случае может еще произойти перераспределение хеш таблицы, что добавит еще O(n) дополнительно.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Пространственная сложность O (n * m + k), где
n - количество документов
m - количество слов
k - массив результатов, который в дальнейшем сортируется.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Алгоритм считаю корректным, так как в конечном итоге релевантность документа строке поиска рассчитывается точно по
количеству слов из запроса совпадающих с документом.
Каждое слово добавляет релевантности столько баллов сколько раз оно встречается в документе, таким образом общая сумма
равна не только количеству самих совпадающих слов, но так же числу раз сколько оно встретилось в документе.

Отчет: https://contest.yandex.ru/contest/24414/run-report/138219239/
*/

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, unordered_map<int, int>> search_index;

#ifndef REMOTE_JUDGE
int main() {
    string line, word;
    getline(cin, line);
    int num = stoi(line);

    for (int i = 0; i < num; i++) {
        getline(cin, line);
        istringstream iss(line);

        while (iss >> word) {
            if (!search_index.contains(word)) {
                search_index[word][i] = 0;
            }

            search_index[word][i]++;
        }
    }

    getline(cin, line);
    num = stoi(line);

    for (int i = 0; i < num; i++) {
        getline(cin, line);
        istringstream iss(line);
        unordered_map<string, bool> used_words;
        unordered_map<int, int> result;

        while (iss >> word) {
            if (!search_index.contains(word) || used_words.contains(word)) {
                continue;
            }

            for (const auto& [first, second] : search_index[word]) {
                if (!result.contains(first)) {
                    result[first] = 0;
                }

                result[first] += second;
            }

            used_words[word] = true;
        }

        vector<pair<int, int>> result_sorted(result.begin(), result.end());
        ranges::partial_sort(result_sorted.begin(), result_sorted.begin() + min(5, static_cast<int>(result_sorted.size())), result_sorted.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second || (a.second == b.second && a.first < b.first);
            });

        for (int f = 0; f < 5 && f < result_sorted.size(); f++) {
            cout << result_sorted[f].first + 1 << " ";
        }

        cout << "\n";
    }
}
#endif
