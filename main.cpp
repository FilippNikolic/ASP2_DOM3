#include <iostream>
#include "heap.cpp"
#include "PriorityQueue.h"
#include "thread"
#include "chrono"
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {

    int k;


    while (true) {
        cout << "1.Merenje preformansi\n2.Unos Elementa\n3.Provera svih funkcija\n4.Kraj rada\n";
        cin >> k;
        switch (k) {
            case 1: {
                int dat;
                cout << "Velicina hipa" << setw(20) << "Vrm umtnj" << setw(20) << "Br k umtnj" << setw(20) << "Vrm izb"
                     << setw(20) << "Br k izb\n";
                FILE *file;

                for (int i = 0; i < 5; i++) {
                    switch (i) {
                        case 0: {
                            file = fopen("test_10.txt", "r");
                            dat = 10;
                            int t, dat1[dat], br = 0;
                            do {
                                fscanf(file, "%d\n", &t);
                                dat1[br++] = t;
                            } while (br < dat);
                            fclose(file);
                            for (int m = 2; m <= 8; m += 2) {
                                cout << dat << "," << m << setw(20);
                                Heap h(dat, m);
                                int steps = 0;
                                double uk, Sumsteps = 0;
                                auto start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.insert(dat1[j], steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                auto end = high_resolution_clock::now();
                                duration<double, std::milli> time_ellapsed_ms = end - start;

                                cout << time_ellapsed_ms.count() << "s" << setw(20);
                                cout << Sumsteps << setw(20);
                                steps = 0;
                                Sumsteps = 0;
                                start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.delete1(steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                end = high_resolution_clock::now();
                                duration<double, std::milli> time = end - start;
                                cout << Sumsteps << setw(20);
                                cout << time.count() << "s" << endl;
                            }
                            break;
                        }
                        case 1: {
                            file = fopen("test_100.txt", "r");
                            dat = 100;
                            int t, dat1[dat], br = 0;
                            do {
                                fscanf(file, "%d\n", &t);
                                dat1[br++] = t;
                            } while (br < dat);
                            fclose(file);
                            for (int m = 2; m <= 8; m += 2) {
                                cout << dat << "," << m << setw(20);
                                Heap h(dat, m);
                                int steps = 0;
                                double uk, Sumsteps = 0;
                                auto start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.insert(dat1[j], steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                auto end = high_resolution_clock::now();
                                duration<double, std::milli> time_ellapsed_ms = end - start;

                                cout << time_ellapsed_ms.count() << "s" << setw(20);
                                cout << Sumsteps << setw(20);
                                steps = 0;
                                Sumsteps = 0;
                                start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.delete1(steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                end = high_resolution_clock::now();
                                duration<double, std::milli> time = end - start;
                                cout << Sumsteps << setw(20);
                                cout << time.count() << "s" << endl;
                            }
                            break;
                        }
                        case 2: {
                            file = fopen("test_1000.txt", "r");
                            dat = 1000;
                            int t, dat1[dat], br = 0;
                            do {
                                fscanf(file, "%d\n", &t);
                                dat1[br++] = t;
                            } while (br < dat);
                            fclose(file);
                            for (int m = 2; m <= 8; m += 2) {
                                cout << dat << "," << m << setw(20);
                                Heap h(dat, m);
                                int steps = 0;
                                double uk, Sumsteps = 0;
                                auto start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.insert(dat1[j], steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                auto end = high_resolution_clock::now();
                                duration<double, std::milli> time_ellapsed_ms = end - start;

                                cout << time_ellapsed_ms.count() << "s" << setw(20);
                                cout << Sumsteps << setw(20);
                                steps = 0;
                                Sumsteps = 0;
                                start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.delete1(steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                end = high_resolution_clock::now();
                                duration<double, std::milli> time = end - start;
                                cout << Sumsteps << setw(20);
                                cout << time.count() << "s" << endl;
                            }
                            break;
                        }
                        case 3: {
                            file = fopen("test_10000.txt", "r");
                            dat = 10000;
                            int t, dat1[dat], br = 0;
                            do {
                                fscanf(file, "%d\n", &t);
                                dat1[br++] = t;
                            } while (br < dat);
                            fclose(file);
                            for (int m = 2; m <= 8; m += 2) {
                                cout << dat << "," << m << setw(20);
                                Heap h(dat, m);
                                int steps = 0;
                                double uk, Sumsteps = 0;
                                auto start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.insert(dat1[j], steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                auto end = high_resolution_clock::now();
                                duration<double, std::milli> time_ellapsed_ms = end - start;

                                cout << time_ellapsed_ms.count() << "s" << setw(20);
                                cout << Sumsteps << setw(20);
                                steps = 0;
                                Sumsteps = 0;
                                start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.delete1(steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                end = high_resolution_clock::now();
                                duration<double, std::milli> time = end - start;
                                cout << Sumsteps << setw(20);
                                cout << time.count() << "s" << endl;
                            }
                            break;
                        }
                        case 4: {
                            file = fopen("test_100000.txt", "r");
                            dat = 100000;
                            int t, dat1[dat], br = 0;
                            do {
                                fscanf(file, "%d\n", &t);
                                dat1[br++] = t;
                            } while (br < dat);
                            fclose(file);
                            for (int m = 2; m <= 8; m += 2) {
                                cout << dat << "," << m << setw(20);
                                Heap h(dat, m);
                                int steps = 0;
                                double uk, Sumsteps = 0;
                                auto start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.insert(dat1[j], steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                auto end = high_resolution_clock::now();
                                duration<double, std::milli> time_ellapsed_ms = end - start;

                                cout << time_ellapsed_ms.count() << "s" << setw(20);
                                cout << Sumsteps << setw(20);
                                steps = 0;
                                Sumsteps = 0;
                                start = high_resolution_clock::now();
                                for (int j = 0; j < dat; j++) {
                                    h.delete1(steps);
                                    Sumsteps += steps;
                                    steps = 0;
                                }
                                end = high_resolution_clock::now();
                                duration<double, std::milli> time = end - start;
                                cout << Sumsteps << setw(20);
                                cout << time.count() << "s" << endl;
                            }
                            break;
                        }
                    }
                }
                cout << endl;
                break;
            }
            case 2: {
                int m, n, key;
                cout << "Unesite kapacitet heap-a:";
                cin >> n;
                cout << "Unesite m heap-a:";
                cin >> m;
                Heap h(n, m);
                cout << "Unesite vrednosti elemenata(za prekid unosa unesite -1)\n";
                while (true) {
                    cin >> key;
                    if (key == -1 || h.getSize() == h.getCapacity())break;
                    h.insert(key, m);
                    cout << h << endl;
                }
                do {
                    cout
                            << "1.Brisanje elementa\n2.Umetanje elementa\n3.Dohvatanje prvog\n4.Da li je red prazan\n5.Ispisivanje hepa-a\n6.Kraj rada\n";
                    cin >> n;
                    switch (n) {
                        case 1:
                            cout << "Pre brisanja:\n" << h << endl;
                            h.delete1(m);
                            cout << "Posle brisanja:\n" << h << endl << endl;
                            break;
                        case 2:
                            cout << "Pre umetanja:\n" << h << endl << "Vrednost kljuca:";
                            cin >> key;
                            h.insert(key);
                            cout << "Posle umetanja:\n" << h << endl << endl;
                            break;
                        case 3:
                            cout << "Dohvatanje prvog elementa: " << h.get() << endl << endl;
                            break;
                        case 4:
                            cout << "Da li je red prazan:";
                            cout << h.is_empty() << endl << endl;
                            break;
                        case 5:
                            cout << "Ispisivanje heap-a\n";
                            cout << h << endl;
                            break;
                        case 6:
                            exit(0);
                    }
                } while (true);
            }
            case 3: {
                int M, N;
                cout << "Unesite M i kapacitet hipa:";
                cin >> M >> N;
                cout << endl;
                int keys[N], keys2[N], br = 1, steps = 0;
                srand(time(0));
                for (int i = 0; i < N; i++) {
                    keys[i] = rand() % 100 + 1;
                }
                for (int i = 0; i < N; i++) {
                    keys2[i] = rand() % 50 + 1;
                }
                Heap h(N, M);

                cout << "Da li je red prazan:";
                cout << h.is_empty() << endl << endl;

                for (int i = 0; i < N; ++i) {
                    h.insert(keys2[i], steps);
                    //cout << steps << "\t";
                }


                Heap h2(N, M);

                for (int i = 0; i < N; ++i) {
                    h2.insert(keys[i], steps);
                }

                cout << endl << endl;
                cout << "Stvaranje heap-a\n";
                cout << h << endl;
                cout << "Da li je red prazan:";
                cout << h.is_empty() << endl;
                cout << "Najmanji element je (i prvi u redu)" << h.get() << endl << endl;
                cout << "Brisanje najmanjeg elementa\n";
                cout << h << endl;
                h = h.delete1(steps);
                cout << h << endl;

                int m;
                cout << "Konvertovaje u heap m:";
                cin >> m;
                Heap h1(h.getCapacity(), m);
                cout << endl;
                h.convertTo(h1, m);
                cout << h1 << endl;

                cout << "Spajanje dva hepa-a\n";
                cout << h2 << endl;
                cout << h << endl;
                cout << "U heap:\n";
                Heap h3(h2.getCapacity() + h.getCapacity(), h.getM() + 1);
                h.union1(h2, h3, steps);
                cout << h3 << endl;

                cout << "Brisanje elemnta heap-a (indeks): ";
                int index, elem;
                cin >> index;
                //h3.change_key(index, elem);
                h3.delete2(index, steps);
                cout << h3 << endl;


                cout << "Brisanje hepa-a\n";
                h3.destroy();
                cout << h3;
                break;
            }
            case 4: {
                cout << "Kraj programa";
                exit(0);
            }
        }
    }
}
