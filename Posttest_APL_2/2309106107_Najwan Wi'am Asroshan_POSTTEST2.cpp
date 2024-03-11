#include <iostream>
using namespace std;

int banyakpegawai = 10; // Batas Pegawai
int jumlahpegawai = 0; // Pegawai yg terdaftar

string pegawai[10][4]; // indeks kedua berisi nama,waktu datang,waktu pergi,dan penghasilan

int login (){
    string user;
    string pasw;
    int percobaanlogin = 0;

    while (percobaanlogin < 3)
    {
        cout << "======== Login ========" << endl;
        cout << "Masukkan Nama Pengguna: ";
        cin >> user;
        cout << "Masukkan Password(NIM): ";
        cin >> pasw;
        cout << "=======================" << endl;

        if (user == "Wiam" && pasw == "2309106107")
        {
            cout << "Berhasil Login." << endl;
            return 1; // Untuk Menandakan Jika Berhasil Login Maka Akan Lanjut
        }
        else
        {
            cout << "Kredensial Salah,Coba Lagi." << endl;
            percobaanlogin++; // Jika Gagal Menambahkan 1 ke loginattemp
        }
    }
    if (percobaanlogin == 3)
    {
            cout << "Terlalu banyak percobaan. Program berhenti.";
            return 0; // Akan Berhenti Jika Gagal Login
    }
    return 0;
}


void tampilkanMenu() {
    cout << "========== Menu ==========" << endl;
    cout << "1. Tambah data pegawai" << endl; // Create
    cout << "2. Tampilkan data pegawai" << endl; // Read
    cout << "3. Perbarui data pegawai" << endl; // Update
    cout << "4. Hapus data pegawai" << endl; // Delete
    cout << "5. Keluar" << endl;
    cout << "==========================" << endl;
}

void tambahDataPegawai() {
    if (jumlahpegawai < banyakpegawai) {
        cout << "Masukkan nama pegawai: ";
        cin >> pegawai[jumlahpegawai][0];
        cout << "Masukkan waktu datang: ";
        cin >> pegawai[jumlahpegawai][1];
        pegawai[jumlahpegawai][2] = "-";
        pegawai[jumlahpegawai][3] = "-"; 
        jumlahpegawai++;
        cout << "Data pegawai berhasil ditambahkan." << endl;
    } else {
        cout << "Melebihi Batas Pegawai." << endl;
    }
}

void tampilkanDataPegawai() {
    if (jumlahpegawai > 0) {
        cout << "Data Pegawai:" << endl;
        for (int i = 0; i < jumlahpegawai; i++) {
            cout << "Nama: " << pegawai[i][0] << ", Waktu Datang: " << pegawai[i][1] << ", Waktu Pergi: " << pegawai[i][2] << ", Penghasilan Hari Ini: " << pegawai[i][3] << endl;
        }
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
    }
}

void perbaruiDataPegawai() {
    if (jumlahpegawai > 0) {
        string nama;
        cout << "Masukkan nama pegawai yang ingin diperbarui: ";
        cin >> nama;
        for (int i = 0; i < jumlahpegawai; i++) {
            if (pegawai[i][0] == nama) {
                cout << "Masukkan waktu pergi: ";
                cin >> pegawai[i][2]; 
                cout << "Masukkan penghasilan hari iniz: ";
                cin >> pegawai[i][3]; 
                cout << "Data pegawai berhasil diperbarui." << endl;
                return;
            }
        }
        cout << "Pegawai dengan nama tersebut tidak ditemukan." << endl;
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
    }
}

void hapusDataPegawai() {
    if (jumlahpegawai > 0) {
        string nama;
        cout << "Masukkan nama pegawai yang ingin dihapus: ";
        cin >> nama;
        for (int i = 0; i < jumlahpegawai; i++) {
            if (pegawai[i][0] == nama) {
                for (int j = i; j < jumlahpegawai - 1; j++) {
                    for (int k = 0; k < 4; k++) {
                        pegawai[j][k] = pegawai[j + 1][k];
                    }
                }
                jumlahpegawai--;
                cout << "Data pegawai berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Pegawai dengan nama tersebut tidak ditemukan." << endl;
    } else {
        cout << "Belum Ada Pegawai Yang Terdaftar." << endl;
    }
}

int main() {
    if (!login()) {
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
                perbaruiDataPegawai();
                break;
            case 4:
                hapusDataPegawai();
                break;
            case 5:
                cout << "Terima kasih. Program berhenti." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 5); // Jika memilih pilihan 1-4 akan mengulang

    return 0;
}