#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>

struct DoubleNode {
    int value;
    DoubleNode* prev;
    DoubleNode* next;

    DoubleNode(int val) {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoubleNode* head;
    DoubleNode* tail;
    int size;  // Dodany licznik rozmiaru

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoublyLinkedList() {
        DoubleNode* current = head;
        while (current != nullptr) {
            DoubleNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void addAtBeginning(int value) {
        DoubleNode* newNode = new DoubleNode(value);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }

    void addAtEnd(int value) {
        DoubleNode* newNode = new DoubleNode(value);
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int value) {
        if (index <= 0) {
            addAtBeginning(value);
            return;
        }

        if (index >= size) {
            addAtEnd(value);
            return;
        }

        DoubleNode* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current != nullptr) {
            DoubleNode* newNode = new DoubleNode(value);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr)
                current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
    }

    void removeFromBeginning() {
        if (head == nullptr) return;

        DoubleNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    void removeFromEnd() {
        if (tail == nullptr) return;

        DoubleNode* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
        size--;
    }

    void removeAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            removeFromBeginning();
            return;
        }

        DoubleNode* current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) return;

        if (current->prev != nullptr)
            current->prev->next = current->next;

        if (current->next != nullptr)
            current->next->prev = current->prev;

        if (current == head)
            head = current->next;

        if (current == tail)
            tail = current->prev;

        delete current;
        size--;
    }

    int search(int value) {
        DoubleNode* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    int getSize() const {
        return size;
    }

    void print() {
        std::cout << "Zawartosc listy dwukierunkowej: ";
        DoubleNode* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif