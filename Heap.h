//
// Created by nfili on 23/12/2022.
//

#ifndef ASP2_DOM3_HEAP_H
#define ASP2_DOM3_HEAP_H

#include <iostream>
#include <cmath>


using namespace std;

class Heap {
public:
    Heap(int n, int m = 1);

    Heap(int *keys, int n, int p) {
        m = p;
        capacity = n;
        size = 0;
        this->storage = keys;
        makeHeap(n);
    }

    Heap(const Heap &h) { makeCopy(h); }

    Heap(Heap &&h) { move(h); }

    Heap &operator=(const Heap &h) {
        if (this != &h) {
            clear();
            makeCopy(h);
        }
        return *this;
    }

    Heap &operator=(Heap &&h) {
        if (this != &h) {
            clear();
            move(h);
        }
        return *this;
    }

    ~Heap() { clear(); }

    int get() const { return storage[0]; }

    void print_storage() {
        for (int i = 0; i < size; i++) {
            cout << storage[i] << "||";
        }
        cout << endl;
    }

    void destroy() {
        clear();
    }

    bool is_empty() {
        if (size == 0)return true;
        return false;
    }


    Heap &delete1(int &steps);

    Heap &delete2(int &steps, int poz);

    int getCapacity() const { return capacity; }

    int getM() const { return m; }

    int getSize() const { return size; }

    static void sort(int *niz, int n, int m) {
        Heap h(niz, n, m);
        h.sort();
        h.storage = nullptr;
    }

    void insert(int key, int &steps);

    void insert(int key);

    void insert_index(int key, int index);

    int peek() const;

    int deleteKey();

    Heap &union1(Heap &h, Heap &h1, int &steps);

    Heap &change_key(int index, int into) {
        cout << *this << endl;
        insert_index(into, index);
        return *this;
    }

    Heap &convertTo(Heap &h1, int newM) {
        int st = 0;

        for (int i = 0; i < size; i++) {
            int p = storage[i];
            h1.insert(storage[i], st);
        }
        return h1;
    }

private:
    int *storage;
    int capacity;
    int size;
    int m;
    int union2 = 0;

    void makeCopy(const Heap &h);

    void move(Heap &h) {
        storage = h.storage;
        capacity = h.capacity;
        size = h.size;
        h.storage = nullptr;
        h.capacity = h.size = 0;
    }


    void clear() {

        storage = nullptr;
        capacity = size = 0;
        m = -1;
    }

    void makeHeap(int n);

    void makeHeap() { makeHeap(capacity); }

    static int leftSon(int i, int m) { return (i + 1) * m - 1; }

    static int rightSon(int i, int m) { return (i + 1) * m; }

    static int father(int i, int m) { return (i - 1) / m; }

    void sort();

    friend ostream &operator<<(ostream &os, const Heap &h);
};


#endif //ASP2_DOM3_HEAP_H
