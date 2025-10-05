<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight* next;
};

Flight* head = NULL;
int counterKode = 0; 


string generateKode() {
    if (counterKode == 0) {
        counterKode++;
        return "JT-104";  
    } else {
        return "JT-104-" + to_string(counterKode++ - 1);
    }
}

// 1. Tambah jadwal penerbangan di akhir
void tambahJadwal(string tujuan, string status) {
    Flight* newFlight = new Flight;
    newFlight->kodePenerbangan = generateKode();
    newFlight->tujuan = tujuan;
    newFlight->status = status;
    newFlight->next = NULL;

    if (head == NULL) {
        head = newFlight;
    } else {
        Flight* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newFlight;
    }
    cout << "Jadwal berhasil ditambahkan dengan kode: " << newFlight->kodePenerbangan << endl;
}

// 2. Sisipkan jadwal penerbangan di posisi ke-5
void sisipkanJadwal(string tujuan, string status) {
    int posisi = 5; 

    Flight* newFlight = new Flight;
    newFlight->kodePenerbangan = generateKode();
    newFlight->tujuan = tujuan;
    newFlight->status = status;

    if (posisi == 1 || head == NULL) {
        newFlight->next = head;
        head = newFlight;
    } else {
        Flight* temp = head;
        int count = 1;
        while (temp != NULL && count < posisi - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Posisi terlalu jauh, jadwal ditambahkan di akhir." << endl;
            newFlight->next = NULL;
            if (head == NULL) head = newFlight;
            else {
                Flight* last = head;
                while (last->next != NULL) last = last->next;
                last->next = newFlight;
            }
        } else {
            newFlight->next = temp->next;
            temp->next = newFlight;
        }
    }
    cout << "Jadwal berhasil disisipkan di posisi " << posisi << " dengan kode: " << newFlight->kodePenerbangan << endl;
}

// 3. Hapus jadwal paling awal
void hapusAwal() {
    if (head == NULL) {
        cout << "Tidak ada jadwal untuk dihapus." << endl;
        return;
    }
    Flight* temp = head;
    head = head->next;
    cout << "Jadwal dengan kode " << temp->kodePenerbangan << " berhasil dihapus." << endl;
    delete temp;
}

// 4. Update status penerbangan
void updateStatus(string kode) {
    Flight* temp = head;
    while (temp != NULL) {
        if (temp->kodePenerbangan == kode) {
            cout << "Status saat ini: " << temp->status << endl;
            cout << "Masukkan status baru: ";
            string newStatus;
            cin.ignore(); 
            getline(cin, newStatus);
            temp->status = newStatus;
            cout << "Status penerbangan " << kode << " berhasil diperbarui menjadi: " << newStatus << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan." << endl;
}

// 5. Tampilkan semua jadwal
void tampilkanJadwal() {
    if (head == NULL) {
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    cout << "\nDaftar Jadwal Penerbangan:\n";
    Flight* temp = head;
    while (temp != NULL) {
        cout << "Kode: " << temp->kodePenerbangan
             << " | Tujuan: " << temp->tujuan
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    }
}

// Main Menu
int main() {
    int pilihan;
    string tujuan, status, kode;

    do {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|                FLIGHT SCHEDULE SYSTEM                     |\n";
        cout << "|            [ Ahmad Habibi - 2409106104 ]                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                              |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                            |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                               |\n";
        cout << "| 4. Update Status Penerbangan                              |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                 |\n";
        cout << "| 0. Keluar                                                 |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cin.ignore();
                cout << "Masukkan tujuan: ";
                getline(cin, tujuan);
                cout << "Masukkan status: ";
                getline(cin, status);
                tambahJadwal(tujuan, status);
                break;
            case 2:
                cin.ignore();
                cout << "Masukkan tujuan: ";
                getline(cin, tujuan);
                cout << "Masukkan status: ";
                getline(cin, status);
                sisipkanJadwal(tujuan, status);
                break;
            case 3:
                hapusAwal();
                break;
            case 4:
                cout << "Masukkan kode penerbangan: ";
                cin >> kode;
                cin.ignore(); 
                updateStatus(kode);
                break;
            case 5:
                tampilkanJadwal();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
=======
#include <iostream>
#include <string>
using namespace std;

struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight* next;
};

Flight* head = NULL;
int counterKode = 0; 


string generateKode() {
    if (counterKode == 0) {
        counterKode++;
        return "JT-104";  
    } else {
        return "JT-104-" + to_string(counterKode++ - 1);
    }
}

// 1. Tambah jadwal penerbangan di akhir
void tambahJadwal(string tujuan, string status) {
    Flight* newFlight = new Flight;
    newFlight->kodePenerbangan = generateKode();
    newFlight->tujuan = tujuan;
    newFlight->status = status;
    newFlight->next = NULL;

    if (head == NULL) {
        head = newFlight;
    } else {
        Flight* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newFlight;
    }
    cout << "Jadwal berhasil ditambahkan dengan kode: " << newFlight->kodePenerbangan << endl;
}

// 2. Sisipkan jadwal penerbangan di posisi ke-5
void sisipkanJadwal(string tujuan, string status) {
    int posisi = 5; 

    Flight* newFlight = new Flight;
    newFlight->kodePenerbangan = generateKode();
    newFlight->tujuan = tujuan;
    newFlight->status = status;

    if (posisi == 1 || head == NULL) {
        newFlight->next = head;
        head = newFlight;
    } else {
        Flight* temp = head;
        int count = 1;
        while (temp != NULL && count < posisi - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Posisi terlalu jauh, jadwal ditambahkan di akhir." << endl;
            newFlight->next = NULL;
            if (head == NULL) head = newFlight;
            else {
                Flight* last = head;
                while (last->next != NULL) last = last->next;
                last->next = newFlight;
            }
        } else {
            newFlight->next = temp->next;
            temp->next = newFlight;
        }
    }
    cout << "Jadwal berhasil disisipkan di posisi " << posisi << " dengan kode: " << newFlight->kodePenerbangan << endl;
}

// 3. Hapus jadwal paling awal
void hapusAwal() {
    if (head == NULL) {
        cout << "Tidak ada jadwal untuk dihapus." << endl;
        return;
    }
    Flight* temp = head;
    head = head->next;
    cout << "Jadwal dengan kode " << temp->kodePenerbangan << " berhasil dihapus." << endl;
    delete temp;
}

// 4. Update status penerbangan
void updateStatus(string kode) {
    Flight* temp = head;
    while (temp != NULL) {
        if (temp->kodePenerbangan == kode) {
            cout << "Status saat ini: " << temp->status << endl;
            cout << "Masukkan status baru: ";
            string newStatus;
            cin.ignore(); 
            getline(cin, newStatus);
            temp->status = newStatus;
            cout << "Status penerbangan " << kode << " berhasil diperbarui menjadi: " << newStatus << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan." << endl;
}

// 5. Tampilkan semua jadwal
void tampilkanJadwal() {
    if (head == NULL) {
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    cout << "\nDaftar Jadwal Penerbangan:\n";
    Flight* temp = head;
    while (temp != NULL) {
        cout << "Kode: " << temp->kodePenerbangan
             << " | Tujuan: " << temp->tujuan
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    }
}

// Main Menu
int main() {
    int pilihan;
    string tujuan, status, kode;

    do {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|                FLIGHT SCHEDULE SYSTEM                     |\n";
        cout << "|            [ Ahmad Habibi - 2409106104 ]                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                              |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                            |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                               |\n";
        cout << "| 4. Update Status Penerbangan                              |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                 |\n";
        cout << "| 0. Keluar                                                 |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cin.ignore();
                cout << "Masukkan tujuan: ";
                getline(cin, tujuan);
                cout << "Masukkan status: ";
                getline(cin, status);
                tambahJadwal(tujuan, status);
                break;
            case 2:
                cin.ignore();
                cout << "Masukkan tujuan: ";
                getline(cin, tujuan);
                cout << "Masukkan status: ";
                getline(cin, status);
                sisipkanJadwal(tujuan, status);
                break;
            case 3:
                hapusAwal();
                break;
            case 4:
                cout << "Masukkan kode penerbangan: ";
                cin >> kode;
                cin.ignore(); 
                updateStatus(kode);
                break;
            case 5:
                tampilkanJadwal();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
>>>>>>> b660279b9ba2d0c62a37ae0e2158a350c1596dbb
