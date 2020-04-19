#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    const int SIZE = 9;
    int list[] = {1, 7, 3, 4, 9, 11, 3, 1, 2};
    Heap<int> heap(list,SIZE);

    heap.heapSort();
    cout << "Sorted elements using heap:\n";
    heap.printList();

    return 0;
}
