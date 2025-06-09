/*

Отчет: https://contest.yandex.ru/contest/24810/run-report/139109059/

Пространственная сложность
    В данном конкретном сценарии пространственная сложность считаю что O(1), так как по условию задачи нужно просто
    вывести значения в отсортированном порядке.
    Если бы требовалось хранить массив с отсортированными значениями, тогда сложность была бы O(n).

Вычислительная сложность:
    Вычислительная сложность в худшем случае O(n log n) потому что для всего набора данных, длина которого n, мы
    проделываем просеивание вверх при вставке и в просеивании вниз при удалении, каждая из которых выполняется за O(log n).

Алгоритм считаю корректным, так как он полностью удовлетворяет условиям приоритетной очереди на основе кучи.
    - При вставке любого нового элемента в конец кучи (в самый низ дерева) выполняется операция просеивания вверх
      и перемещает новый вставленный элемент вверх по дереву на такую позицию, где он будет меньше родителя
      и больше потомков. Тем самым сохраняя приоритетность в куче.
    - При извлечении элементов в порядке приоритета первым извлекается самый верхний элемент (с самым большим приоритетом),
      а на его место переносится элемент из конца кучи - с одним из наименьших приоритетов.
      Далее выполняется просеивание этого элемента вниз, пока он не займет место, где будет меньше родителя и больше потомков,
      тем самым восстанавливая приоритетность всей кучи.
*/


#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

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

void sift_up(vector<tuple<string, int, int>>& heap, const int index) {
    if (index == 1) {
        return;
    }

    const int parent = index / 2;

    if (compare(heap[index], heap[parent])) {
        swap(heap[index], heap[parent]);
        sift_up(heap, parent);
    }
}

void sift_down(vector<tuple<string, int, int>>& students, const int index) {
    const int left_idx = index * 2;
    const int right_idx = index * 2 + 1;
    int child_idx = left_idx;

    if (left_idx >= students.size()) {
        return;
    }

    if (right_idx < students.size() && compare(students[right_idx], students[left_idx])) {
        child_idx = right_idx;
    }

    if (compare(students[child_idx], students[index])) {
        swap(students[child_idx], students[index]);
        sift_down(students, child_idx);
    }
}

void add_to_heap(vector<tuple<string, int, int>>& students, const tuple<string, int, int>& student) {
    students.push_back(student);
    sift_up(students, static_cast<int>(students.size()) - 1);
}

tuple<string, int, int> pop_from_heap(vector<tuple<string, int, int>>& students) {
    tuple<string, int, int> result = students[1];
    students[1] = students[students.size() - 1];
    students.pop_back();
    sift_down(students, 1);

    return result;
}

int main() {
    int len;
    vector<tuple<string, int, int>> students;
    std::cin >> len;
    students.resize(1);
    students.reserve(len + 1);

    for (int i = 0; i < len; i++) {
        string name;
        int num1, num2;

        cin >> name >> num1 >> num2;
        add_to_heap(students, make_tuple(name, num1, num2));
    }

    for (int i = 0; i < len; i++) {
        tuple<string, int, int> student = pop_from_heap(students);

        cout << get<0>(student) << "\n";
    }
}
