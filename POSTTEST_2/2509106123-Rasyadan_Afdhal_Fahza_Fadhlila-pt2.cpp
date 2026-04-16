#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    float harga;
};

const int MAX = 100;

void swap(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambahData(Hewan *arr, int &n) {
    cout << "\nTambah Data Hewan\n";
    cout << "ID    : "; cin >> (arr + n)->id;
    cout << "Nama  : "; cin >> (arr + n)->nama;
    cout << "Harga : "; cin >> (arr + n)->harga;
    n++;
}

void tampilData(Hewan *arr, int n) { 
    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->id << " | "
             << (arr + i)->nama << " | "
             << (arr + i)->harga << endl;
    }
}

void linearSearch(Hewan *arr, int n, string key) {
    bool found = false;

    cout << "\nProses Linear Search:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cek index " << i << " -> " << (arr + i)->nama << endl;

        if ((arr + i)->nama == key) {
            cout << "Ditemukan di index " << i << endl;
            cout << "ID: " << (arr + i)->id
                 << " | Harga: " << (arr + i)->harga << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Data tidak ditemukan\n";
}

void fibonacciSearch(Hewan *arr, int n, int key) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        if ((arr + i)->id < key) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if ((arr + i)->id > key) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else {
            cout << "Data ditemukan:\n";
            cout << (arr + i)->id << " | "
                 << (arr + i)->nama << " | "
                 << (arr + i)->harga << endl;
            return;
        }
    }

    if (fibMMm1 && (arr + offset + 1)->id == key) {
        cout << "Data ditemukan:\n";
        cout << (arr + offset + 1)->id << " | "
             << (arr + offset + 1)->nama << " | "
             << (arr + offset + 1)->harga << endl;
        return;
    }

    cout << "Data tidak ditemukan\n";
}

void bubbleSort(Hewan *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swap(arr + j, arr + j + 1); // pointer swap
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan nama (A-Z)\n";
}

void selectionSort(Hewan *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }

        swap(arr + i, arr + minIdx);
    }
    cout << "Data berhasil diurutkan berdasarkan harga\n";
}

int main() {
    Hewan data[MAX];
    int jumlah = 0;
    int pilih;

    do {
        cout << "\nPAWCARE PETSHOP\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Linear Search (Nama)\n";
        cout << "4. Fibonacci Search (ID)\n";
        cout << "5. Bubble Sort (Nama)\n";
        cout << "6. Selection Sort (Harga)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            tambahData(data, jumlah);
        }
        else if (pilih == 2) {
            tampilData(data, jumlah);
        }
        else if (pilih == 3) {
            string nama;
            cout << "Cari nama: ";
            cin >> nama;
            linearSearch(data, jumlah, nama);
        }
        else if (pilih == 4) {
            int id;
            cout << "Cari ID: ";
            cin >> id;
            fibonacciSearch(data, jumlah, id);
        }
        else if (pilih == 5) {
            bubbleSort(data, jumlah);
        }
        else if (pilih == 6) {
            selectionSort(data, jumlah);
        }

    } while (pilih != 0);

    return 0;
}