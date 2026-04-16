#include <iostream>
#include <string>
using namespace std;

#define MAX 100
#define CHAR 256

struct Hewan {
    int id;
    string nama;
    float harga;
};

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
            cout << "Ditemukan: "
                 << (arr + i)->id << " | "
                 << (arr + i)->nama << " | "
                 << (arr + i)->harga << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Data tidak ditemukan\n";
}

void fibonacciSearch(Hewan *arr, int n, int key) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if ((arr + i)->id < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if ((arr + i)->id > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            cout << "Ditemukan: "
                 << (arr + i)->id << " | "
                 << (arr + i)->nama << " | "
                 << (arr + i)->harga << endl;
            return;
        }
    }

    if (fib1 && (arr + offset + 1)->id == key) {
        cout << "Ditemukan: "
             << (arr + offset + 1)->id << " | "
             << (arr + offset + 1)->nama << " | "
             << (arr + offset + 1)->harga << endl;
        return;
    }

    cout << "Data tidak ditemukan\n";
}

void badChar(string str, int size, int badchar[CHAR]) {
    for (int i = 0; i < CHAR; i++)
        badchar[i] = -1;

    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void boyerMoore(Hewan *arr, int n, string pattern) {
    bool found = false;

    for (int k = 0; k < n; k++) {
        string text = (arr + k)->nama;
        int m = pattern.size();
        int len = text.size();

        int badchar[CHAR];
        badChar(pattern, m, badchar);

        int s = 0;
        while (s <= (len - m)) {
            int j = m - 1;

            while (j >= 0 && pattern[j] == text[s + j])
                j--;

            if (j < 0) {
                cout << "Ditemukan: "
                     << (arr + k)->id << " | "
                     << text << " | "
                     << (arr + k)->harga << endl;
                found = true;
                break;
            }
            else {
                s += max(1, j - badchar[text[s + j]]);
            }
        }
    }

    if (!found) cout << "Data tidak ditemukan\n";
}

void bubbleSort(Hewan *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
    cout << "Sorted nama (A-Z)\n";
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
    cout << "Sorted harga\n";
}

int partition(Hewan *arr, int low, int high) {
    int pivot = (arr + high)->id;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if ((arr + j)->id < pivot) {
            i++;
            swap(arr + i, arr + j);
        }
    }

    swap(arr + i + 1, arr + high);
    return i + 1;
}

void quickSort(Hewan *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
        cout << "7. Quick Sort (ID)\n";
        cout << "8. Boyer Moore (Nama)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) tambahData(data, jumlah);
        else if (pilih == 2) tampilData(data, jumlah);
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
        else if (pilih == 5) bubbleSort(data, jumlah);
        else if (pilih == 6) selectionSort(data, jumlah);
        else if (pilih == 7) {
            quickSort(data, 0, jumlah - 1);
            cout << "Sorted Quick Sort (ID)\n";
        }
        else if (pilih == 8) {
            string key;
            cout << "Cari nama: ";
            cin >> key;
            boyerMoore(data, jumlah, key);
        }

    } while (pilih != 0);

    return 0;
}