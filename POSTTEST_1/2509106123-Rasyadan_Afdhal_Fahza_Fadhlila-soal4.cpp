#include <iostream>
using namespace std;

int main(){
    int x, y;

    cout << "masukan nilai pertama: ";
    cin >> x;
    cout << "masukan nilai kesua: ";
    cin >> y;
    cout << string(50, '-') << endl;
    
    cout << "\nsebelum penukaran: " << endl;
    cout << string(50, '-') << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    int &a = x;
    int &b = y;

    int tampung = a;
    a = b;
    b = tampung;

    cout << "\nsetelah penukaran: " << endl;
    cout << string(50, '-') << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}