//
// Created by Jaquan Jones on 4/17/20.
//

#ifndef HEAPSORT_HEAP_H
#define HEAPSORT_HEAP_H

#include <vector>
#include <iostream>

template<typename T>
class Heap {
public:
    Heap() = default;
    Heap(const T elements[], int arraySize);
    T &remove() noexcept(false) { return v[0]; }
    int getSize() const { return v.size(); }

    void add(const T &element); // not used in example output
    void heapSort();
    void printList();

    bool operator<(const Heap &rhs) const;
    bool operator>(const Heap &rhs) const;
    bool operator<=(const Heap &rhs) const;
    bool operator>=(const Heap &rhs) const;

private:
    std::vector<T> v;
    void reheapDown(int root, int bottom);
};

// functions
template<typename T>
void Heap<T>::printList() {
    for (int i = 0; i < getSize(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void Heap<T>::reheapDown(int root, int bottom) {
    int temp, lChild, rChild;
    while (root < bottom) {
        temp = root;
        lChild = (2 * root) + 1;
        rChild = (2 * root) + 2;

        if (lChild < bottom && v[lChild] >= v[root]) {
            root = lChild;
        }
        if (rChild < bottom && v[rChild] >= v[root]) {
            root = rChild;
        }

        if (root != temp) {
            std::swap(v[temp], v[root]);
        } else {
            break;
        }
    }
}


template<typename T>
void Heap<T>::add(const T &element) {
    v.push_back(element);
    reheapDown(0, getSize());
}

template<typename T>
void Heap<T>::heapSort() {
    int size = getSize();

    for (int i = (size / 2) - 1; i >= 0; i--) {
        reheapDown(i, size);
    }

    for (int j = size - 1; j >= 0; j--) {
        std::swap(remove(), v[j]);
        reheapDown(0, j);
    }
}

template<typename T>
Heap<T>::Heap(const T elements[], int arraySize) {
    for (int i = 0; i < arraySize; i++)
        v.push_back(elements[i]);
}


template<typename T>
bool Heap<T>::operator<(const Heap &rhs) const {
    return v < rhs.v;
}

template<typename T>
bool Heap<T>::operator>(const Heap &rhs) const {
    return rhs < *this;
}

template<typename T>
bool Heap<T>::operator<=(const Heap &rhs) const {
    return !(rhs < *this);
}

template<typename T>
bool Heap<T>::operator>=(const Heap &rhs) const {
    return !(*this < rhs);
}


#endif //HEAPSORT_HEAP_H
