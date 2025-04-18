#include <iostream>
#include <queue>
using namespace std;

// Định nghĩa cấu trúc một nút trong cây BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root;
    BST() : root(NULL) {}

    // Hàm chèn một nút vào cây BST
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val); // Nếu nút rỗng, tạo nút mới
        if (val < node->data) node->left = insert(node->left, val); // Chèn vào cây con trái nếu giá trị nhỏ hơn
        else node->right = insert(node->right, val); // Chèn vào cây con phải nếu giá trị lớn hơn
        return node;
    }

    // Hàm tìm phần tử nhỏ nhất trong cây con phải
    Node* findMin(Node* node) {
        while (node && node->left) node = node->left; // Duyệt về phía trái để tìm giá trị nhỏ nhất
        return node;
    }

    // Hàm xóa một nút khỏi cây BST
    Node* remove(Node* node, int val) {
        if (!node) return NULL; // Nếu cây rỗng, trả về NULL
        if (val < node->data) node->left = remove(node->left, val); // Tìm giá trị cần xóa ở cây con trái
        else if (val > node->data) node->right = remove(node->right, val); // Tìm giá trị cần xóa ở cây con phải
        else {
            if (!node->left) { // Nếu nút có 1 con hoặc không có con
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right); // Tìm phần tử nhỏ nhất bên phải để thay thế
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Duyệt trung tố (inorder) để in cây theo thứ tự tăng dần
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // In cây theo từng cấp, sử dụng dấu / và \ để biểu diễn cấu trúc cây
    void printTree(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(); // Số lượng nút trong một cấp
            while (size--) {
                Node* node = q.front(); q.pop();
                cout << node->data << " "; // In giá trị của nút
                if (node->left || node->right) cout << " / \\ "; // Biểu diễn nhánh đi xuống
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << endl;
        }
    }
};

int main() {
    BST tree;
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int val : values) tree.root = tree.insert(tree.root, val);

    cout << "BST after initial insertion:\n";
    tree.printTree(tree.root);
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    int insertions[] = {14, 0, 35};
    for (int val : insertions) tree.root = tree.insert(tree.root, val);
    cout << "\nBST after inserting 14, 0, 35:\n";
    tree.printTree(tree.root);
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    int deletions[] = {6, 13, 35};
    for (int val : deletions) tree.root = tree.remove(tree.root, val);
    cout << "\nBST after deleting 6, 13, 35:\n";
    tree.printTree(tree.root);
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
