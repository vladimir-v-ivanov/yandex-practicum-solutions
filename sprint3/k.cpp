#include <vector>

using namespace std;

using Iterator  = vector<int>::iterator;
using CIterator = vector<int>::const_iterator;

vector<int> merge(
    CIterator left_begin, CIterator  left_end,
    CIterator right_begin, CIterator right_end) {
    vector<int> result;

    while (left_begin != left_end && right_begin != right_end) {
        if (*left_begin <= *right_begin) {
            result.push_back(*left_begin);
            ++left_begin;
        }
        else {
            result.push_back(*right_begin);
            ++right_begin;
        }
    }

    result.insert(result.end(), left_begin, left_end);
    result.insert(result.end(), right_begin, right_end);

    return result;
}

void merge_sort(Iterator begin, Iterator end) {
    if (end - begin <= 1) {
        return;
    }

    const auto mid = begin + (end - begin) / 2;

    merge_sort(begin, mid);
    merge_sort(mid, end);

    vector<int> merged = merge(begin, mid, mid, end);
    copy(merged.begin(), merged.end(), begin);
}
