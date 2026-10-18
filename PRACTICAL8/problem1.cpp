#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;

    Node(string val) : name(val), left(NULL), right(NULL) {}
};

void HR(Node* root) {
    if (root == NULL) return;
    HR(root->left);
    cout << root->name << " ";
    HR(root->right);
}

void Archive(Node* root) {
    if (root == NULL) return;
    cout << root->name << " ";
    Archive(root->left);
    Archive(root->right);
}

void Payroll(Node* root) {
    if (root == NULL) return;
    Payroll(root->left);
   Payroll(root->right);
    cout << root->name << " ";
}
void FloorManager(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->name << " ";

        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
    }
}

int main() {

    Node* root = new Node("CEO");
    root->left = new Node("MgrA");
    root->right = new Node("MgrB");
    root->left->left = new Node("E1");
    root->left->right = new Node("E2");
    root->right->left = new Node("E3");
    root->right->right = new Node("E4");

    cout << "HR (Inorder): ";
    HR(root);
    cout << "\n \n";

    cout << "Archive (Preorder): ";
   Archive(root);
    cout << "\n \n";

    cout << "Payroll (Postorder): ";
    Payroll(root);
    cout << "\n \n";

    cout << "Floor Manager (Level-Order): ";
    FloorManager(root);
    cout << "\n \n";

    return 0;
}