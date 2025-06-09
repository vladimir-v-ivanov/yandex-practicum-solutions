#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

using namespace std;

int siftUp(vector<int>& heap, const int idx) {
    if (idx == 1) {
        return idx;
    }

    const int parentIdx = idx / 2;
    if (heap[parentIdx] < heap[idx]) {
        swap(heap[parentIdx], heap[idx]);
        return siftUp(heap, parentIdx);
    }

    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    vector sample = {-1, 12, 6, 8, 3, 15, 7};
    assert(siftUp(sample, 5) == 1);
}


int main() {
    test();
}
#endif
