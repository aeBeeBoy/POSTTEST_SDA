#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi push dan pop
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi pengecekan keseimbangan kurung
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char ch : expr) {
        // Jika kurung buka, push ke stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stackTop, ch);
        }
        // Jika kurung tutup, periksa kecocokan
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stackTop == nullptr) return false; // Tidak ada pasangan buka

            char topChar = pop(stackTop);

            // Cek apakah pasangan sesuai
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // Jika setelah semua karakter, stack masih berisi kurung buka, berarti tidak seimbang
    bool balanced = (stackTop == nullptr);

    // Bersihkan sisa node jika ada
    while (stackTop != nullptr) pop(stackTop);

    return balanced;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr3 = "{[()]()}";
    cout << expr3 << " -> " << (areBracketsBalanced(expr3) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr4 = "{[}";
    cout << expr4 << " -> " << (areBracketsBalanced(expr4) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
