/*
    TLS - FASE 2
    Problem 1: Eliminasi Astronot dalam Lingkaran (Josephus Problem dengan K dinamis)

    Ketentuan:
    - Hanya menggunakan library <iostream>
    - Tidak ada function dari library lain; semua function dibuat manual
*/
#include <iostream>
using namespace std;

// Fungsi manual: mencari indeks astronot AKTIF (belum tereliminasi) berikutnya
// di dalam lingkaran, dimulai tepat setelah indeks 'dariIndeks'.
int astronotAktifBerikutnya(int dariIndeks, int N, bool tereliminasi[]) {
    int idx = dariIndeks;
    do {
        idx = (idx + 1) % N;
    } while (tereliminasi[idx]);
    return idx;
}

int main() {
    int N, K;

    cout << "=== Eliminasi Astronot dalam Lingkaran ===" << endl;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    if (N < 1) {
        cout << "Input tidak valid. N harus >= 1." << endl;
        return 0;
    }
    if (K < 2) {
        cout << "K tidak boleh kurang dari 2, nilai K disesuaikan menjadi 2." << endl;
        K = 2;
    }

    bool* tereliminasi = new bool[N];
    for (int i = 0; i < N; i++) {
        tereliminasi[i] = false;
    }

    int current = 0;     // indeks astronot nomor 1 -> perhitungan awal dimulai di sini
    int sisa = N;

    cout << "\nUrutan astronot yang dieliminasi: ";

    if (sisa == 1) {
        cout << "(tidak ada, hanya 1 astronot)";
    }

    while (sisa > 1) {
        // Majukan (K-1) langkah dari 'current' melewati astronot yang masih aktif.
        // Mengelilingi lingkaran penuh tidak mengubah hasil, jadi cukup (K-1) mod sisa langkah.
        int target = current;
        int jumlahLangkah = (K - 1) % sisa;
        for (int langkah = 1; langkah <= jumlahLangkah; langkah++) {
            target = astronotAktifBerikutnya(target, N, tereliminasi);
        }

        int nomorKeluar = target + 1;   // nomor astronot = indeks + 1
        cout << nomorKeluar;

        tereliminasi[target] = true;
        sisa = sisa - 1;

        if (sisa > 1) {
            cout << ", ";
        }

        // Aturan perubahan nilai K setelah eliminasi
        if (nomorKeluar % 2 == 0) {
            K = K + 2;   // nomor genap -> K bertambah 2
        } else {
            K = K - 1;   // nomor ganjil -> K berkurang 1
        }
        if (K < 2) {
            K = 2;       // K tidak boleh kurang dari 2
        }

        if (sisa >= 1) {
            current = astronotAktifBerikutnya(target, N, tereliminasi);
        }
    }

    cout << "\nAstronot yang bertahan (selamat): " << (current + 1) << endl;

    delete[] tereliminasi;
    return 0;
}
