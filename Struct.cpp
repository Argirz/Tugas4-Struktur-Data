#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

struct daftarMahasiswa {
    mahasiswa data[30];
    int pos;

    daftarMahasiswa() : pos(-1) {}
} sikc;

void dMenu() {
    system("cls");
    cout << "Aplikasi Tampilan Menu dan Sorting\n";
    cout << "1. Masukkan Data Mahasiswa\n";
    cout << "2. Tampilkan Data Mahasiswa\n";
    cout << "3. Perbaiki Data Mahasiswa\n";
    cout << "4. Data Default: Argi Rizky Kurniawan\n";
    cout << "5. Sorting Ascending (IPK)\n";
    cout << "6. Sorting Descending (IPK)\n";
    cout << "7. Exit\n";
    cout << "Masukkan angka: ";
}

void tampilkanData(int p) {
    if (p < 0 || p > sikc.pos) {
        cout << "Data tidak ditemukan!\n";
        return;
    }
    cout << "NIM: " << sikc.data[p].nim << "\n";
    cout << "Nama: " << sikc.data[p].nama << "\n";
    cout << "Alamat: " << sikc.data[p].alamat << "\n";
    cout << "IPK: " << sikc.data[p].ipk << "\n";
}

void masukanData() {
    if (sikc.pos >= 29) {
        cout << "Data sudah penuh! Tidak bisa menambah data.\n";
        return;
    }
    sikc.pos++;
    system("cls");
    cout << "Masukkan NIM: ";
    getline(cin, sikc.data[sikc.pos].nim);
    cout << "Masukkan Nama: ";
    getline(cin, sikc.data[sikc.pos].nama);
    cout << "Masukkan Alamat: ";
    getline(cin, sikc.data[sikc.pos].alamat);
    cout << "Masukkan IPK: ";
    cin >> sikc.data[sikc.pos].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void perbaikanData(int p) {
    if (p < 0 || p > sikc.pos) {
        cout << "Data tidak ditemukan!\n";
        return;
    }
    system("cls");
    cout << "Masukkan Nama: ";
    getline(cin, sikc.data[p].nama);
    cout << "Masukkan Alamat: ";
    getline(cin, sikc.data[p].alamat);
    cout << "Masukkan IPK: ";
    cin >> sikc.data[p].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void tambahDataDefault() {
    if (sikc.pos >= 29) {
        cout << "Data sudah penuh! Tidak bisa menambah data default.\n";
        return;
    }
    sikc.pos++;
    sikc.data[sikc.pos].nim = "C050423025";
    sikc.data[sikc.pos].nama = "Argi Rizky Kurniawan";
    sikc.data[sikc.pos].alamat = "Banjarbaru";
    sikc.data[sikc.pos].ipk = 3.54;
    cout << "Data default berhasil ditambahkan!\n";
}

void tukar(mahasiswa &a, mahasiswa &b) {
    mahasiswa t = a;
    a = b;
    b = t;
}

void sortingAscending() {
    for (int i = 0; i < sikc.pos; i++) {
        for (int j = 0; j < sikc.pos - i; j++) {
            if (sikc.data[j].ipk > sikc.data[j + 1].ipk) {
                tukar(sikc.data[j], sikc.data[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan secara ascending berdasarkan IPK!\n";
}

void sortingDescending() {
    for (int i = 0; i < sikc.pos; i++) {
        for (int j = 0; j < sikc.pos - i; j++) {
            if (sikc.data[j].ipk < sikc.data[j + 1].ipk) {
                tukar(sikc.data[j], sikc.data[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan secara descending berdasarkan IPK!\n";
}

int main() {
    char pl;
    do {
        dMenu();
        pl = cin.get();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        switch (pl) {
            case '1':
                masukanData();
                break;
            case '2':
                system("cls");
                for (int i = 0; i <= sikc.pos; i++) {
                    cout << "Data Mahasiswa ke-" << (i + 1) << ":\n";
                    tampilkanData(i);
                    cout << "\n";
                }
                cin.get();
                break;
            case '3': {
                int index;
                system("cls");
                cout << "Masukkan indeks data yang ingin diperbaiki (dimulai dari 0): ";
                cin >> index;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                perbaikanData(index);
                break;
            }
            case '4':
                tambahDataDefault();
                break;
            case '5':
                system("cls");
                if (sikc.pos >= 0) {
                    sortingAscending();
                } else {
                    cout << "Data kosong. Masukkan data terlebih dahulu!\n";
                }
                cin.get();
                break;
            case '6':
                system("cls");
                if (sikc.pos >= 0) {
                    sortingDescending();
                } else {
                    cout << "Data kosong. Masukkan data terlebih dahulu!\n";
                }
                cin.get();
                break;
            case '7':
                break;
            default:
                system("cls");
                cout << "Pilihan Tidak Tersedia";
                cin.get();
                break;
        }
    } while (pl != '7');

    return 0;
}