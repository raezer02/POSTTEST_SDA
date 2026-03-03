#include <iostream>
#include <iomanip>
using namespace std;

void reverse(int* arr, int n) {
    int* i = arr;
    int* j = arr + n - 1;

    while (i < j) {
        int temp = *i;
        *i = *j;
        *j = temp;

        i++;
        j--;
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int sebelum[7];
    int n = 7;

    for (int i = 0; i < n; i++) {
        sebelum[i] = prima[i];
    }

    reverse(prima, n);

    cout << left << setw(40) << "sebelum dibalik";
    cout << "sesudah dibalik" << endl;
    cout << string(80, '=') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(12) << ("Index: " + to_string(i));
        cout << setw(12) << ("Nilai: " + to_string(sebelum[i]));
        cout << setw(16) << ("Alamat: " + to_string((long long)&sebelum[i]));
        cout << setw(12) << ("Index: " + to_string(i));
        cout << setw(12) << ("Nilai: " + to_string(prima[i]));
        cout << ("Alamat: " + to_string((long long)&prima[i])) << endl;
    }

    return 0;
}