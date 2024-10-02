#include <iostream>
#include <string>
#include <limits>
#include <cstddef>

using namespace std;

struct Pelanggan {
    string nama;
    string email;
    string nomorTelepon;
    string alamat;
    Pelanggan* next;
};

struct Perjalanan {
    string namaPerjalanan;
    string tujuan;
    string tanggal;
    int harga;
    Perjalanan* next;
};

struct Pemesanan {
    Pelanggan pelanggan;
    Perjalanan perjalanan;
    string tanggalPemesanan;
    string status;
    Pemesanan* next;
};

struct Pembayaran {
    Pemesanan pemesanan;
    string tanggalPembayaran;
    int jumlah;
    Pembayaran* next;
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void create(Pelanggan*& headPelanggan, Perjalanan*& headPerjalanan, Pemesanan*& headPemesanan, Pembayaran*& headPembayaran) {
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
        case 1: {
            Pelanggan* newNode = new Pelanggan;
            cout << "Masukkan nama pelanggan: ";
            getline(cin, newNode->nama);
            cout << "Masukkan email pelanggan: ";
            getline(cin, newNode->email);
            cout << "Masukkan nomor telepon pelanggan: ";
            getline(cin, newNode->nomorTelepon);
            cout << "Masukkan alamat pelanggan: ";
            getline(cin, newNode->alamat);
            newNode->next = headPelanggan;
            headPelanggan = newNode;
            break;
        }
        case 2: {
            Perjalanan* newNode = new Perjalanan;
            cout << "Masukkan nama perjalanan: ";
            getline(cin, newNode->namaPerjalanan);
            cout << "Masukkan tujuan perjalanan: ";
            getline(cin, newNode->tujuan);
            cout << "Masukkan tanggal perjalanan: ";
            getline(cin, newNode->tanggal);
            cout << "Masukkan harga perjalanan: ";
            cin >> newNode->harga;
            clearInputBuffer();
            newNode->next = headPerjalanan;
            headPerjalanan = newNode;
            break;
        }
        case 3: {
            Pemesanan* newNode = new Pemesanan;
            cout << "Masukkan nama pelanggan: ";
            getline(cin, newNode->pelanggan.nama);
            cout << "Masukkan nama perjalanan: ";
            getline(cin, newNode->perjalanan.namaPerjalanan);
            cout << "Masukkan tanggal pemesanan: ";
            getline(cin, newNode->tanggalPemesanan);
            cout << "Masukkan status pemesanan: ";
            getline(cin, newNode->status);
            newNode->next = headPemesanan;
            headPemesanan = newNode;
            break;
        }
        case 4: {
            Pembayaran* newNode = new Pembayaran;
            cout << "Masukkan nama pelanggan: ";
            getline(cin, newNode->pemesanan.pelanggan.nama);
            cout << "Masukkan nama perjalanan: ";
            getline(cin, newNode->pemesanan.perjalanan.namaPerjalanan);
            cout << "Masukkan tanggal pembayaran: ";
            getline(cin, newNode->tanggalPembayaran);
            cout << "Masukkan jumlah pembayaran: ";
            cin >> newNode->jumlah;
            clearInputBuffer();
            newNode->next = headPembayaran;
            headPembayaran = newNode;
            break;
        }
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

void read(Pelanggan* headPelanggan, Perjalanan* headPerjalanan, Pemesanan* headPemesanan, Pembayaran* headPembayaran) {
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
        case 1: {
            Pelanggan* temp = headPelanggan;
            while (temp != NULL) {
                cout << "Nama Pelanggan: " << temp->nama << endl;
                cout << "Email Pelanggan: " << temp->email << endl;
                cout << "Nomor Telepon Pelanggan: " << temp->nomorTelepon << endl;
                cout << "Alamat Pelanggan: " << temp->alamat << endl;
                temp = temp->next;
            }
            break;
        }
        case 2: {
            Perjalanan* temp = headPerjalanan;
            while (temp != NULL) {
                cout << "Nama Perjalanan: " << temp->namaPerjalanan << endl;
                cout << "Tujuan Perjalanan: " << temp->tujuan << endl;
                cout << "Tanggal Perjalanan: " << temp->tanggal << endl;
                cout << "Harga Perjalanan: " << temp->harga << endl;
                temp = temp->next;
            }
            break;
        }
        case 3: {
            Pemesanan* temp = headPemesanan;
            while (temp != NULL) {
                cout << "Nama Pelanggan: " << temp->pelanggan.nama << endl;
                cout << "Nama Perjalanan: " << temp->perjalanan.namaPerjalanan << endl;
                cout << "Tanggal Pemesanan: " << temp->tanggalPemesanan << endl;
                cout << "Status Pemesanan: " << temp->status << endl;
                temp = temp->next;
            }
            break;
        }
        case 4: {
            Pembayaran* temp = headPembayaran;
            while (temp != NULL) {
                cout << "Nama Pelanggan: " << temp->pemesanan.pelanggan.nama << endl;
                cout << "Nama Perjalanan: " << temp->pemesanan.perjalanan.namaPerjalanan << endl;
                cout << "Tanggal Pembayaran: " << temp->tanggalPembayaran << endl;
                cout << "Jumlah Pembayaran: " << temp->jumlah << endl;
                temp = temp->next;
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

void update(Pelanggan*& headPelanggan, Perjalanan*& headPerjalanan, Pemesanan*& headPemesanan, Pembayaran*& headPembayaran) {
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
        case 1: {
            Pelanggan* temp = headPelanggan;
            string namaPelanggan;
            cout << "Masukkan nama pelanggan yang ingin diupdate: ";
            getline(cin, namaPelanggan);
            while (temp != NULL) {
                if (temp->nama == namaPelanggan) {
                    cout << "Masukkan nama baru: ";
                    getline(cin, temp->nama);
                    cout << "Masukkan email baru: ";
                    getline(cin, temp->email);
                    cout << "Masukkan nomor telepon baru: ";
                    getline(cin, temp->nomorTelepon);
                    cout << "Masukkan alamat baru: ";
                    getline(cin, temp->alamat);
                    break;
                }
                temp = temp->next;
            }
            break;
        }
        
        
        
        case 2: {
            int indexPerjalanan;
            cout << "Masukkan index perjalanan yang ingin diupdate: ";
            cin >> indexPerjalanan;
            clearInputBuffer();

            Perjalanan* temp = headPerjalanan;
            int i = 0;
            while (temp != NULL) {
                if (i == indexPerjalanan) {
                    cout << "Masukkan nama perjalanan baru: ";
                    getline(cin, temp->namaPerjalanan);
                    cout << "Masukkan tujuan perjalanan baru: ";
                    getline(cin, temp->tujuan);
                    cout << "Masukkan tanggal perjalanan baru: ";
                    getline(cin, temp->tanggal);
                    cout << "Masukkan harga perjalanan baru: ";
                    cin >> temp->harga;
                    clearInputBuffer();
                    return;
                }
                temp = temp->next;
                i++;
            }
            cout << "Index perjalanan tidak valid" << endl;
            break;
        }
        case 3: {
            int indexPemesanan;
            cout << "Masukkan index pemesanan yang ingin diupdate: ";
            cin >> indexPemesanan;
            clearInputBuffer();

            Pemesanan* temp = headPemesanan;
            int i = 0;
            while (temp != NULL) {
                if (i == indexPemesanan) {
                    cout << "Masukkan nama pelanggan baru: ";
                    getline(cin, temp->pelanggan.nama);
                    cout << "Masukkan nama perjalanan baru: ";
                    getline(cin, temp->perjalanan.namaPerjalanan);
                    cout << "Masukkan tanggal pemesanan baru: ";
                    getline(cin, temp->tanggalPemesanan);
                    cout << "Masukkan status pemesanan baru: ";
                    getline(cin, temp->status);
                    return;
                }
                temp = temp->next;
                i++;
            }
            cout << "Index pemesanan tidak valid" << endl;
            break;
        }
        case 4: {
            int indexPembayaran;
            cout << "Masukkan index pembayaran yang ingin diupdate: ";
            cin >> indexPembayaran;
            clearInputBuffer();

            Pembayaran* temp = headPembayaran;
            int i = 0;
            while (temp != NULL) {
                if (i == indexPembayaran) {
                    cout << "Masukkan nama pelanggan baru: ";
                    getline(cin, temp->pemesanan.pelanggan.nama);
                    cout << "Masukkan nama perjalanan baru: ";
                    getline(cin, temp->pemesanan.perjalanan.namaPerjalanan);
                    cout << "Masukkan tanggal pembayaran baru: ";
                    getline(cin, temp->tanggalPembayaran);
                    cout << "Masukkan jumlah pembayaran baru: ";
                    cin >> temp->jumlah;
                    clearInputBuffer();
                    return;
                }
                temp = temp->next;
                i++;
            }
            cout << "Index pembayaran tidak valid" << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

void deleteItem(Pelanggan*& headPelanggan, Perjalanan*& headPerjalanan, Pemesanan*& headPemesanan, Pembayaran*& headPembayaran) {
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
        case 1: {
            int indexPelanggan;
            cout << "Masukkan index pelanggan yang ingin dihapus: ";
            cin >> indexPelanggan;
            clearInputBuffer();

            if (indexPelanggan == 0) {
                Pelanggan* temp = headPelanggan;
                headPelanggan = headPelanggan->next;
                delete temp;
            } else {
                Pelanggan* temp = headPelanggan;
                int i = 0;
                while (temp != NULL) {
                    if (i == indexPelanggan - 1) {
                        Pelanggan* temp = temp->next;
                        temp->next = temp->next->next;
                        delete temp;
                        return;
                    }
                    temp = temp->next;
                    i++;
                }
            }
            cout << "Index pelanggan tidak valid" << endl;
            break;
        }
        case 2: {
            int indexPerjalanan;
            cout << "Masukkan index perjalanan yang ingin dihapus: ";
            cin >> indexPerjalanan;
            clearInputBuffer();

            if (indexPerjalanan == 0) {
                Perjalanan* temp = headPerjalanan;
                headPerjalanan = headPerjalanan->next;
                delete temp;
            } else {
                Perjalanan* temp = headPerjalanan;
                int i = 0;
                while (temp != NULL) {
                    if (i == indexPerjalanan - 1) {
                        Perjalanan* temp = temp->next;
                        temp->next = temp->next->next;
                        delete temp;
                        return;
                    }
                    temp = temp->next;
                    i++;
                }
            }
            cout << "Index perjalanan tidak valid" << endl;
            break;
        }
        case 3: {
            int indexPemesanan;
            cout << "Masukkan index pemesanan yang ingin dihapus: ";
            cin >> indexPemesanan;
            clearInputBuffer();

            if (indexPemesanan == 0) {
                Pemesanan* temp = headPemesanan;
                headPemesanan = headPemesanan->next;
                delete temp;
            } else {
                Pemesanan* temp = headPemesanan;
                int i = 0;
                while (temp != NULL) {
                    if (i == indexPemesanan - 1) {
                        Pemesanan* temp = temp->next;
                        temp->next = temp->next->next;
                        delete temp;
                        return;
                    }
                    temp = temp->next;
                    i++;
                }
            }
            cout << "Index pemesanan tidak valid" << endl;
            break;
        }
        case 4: {
            int indexPembayaran;
            cout << "Masukkan index pembayaran yang ingin dihapus: ";
            cin >> indexPembayaran;
            clearInputBuffer();

            if (indexPembayaran == 0) {
                Pembayaran* temp = headPembayaran;
                headPembayaran = headPembayaran->next;
                delete temp;
            } else {
                Pembayaran* temp = headPembayaran;
                int i = 0;
                while (temp != NULL) {
                    if (i == indexPembayaran - 1) {
                        Pembayaran* temp = temp->next;
                        temp->next = temp->next->next;
                        delete temp;
                        return;
                    }
                    temp = temp->next;
                    i++;
                }
            }
            cout << "Index pembayaran tidak valid" << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

int main() {
    Pelanggan* headPelanggan = NULL;
    Perjalanan* headPerjalanan = NULL;
    Pemesanan* headPemesanan = NULL;
    Pembayaran* headPembayaran = NULL;

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
                create(headPelanggan, headPerjalanan, headPemesanan, headPembayaran);
                break;
            case 2:
                read(headPelanggan, headPerjalanan, headPemesanan, headPembayaran);
                break;
            case 3:
                update(headPelanggan, headPerjalanan, headPemesanan, headPembayaran);
                break;
            case 4:
                deleteItem(headPelanggan, headPerjalanan, headPemesanan, headPembayaran);
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}
