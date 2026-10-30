#include <iostream>
using namespace std;

const int MAKS = 1000;

int hitungPanjang(char teks[]) {
    int panjang = 0;
    while (teks[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

bool apakahHuruf(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char keHurufBesar(char c) {
    if (c >= 'a' && c <= 'z') {
        return (char)(c - 'a' + 'A');
    }
    return c;
}

int posisiHuruf(char c) {
    return (c - 'A') + 1;
}

char hurufDariPosisi(int posisi) {
    return (char)('A' + (posisi - 1));
}

int main() {
    char pesan[MAKS];
    char hasil[MAKS];

    cout << "=== Sistem Sandi Alien ===" << endl;
    cout << "Masukkan pesan asli (hanya huruf A-Z, tanpa spasi): ";
    cin.getline(pesan, MAKS);

    int panjang = hitungPanjang(pesan);

    if (panjang == 0) {
        cout << "Pesan kosong." << endl;
        return 0;
    }

    for (int i = 0; i < panjang; i++) {
        if (!apakahHuruf(pesan[i])) {
            cout << "Pesan hanya boleh berisi huruf A-Z (tanpa spasi atau simbol)." << endl;
            return 0;
        }
        pesan[i] = keHurufBesar(pesan[i]);
    }

    hasil[0] = pesan[0];

    for (int i = 1; i < panjang; i++) {
        int nilaiSkrg = posisiHuruf(pesan[i]);
        int nilaiSblm = posisiHuruf(pesan[i - 1]);

        int nilaiBaru = nilaiSkrg + nilaiSblm;
        if (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26; 
        }

        hasil[i] = hurufDariPosisi(nilaiBaru);
    }
    hasil[panjang] = '\0';

    cout << "Pesan tersandi: " << hasil << endl;

    return 0;
}
