#include "produk.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

// Implementasi color
void color(int colorId) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorId);
}

void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

vector<Produk> daftarProduk;

void tampilAsciiProduk(){
	system("cls");
    color(14);
    gotoxy(23, 16);cout << " __| |____________________________________________| |__";
    gotoxy(23, 17);cout << "(__   ____________________________________________   __)";
    gotoxy(23, 18);cout << "   | |                                            | |";
    gotoxy(23, 19);cout << "   | |          # APLIKASI MESIN KASIR #          | |";
    gotoxy(23, 20);cout << " __| |____________________________________________| |__";
    gotoxy(23, 21);cout << "(__   ____________________________________________   __)";
    gotoxy(23, 22);cout << "   | |                                            | |";
    gotoxy(23, 23);cout << "   | |              Daftar Produk                 | |";
    gotoxy(23, 24);cout << " __| |____________________________________________| |__";
    gotoxy(23, 25);cout << "(__   ____________________________________________   __)";
    gotoxy(23, 26);cout << "   | |                                            | |";
    gotoxy(23, 27);cout << "   | |                                            | |";
    gotoxy(23, 28);cout << "   | |                                            | |";
    gotoxy(23, 29);cout << "   | |                                            | |";
    gotoxy(23, 30);cout << "   | |                                            | |";
    gotoxy(23, 31);cout << "   | |                                            | |";
    gotoxy(23, 32);cout << " __| |____________________________________________| |__";
    gotoxy(23, 33);cout << "(__   ____________________________________________   __)";
    gotoxy(23, 34);cout << "   | |                                            | |";

    cout << endl << endl;
}

void tambahProduk(){
    tampilAsciiProduk();
    
    Produk p;

    gotoxy(30, 26);
    cout << "Masukkan nama produk: "; 
    cin.ignore();
    getline(cin, p.nama);

    gotoxy(30, 27);
    cout << "Masukkan harga produk: "; 
    cin >> p.harga;

    daftarProduk.push_back(p);
    gotoxy(30, 29);
    cout << "Produk ditambah!" << endl;

    gotoxy(30, 30);
    cout << "Tekan tombol apa saja untuk melanjutkan.";
    _getch();

}

void tampilkanProduk(){
    tampilAsciiProduk();

    gotoxy(30, 26);
    cout << "Daftar Produk:" << endl;

    for (int i = 0; i < (int)daftarProduk.size(); i++) {
        gotoxy(30, 27 + i);
        cout << i + 1 << ". " << daftarProduk[i].nama << " - " << daftarProduk[i].harga << endl;
    }

    cout << endl;

    gotoxy(30, 27 + (int)daftarProduk.size()); 
    cout << "Tekan tombol apa saja untuk melanjutkan.";
    _getch();
}

void hapusProduk(){
    tampilAsciiProduk();

    gotoxy(30, 26);
    cout << "Pilih nomor produk yang ingin dihapus: "; 
    int index;
    cin >> index;

    if (index > 0 && index <= (int)daftarProduk.size()) {
        daftarProduk.erase(daftarProduk.begin() + index - 1);
        gotoxy(30, 27);
        cout << "Produk dihapus!" << endl;
    } else {
        gotoxy(30, 27);
        cout << "Pilihan invalid!" << endl;
    }

    gotoxy(30, 29);
    cout << "Tekan tombol apa saja untuk melanjutkan.";
    _getch();

}

