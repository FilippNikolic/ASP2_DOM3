//
// Created by nfili on 23/12/2022.
//

#include "Heap.h"


Heap::Heap(int n, int p) {
    storage = new int[n];
    capacity = n;
    size = 0;
    m = p;
}

void Heap::makeHeap(int n) {
    if (n < 1) return;
    if (n > capacity) n = capacity;
    size = 1;
    int steps = 0;
    for (int i = 1; i < n; i++) insert(storage[i], steps);
}

void Heap::insert(int key, int &steps) {
    if (size == capacity) throw "Container full";
    int f = father(size, getM());
    int s = size++;
    steps = 1;
    while (s > 0 && storage[f] > key) {
        storage[s] = storage[f];
        s = f;
        f = father(f, getM());
        steps++;
    }
    storage[s] = key;
}

void Heap::insert_index(int key, int index) {
    if (size == capacity) throw "Container full";
    int f = father(index, getM());
    int s = size;
    int br = 0;
    while (s > 0 && storage[f] > key) {
        storage[index] = storage[f];
        index = f;
        f = father(f, getM());
        if (f == 0) {
            if (br == 1)break;
            br++;
        }
    }
    storage[index] = key;
}


int Heap::peek() const {
    if (size == 0) throw "Container empty";
    return storage[0];
}

int Heap::deleteKey() {
    if (size == 0) throw "Container empty";
    int first = storage[0];
    storage[0] = storage[--size];
    int f = 0;
    while (f < size - 1) {
        int s1 = leftSon(f, getM()), s2 = s1 + 1;
        if (s1 > size - 1) break;
        int x = s1, y = storage[s1];
        if (s2 <= size - 1 && y < storage[s2])    {
            x = s2;
            y = storage[s2];
        }
        if (storage[f] >= y) break;
        storage[x] = storage[f];
        storage[f] = y;
        f = x;
    }
    return first;
}

void Heap::sort() {
    while (size > 0) {
        int first = deleteKey();
        storage[size] = first;
    }
}

ostream &operator<<(ostream &os, const Heap &heap) {
    if (heap.m == -1) {
        os << "Heap je obrisan\n" << endl;
        return os;
    }
    if (heap.union2 == 0) {
        int t = 0, m = heap.getM();
        os << heap.storage[0] << endl;
        for (int i = 1; i < heap.getSize(); i++) {
            os << heap.storage[i] << "  ";
            t++;
            if (t == m) {
                cout << endl;
                t = 0;
                m *= heap.getM();
            }

        }
        os << endl;
        return os;
    }
    int t = 0, m = heap.getM();
    os << heap.storage[0] << endl;
    for (int i = 1; i < heap.getSize(); i++) {
        os << heap.storage[i] << "  ";
        t++;
        if (t == m) {
            cout << endl;
            t = 0;
            m *= heap.getM() - 1;
        }

    }
    os << endl;
    return os;

}

void Heap::makeCopy(const Heap &h) {

}

void Heap::insert(int key) {
    if (size == capacity - 1) {
        cout << "Container full";
        return;
    }
    int f = father(size, getM());
    int s = size++;
    while (s > 0 && storage[f] > key) {
        storage[s] = storage[f];
        s = f;
        f = father(f, getM());
    }
    storage[s] = key;
}

Heap &Heap::delete1(int &steps) {
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

Heap &Heap::delete2(int &steps, int poz) {
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

Heap &Heap::union1(Heap &h, Heap &h1, int &steps) {
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

int removeDuplicates(int *nums, int numsSize) {
    for (int q = 0; q < numsSize; q++) {
        if (q > 0 && nums[q] == nums[q - 1]) {
            numsSize--;
            for (int i = q; i < numsSize; i++) {
                nums[q] = nums[q + 1];
            }
        }
    }
    return numsSize;
}
