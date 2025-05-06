#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int initialCapacity = 4){
        capacity = initialCapacity;
        data = new int[capacity];
        size = 0;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void addAtEnd(int value) {
        if (size == capacity) resize();
        data[size++] = value;
    }

    void addAtBeginning(int value) {
        if (size == capacity) resize();
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }

    void addAtIndex(int index, int value) {
        if (index < 0 || index > size) {
            std::cout << "Niepoprawny indeks!\n";
            return;
        }
        if (size == capacity) resize();
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void removeFromBeginning() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void removeFromEnd() {
        if (size > 0) size--;
    }

    void removeAtIndex(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Niepoprawny indeks!\n";
            return;
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) return i;
        }
        return -1;
    }

    void print() {
        std::cout << "Zawartosc tablicy: ";
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    int getSize() const {
        return size;
    }
};

#endif