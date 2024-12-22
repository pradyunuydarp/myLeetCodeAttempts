#include <iostream>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

class MinHeap {
public:
    vector<int> vals;
    int size;

    MinHeap() : size(0) {}

    void add(int x) {
        vals.push_back(x);
        size++;
        bottom_up_heapify(size - 1);
    }

    void bottom_up_heapify(int ind) {
        int parent = (ind - 1) / 2;
        while (ind > 0 && vals[parent] > vals[ind]) {
            swap(vals[parent], vals[ind]);
            ind = parent;
            parent = (ind - 1) / 2;
        }
    }

    int min_ele() {
        if (size > 0)
            return vals[0];
        else
            return INT_MIN;
    }

    int del_min() {
        if (size == 0) return INT_MAX;

        int ans = vals[0];
        vals[0] = vals[size - 1];
        vals.pop_back();
        size--;
        top_down_heapify(0);

        return ans;
    }

    void top_down_heapify(int ind) {
        while (2 * ind + 1 < size) {
            int c1 = 2 * ind + 1;
            int c2 = 2 * ind + 2;
            int smallest = c1;

            if (c2 < size && vals[c2] < vals[c1]) {
                smallest = c2;
            }

            if (vals[ind] <= vals[smallest]) {
                break;
            }

            swap(vals[ind], vals[smallest]);
            ind = smallest;
        }
    }
    void ChangeKey(int x, int ind) {
    if (ind < 0 || ind >= size) {
        cout << "Index out of bounds!" << endl;
        return;
    }
    if (x == vals[ind]) return;

    if (x > vals[ind]) {
        vals[ind] = x;
        top_down_heapify(ind);
    } else {
        vals[ind] = x;
        bottom_up_heapify(ind);
    }
}

};

int main() {
    MinHeap heap;

    heap.add(10);
    heap.add(5);
    heap.add(20);
    heap.add(2);

    cout << "Min element: " << heap.min_ele() << endl;

    cout << "Deleted min: " << heap.del_min() << endl;
    cout << "Min element after deletion: " << heap.min_ele() << endl;

     cout << "Initial heap: ";
    for (int val : heap.vals) cout << val << " ";
    cout << endl;

    // Test ChangeKey
    cout << "Changing key at index 2 to 1 (smaller):" << endl;
    heap.ChangeKey(1, 2); // Reduce the key at index 2 to 1

    cout << "Heap after reducing key: ";
    for (int val : heap.vals) cout << val << " ";
    cout << endl;

    cout << "Changing key at index 0 to 15 (greater):" << endl;
    heap.ChangeKey(15, 0); // Increase the key at index 0 to 15

    cout << "Heap after increasing key: ";
    for (int val : heap.vals) cout << val << " ";
    cout << endl;

    return 0;
}
