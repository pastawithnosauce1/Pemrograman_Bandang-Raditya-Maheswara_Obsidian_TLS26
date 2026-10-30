#include <iostream>
using namespace std;

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

    int current = 0;   
    int sisa = N;

    cout << "\nUrutan astronot yang dieliminasi: ";

    if (sisa == 1) {
        cout << "(tidak ada, hanya 1 astronot)";
    }

    while (sisa > 1) {
        int target = current;
        int jumlahLangkah = (K - 1) % sisa;
        for (int langkah = 1; langkah <= jumlahLangkah; langkah++) {
            target = astronotAktifBerikutnya(target, N, tereliminasi);
        }

        int nomorKeluar = target + 1;  
        cout << nomorKeluar;

        tereliminasi[target] = true;
        sisa = sisa - 1;

        if (sisa > 1) {
            cout << ", ";
        }

        if (nomorKeluar % 2 == 0) {
            K = K + 2;  
        } else {
            K = K - 1;
        }
        if (K < 2) {
            K = 2;      
        }

        if (sisa >= 1) {
            current = astronotAktifBerikutnya(target, N, tereliminasi);
        }
    }

    cout << "\nAstronot yang bertahan (selamat): " << (current + 1) << endl;

    delete[] tereliminasi;
    return 0;
}
