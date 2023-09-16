#include <iostream>
using namespace std;

// Definisikan struktur node untuk CLL
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan elemen ke awal CLL
    void tambah_awal(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (head == nullptr) {
            newNode->next = newNode; // Untuk kasus ketika CLL kosong
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Fungsi untuk menampilkan elemen-elemen CLL
    void tampil() {
        if (head == nullptr) {
            cout << "CLL kosong" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "Pertama" << endl;
    }

    // Fungsi untuk menghapus elemen pertama dari CLL
    void hapus_awal() {
        if (head == nullptr) {
            cout << "CLL kosong, tidak ada yang dihapus" << endl;
            return;
        }

        Node* temp = head;
        Node* lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }

        head = head->next;
        lastNode->next = head;
        delete temp;
    }
};

int main() {
    CircularLinkedList cll;

    cll.tambah_awal(1);
    cll.tambah_awal(2);
    cll.tambah_awal(3);

    cout << "Isi Circular Linked List: ";
    cll.tampil();

    cll.hapus_awal();
    cout << "Setelah menghapus elemen pertama: ";
    cll.tampil();

    return 0;
}
