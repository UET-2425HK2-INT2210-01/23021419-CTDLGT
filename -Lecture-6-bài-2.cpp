#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class MinHeap {
private:
    int heap[MAX_SIZE];
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int left, right, smallest;
        while (2 * index + 1 < size) {
            left = 2 * index + 1;
            right = 2 * index + 2;
            smallest = index;
            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else break;
        }
    }

    void printTree(int index, int space = 0, int gap = 5, string prefix = "") {
        if (index >= size) return;
        space += gap;

        printTree(2 * index + 2, space, gap, "/");

        cout << endl;
        for (int i = gap; i < space; i++) cout << " ";
        cout << prefix << heap[index] << "\n";

        printTree(2 * index + 1, space, gap, "\\");
    }

public:
    MinHeap() : size(0) {}

    void insert(int val) {
        if (size >= MAX_SIZE) {
            cout << "Heap đầy!\n";
            return;
        }
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    void remove(int val) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (heap[i] == val) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Không tìm thấy " << val << " trong Heap!\n";
            return;
        }
        heap[index] = heap[size - 1];
        size--;
        heapifyDown(index);
    }

    void printHeap() {
        if (size == 0) {
            cout << "Heap rỗng!\n";
            return;
        }
        printTree(0);
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int val : values) heap.insert(val);
    cout << "Min Heap after initial insertion:\n";
    heap.printHeap();

    heap.insert(14);
    heap.insert(0);
    heap.insert(35);
    cout << "\nMin Heap after inserting 14, 0, 35:\n";
    heap.printHeap();

    heap.remove(6);
    heap.remove(13);
    heap.remove(35);
    cout << "\nMin Heap after deleting 6, 13, 35:\n";
    heap.printHeap();

    return 0;
}
