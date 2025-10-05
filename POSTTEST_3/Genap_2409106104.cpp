#include <iostream>
#include <string>
using namespace std;

struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight* next;
    Flight* prev;
};

Flight* head = NULL;
Flight* tail = NULL; 
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
    newFlight->prev = NULL;

    if (head == NULL) {
        head = tail = newFlight;
    } else {
        tail->next = newFlight;
        newFlight->prev = tail;
        tail = newFlight;
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
    newFlight->next = NULL;
    newFlight->prev = NULL;

    if (posisi == 1 || head == NULL) {
        newFlight->next = head;
        if (head != NULL) head->prev = newFlight;
        head = newFlight;
        if (tail == NULL) tail = newFlight;
    } else {
        Flight* temp = head;
        int count = 1;
        while (temp != NULL && count < posisi - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL || temp->next == NULL) {
            if (tail != NULL) {
                tail->next = newFlight;
                newFlight->prev = tail;
                tail = newFlight;
            } else {
                head = tail = newFlight;
            }
        } else {
            newFlight->next = temp->next;
            newFlight->prev = temp;
            temp->next->prev = newFlight;
            temp->next = newFlight;
        }
    }
    cout << "Jadwal berhasil disisipkan di posisi " << posisi 
         << " dengan kode: " << newFlight->kodePenerbangan << endl;
}

// 3. Hapus jadwal paling awal
void hapusAwal() {
    if (head == NULL) {
        cout << "Tidak ada jadwal untuk dihapus." << endl;
        return;
    }
    Flight* temp = head;
    cout << "Jadwal dengan kode " << temp->kodePenerbangan << " berhasil dihapus." << endl;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    else tail = NULL; 
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

// 5. Tampilkan semua jadwal (forward traversal)
void tampilkanJadwal() {
    if (head == NULL) {
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    cout << "\nDaftar Jadwal Penerbangan (Forward):\n";
    Flight* temp = head;
    while (temp != NULL) {
        cout << "Kode: " << temp->kodePenerbangan
             << " | Tujuan: " << temp->tujuan
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    }
}

// 6. Tampilkan dari belakang (reverse traversal)
void tampilkanJadwalBelakang() {
    if (tail == NULL) {
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    cout << "\nDaftar Jadwal Penerbangan (Reverse):\n";
    Flight* temp = tail;
    while (temp != NULL) {
        cout << "Kode: " << temp->kodePenerbangan
             << " | Tujuan: " << temp->tujuan
             << " | Status: " << temp->status << endl;
        temp = temp->prev;
    }
}

// 7. Cari detail data berdasarkan kode atau tujuan
void cariJadwal(string keyword) {
    if (head == NULL) {
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    Flight* temp = head;
    bool found = false;
    while (temp != NULL) {
        if (temp->kodePenerbangan == keyword || temp->tujuan == keyword) {
            cout << "\nDetail Penerbangan:\n";
            cout << "Kode: " << temp->kodePenerbangan << endl;
            cout << "Tujuan: " << temp->tujuan << endl;
            cout << "Status: " << temp->status << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) cout << "Data dengan kode/nama tujuan \"" << keyword << "\" tidak ditemukan." << endl;
}

// Main Menu
int main() {
    int pilihan;
    string tujuan, status, kode, keyword;

    do {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|                FLIGHT SCHEDULE SYSTEM (DLL)               |\n";
        cout << "|            [ Ahmad Habibi - 2409106104 ]                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                              |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                            |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                               |\n";
        cout << "| 4. Update Status Penerbangan                              |\n";
        cout << "| 5. Tampilkan Semua Jadwal (Forward)                       |\n";
        cout << "| 6. Tampilkan Semua Jadwal (Reverse)                       |\n";
        cout << "| 7. Cari Detail Jadwal (Kode / Tujuan)                     |\n";
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
                updateStatus(kode);
                break;
            case 5:
                tampilkanJadwal();
                break;
            case 6:
                tampilkanJadwalBelakang();
                break;
            case 7:
                cin.ignore();
                cout << "Masukkan kode / tujuan: ";
                getline(cin, keyword);
                cariJadwal(keyword);
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
