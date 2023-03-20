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
    Heap(int n, int m=1);

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

    bool is_empty(){
        if(size==0)return true;
        return false;
    }

    Heap &delete1(int &steps) {
        storage[0] = storage[--size];
        int f = 1, tmp, tek, tmp2 = 0, tmp3 = 0;
        int min = get();
        steps++;
        while (true) {
            //print_storage();
            for (int i = tmp2 + 1; i <= tmp2 + m; i++) {
                if (i > size)return *this;
                if (storage[i] < min) {
                    steps++;
                    min = storage[i];
                    tmp = i;
                    f = 0;
                }
            }
            if (f)break;
            if (tmp2 > size)break;
            tek = storage[tmp];
            storage[tmp] = storage[tmp3];
            storage[tmp3] = tek;
            min = storage[tmp];
            tmp2 = tmp * m;
            tmp3 = tmp;
            f = 1;
            if (tmp2 > size)break;
        }
        return *this;
    }

    Heap &delete2(int &steps,int poz) {
        storage[poz] = storage[--size];
        int f = 1, tmp, tek, tmp2 = 0, tmp3 = 0;
        int min = get();
        steps++;
        while (true) {
            //print_storage();
            for (int i = tmp2 + 1; i <= tmp2 + m; i++) {
                if (i > size)return *this;
                if (storage[i] < min) {
                    steps++;
                    min = storage[i];
                    tmp = i;
                    f = 0;
                }
            }
            if (f)break;
            if (tmp2 > size)break;
            tek = storage[tmp];
            storage[tmp] = storage[tmp3];
            storage[tmp3] = tek;
            min = storage[tmp];
            tmp2 = tmp * m;
            tmp3 = tmp;
            f = 1;
            if (tmp2 > size)break;
        }
        return *this;
    }

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

    Heap &union1(Heap &h, Heap &h1, int &steps) {
        int br1 = 0, br2 = 0, f1 = 1, f2 = 0, f3 = 1, f4 = 1, br3 = 0;
        if (m != h.getM())return *this;
        /*print_storage();
        cout << endl;
        h.print_storage();
        cout << endl;*/
        if (h.get() >= get()) {

            while (br1 < size || br2 < h.size) {
                for (int i = 0; i < pow(m, f1); i++) {
                    if (br1 >= size)break;
                    h1.storage[br3++] = storage[br1++];
                    h1.size++;
                    /*h1.print_storage();
                    cout << endl;*/

                    if (f3) {
                        f3 = 0;
                        f1--;
                        break;
                    }
                }
                f1++;
                for (int i = 0; i < pow(m, f2); ++i) {
                    if (br2 >= h.size || f2 == 0)break;
                    h1.storage[br3++] = h.storage[br2++];
                    h1.size++;
                    /*h1.print_storage();
                    cout << endl;*/
                    if (f4) {
                        f4 = 0;
                        f2--;
                        break;
                    }
                }
                f2++;
            }
        } else {
            while (br1 < h.size || br2 < size) {
                for (int i = 0; i < pow(m, f1); i++) {
                    if (br1 >= h.size)break;
                    h1.storage[br3++] = h.storage[br1++];
                    h1.size++;
                    /*h1.print_storage();
                    cout << endl;*/

                    if (f3) {
                        f3 = 0;
                        f1--;
                        break;
                    }
                }
                f1++;
                for (int i = 0; i < pow(m, f2); ++i) {
                    if (br2 >= size || f2 == 0)break;
                    h1.storage[br3++] = storage[br2++];
                    h1.size++;
                    /*h1.print_storage();
                    cout << endl;*/
                    if (f4) {
                        f4 = 0;
                        f2--;
                        break;
                    }
                }
                f2++;
            }
        }
        h1.union2 = 1;
        //h1.print_storage();
        return h1;
    }

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
