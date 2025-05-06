#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include "DynamicArray.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;
using namespace chrono;

int main() {
    ofstream addBeg("addAtBeginning.csv");
    ofstream addEnd("addAtEnd.csv");
    ofstream addIdx("addAtIndex.csv");
    ofstream remBeg("removeFromBeginning.csv");
    ofstream remEnd("removeFromEnd.csv");
    ofstream remIdx("removeAtIndex.csv");
    ofstream search("search.csv");

    addBeg << "n;Singly(ns);Doubly(ns);Array(ns)\n";
    addEnd << "n;Singly(ns);Doubly(ns);Array(ns)\n";
    addIdx << "n;Singly(ns);Doubly(ns);Array(ns)\n";
    remBeg << "n;Singly(ns);Doubly(ns);Array(ns)\n";
    remEnd << "n;Singly(ns);Doubly(ns);Array(ns)\n";
    remIdx << "n;Singly(ns);Doubly(ns);Array(ns)\n";
    search << "n;Singly(ns);Doubly(ns);Array(ns)\n";

    srand(time(NULL)); // losowoœæ

    for (int n = 10000; n <= 100000; n += 10000) {
        long long s, d, a;

        // ADD AT BEGINNING
        s = d = a = 0;
        for (int i = 0; i < 5; i++) {
            SinglyLinkedList sl;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) sl.addAtBeginning(j);
            auto end = high_resolution_clock::now();
            s += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DoublyLinkedList dl;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) dl.addAtBeginning(j);
            auto end = high_resolution_clock::now();
            d += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DynamicArray ar;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) ar.addAtBeginning(j);
            auto end = high_resolution_clock::now();
            a += duration_cast<nanoseconds>(end - start).count();
        }
        addBeg << n << ";" << s / 5 << ";" << d / 5 << ";" << a / 5 << "\n";

        // ADD AT END
        s = d = a = 0;
        for (int i = 0; i < 5; i++) {
            SinglyLinkedList sl;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) sl.addAtEnd(j);
            auto end = high_resolution_clock::now();
            s += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DoublyLinkedList dl;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) dl.addAtEnd(j);
            auto end = high_resolution_clock::now();
            d += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DynamicArray ar;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) ar.addAtEnd(j);
            auto end = high_resolution_clock::now();
            a += duration_cast<nanoseconds>(end - start).count();
        }
        addEnd << n << ";" << s / 5 << ";" << d / 5 << ";" << a / 5 << "\n";

        // ADD AT INDEX
        s = d = a = 0;
        for (int i = 0; i < 5; i++) {
            SinglyLinkedList sl;
            for (int j = 0; j < n; j++) sl.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) sl.addAtIndex(j / 2, j);
            auto end = high_resolution_clock::now();
            s += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DoublyLinkedList dl;
            for (int j = 0; j < n; j++) dl.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) dl.addAtIndex(j / 2, j);
            auto end = high_resolution_clock::now();
            d += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DynamicArray ar;
            for (int j = 0; j < n; j++) ar.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) ar.addAtIndex(j / 2, j);
            auto end = high_resolution_clock::now();
            a += duration_cast<nanoseconds>(end - start).count();
        }
        addIdx << n << ";" << s / 5 << ";" << d / 5 << ";" << a / 5 << "\n";

        // REMOVE FROM BEGINNING
        s = d = a = 0;
        for (int i = 0; i < 5; i++) {
            SinglyLinkedList sl;
            for (int j = 0; j < n; j++) sl.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) sl.removeFromBeginning();
            auto end = high_resolution_clock::now();
            s += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DoublyLinkedList dl;
            for (int j = 0; j < n; j++) dl.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) dl.removeFromBeginning();
            auto end = high_resolution_clock::now();
            d += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DynamicArray ar;
            for (int j = 0; j < n; j++) ar.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) ar.removeFromBeginning();
            auto end = high_resolution_clock::now();
            a += duration_cast<nanoseconds>(end - start).count();
        }
        remBeg << n << ";" << s / 5 << ";" << d / 5 << ";" << a / 5 << "\n";

        // REMOVE FROM END
        s = d = a = 0;
        for (int i = 0; i < 5; i++) {
            SinglyLinkedList sl;
            for (int j = 0; j < n; j++) sl.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) sl.removeFromEnd();
            auto end = high_resolution_clock::now();
            s += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DoublyLinkedList dl;
            for (int j = 0; j < n; j++) dl.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) dl.removeFromEnd();
            auto end = high_resolution_clock::now();
            d += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DynamicArray ar;
            for (int j = 0; j < n; j++) ar.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) ar.removeFromEnd();
            auto end = high_resolution_clock::now();
            a += duration_cast<nanoseconds>(end - start).count();
        }
        remEnd << n << ";" << s / 5 << ";" << d / 5 << ";" << a / 5 << "\n";

        // ? REMOVE AT INDEX – losowy indeks!
        s = d = a = 0;
        for (int i = 0; i < 5; i++) {
            SinglyLinkedList sl;
            for (int j = 0; j < n; j++) sl.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) {
                int index = rand() % sl.getSize();
                sl.removeAtIndex(index);
            }
            auto end = high_resolution_clock::now();
            s += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DoublyLinkedList dl;
            for (int j = 0; j < n; j++) dl.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) {
                int index = rand() % dl.getSize();
                dl.removeAtIndex(index);
            }
            auto end = high_resolution_clock::now();
            d += duration_cast<nanoseconds>(end - start).count();
        }
        for (int i = 0; i < 5; i++) {
            DynamicArray ar;
            for (int j = 0; j < n; j++) ar.addAtEnd(j);
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) {
                int index = rand() % ar.getSize();
                ar.removeAtIndex(index);
            }
            auto end = high_resolution_clock::now();
            a += duration_cast<nanoseconds>(end - start).count();
        }
        remIdx << n << ";" << s / 5 << ";" << d / 5 << ";" << a / 5 << "\n";

        // ? SEARCH – wynik sumujemy i wypisujemy
        s = d = a = 0;
        for (int i = 0; i < 5; i++) {
            SinglyLinkedList sl;
            for (int j = 0; j < n; j++) sl.addAtEnd(j);
            int tmp = 0;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) tmp += sl.search(j);
            auto end = high_resolution_clock::now();
            s += duration_cast<nanoseconds>(end - start).count();
            cout << "Singly search tmp: " << tmp << endl;
        }
        for (int i = 0; i < 5; i++) {
            DoublyLinkedList dl;
            for (int j = 0; j < n; j++) dl.addAtEnd(j);
            int tmp = 0;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) tmp += dl.search(j);
            auto end = high_resolution_clock::now();
            d += duration_cast<nanoseconds>(end - start).count();
            cout << "Doubly search tmp: " << tmp << endl;
        }
        for (int i = 0; i < 5; i++) {
            DynamicArray ar;
            for (int j = 0; j < n; j++) ar.addAtEnd(j);
            int tmp = 0;
            auto start = high_resolution_clock::now();
            for (int j = 0; j < n; j++) tmp += ar.search(j);
            auto end = high_resolution_clock::now();
            a += duration_cast<nanoseconds>(end - start).count();
            cout << "Array search tmp: " << tmp << endl;
        }
        search << n << ";" << s / 5 << ";" << d / 5 << ";" << a / 5 << "\n";
    }

    addBeg.close(); addEnd.close(); addIdx.close();
    remBeg.close(); remEnd.close(); remIdx.close(); search.close();

    cout << "Wszystkie testy zakoñczone!" << endl;
    return 0;
}