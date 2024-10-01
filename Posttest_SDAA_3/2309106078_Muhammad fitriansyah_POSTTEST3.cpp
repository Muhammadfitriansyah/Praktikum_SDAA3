#include <iostream>
#include <string>

using namespace std;

struct Sparepart {
    string kodeSparepart;
    string namaSparepart;
    int stok;
    float harga;
    Sparepart* next;  // Pointer to the next node
};

Sparepart* head = nullptr; // Pointer to the head of the list

void tambahSparepart() {
    Sparepart* sparepartBaru = new Sparepart;
    
    cout << "Masukkan Kode Sparepart: ";
    cin >> sparepartBaru->kodeSparepart;
    cout << "Masukkan Nama Sparepart: ";
    cin.ignore();
    getline(cin, sparepartBaru->namaSparepart);
    cout << "Masukkan Stok: ";
    cin >> sparepartBaru->stok;
    cout << "Masukkan Harga: ";
    cin >> sparepartBaru->harga;

    sparepartBaru->next = nullptr; // Set next to null, since it will be the last node for now

    if (head == nullptr) {
        head = sparepartBaru;
    } else {
        Sparepart* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = sparepartBaru;
    }

    cout << "Sparepart berhasil ditambahkan!" << endl;
}

void tampilkanSpareparts() {
    if (head == nullptr) {
        cout << "Tidak ada sparepart dalam daftar." << endl;
        return;
    }

    Sparepart* temp = head;
    cout << "Daftar Sparepart Motor: " << endl;
    while (temp != nullptr) {
        cout << "Kode: " << temp->kodeSparepart << ", Nama: " << temp->namaSparepart
             << ", Stok: " << temp->stok << ", Harga: Rp" << temp->harga << endl;
        temp = temp->next;
    }
}

void updateSparepart() {
    string kode;
    cout << "Masukkan kode sparepart yang ingin diupdate: ";
    cin >> kode;

    Sparepart* temp = head;
    while (temp != nullptr) {
        if (temp->kodeSparepart == kode) {
            cout << "Masukkan Nama Sparepart Baru: ";
            cin.ignore();
            getline(cin, temp->namaSparepart);
            cout << "Masukkan Stok Baru: ";
            cin >> temp->stok;
            cout << "Masukkan Harga Baru: ";
            cin >> temp->harga;
            cout << "Sparepart berhasil diupdate!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Sparepart dengan kode tersebut tidak ditemukan." << endl;
}

void hapusSparepart() {
    string kode;
    cout << "Masukkan kode sparepart yang ingin dihapus: ";
    cin >> kode;

    if (head == nullptr) {
        cout << "Daftar kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    if (head->kodeSparepart == kode) {
        Sparepart* temp = head;
        head = head->next;
        delete temp;
        cout << "Sparepart berhasil dihapus!" << endl;
        return;
    }

    Sparepart* current = head;
    Sparepart* previous = nullptr;

    while (current != nullptr && current->kodeSparepart != kode) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Sparepart dengan kode tersebut tidak ditemukan." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Sparepart berhasil dihapus!" << endl;
}

void menu() {
    int pilihan;
    do {
        cout << "\nMenu Manajemen Penjualan Sparepart Motor:" << endl;
        cout << "1. Tambah Sparepart" << endl;
        cout << "2. Tampilkan Sparepart" << endl;
        cout << "3. Update Sparepart" << endl;
        cout << "4. Hapus Sparepart" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahSparepart();
                break;
            case 2:
                tampilkanSpareparts();
                break;
            case 3:
                updateSparepart();
                break;
            case 4:
                hapusSparepart();
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 5);
}

int main() {
    menu();
    return 0;
}
