#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;

struct Pegawai {
    string nama;
    struct Waktu {
        string datang;
        string pergi;
    } waktu;
    string penghasilan;
};

int bataspegawai = 10; // Batas Pegawai
Pegawai pegawai[10];
int jumlahpegawai = 0; // Pegawai yang terdaftar

int login(int* percobaanlogin) {
    string user;
    string pasw;

    if (*percobaanlogin == 3) {
        cout << "Terlalu banyak percobaan. Program berhenti.";
        return 0; // Akan Berhenti Jika Gagal Login
    }

    cout << "======== Login ========" << endl;
    cout << "Masukkan Nama Pengguna: ";
    cin >> user;
    cout << "Masukkan Password(NIM): ";
    cin >> pasw;
    cout << "=======================" << endl;

    if (user == "Wiam" && pasw == "2309106107") {
        cout << "Berhasil Login." << endl;
        getch();
        cout << "\033[2J\033[1;1H";
        return 1; // Untuk Menandakan Jika Berhasil Login Maka Akan Lanjut
    } else {
        cout << "Kredensial Salah, Coba Lagi." << endl;
        getch();
        cout << "\033[2J\033[1;1H";
        (*percobaanlogin)++;
        return login(percobaanlogin); // Rekursi dengan menambahkan 1 ke percobaanlogin
    }
}

void tampilkanMenu() {
    cout << "\033[2J\033[1;1H";
    cout << "========== Menu ==========" << endl;
    cout << "1. Tambah data pegawai" << endl; // Create
    cout << "2. Tampilkan data pegawai" << endl; // Read
    cout << "3. Perbarui data pegawai" << endl; // Update
    cout << "4. Hapus data pegawai" << endl; // Delete
    cout << "5. Urutkan data pegawai berdasarkan nama (Ascending)" << endl;
    cout << "6. Urutkan data pegawai berdasarkan waktu datang (Descending)" << endl;
    cout << "7. Urutkan data pegawai berdasarkan waktu pergi (Ascending)" << endl;
    cout << "8. Cari data pegawai berdasarkan nama (Ascending)" << endl;
    cout << "9. Cari data pegawai berdasarkan waktu datang (Descending)" << endl;
    cout << "10. Keluar" << endl;
    cout << "==========================" << endl;
}

void tambahDataPegawai() {
    cout << "\033[2J\033[1;1H";
    if (jumlahpegawai < bataspegawai) {
        cout << "Masukkan nama pegawai: ";
        cin >> pegawai[jumlahpegawai].nama;
        cout << "Masukkan waktu datang: ";
        cin >> pegawai[jumlahpegawai].waktu.datang;
        pegawai[jumlahpegawai].waktu.pergi = "-";
        pegawai[jumlahpegawai].penghasilan = "-";
        jumlahpegawai++;
        cout << "Data pegawai berhasil ditambahkan." << endl;
        getch();
    } else {
        cout << "Melebihi Batas Pegawai." << endl;
        getch();
    }
}

void tampilkanDataPegawai() {
    cout << "\033[2J\033[1;1H";
    if (jumlahpegawai > 0) {
        cout << "Data Pegawai:" << endl;
        for (int i = 0; i < jumlahpegawai; i++) {
            cout << "Nama: " << pegawai[i].nama << ", Waktu Datang: " << pegawai[i].waktu.datang << ", Waktu Pergi: " << pegawai[i].waktu.pergi << ", Penghasilan Hari Ini: " << pegawai[i].penghasilan << endl;
            getch();
        }
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
        getch();
    }
}

void perbaruiDataPegawai(Pegawai* pegawaiPtr) {
    cout << "\033[2J\033[1;1H";
    if (jumlahpegawai > 0) {
        string nama;
        cout << "Masukkan nama pegawai yang ingin diperbarui: ";
        cin >> nama;
        for (int i = 0; i < jumlahpegawai; i++) {
            if (pegawaiPtr[i].nama == nama) {
                cout << "Masukkan waktu pergi: ";
                cin >> pegawaiPtr[i].waktu.pergi;
                cout << "Masukkan penghasilan hari ini: ";
                cin >> pegawaiPtr[i].penghasilan;
                cout << "Data pegawai berhasil diperbarui." << endl;
                getch();
                return;
            }
        }
        cout << "Pegawai dengan nama tersebut tidak ditemukan." << endl;
        getch();
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
        getch();
    }
}

void hapusDataPegawai() {
    cout << "\033[2J\033[1;1H";
    if (jumlahpegawai > 0) {
        string nama;
        cout << "Masukkan nama pegawai yang ingin dihapus: ";
        cin >> nama;
        for (int i = 0; i < jumlahpegawai; i++) {
            if (pegawai[i].nama == nama) {
                for (int j = i; j < jumlahpegawai - 1; j++) {
                    pegawai[j] = pegawai[j + 1];
                }
                jumlahpegawai--;
                cout << "Data pegawai berhasil dihapus." << endl;
                getch();
                return;
            }
        }
        cout << "Pegawai dengan nama tersebut tidak ditemukan." << endl;
        getch();
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
        getch();
    }
}

// Bubble Sort
void sortNama() {
    if (jumlahpegawai > 0) {
        Pegawai sortedPegawai[jumlahpegawai];
        copy(pegawai, pegawai + jumlahpegawai, sortedPegawai);
        sort(sortedPegawai, sortedPegawai + jumlahpegawai, [](const Pegawai &a, const Pegawai &b) {
            return a.nama < b.nama;
        });
        cout << "Data pegawai berhasil diurutkan berdasarkan nama (ascending)." << endl;
        cout << "Data Pegawai:" << endl;
        for (int i = 0; i < jumlahpegawai; i++) {
            cout << "Nama: " << sortedPegawai[i].nama << ", Waktu Datang: " << sortedPegawai[i].waktu.datang << ", Waktu Pergi: " << sortedPegawai[i].waktu.pergi << ", Penghasilan Hari Ini: " << sortedPegawai[i].penghasilan << endl;
        }
        getch();
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
        getch();
    }
}

// Insertion Sort
void sortWaktuDatang() {
    if (jumlahpegawai > 0) {
        Pegawai sortedPegawai[jumlahpegawai];
        copy(pegawai, pegawai + jumlahpegawai, sortedPegawai);
        sort(sortedPegawai, sortedPegawai + jumlahpegawai, [](const Pegawai &a, const Pegawai &b) {
            return a.waktu.datang > b.waktu.datang;
        });
        cout << "Data pegawai berhasil diurutkan berdasarkan waktu datang (descending)." << endl;
        cout << "Data Pegawai:" << endl;
        for (int i = 0; i < jumlahpegawai; i++) {
            cout << "Nama: " << sortedPegawai[i].nama << ", Waktu Datang: " << sortedPegawai[i].waktu.datang << ", Waktu Pergi: " << sortedPegawai[i].waktu.pergi << ", Penghasilan Hari Ini: " << sortedPegawai[i].penghasilan << endl;
        }
        getch();
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
        getch();
    }
}

// Quick Sort
void sortWaktuPergi() {
    if (jumlahpegawai > 0) {
        Pegawai sortedPegawai[jumlahpegawai];
        copy(pegawai, pegawai + jumlahpegawai, sortedPegawai);
        sort(sortedPegawai, sortedPegawai + jumlahpegawai, [](const Pegawai &a, const Pegawai &b) {
            return a.waktu.pergi < b.waktu.pergi;
        });
        cout << "Data pegawai berhasil diurutkan berdasarkan waktu pergi (ascending)." << endl;
        cout << "Data Pegawai:" << endl;
        for (int i = 0; i < jumlahpegawai; i++) {
            cout << "Nama: " << sortedPegawai[i].nama << ", Waktu Datang: " << sortedPegawai[i].waktu.datang << ", Waktu Pergi: " << sortedPegawai[i].waktu.pergi << ", Penghasilan Hari Ini: " << sortedPegawai[i].penghasilan << endl;
        }
        getch();
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
        getch();
    }
}

int searchNama(const string& key, int indices[]) {
    int count = 0;
    for (int i = 0; i < jumlahpegawai; i++) {
        if (pegawai[i].nama == key) {
            indices[count++] = i;
        }
    }
    return count;
}


int searchWaktuDatang(const string& key, int indices[]) {
    int count = 0;
    for (int i = 0; i < jumlahpegawai; i++) {
        if (pegawai[i].waktu.datang == key) {
            indices[count++] = i;
        }
    }
    return count;
}


int main() {
    cout << "\033[2J\033[1;1H";
    int percobaanlogin = 0;
    if (!login(&percobaanlogin)) {
        return 0; // Tidak Lanjut Jika Tidak Berhasil Login
    }
    int pilihan;
    do {
        tampilkanMenu();
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahDataPegawai();
                break;
            case 2:
                tampilkanDataPegawai();
                break;
            case 3:
                perbaruiDataPegawai(pegawai);
                break;
            case 4:
                hapusDataPegawai();
                break;
            case 5:
                sortNama();
                break;
            case 6:
                sortWaktuDatang();
                break;
            case 7:
                sortWaktuPergi();
                break;
            case 8: {
                string key;
                cout << "Masukkan nama pegawai yang ingin dicari: ";
                cin >> key;
                int indices[jumlahpegawai];
                int count = searchNama(key, indices);
                if (count > 0) {
                    cout << "Pegawai ditemukan:" << endl;
                    for (int i = 0; i < count; i++) {
                        int index = indices[i];
                        cout << "Nama: " << pegawai[index].nama << ", Waktu Datang: " << pegawai[index].waktu.datang << ", Waktu Pergi: " << pegawai[index].waktu.pergi << ", Penghasilan Hari Ini: " << pegawai[index].penghasilan << endl;
                    }
                } else {
                    cout << "Pegawai tidak ditemukan." << endl;
                }
                getch();
                break;
            }
            case 9: {
                string key;
                cout << "Masukkan waktu datang yang ingin dicari: ";
                cin >> key;
                int indices[jumlahpegawai];
                int count = searchWaktuDatang(key, indices);
                if (count > 0) {
                    cout << "Pegawai ditemukan:" << endl;
                    for (int i = 0; i < count; i++) {
                        int index = indices[i];
                        cout << "Nama: " << pegawai[index].nama << ", Waktu Datang: " << pegawai[index].waktu.datang << ", Waktu Pergi: " << pegawai[index].waktu.pergi << ", Penghasilan Hari Ini: " << pegawai[index].penghasilan << endl;
                    }
                } else {
                    cout << "Pegawai tidak ditemukan." << endl;
                }
                getch();
                break;
            }
            case 10:
                cout << "Terima kasih. Program berhenti." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                getch();
                break;
        }
    } while (pilihan != 10); // Jika memilih pilihan 1-9 akan mengulang

    return 0;
}
