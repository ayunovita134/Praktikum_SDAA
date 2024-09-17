#include <iostream>
using namespace std;

int pascal(int baris, int posisi) {
    if ((posisi == 0) || (posisi == baris))
        return 1;
    else
        return pascal(baris - 1, posisi) + pascal(baris - 1, posisi - 1);
}

int main() {
    int tinggi = 3;

    for (int i = 0; i < tinggi; i++) {
        for (int j = 0; j < tinggi - i; j++)
            cout << " ";
        for (int j = 0; j <= i; j++)
            cout << pascal(i, j) << " ";
        cout << endl;
    }

    return 0;
}
