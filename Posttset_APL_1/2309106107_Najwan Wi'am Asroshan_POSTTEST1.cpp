#include <iostream>
using namespace std;

int main(){
    string user;
    string pasw;
    int percobaanlogin;
    percobaanlogin = 0;


    while (percobaanlogin < 3){
        cout << "======== Login ========" << endl;
        cout << "Masukkan Nama Pengguna :";
        cin >> user;
        cout << "Masukkan Password User(NIM) :";
        cin >> pasw;
        cout << "=======================" << endl;

        if (user == "Wiam" && pasw == "2309106107"){
            cout << "Berhasil Login" << endl;
            while (true) {
                string pilihan;
                double celcius, reamur, fahrenheit, kelvin;

                cout << "============== Konversi Suhu ==============" << endl;
                cout << "Pilih Suhu Awal Yang Ingin Di Konversikan :" << endl;
                cout << "1.Celcius ke Reamur,Fahrenheit,Kelvin" << endl;
                cout << "2.Reamur ke Celcius,Fahrenheit,Kelvin" << endl;
                cout << "3.Fahrenheit ke Celcius,Reamur,Kelvin" << endl;
                cout << "4.Kelvin ke Celcius,Reamur,Fahrenheit" << endl;
                cout << "5.Keluar Program" << endl;
                cout << "Masukkan Pilihan(1-5)";
                cout << "==========================================" << endl;
                cin >> pilihan;

                if (pilihan == "1"){
                    cout << "Masukkan Suhu Celcius Yang Ingin Dikonversikan :";
                    cin >> celcius;
                    kelvin = celcius + 273;
                    reamur = celcius * 4 / 5;
                    fahrenheit = (celcius * 9 / 5) + 32;
                    cout << celcius << " Celcius = " << reamur << " Konversi Reamur" << endl;
                    cout << celcius << " Celcius = " << fahrenheit << " Konversi Fahrenheit" << endl;
                    cout << celcius << " Celcius = " << kelvin << " Konversi Kelvin" << endl;
                } else if (pilihan == "2") {
                    cout << "Masukkan Suhu Reamur Yang Ingin Dikonversikan :";
                    cin >> reamur;
                    celcius = reamur * 5 / 4;
                    kelvin = reamur * 5 / 4 + 32;
                    fahrenheit = reamur * 9 / 4 + 32;
                    cout << reamur << " Reamur = " << celcius << " Konversi Celcius" << endl;
                    cout << reamur << " Reamur = " << fahrenheit << " Konversi Fahrenheit" << endl;
                    cout << reamur << " Reamur = " << kelvin << " Konversi Kelvin" << endl;
                } else if (pilihan == "3") {
                    cout << "Masukkan Suhu Fahrenheit Yang Ingin Dikonversikan :";
                    cin >> fahrenheit;
                    celcius = (fahrenheit - 32) * 5 / 9;
                    reamur = (fahrenheit - 32) * 4 / 9;
                    kelvin = (fahrenheit - 32) * 5 / 9 + 273;
                    cout << fahrenheit << " Fahrenheit = " << celcius << " Konversi Celcius" << endl;
                    cout << fahrenheit << " Fahrenheit = " << reamur << " Konversi Reamur" << endl;
                    cout << fahrenheit << " Fahrenheit = " << kelvin << " Konversi Kelvin" << endl;
                } else if (pilihan == "4") {
                    cout << "Masukkan Suhu Kelvin Yang Ingin Dikonversikan :";
                    cin >> kelvin;
                    celcius = kelvin - 273;
                    reamur = (kelvin - 273 ) * 4 / 5;
                    fahrenheit = (kelvin - 273) * 9 / 5 + 32;
                    cout << kelvin << " Kelvin = " << celcius << " Konversi Celcius" << endl;
                    cout << kelvin << " Kelvin = " << reamur << " Konversi Reamur" << endl;
                    cout << kelvin << " Kelvin = " << fahrenheit << " Konversi Fahrenheit" << endl;
                } else if (pilihan == "5") {
                    percobaanlogin += 3;
                    break;
                } else {
                    cout << "Pilihan Tidak Valid" << endl;
                }
            }

        }
        else{
            cout << "Kredensial Akun Salah,Silahkan Coba Lagi(Batas 3x)" << endl;
            percobaanlogin ++;
        }
    if (percobaanlogin == 3){
        cout << "Program Berhenti." << endl;
        break;
    }
    }
    return 0;
}


