#include <iostream>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

class MaxHeap {
public:
    vector<int> vals;
    int size;

    MaxHeap() : size(0) {}

    // Add an element to the heap
    void add(int x) {
        vals.push_back(x);
        size++;
        bottom_up_heapify(size - 1);
    }

    // Return the maximum element (root of the heap)
    int max_ele() {
        if (size > 0)
            return vals[0];
        else
            return INT_MIN;
    }

    // Delete and return the maximum element
    int del_max() {
        if (size == 0) return INT_MIN;

        int maxVal = vals[0];
        vals[0] = vals[size - 1];
        vals.pop_back();
        size--;
        top_down_heapify(0);

        return maxVal;
    }

    // Change the value of an element at a given index
    void ChangeKey(int x, int ind) {
        if (ind < 0 || ind >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        if (x == vals[ind]) return;

        if (x < vals[ind]) {
            vals[ind] = x;
            top_down_heapify(ind);
        } else {
            vals[ind] = x;
            bottom_up_heapify(ind);
        }
    }

private:
    // Maintain heap property from bottom to top
    void bottom_up_heapify(int ind) {
        int parent = (ind - 1) / 2;
        while (ind > 0 && vals[parent] < vals[ind]) {
            swap(vals[parent], vals[ind]);
            ind = parent;
            parent = (ind - 1) / 2;
        }
    }

    // Maintain heap property from top to bottom
    void top_down_heapify(int ind) {
        while (2 * ind + 1 < size) {
            int c1 = 2 * ind + 1;
            int c2 = 2 * ind + 2;
            int largest = c1;

            if (c2 < size && vals[c2] > vals[c1]) {
                largest = c2;
            }

            if (vals[ind] >= vals[largest]) {
                break;
            }

            swap(vals[ind], vals[largest]);
            ind = largest;
        }
    }
};

int main() {
    MaxHeap heap;

    // Add elements to the heap
    heap.add(10);
    heap.add(5);
    heap.add(20);
    heap.add(2);

    cout << "Initial heap: ";
    for (int val : heap.vals) cout << val << " ";
    cout << endl;

    // Test max_ele
    cout << "Max element: " << heap.max_ele() << endl;

    // Test del_max
    cout << "Deleted max: " << heap.del_max() << endl;
    cout << "Heap after deleting max: ";
    for (int val : heap.vals) cout << val << " ";
    cout << endl;

    // Test ChangeKey: Increase a value
    cout << "Changing key at index 2 to 25 (greater):" << endl;
    heap.ChangeKey(25, 2);
    cout << "Heap after increasing key: ";
    for (int val : heap.vals) cout << val << " ";
    cout << endl;

    // Test ChangeKey: Decrease a value
    cout << "Changing key at index 1 to 1 (smaller):" << endl;
    heap.ChangeKey(1, 1);
    cout << "Heap after decreasing key: ";
    for (int val : heap.vals) cout << val << " ";
    cout << endl;

    return 0;
}
