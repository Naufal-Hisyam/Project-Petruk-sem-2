#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

struct Produk {
    string nama;
    int harga;
};

extern vector<Produk> daftarProduk;

void color(int color);
void gotoxy(int x, int y);
void tampilAsciiProduk();
void tambahProduk();
void tampilkanProduk();
void hapusProduk();

