#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Struct untuk pelanggan
struct Pelanggan {
    string nama;
    string email;
    string nomorTelepon;
    string alamat;
};

// Struct untuk perjalanan
struct Perjalanan {
    string namaPerjalanan;
    string tujuan;
    string tanggal;
    int harga;
};

// Struct untuk pemesanan
struct Pemesanan {
    Pelanggan pelanggan;
    Perjalanan perjalanan;
    string tanggalPemesanan;
    string status;
};

// Struct untuk pembayaran
struct Pembayaran {
    Pemesanan pemesanan;
    string tanggalPembayaran;
    int jumlah;
};

// Fungsi untuk membersihkan buffer input
void clearInputBuffer() {
    cin.clear(); // Membersihkan flag kesalahan
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan sisa baris
}

// Fungsi untuk create
void create(Pelanggan*& pelanggan, Perjalanan*& perjalanan, Pemesanan*& pemesanan, Pembayaran*& pembayaran, int& jumlahPelanggan, int& jumlahPerjalanan, int& jumlahPemesanan, int& jumlahPembayaran) {
    int pilihan;
    cout << "Create apa?" << endl;
    cout << "1. Pelanggan" << endl;
    cout << "2. Perjalanan" << endl;
    cout << "3. Pemesanan" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    clearInputBuffer();

    switch (pilihan) {
        case 1:
            cout << "Masukkan nama pelanggan: ";
            getline(cin, pelanggan[jumlahPelanggan].nama);
            cout << "Masukkan email pelanggan: ";
            getline(cin, pelanggan[jumlahPelanggan].email);
            cout << "Masukkan nomor telepon pelanggan: ";
            getline(cin, pelanggan[jumlahPelanggan].nomorTelepon);
            cout << "Masukkan alamat pelanggan: ";
            getline(cin, pelanggan[jumlahPelanggan].alamat);
            jumlahPelanggan++;
            break;
        case 2:
            cout << "Masukkan nama perjalanan: ";
            getline(cin, perjalanan[jumlahPerjalanan].namaPerjalanan);
            cout << "Masukkan tujuan perjalanan: ";
            getline(cin, perjalanan[jumlahPerjalanan].tujuan);
            cout << "Masukkan tanggal perjalanan: ";
            getline(cin, perjalanan[jumlahPerjalanan].tanggal);
            cout << "Masukkan harga perjalanan: ";
            cin >> perjalanan[jumlahPerjalanan].harga;
            clearInputBuffer();
            jumlahPerjalanan++;
            break;
        case 3:
            cout << "Masukkan nama pelanggan: ";
            getline(cin, pemesanan[jumlahPemesanan].pelanggan.nama);
            cout << "Masukkan nama perjalanan: ";
            getline(cin, pemesanan[jumlahPemesanan].perjalanan.namaPerjalanan);
            cout << "Masukkan tanggal pemesanan: ";
            getline(cin, pemesanan[jumlahPemesanan].tanggalPemesanan);
            cout << "Masukkan status pemesanan: ";
            getline(cin, pemesanan[jumlahPemesanan].status);
            jumlahPemesanan++;
            break;
        case 4:
            cout << "Masukkan nama pelanggan: ";
            getline(cin, pembayaran[jumlahPembayaran].pemesanan.pelanggan.nama);
            cout << "Masukkan nama perjalanan: ";
            getline(cin, pembayaran[jumlahPembayaran].pemesanan.perjalanan.namaPerjalanan);
            cout << "Masukkan tanggal pembayaran: ";
            getline(cin, pembayaran[jumlahPembayaran].tanggalPembayaran);
            cout << "Masukkan jumlah pembayaran: ";
            cin >> pembayaran[jumlahPembayaran].jumlah;
            clearInputBuffer();
            jumlahPembayaran++;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

// Fungsi untuk read
void read(Pelanggan* pelanggan, Perjalanan* perjalanan, Pemesanan* pemesanan, Pembayaran* pembayaran, int jumlahPelanggan, int jumlahPerjalanan, int jumlahPemesanan, int jumlahPembayaran) {
    int pilihan;
    cout << "Read apa?" << endl;
    cout << "1. Pelanggan" << endl;
    cout << "2. Perjalanan" << endl;
    cout << "3. Pemesanan" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
	clearInputBuffer();
	
    switch (pilihan) {
        case 1:
            for (int i = 0; i < jumlahPelanggan; i++) {
                cout << "Pelanggan ke-" << i + 1                 << ":" << endl;
                cout << "Nama pelanggan: " << pelanggan[i].nama << endl;
                cout << "Email pelanggan: " << pelanggan[i].email << endl;
                cout << "Nomor telepon pelanggan: " << pelanggan[i].nomorTelepon << endl;
                cout << "Alamat pelanggan: " << pelanggan[i].alamat << endl;
            }
            break;
        case 2:
            for (int i = 0; i < jumlahPerjalanan; i++) {
                cout << "Perjalanan ke-" << i + 1 << ":" << endl;
                cout << "Nama perjalanan: " << perjalanan[i].namaPerjalanan << endl;
                cout << "Tujuan perjalanan: " << perjalanan[i].tujuan << endl;
                cout << "Tanggal perjalanan: " << perjalanan[i].tanggal << endl;
                cout << "Harga perjalanan: " << perjalanan[i].harga << endl;
            }
            break;
        case 3:
            for (int i = 0; i < jumlahPemesanan; i++) {
                cout << "Pemesanan ke-" << i + 1 << ":" << endl;
                cout << "Nama pelanggan: " << pemesanan[i].pelanggan.nama << endl;
                cout << "Nama perjalanan: " << pemesanan[i].perjalanan.namaPerjalanan << endl;
                cout << "Tanggal pemesanan: " << pemesanan[i].tanggalPemesanan << endl;
                cout << "Status pemesanan: " << pemesanan[i].status << endl;
            }
            break;
        case 4:
            for (int i = 0; i < jumlahPembayaran; i++) {
                cout << "Pembayaran ke-" << i + 1 << ":" << endl;
                cout << "Nama pelanggan: " << pembayaran[i].pemesanan.pelanggan.nama << endl;
                cout << "Nama perjalanan: " << pembayaran[i].pemesanan.perjalanan.namaPerjalanan << endl;
                cout << "Tanggal pembayaran: " << pembayaran[i].tanggalPembayaran << endl;
                cout << "Jumlah pembayaran: " << pembayaran[i].jumlah << endl;
            }
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

// Fungsi untuk update
void update(Pelanggan*& pelanggan, Perjalanan*& perjalanan, Pemesanan*& pemesanan, Pembayaran*& pembayaran, int& jumlahPelanggan, int& jumlahPerjalanan, int& jumlahPemesanan, int& jumlahPembayaran) {
    int pilihan;
    cout << "Update apa?" << endl;
    cout << "1. Pelanggan" << endl;
    cout << "2. Perjalanan" << endl;
    cout << "3. Pemesanan" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    clearInputBuffer();

    switch (pilihan) {
        case 1:
            int indexPelanggan;
            cout << "Masukkan index pelanggan yang ingin diupdate: ";
            cin >> indexPelanggan;
            clearInputBuffer();

            if (indexPelanggan >= 0 && indexPelanggan < jumlahPelanggan) {
                cout << "Masukkan nama pelanggan baru: ";
                getline(cin, pelanggan[indexPelanggan].nama);
                cout << "Masukkan email pelanggan baru: ";
                getline(cin, pelanggan[indexPelanggan].email);
                cout << "Masukkan nomor telepon pelanggan baru: ";
                getline(cin, pelanggan[indexPelanggan].nomorTelepon);
                cout << "Masukkan alamat pelanggan baru: ";
                getline(cin, pelanggan[indexPelanggan].alamat);
            } else {
                cout << "Index pelanggan tidak valid" << endl;
            }
            break;
        case 2:
            int indexPerjalanan;
            cout << "Masukkan index perjalanan yang ingin diupdate: ";
            cin >> indexPerjalanan;
            clearInputBuffer();

            if (indexPerjalanan >= 0 && indexPerjalanan < jumlahPerjalanan) {
                cout << "Masukkan nama perjalanan baru: ";
                getline(cin, perjalanan[indexPerjalanan].namaPerjalanan);
                cout << "Masukkan tujuan perjalanan baru: ";
                getline(cin, perjalanan[indexPerjalanan].tujuan);
                cout << "Masukkan tanggal perjalanan baru: ";
                getline(cin, perjalanan[indexPerjalanan].tanggal);
                cout << "Masukkan harga perjalanan baru: ";
                cin >> perjalanan[indexPerjalanan].harga;
                clearInputBuffer();
            } else {
                cout << "Index perjalanan tidak valid" << endl;
            }
            break;
        case 3:
            int indexPemesanan;
            cout << "Masukkan index pemesanan yang ingin diupdate: ";
            cin >> indexPemesanan;
            clearInputBuffer();

            if (indexPemesanan >= 0 && indexPemesanan < jumlahPemesanan) {
                cout << "Masukkan nama pelanggan baru: ";
                getline(cin, pemesanan[indexPemesanan].pelanggan.nama);
                cout << "Masukkan nama perjalanan baru: ";
                getline(cin, pemesanan[indexPemesanan].perjalanan.namaPerjalanan);
                cout << "Masukkan tanggal pemesanan baru: ";
                getline(cin, pemesanan[indexPemesanan].tanggalPemesanan);
                cout << "Masukkan status pemesanan baru: ";
                getline(cin, pemesanan[indexPemesanan].status);
            } else {
                cout << "Index pemesanan tidak valid" << endl;
            }
            break;
        case 4:
            int indexPembayaran;
            cout << "Masukkan index pembayaran yang ingin diupdate: ";
            cin >> indexPembayaran;
            clearInputBuffer();

            if (indexPembayaran >= 0 && indexPembayaran < jumlahPembayaran) {
                cout << "Masukkan nama pelanggan baru: ";
                getline(cin, pembayaran[indexPembayaran].pemesanan.pelanggan.nama);
                cout << "Masukkan nama perjalanan baru: ";
                getline(cin, pembayaran[indexPembayaran].pemesanan.perjalanan.namaPerjalanan);
                cout << "Masukkan tanggal pembayaran baru: ";
                getline(cin, pembayaran[indexPembayaran].tanggalPembayaran);
                cout << "Masukkan jumlah pembayaran baru: ";
                cin >> pembayaran[indexPembayaran].jumlah;
                clearInputBuffer();
            } else {
                cout << "Index pembayaran tidak valid" << endl;
            }
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

// Fungsi untuk delete
void deleteItem(Pelanggan*& pelanggan, Perjalanan*& perjalanan, Pemesanan*& pemesanan, Pembayaran*& pembayaran, int& jumlahPelanggan, int& jumlahPerjalanan, int& jumlahPemesanan, int& jumlahPembayaran) {
    int pilihan;
    cout << "Delete apa?" << endl;
    cout << "1. Pelanggan" << endl;
    cout << "2. Perjalanan" << endl;
    cout << "3. Pemesanan" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    clearInputBuffer();

    switch (pilihan) {
        case 1:
            int indexPelanggan;
            cout << "Masukkan index pelanggan yang ingin dihapus: ";
            cin >> indexPelanggan;
            clearInputBuffer();
            for (int i = indexPelanggan; i < jumlahPelanggan - 1; i++) {
                pelanggan[i] = pelanggan[i + 1];
            }
            jumlahPelanggan--;
            break;
        case 2:
            int indexPerjalanan;
            cout << "Masukkan index perjalanan yang ingin dihapus: ";
            cin >> indexPerjalanan;
            clearInputBuffer();
            for (int i = indexPerjalanan; i < jumlahPerjalanan - 1; i++) {
                perjalanan[i] = perjalanan[i + 1];
            }
            jumlahPerjalanan--;
            break;
        case 3:
            int indexPemesanan;
            cout << "Masukkan index pemesanan yang ingin dihapus: ";
            cin >> indexPemesanan;
            clearInputBuffer();
            for (int i = indexPemesanan; i < jumlahPemesanan - 1; i++) {
                pemesanan[i] = pemesanan[i + 1];
            }
            jumlahPemesanan--;
            break;
        case 4:
            int indexPembayaran;
            cout << "Masukkan index pembayaran yang ingin dihapus: ";
            cin >> indexPembayaran;
            clearInputBuffer();
            for (int i = indexPembayaran; i < jumlahPembayaran - 1; i++) {
                pembayaran[i] = pembayaran[i + 1];
            }
            jumlahPembayaran--;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

int main() {
    int jumlahPelanggan = 0;
    int jumlahPerjalanan = 0;
    int jumlahPemesanan = 0;
    int jumlahPembayaran = 0;

    Pelanggan* pelanggan = new Pelanggan[100];
    Perjalanan* perjalanan = new Perjalanan[100];
    Pemesanan* pemesanan = new Pemesanan[100];
    Pembayaran* pembayaran = new Pembayaran[100];

    int pilihan;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "Masukkan pilihan: ";
        if (!(cin >> pilihan)) { 
            cout << "Input tidak valid. Masukkan angka." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearInputBuffer();
			continue; 
        }
        
        clearInputBuffer();

        switch (pilihan) {
            case 1:
                create(pelanggan, perjalanan, pemesanan, pembayaran, jumlahPelanggan, jumlahPerjalanan, jumlahPemesanan, jumlahPembayaran);
                break;
            case 2:
                read(pelanggan, perjalanan, pemesanan, pembayaran, jumlahPelanggan, jumlahPerjalanan, jumlahPemesanan, jumlahPembayaran);
                break;
            case 3:
                update(pelanggan, perjalanan, pemesanan, pembayaran, jumlahPelanggan, jumlahPerjalanan, jumlahPemesanan, jumlahPembayaran);
                break;
            case 4:
                deleteItem(pelanggan, perjalanan, pemesanan, pembayaran, jumlahPelanggan, jumlahPerjalanan, jumlahPemesanan, jumlahPembayaran);
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}
