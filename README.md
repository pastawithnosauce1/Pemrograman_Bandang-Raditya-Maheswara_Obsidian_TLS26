# Pemrograman_Bandang-Raditya-Maheswara_Obsidian_TLS26

## Ringkasan Masalah

Masalah Pertama: Eliminasi Astronot dalam Lingkaran

N astronot berdiri melingkar dengan nomor 1 sampai N. Hitungan dimulai dari astronot nomor 1, astronot yang mendapat hitungan ke-K dieliminasi, lalu hitungan berikutnya dimulai dari astronot tepat setelahnya. Setelah setiap eliminasi, nilai K berubah: bertambah 2 jika nomor yang dieliminasi genap, berkurang 1 jika ganjil, dan tidak boleh kurang dari 2. Program menampilkan urutan astronot yang dieliminasi dan astronot terakhir yang bertahan.

Masalah Kedua: Sistem Sandi Pergeseran Huruf

Huruf pertama pesan tidak berubah, sedangkan setiap huruf berikutnya digeser sebanyak nilai huruf asli yang berada tepat sebelumnya (A = 1, B = 2, ..., Z = 26). Jika melewati Z, hitungan kembali ke A. Contoh: `ALIENS` → `AMUNSG`.

Cara Menjalankan
Dibutuhkan compiler C++, misalnya `g++`.
```bash
g++ problem1.cpp -o problem1
./problem1
g++ problem2.cpp -o problem2
./problem2
```
Di Windows (CMD/PowerShell), jalankan `problem1.exe` dan `problem2.exe`.

### Contoh Keluaran
**Problem 1** (N = 5, K = 2):
```
Urutan astronot yang dieliminasi: 2, 1, 5, 4
Astronot yang bertahan (selamat): 3
```
**Problem 2** (pesan `ALIENS`):
```
Pesan tersandi: AMUNSG
```

## Ketentuan Implementasi (Fase 2)

- Hanya menggunakan library `<iostream>`.
- Tidak menggunakan function dari library; function yang dibutuhkan dibuat sendiri (user-defined function).
