/*
Отчет: https://contest.yandex.ru/contest/25070/run-report/139444675/

Принцип работы:
    Этот замечательный алгоритм реализует поиск всех связанных компонент в матрице, где смежными считаются клетки с символом #,
    соединённые по вертикали и горизонтали. Для поиска компонент используется обход графа в ширину (BFS).

    Изначально вся матрица считывается в двумерный массив, где каждая # считается вершиной графа.

    Основной цикл программы перебирает все клетки матрицы. Если встречается непосещённая вершина - #,
    то запускается алгоритм BFS от этой вершины. BFS обходит все смежные клетки, и помечает их как посещённые.
    Таким образом, каждая компонента посещается ровно один раз.
    Также во время обхода подсчитывается размер текущей компоненты и обновляется максимум.

Вычислительная сложность:
    Общая вычислительная сложность (V + E).
    - Основной двойной цикл проходит по всей матрице размера V, где V это обшее количество вершин матрицы n × m.
    - Каждая вершина участвует в BFS ровно один раз.
    - Обход BFS занимает O(V + E) где E это количество смежных вершин и E количество ребер.

    Итого общая сложность получается O(2V + E) = O(V + E).

Пространственная сложность:
Общая пространственная сложность O(V):
- Для хранения информации о посещённых клетках используется булев массив visited размером n × m = O(V).
- Для BFS используется очередь, в которой в худшем случае может одновременно находиться до O(V) элементов.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<bool>> matrix;
vector<vector<bool>> visited;
int                  max_size = 0;

int bfs(int i, int j, const int n, const int m) {
    int                   size = 0;
    queue<pair<int, int>> q;
    q.emplace(i, j);

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if (!visited[p.first][p.second]) {
            visited[p.first][p.second] = true;
            size += 1;
            q.push(p);

            // Проверяем исходящие вершины, слева, сверху, справа, снизу
            for (int k = 0; k < 4; k++) {
                constexpr int dy[4] = {0, 0, -1, 1};
                constexpr int dx[4] = {-1, 1, 0, 0};
                i                   = p.first + dx[k];
                j                   = p.second + dy[k];

                if (i >= 0 && i < n && j >= 0 && j < m && matrix[i][j] && !visited[i][j]) {
                    q.emplace(i, j);
                }
            }
        }
    }

    return size;
}

int main() {
    int n, m;
    cin >> n >> m;
    matrix.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
        visited[i].resize(m);

        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            matrix[i][j] = c == '#';
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] && !visited[i][j]) {
                if (int size = bfs(i, j, n, m)) {
                    count++;
                    max_size = max(max_size, size);
                }
            }
        }
    }

    cout << count << " " << max_size << endl;
}
