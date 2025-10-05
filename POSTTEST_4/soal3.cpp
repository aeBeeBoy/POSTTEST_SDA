#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

// Fungsi untuk menambahkan dokumen ke antrian (enqueue)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // Jika queue kosong
    if (front == nullptr) {
        front = rear = newNode;
    } 
    // Jika tidak kosong, tambahkan di belakang
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Fungsi untuk mengeluarkan dokumen dari antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    Node* temp = front;
    string doc = temp->document;

    // Geser front ke elemen berikutnya
    front = front->next;

    // Jika queue jadi kosong, rear juga harus nullptr
    if (front == nullptr)
        rear = nullptr;

    delete temp;
    return doc;
}

// Fungsi untuk memproses seluruh dokumen di antrian
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
