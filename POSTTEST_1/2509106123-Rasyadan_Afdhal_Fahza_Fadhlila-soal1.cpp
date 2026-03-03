#include <iostream>
using namespace std;

/*
Kompleksitas Waktu Analisis

langkah algoritma:

1. min = A[0]           : dijalankan 1 kali (c1)
2. minIndex = 0         : dijalankan 1 kali (c2)
3. looping for          : berjalan dari 1 sampai n-1
                          dengan total perulangan (n-1) * (c3)
4. mengecek A[i] < min  : dijalankan setiap iterasi
                          total = (n-1) * (c4) 
5. if true              : min = A[i];       max (n-1) * (c5)
                          minIndex = i;     max (n-1) * (c6)
6. return min           : 1 kali (c7)


fungsi kompleksitas waktu
T(n) = c1 + c2 + c3(n-1) + c4(n-1) + c5x + c6x + c7
yang dimana x = jumlah kondisi (A[i] < min) terpenuhi

best case (Tmin)
terjadi jika elemen terkecil sudah berada di index 0
yang dimana kondisi A([i] < min) tidak terpenuhi
x = 0

Tmin(n) = c1 + c2 + c3(n-1) + c4(n-1) + c7
Tmin(n) = an + b
sehingga kompleksitasnya: O(n)

worst case (Tmax)
terjadi jika elemen terkecil berada di akhir atau terurut descending 
yang dimana kondisi A([i] < min) selalu terpenuhi untuk semua i
x = n-1

Tmax(n) = c1 + c2 + c3(n-1) + c4(n-1) + c5(n-1) + c6(n-1) + c7
Tmax(n) = an + b
Sehingga kompleksitasnya: O(n)

kesimpulan

baik best case maupun worst case jumlah akan tetap bertambah setara dengan n.

Jadi kompleksitas waktu algoritma ini adalah O(n).
*/ 



int finderMn(int A[], int n, int &minIndex){
    int min = A[0];
    minIndex = 0;

    for (int i = 1; i < n; i++){
        if (A[i] < min)
        {
            min = A[i];
            minIndex = i;
        }
    }

    return min;
}

int main(){
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int index;

    int minim = finderMn(A, n, index);

    cout << "Hasil Dari Pencarian" << endl;
    cout << string(50, '-') << endl;
    cout << "Nilai minimum: " << minim <<endl;
    cout << "Index ke-    : " << index << endl;

    return 0;
}