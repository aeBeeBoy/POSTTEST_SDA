#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    cout << "Program Struct + Array Mahasiswa - NIM 104\n\n";

    const int N = 4;
    Mahasiswa mhs[N];

   
    cout << "Masukkan data 4 mahasiswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama : ";
        getline(cin >> ws, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin >> ws, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

  
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (mhs[j].ipk > mhs[j + 1].ipk) {
                swap(mhs[j], mhs[j + 1]);
            }
        }
    }

  
    cout << "\nData Mahasiswa setelah diurutkan berdasarkan IPK (Ascending):\n";
    cout << left << setw(20) << "Nama" 
         << setw(15) << "NIM" 
         << setw(10) << "IPK" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < N; i++) {
        cout << left << setw(20) << mhs[i].nama 
             << setw(15) << mhs[i].nim 
             << setw(10) << fixed << setprecision(2) << mhs[i].ipk 
             << endl;
    }

    return 0;
}
