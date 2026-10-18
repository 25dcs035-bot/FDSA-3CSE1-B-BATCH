#include <iostream>

using namespace std;

struct Node {
    int code;
    Node* left;
    Node* right;

    Node(int val) : code(val), left(NULL), right(NULL) {}
};
Node* insert(Node* root, int code) {
    if (root == NULL) {
        return new Node(code);
    }

    if (code < root->code) {
        root->left = insert(root->left, code);   
    } else if (code > root->code) {
        root->right = insert(root->right, code); 
    }

    return root;
}

void printInorder(Node* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->code << " ";
    printInorder(root->right);
}

int main() {
    Node* root = NULL;

    int bookCodes[] = {45, 12, 78, 23, 7, 56, 89};
    int n = sizeof(bookCodes) / sizeof(bookCodes[0]);

    cout << "Inserting book codes: ";
    for (int i = 0; i < n; i++) {
        cout << bookCodes[i] << " ";
        root = insert(root, bookCodes[i]);
    }

    cout << "\n-----------------------------------\n";
    cout << "Sorted Shelf Order (Inorder): ";
    printInorder(root);
    cout << "\n";

    return 0;
}