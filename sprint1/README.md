# Sprint 1 — Basic Algorithms and Math

This sprint introduces fundamental algorithmic tasks: arithmetic, conditions, loops, arrays, and strings.  
Each task has a separate `.cpp` file with solution and complexity analysis.

## Task list

| Task    | File                                                       | Description                                  | Complexity              |
|---------|------------------------------------------------------------|----------------------------------------------|-------------------------|
| A       | [A_func_value.cpp](./A_func_value.cpp)                     | Compute value of function `ax^2 + bx + c`    | O(1) time, O(1) space   |
| B       | [B_odd_even.cpp](./B_odd_even.cpp)                         | Check if a number is odd or even             | O(1) time, O(1) space   |
| C       | [C_neighbors.cpp](./C_neighbors.cpp)                       | Find neighbors in an array                   | O(n) time, O(1) space   |
| D       | [D_weather_randomness.cpp](./D_weather_randomness.cpp)     | Count number of random temperature anomalies | O(n) time, O(1) space   |
| E       | [E_longest_word.cpp](./E_longest_word.cpp)                 | Count number of random temperature anomalies | O(n) time, O(1) space   |
| ...     | ...                                                        | ...                                          | ...                     |
| Final A | [final_01_nearest_zero.cpp](./final_01_nearest_zero.cpp)   | Find nearest zero in array                   | O(n) time, O(n) space   |
| Final B | [final_02_sleight_hands.cpp](./final_02_sleight_hands.cpp) | Max points in "Sleight of Hands" game        | O(n^2) time, O(1) space |

## How to build

```bash
mkdir build && cd build
cmake ..
make
./sprint1/A_func_value < input.txt
