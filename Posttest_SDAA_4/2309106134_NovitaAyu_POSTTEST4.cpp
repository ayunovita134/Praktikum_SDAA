#include <iostream>
#include <string>
#include <limits>
#include <cstddef>

using namespace std;

// Struktur Pelanggan
struct Pelanggan {
    string nama;
    string email;
    string nomorTelepon;
    string alamat;
    Pelanggan* next;
};

// Struktur Perjalanan
struct Perjalanan {
    string namaPerjalanan;
    string tujuan;
    string tanggal;
    int harga;
    Perjalanan* next;
};

// Struktur Pemesanan
struct Pemesanan {
    Pelanggan pelanggan;
    Perjalanan perjalanan;
    string tanggalPemesanan;
    string status;
    Pemesanan* next;
};

// Struktur Pembayaran
struct Pembayaran {
    Pemesanan pemesanan;
    string tanggalPembayaran;
    int jumlah;
    Pembayaran* next;
};

// Struktur Stack
struct Stack {
    int data;
    Stack* next;
};

// Struktur Queue
struct Queue {
    int data;
    Queue* next;
};

// Fungsi untuk membersihkan input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi untuk membuat node baru pada stack
Stack* createStackNode(int data) {
    Stack* newNode = new Stack;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk membuat node baru pada queue
Queue* createQueueNode(int data) {
    Queue* newNode = new Queue;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk memasukkan data ke dalam stack
void push(Stack*& head, int data) {
    Stack* newNode = createStackNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Fungsi untuk mengeluarkan data dari stack
void pop(Stack*& head) {
    if (head == NULL) {
        cout << "Stack kosong" << endl;
    } else {
        Stack* temp = head;
        head = head->next;
        delete temp;
    }
}

// Fungsi untuk memasukkan data ke dalam queue
void enqueue(Queue*& head, Queue*& tail, int data) {
    Queue* newNode = createQueueNode(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Fungsi untuk mengeluarkan data dari queue
void dequeue(Queue*& head, Queue*& tail) {
    if (head == NULL) {
        cout << "Queue kosong" << endl;
    } else {
        Queue* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    }
}

// Fungsi untuk membuat data
void create(Pelanggan*& headPelanggan, Perjalanan*& headPerjalanan, Pemesanan*& headPemesanan, Pembayaran*& headPembayaran, Stack*& headStack, Queue*& headQueue, Queue*& tailQueue) {
    int pilihan;
    cout << "Create apa?" << endl;
    cout << "1. Pelanggan" << endl;
    cout << "2. Perjalanan" << endl;
    cout << "3. Pemesanan" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "5. Stack" << endl;
    cout << "6. Queue" << endl;
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
        case 5: {
            int data;
            cout << "Masukkan data untuk stack: ";
            cin >> data;
            clearInputBuffer();
            push(headStack, data);
            break;
        }
        case 6: {
            int data;
            cout << "Masukkan data untuk queue: ";
            cin >> data;
            clearInputBuffer();
            enqueue(headQueue, tailQueue, data);
            break;
        }
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

// Fungsi untuk membaca data
void read(Pelanggan* headPelanggan, Perjalanan* headPerjalanan, Pemesanan* headPemesanan, Pembayaran* headPembayaran, Stack* headStack, Queue* headQueue) {
    int pilihan;
    cout << "Read apa?" << endl;
    cout << "1. Pelanggan" << endl;
    cout << "2. Perjalanan" << endl;
    cout << "3. Pemesanan" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "5. Stack" << endl;
    cout << "6. Queue" << endl;
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
        case 5: {
            Stack* temp = headStack;
            while (temp != NULL) {
                cout << "Data pada Stack: " << temp->data << endl;
                temp = temp->next;
            }
            break;
        }
        case 6: {
            Queue* temp = headQueue;
            while (temp != NULL) {
                cout << "Data pada Queue: " << temp->data << endl;
                temp = temp->next;
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

void update(Pelanggan* headPelanggan, Perjalanan* headPerjalanan, Pemesanan* headPemesanan, Pembayaran* headPembayaran) {
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
            string nama;
            cout << "Masukkan nama pelanggan yang ingin diupdate: ";
            getline(cin, nama);
            
            Pelanggan* temp = headPelanggan;
            while (temp != NULL) {
                if (temp->nama == nama) {
                    cout << "Masukkan nama baru: ";
                    getline(cin, temp->nama);
                    cout << "Masukkan email baru: ";
                    getline(cin, temp->email);
                    cout << "Masukkan nomor telepon baru: ";
                    getline(cin, temp->nomorTelepon);
                    cout << "Masukkan alamat baru: ";
                    getline(cin, temp->alamat);
                    cout << "Data pelanggan berhasil diupdate." << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Pelanggan dengan nama " << nama << " tidak ditemukan." << endl;
            break;
        }
        case 2: {
            string namaPerjalanan;
            cout << "Masukkan nama perjalanan yang ingin diupdate: ";
            getline(cin, namaPerjalanan);
            
            Perjalanan* temp = headPerjalanan;
            while (temp != NULL) {
                if (temp->namaPerjalanan == namaPerjalanan) {
                    cout << "Masukkan nama perjalanan baru: ";
                    getline(cin, temp->namaPerjalanan);
                    cout << "Masukkan tujuan baru: ";
                    getline(cin, temp->tujuan);
                    cout << "Masukkan tanggal baru: ";
                    getline(cin, temp->tanggal);
                    cout << "Masukkan harga baru: ";
                    cin >> temp->harga;
                    clearInputBuffer();
                    cout << "Data perjalanan berhasil diupdate." << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Perjalanan dengan nama " << namaPerjalanan << " tidak ditemukan." << endl;
            break;
        }
        case 3: {
            string namaPelanggan, namaPerjalanan;
            cout << "Masukkan nama pelanggan dari pemesanan yang ingin diupdate: ";
            getline(cin, namaPelanggan);
            cout << "Masukkan nama perjalanan yang ingin diupdate: ";
            getline(cin, namaPerjalanan);
            
            Pemesanan* temp = headPemesanan;
            while (temp != NULL) {
                if (temp->pelanggan.nama == namaPelanggan && temp->perjalanan.namaPerjalanan == namaPerjalanan) {
                    cout << "Masukkan nama perjalanan baru: ";
                    getline(cin, temp->perjalanan.namaPerjalanan);
                    cout << "Masukkan tanggal pemesanan baru: ";
                    getline(cin, temp->tanggalPemesanan);
                    cout << "Masukkan status baru: ";
                    getline(cin, temp->status);
                    cout << "Data pemesanan berhasil diupdate." << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Pemesanan dengan pelanggan " << namaPelanggan << " dan perjalanan " << namaPerjalanan << " tidak ditemukan." << endl;
            break;
        }

        case 4: {
            string namaPelanggan, namaPerjalanan;
            cout << "Masukkan nama pelanggan dari pembayaran yang ingin diupdate: ";
            getline(cin, namaPelanggan);
            cout << "Masukkan nama perjalanan yang ingin diupdate: ";
            getline(cin, namaPerjalanan);
            
            Pembayaran* temp = headPembayaran;
            while (temp != NULL) {
                if (temp->pemesanan.pelanggan.nama == namaPelanggan && temp->pemesanan.perjalanan.namaPerjalanan == namaPerjalanan) {
                    cout << "Masukkan jumlah pembayaran baru: ";
                    cin >> temp->jumlah;
                    clearInputBuffer();
                    cout << "Masukkan tanggal pembayaran baru: ";
                    getline(cin, temp->tanggalPembayaran);
                    cout << "Data pembayaran berhasil diupdate." << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Pembayaran dengan pelanggan " << namaPelanggan << " dan perjalanan " << namaPerjalanan << " tidak ditemukan." << endl;
            break;
        }

        default:
            cout << "Pilihan tidak valid." << endl;
    }
}

// Fungsi untuk menghapus data
void deleteItem(Pelanggan*& headPelanggan, Perjalanan*& headPerjalanan, Pemesanan*& headPemesanan, Pembayaran*& headPembayaran, Stack*& headStack, Queue*& headQueue, Queue*& tailQueue) {
    int pilihan;
    cout << "Delete apa?" << endl;
    cout << "1. Pelanggan" << endl;
    cout << "2. Perjalanan" << endl;
    cout << "3. Pemesanan" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "5. Stack" << endl;
    cout << "6. Queue" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    clearInputBuffer();

    switch (pilihan) {
        case 1: {
            string namaCari;
            cout << "Masukkan nama pelanggan yang ingin dihapus: ";
            getline(cin, namaCari);
            Pelanggan* temp = headPelanggan;
            Pelanggan* prev = NULL;
            while (temp != NULL) {
                if (temp->nama == namaCari) {
                    if (prev == NULL) {
                        headPelanggan = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    cout << "Pelanggan berhasil dihapus." << endl;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "Pelanggan tidak ditemukan." << endl;
            break;
        }
        case 2: {
            string namaCari;
            cout << "Masukkan nama perjalanan yang ingin dihapus: ";
            getline(cin, namaCari);
            Perjalanan* temp = headPerjalanan;
            Perjalanan* prev = NULL;
            while (temp != NULL) {
                if (temp->namaPerjalanan == namaCari) {
                    if (prev == NULL) {
                        headPerjalanan = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    cout << "Perjalanan berhasil dihapus." << endl;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "Perjalanan tidak ditemukan." << endl;
            break;
        }
        case 3: {
            string namaCari;
            cout << "Masukkan nama pelanggan dari pemesanan yang ingin dihapus: ";
            getline(cin, namaCari);
            Pemesanan* temp = headPemesanan;
            Pemesanan* prev = NULL;
            while (temp != NULL) {
                if (temp->pelanggan.nama == namaCari) {
                    if (prev == NULL) {
                        headPemesanan = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    cout << "Pemesanan berhasil dihapus." << endl;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "Pemesanan tidak ditemukan." << endl;
            break;
        }
        case 4: {
            string namaCari;
            cout << "Masukkan nama pelanggan dari pembayaran yang ingin dihapus: ";
            getline(cin, namaCari);
            Pembayaran* temp = headPembayaran;
            Pembayaran* prev = NULL;
            while (temp != NULL) {
                if (temp->pemesanan.pelanggan.nama == namaCari) {
                    if (prev == NULL) {
                        headPembayaran = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    cout << "Pembayaran berhasil dihapus." << endl;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "Pembayaran tidak ditemukan." << endl;
            break;
        }
        case 5: {
            pop(headStack);
            break;
        }
        case 6: {
            dequeue(headQueue, tailQueue);
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
    Stack* headStack = NULL;
    Queue* headQueue = NULL;
    Queue* tailQueue = NULL;

    int pilihan;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        clearInputBuffer();

        switch (pilihan) {
            case 1:
                create(headPelanggan, headPerjalanan, headPemesanan, headPembayaran, headStack, headQueue, tailQueue);
                break;
            case 2:
                read(headPelanggan, headPerjalanan, headPemesanan, headPembayaran, headStack, headQueue);
                break;
            case 3:
                update(headPelanggan, headPerjalanan, headPemesanan, headPembayaran);
                break;
            case 4:
                deleteItem(headPelanggan, headPerjalanan, headPemesanan, headPembayaran, headStack, headQueue, tailQueue);
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}