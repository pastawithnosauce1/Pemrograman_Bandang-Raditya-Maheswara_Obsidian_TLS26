/*
    TLS - FASE 2
    Problem 2: Sistem Sandi Pergeseran Huruf

    Aturan sandi:
    - Huruf pertama tidak berubah.
    - Huruf berikutnya digeser sebanyak nilai huruf ASLI yang berada tepat sebelumnya
      (A = 1, B = 2, ..., Z = 26). Jika melewati Z, hitungan kembali ke A.

    Ketentuan:
    - Hanya menggunakan library <iostream>
    - Tidak ada function dari library lain; semua function dibuat manual
*/
#include <iostream>
using namespace std;

const int MAKS = 1000;

// Fungsi manual: menghitung panjang teks (pengganti strlen)
int hitungPanjang(char teks[]) {
    int panjang = 0;
    while (teks[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

// Fungsi manual: mengecek apakah karakter adalah huruf (A-Z atau a-z)
bool apakahHuruf(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Fungsi manual: mengubah huruf kecil menjadi huruf besar (pengganti toupper)
char keHurufBesar(char c) {
    if (c >= 'a' && c <= 'z') {
        return (char)(c - 'a' + 'A');
    }
    return c;
}

// Fungsi manual: posisi huruf besar dalam alfabet (A = 1, ..., Z = 26)
int posisiHuruf(char c) {
    return (c - 'A') + 1;
}

// Fungsi manual: mengubah posisi (1-26) kembali menjadi huruf besar
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

    // Validasi: pesan hanya boleh berisi huruf; sekaligus ubah ke huruf besar
    for (int i = 0; i < panjang; i++) {
        if (!apakahHuruf(pesan[i])) {
            cout << "Pesan hanya boleh berisi huruf A-Z (tanpa spasi atau simbol)." << endl;
            return 0;
        }
        pesan[i] = keHurufBesar(pesan[i]);
    }

    // Huruf pertama tidak berubah
    hasil[0] = pesan[0];

    // Huruf ke-2 dan seterusnya: geser sebanyak nilai huruf ASLI sebelumnya
    for (int i = 1; i < panjang; i++) {
        int nilaiSkrg = posisiHuruf(pesan[i]);
        int nilaiSblm = posisiHuruf(pesan[i - 1]);

        int nilaiBaru = nilaiSkrg + nilaiSblm;
        if (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;   // melewati Z -> kembali ke A
        }

        hasil[i] = hurufDariPosisi(nilaiBaru);
    }
    hasil[panjang] = '\0';

    cout << "Pesan tersandi: " << hasil << endl;

    return 0;
}
