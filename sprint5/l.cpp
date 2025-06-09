#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif


int siftDown(std::vector<int>& heap, const int idx) {
    const int left_idx = idx * 2;
    const int right_idx = idx * 2 + 1;

    if (left_idx >= heap.size()) {
        return idx;
    }

    int largest = left_idx;

    if (right_idx < heap.size() && heap[right_idx] > heap[left_idx]) {
        largest = right_idx;
    }

    if (heap[largest] > heap[idx]) {
        std::swap(heap[largest], heap[idx]);
        return siftDown(heap, largest);
    }

    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = {-1, 12, 1, 8, 3, 4, 7};
    const int idx = siftDown(sample, 2);
    assert(idx == 5);
}


int main() {
    test();
}
#endif
