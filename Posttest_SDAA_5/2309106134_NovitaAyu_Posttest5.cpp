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

struct Stack {
    int data;
    Stack* next;
};

struct Queue {
    int data;
    Queue* next;
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

Stack* createStackNode(int data) {
    Stack* newNode = new Stack;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueueNode(int data) {
    Queue* newNode = new Queue;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack*& head, int data) {
    Stack* newNode = createStackNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void pop(Stack*& head) {
    if (head == NULL) {
        cout << "Stack kosong" << endl;
    } else {
        Stack* temp = head;
        head = head->next;
        delete temp;
    }
}

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

// Fungsi merge untuk Pelanggan (sort by nama)
Pelanggan* mergePelanggan(Pelanggan* left, Pelanggan* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Pelanggan* result = NULL;

    if (left->nama <= right->nama) {
        result = left;
        result->next = mergePelanggan(left->next, right);
    } else {
        result = right;
        result->next = mergePelanggan(left, right->next);
    }

    return result;
}

// Fungsi split untuk Pelanggan
void splitListPelanggan(Pelanggan* head, Pelanggan** left, Pelanggan** right) {
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
        return;
    }

    Pelanggan* slow = head;
    Pelanggan* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

// Fungsi mergeSort untuk Pelanggan
Pelanggan* mergeSortPelanggan(Pelanggan* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Pelanggan* left = NULL;
    Pelanggan* right = NULL;

    splitListPelanggan(head, &left, &right);

    left = mergeSortPelanggan(left);
    right = mergeSortPelanggan(right);

    return mergePelanggan(left, right);
}  

// Fungsi untuk menampilkan data Pelanggan yang sudah diurutkan
void readSortedPelanggan(Pelanggan*& headPelanggan) {
    if (headPelanggan == NULL) {
        cout << "Data Pelanggan kosong." << endl;
        return;
    }

    headPelanggan = mergeSortPelanggan(headPelanggan);

    Pelanggan* temp = headPelanggan;
    cout << "=== Daftar Pelanggan (Diurutkan berdasarkan Nama) ===" << endl;
    while (temp != NULL) {
        cout << "Nama Pelanggan: " << temp->nama << endl;
        cout << "Email Pelanggan: " << temp->email << endl;
        cout << "Nomor Telepon Pelanggan: " << temp->nomorTelepon << endl;
        cout << "Alamat Pelanggan: " << temp->alamat << endl;
        cout << "----------------------------------------" << endl;
        temp = temp->next;
    }
}

Perjalanan* merge(Perjalanan* left, Perjalanan* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Perjalanan* result = NULL;

    if (left->harga <= right->harga) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

void splitList(Perjalanan* head, Perjalanan** left, Perjalanan** right) {
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
        return;
    }

    Perjalanan* slow = head;
    Perjalanan* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

Perjalanan* mergeSort(Perjalanan* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Perjalanan* left = NULL;
    Perjalanan* right = NULL;

    splitList(head, &left, &right);

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void readSortedPerjalanan(Perjalanan*& headPerjalanan) {
    if (headPerjalanan == NULL) {
        cout << "Data Perjalanan kosong." << endl;
        return;
    }

    headPerjalanan = mergeSort(headPerjalanan);

    Perjalanan* temp = headPerjalanan;
    cout << "=== Daftar Perjalanan (Diurutkan berdasarkan Harga) ===" << endl;
    while (temp != NULL) {
        cout << "Nama Perjalanan: " << temp->namaPerjalanan << endl;
        cout << "Tujuan Perjalanan: " << temp->tujuan << endl;
        cout << "Tanggal Perjalanan: " << temp->tanggal << endl;
        cout << "Harga Perjalanan: " << temp->harga << endl;
        cout << "----------------------------------------" << endl;
        temp = temp->next;
    }
}

// Fungsi merge untuk Pemesanan (sort by tanggalPemesanan)
Pemesanan* mergePemesanan(Pemesanan* left, Pemesanan* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Pemesanan* result = NULL;

    if (left->tanggalPemesanan <= right->tanggalPemesanan) {
        result = left;
        result->next = mergePemesanan(left->next, right);
    } else {
        result = right;
        result->next = mergePemesanan(left, right->next);
    }

    return result;
}

// Fungsi split untuk Pemesanan
void splitListPemesanan(Pemesanan* head, Pemesanan** left, Pemesanan** right) {
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
        return;
    }

    Pemesanan* slow = head;
    Pemesanan* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

// Fungsi mergeSort untuk Pemesanan
Pemesanan* mergeSortPemesanan(Pemesanan* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Pemesanan* left = NULL;
    Pemesanan* right = NULL;

    splitListPemesanan(head, &left, &right);

    left = mergeSortPemesanan(left);
    right = mergeSortPemesanan(right);

    return mergePemesanan(left, right);
}

// Fungsi untuk menampilkan data Pemesanan yang sudah diurutkan
void readSortedPemesanan(Pemesanan*& headPemesanan) {
    if (headPemesanan == NULL) {
        cout << "Data Pemesanan kosong." << endl;
        return;
    }

    headPemesanan = mergeSortPemesanan(headPemesanan);

    Pemesanan* temp = headPemesanan;
    cout << "=== Daftar Pemesanan (Diurutkan berdasarkan Tanggal Pemesanan) ===" << endl;
    while (temp != NULL) {
        cout << "Nama Pelanggan: " << temp->pelanggan.nama << endl;
        cout << "Nama Perjalanan: " << temp->perjalanan.namaPerjalanan << endl;
        cout << "Tanggal Pemesanan: " << temp->tanggalPemesanan << endl;
        cout << "Status Pemesanan: " << temp->status << endl;
        cout << "----------------------------------------" << endl;
        temp = temp->next;
    }
}

// Fungsi merge untuk Pembayaran (sort by jumlah)
Pembayaran* mergePembayaran(Pembayaran* left, Pembayaran* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Pembayaran* result = NULL;

    if (left->jumlah <= right->jumlah) {
        result = left;
        result->next = mergePembayaran(left->next, right);
    } else {
        result = right;
        result->next = mergePembayaran(left, right->next);
    }

    return result;
}

// Fungsi split untuk Pembayaran
void splitListPembayaran(Pembayaran* head, Pembayaran** left, Pembayaran** right) {
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
        return;
    }

    Pembayaran* slow = head;
    Pembayaran* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

// Fungsi mergeSort untuk Pembayaran
Pembayaran* mergeSortPembayaran(Pembayaran* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Pembayaran* left = NULL;
    Pembayaran* right = NULL;

    splitListPembayaran(head, &left, &right);

    left = mergeSortPembayaran(left);
    right = mergeSortPembayaran(right);

    return mergePembayaran(left, right);
}

void readSortedPembayaran(Pembayaran*& headPembayaran) {
    if (headPembayaran == NULL) {
        cout << "Data Pembayaran kosong." << endl;
        return;
    }

    headPembayaran = mergeSortPembayaran(headPembayaran);

    Pembayaran* temp = headPembayaran;
    cout << "=== Daftar Pembayaran (Diurutkan berdasarkan Jumlah Pembayaran) ===" << endl;
    while (temp != NULL) {
        cout << "Nama Pelanggan: " << temp->pemesanan.pelanggan.nama << endl;
        cout << "Nama Perjalanan: " << temp->pemesanan.perjalanan.namaPerjalanan << endl;
        cout << "Tanggal Pembayaran: " << temp->tanggalPembayaran << endl;
        cout << "Jumlah Pembayaran: " << temp->jumlah << endl;
        cout << "----------------------------------------" << endl;
        temp = temp->next;
    }
}

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
void read(Pelanggan*& headPelanggan, Perjalanan*& headPerjalanan, Pemesanan*& headPemesanan, Pembayaran*& headPembayaran, Stack* headStack, Queue* headQueue) {
    int pilihan;
    cout << "Read apa?" << endl;
    cout << "1. Pelanggan" << endl;
    cout << "2. Perjalanan" << endl;
    cout << "3. Pemesanan" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "5. Stack" << endl;
    cout << "6. Queue" << endl;
    cout << "7. Perjalanan (Diurutkan berdasarkan harga)" << endl;
    cout << "8. Pelanggan (Diurutkan berdasarkan nama)" << endl;
    cout << "9. Pemesanan (Diurutkan berdasarkan tanggal)" << endl;
    cout << "10. Pembayaran (Diurutkan berdasarkan jumlah)" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    clearInputBuffer();

    switch (pilihan) {
        case 1: {
            Pelanggan* temp = headPelanggan;
            if (temp == NULL) {
                cout << "Data Pelanggan kosong." << endl;
                break;
            }
            cout << "=== Daftar Pelanggan ===" << endl;
            while (temp != NULL) {
                cout << "Nama Pelanggan: " << temp->nama << endl;
                cout << "Email Pelanggan: " << temp->email << endl;
                cout << "Nomor Telepon Pelanggan: " << temp->nomorTelepon << endl;
                cout << "Alamat Pelanggan: " << temp->alamat << endl;
                cout << "----------------------------------------" << endl;
                temp = temp->next;
            }
            break;
        }
        case 2: {
            Perjalanan* temp = headPerjalanan;
            if (temp == NULL) {
                cout << "Data Perjalanan kosong." << endl;
                break;
            }
            cout << "=== Daftar Perjalanan ===" << endl;
            while (temp != NULL) {
                cout << "Nama Perjalanan: " << temp->namaPerjalanan << endl;
                cout << "Tujuan Perjalanan: " << temp->tujuan << endl;
                cout << "Tanggal Perjalanan: " << temp->tanggal << endl;
                cout << "Harga Perjalanan: " << temp->harga << endl;
                cout << "----------------------------------------" << endl;
                temp = temp->next;
            }
            break;
        }
        case 3: {
            Pemesanan* temp = headPemesanan;
            if (temp == NULL) {
                cout << "Data Pemesanan kosong." << endl;
                break;
            }
            cout << "=== Daftar Pemesanan ===" << endl;
            while (temp != NULL) {
                cout << "Nama Pelanggan: " << temp->pelanggan.nama << endl;
                cout << "Nama Perjalanan: " << temp->perjalanan.namaPerjalanan << endl;
                cout << "Tanggal Pemesanan: " << temp->tanggalPemesanan << endl;
                cout << "Status Pemesanan: " << temp->status << endl;
                cout << "----------------------------------------" << endl;
                temp = temp->next;
            }
            break;
        }
        case 4: {
            Pembayaran* temp = headPembayaran;
            if (temp == NULL) {
                cout << "Data Pembayaran kosong." << endl;
                break;
            }
            cout << "=== Daftar Pembayaran ===" << endl;
            while (temp != NULL) {
                cout << "Nama Pelanggan: " << temp->pemesanan.pelanggan.nama << endl;
                cout << "Nama Perjalanan: " << temp->pemesanan.perjalanan.namaPerjalanan << endl;
                cout << "Tanggal Pembayaran: " << temp->tanggalPembayaran << endl;
                cout << "Jumlah Pembayaran: " << temp->jumlah << endl;
                cout << "----------------------------------------" << endl;
                temp = temp->next;
            }
            break;
        }
        case 5: {
            Stack* temp = headStack;
            if (temp == NULL) {
                cout << "Stack kosong." << endl;
                break;
            }
            cout << "=== Data pada Stack ===" << endl;
            while (temp != NULL) {
                cout << "Data pada Stack: " << temp->data << endl;
                temp = temp->next;
            }
            break;
        }
        case 6: {
            Queue* temp = headQueue;
            if (temp == NULL) {
                cout << "Queue kosong." << endl;
                break;
            }
            cout << "=== Data pada Queue ===" << endl;
            while (temp != NULL) {
                cout << "Data pada Queue: " << temp->data << endl;
                temp = temp->next;
            }
            break;
        }
        case 7: {  // Opsi baru untuk perjalanan yang diurutkan
            readSortedPerjalanan(headPerjalanan);
            break;
        }
        case 8: {
            readSortedPelanggan(headPelanggan);
            break;
        }
        case 9: {
            readSortedPemesanan(headPemesanan);
            break;
        }
        case 10: {
            readSortedPembayaran(headPembayaran);
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

