// PROGRAM DATA MAHASISWA 
#include <iostream>

using namespace std;

// STRUCT NILAI DATA MAHASISWA 
struct Nilai {
    float absen, tugas, uts, uas, akhir;
    char huruf;
};

// STRUCT DATA MAHASISWA 
struct Mahasiswa {
    char npm[20];
    char nama[50];
    char fakultas[50];
    Nilai nilai;
};

// INISIASI MAKSIMAL DATA MAHASISWA YANG DAPAT DI SIMPAN 
const int MAX_MAHASISWA = 20;
Mahasiswa mahasiswa[MAX_MAHASISWA];
int jumlah = 0;


//FUNGSI MEMBANDINGKAN 2 NPM DALAM ARRAY
bool bandingkanNPM(const char npm1[], const char npm2[]) {
    int i = 0;
    while (npm1[i] != '\0' && npm2[i] != '\0') {
        if (npm1[i] != npm2[i]) {
            return false;
        }
        i++;
    }
    return (npm1[i] == '\0' && npm2[i] == '\0');
}

//FUNGSI MENENTUKAN NILAI MUTU MAHASISWA 
char hitungHuruf(float nilai) {
    if (nilai > 80) return 'A';
    else if (nilai > 70) return 'B';
    else if (nilai > 60) return 'C';
    else return 'D';
}

//FUNGSI INPUT DATA (MAKSIMAL 20 DATA) 
void inputData() {
    if (jumlah >= MAX_MAHASISWA) {
        cout << "Data penuh!\n";
        return;
    }
    
    cout << "\nMasukkan NPM: ";
    cin >> mahasiswa[jumlah].npm;
    cin.ignore();

    cout << "Masukkan Nama: ";
    cin.getline(mahasiswa[jumlah].nama, 50);

    cout << "Masukkan Fakultas: ";
    cin.getline(mahasiswa[jumlah].fakultas, 50);

    cout << "Masukkan Nilai Absen: ";
    cin >> mahasiswa[jumlah].nilai.absen;
    cout << "Masukkan Nilai Tugas: ";
    cin >> mahasiswa[jumlah].nilai.tugas;
    cout << "Masukkan Nilai UTS: ";
    cin >> mahasiswa[jumlah].nilai.uts;
    cout << "Masukkan Nilai UAS: ";
    cin >> mahasiswa[jumlah].nilai.uas;

    mahasiswa[jumlah].nilai.akhir = 0.1 * mahasiswa[jumlah].nilai.absen +
                                    0.2 * mahasiswa[jumlah].nilai.tugas +
                                    0.3 * mahasiswa[jumlah].nilai.uts +
                                    0.4 * mahasiswa[jumlah].nilai.uas;
    
    mahasiswa[jumlah].nilai.huruf = hitungHuruf(mahasiswa[jumlah].nilai.akhir);
    
    jumlah++;
    cout << "Data berhasil ditambahkan!\n\n";
}

//FUNGSI UNTUK MELIHAT DATA MAHASISWA YANG SUDAH DI SIMPAN
void tampilData() {
    if (jumlah == 0) {
        cout << "\nBelum ada data mahasiswa.\n\n";
        return;
    }
    cout << "==========================";
    cout << "\n=== Data Mahasiswa ===\n";
    cout << "==========================\n";

    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << (i + 1) << ":\n";
        cout << "NPM        : " << mahasiswa[i].npm << "\n";
        cout << "Nama       : " << mahasiswa[i].nama << "\n";
        cout << "Fakultas   : " << mahasiswa[i].fakultas << "\n";
        cout << "Nilai Absen: " << mahasiswa[i].nilai.absen << "\n";
        cout << "Nilai Tugas: " << mahasiswa[i].nilai.tugas << "\n";
        cout << "Nilai UTS  : " << mahasiswa[i].nilai.uts << "\n";
        cout << "Nilai UAS  : " << mahasiswa[i].nilai.uas << "\n";
        cout << "Nilai Akhir: " << mahasiswa[i].nilai.akhir << "\n";
        cout << "Huruf      : " << mahasiswa[i].nilai.huruf << "\n";
        cout << "----------------------\n";
    }
}


//FUNGSI UNTUK EDIT DATA MAHASISWA 
void editData() {
    char npm[20];
    cout << "\nMasukkan NPM mahasiswa yang ingin diedit: ";
    cin >> npm;

    for (int i = 0; i < jumlah; i++) {
        if (bandingkanNPM(mahasiswa[i].npm, npm)) {
            cout << "Masukkan Nilai Absen: ";
            cin >> mahasiswa[i].nilai.absen;
            cout << "Masukkan Nilai Tugas: ";
            cin >> mahasiswa[i].nilai.tugas;
            cout << "Masukkan Nilai UTS: ";
            cin >> mahasiswa[i].nilai.uts;
            cout << "Masukkan Nilai UAS: ";
            cin >> mahasiswa[i].nilai.uas;

            mahasiswa[i].nilai.akhir = 0.1 * mahasiswa[i].nilai.absen +
                                       0.2 * mahasiswa[i].nilai.tugas +
                                       0.3 * mahasiswa[i].nilai.uts +
                                       0.4 * mahasiswa[i].nilai.uas;
            mahasiswa[i].nilai.huruf = hitungHuruf(mahasiswa[i].nilai.akhir);

            cout << "Data berhasil diperbarui!\n\n";
            return;
        }
    }
    cout << "Mahasiswa dengan NPM " << npm << " tidak ditemukan!\n";
}


//FUNGSI UTAMA (TAMPILAN UTAMA SAAT KODE DI JALANKAN)
int main() {
    int pilihan;
    do {
        cout << "========================";
        cout << "\nPROGRAM DATA MAHASISWA";
        cout << "\n========================";
        cout << "\nMenu:\n\n";
        cout << "1. Input Data Mahasiswa\n";
        cout << "2. Tampil Data Mahasiswa\n";
        cout << "3. Edit Data Mahasiswa\n";
        cout << "4. Keluar\n";
        cout << "\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: inputData(); break;
            case 2: tampilData(); break;
            case 3: editData(); break;
            case 4: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);
    return 0;
}




//PROGRAM HITUNG DURASI RENTAL WARNET
#include <iostream>
#include <iomanip>

using namespace std;

// INISIASI TARIF PER DETIK
const int TARIF_PER_30_DETIK = 130;

// FUNGSI KONVERSI WAKTU MENJADI DETIK 
int konversiKeDetik(int jam, int menit, int detik) {
    return (jam * 3600) + (menit * 60) + detik;
}

// FUNGSI MENGHITUNG DURASI RENTAL
int hitungBiaya(int durasi) {
    return (durasi / 30) * TARIF_PER_30_DETIK;
}

//FUNGSI UTAMA (TAMPILAN UTAMA SAAT KODE DI JALANKAN)
int main() {
    int jamMulai, menitMulai, detikMulai;
    int jamSelesai, menitSelesai, detikSelesai;

    
    cout << "=============================================" << endl;
    cout << "           WARNET NET NET ZONET              " << endl;
    cout << "=============================================" << endl;


    cout << "\n Masukkan Waktu Mulai\n";
    cout << "------------------------------" << endl;
    cout << " Jam   : "; cin >> jamMulai;
    cout << " Menit : "; cin >> menitMulai;
    cout << " Detik : "; cin >> detikMulai;

    
    cout << "\n Masukkan Waktu Selesai\n";
    cout << "------------------------------" << endl;
    cout << " Jam   : "; cin >> jamSelesai;
    cout << " Menit : "; cin >> menitSelesai;
    cout << " Detik : "; cin >> detikSelesai;

    // Konversi waktu ke detik
    int totalDetikMulai = konversiKeDetik(jamMulai, menitMulai, detikMulai);
    int totalDetikSelesai = konversiKeDetik(jamSelesai, menitSelesai, detikSelesai);

    // PERKONDISIAN (MEMEASTIKAN WAKTU SELESAI TIDAK LEBIH KECIL DARI WAKTU MULAI)
    if (totalDetikSelesai < totalDetikMulai) {
        cout << "\n Waktu selesai tidak boleh lebih kecil dari waktu mulai!\n";
        return 1;
    }

    //HITUNG DURASI MENGGUNAKAN DETIK
    int durasiDetik = totalDetikSelesai - totalDetikMulai;

    // KONVERSI WAKTU DARI DETIK MENJADI JAM & MENIT 
    int durasiJam = durasiDetik / 3600;
    int sisaDetik = durasiDetik % 3600;
    int durasiMenit = sisaDetik / 60;
    int durasiSisaDetik = sisaDetik % 60;

    // HIUTNG BIAYA RENTAL
    int biaya = hitungBiaya(durasiDetik);

    // OUTPUT HASIL
    cout << "---------------------------------------------" << endl;
    cout << " Durasi rental: " 
        << setw(2) << setfill('0') << durasiJam << " jam " 
        << setw(2) << setfill('0') << durasiMenit << " menit " 
        << setw(2) << setfill('0') << durasiSisaDetik << " detik\n";
    cout << "---------------------------------------------" << endl;
    cout << " Total biaya  : Rp. " << biaya << ",-\n";
    cout << "=============================================" << endl;
    
    cout << " Terima kasih telah menggunakan layanan warnet kami!  :)\n";
    cout << "=============================================" << endl;
    return 0;
}





