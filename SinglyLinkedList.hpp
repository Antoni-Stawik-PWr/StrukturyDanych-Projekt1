#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;  // Dodany licznik rozmiaru

public:
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void addAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }

    void addAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
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

        Node* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current != nullptr) {
            Node* newNode = new Node(value);
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void removeFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr) tail = nullptr;
    }

    void removeFromEnd() {
        if (head == nullptr) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
    }

    void removeAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            removeFromBeginning();
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1 && current->next != nullptr; i++) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail) tail = current;
        delete temp;
        size--;
    }

    int search(int value) {
        Node* current = head;
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
        Node* current = head;
        std::cout << "Lista: ";
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif