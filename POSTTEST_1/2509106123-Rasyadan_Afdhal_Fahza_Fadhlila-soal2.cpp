#include <iostream>
using namespace std;

struct data_mhs
{
    string nama;
    string nim;
    float ipk;
};

int main(){
    const int jumlah = 5;
    data_mhs mhs[jumlah];

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Data mahasiswa ke " << i+1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
        cout << endl;
    }
    
    int tertinggi = 0;
    for (int i = 1; i < jumlah; i++)
    {
        if (mhs[i].ipk > mhs[tertinggi].ipk)
        {
            tertinggi = i;
        }
    }
    
    cout << "\nData Mahasiswa" << endl;
    cout << string(50, '-') << endl;
    for (int i = 0; i < jumlah; i++)
    {
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM  : " << mhs[i].nim << endl;
        cout << "IPK  : " << mhs[i].ipk << endl;
        cout << string(50, '-') << endl;
    }
    
    cout << "\nMahasiswa Dengan IPK Tertinggi" << endl;
    cout << string(50, '-') << endl;
    cout << "Nama :" << mhs[tertinggi].nama << endl;
    cout << "NIM  :" << mhs[tertinggi].nim << endl;
    cout << "IPK  :" << mhs[tertinggi].ipk << endl;
    
    return 0;
}
