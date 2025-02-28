#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

void insert(Node* head, int x){
    Node* newNode = new Node(x);
    Node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteNode(Node*& head){
    Node* temp = head;
    while (temp->next->next != nullptr){
        temp = temp->next;
    }
    temp->next = nullptr;
}

int main(){
    int ops; cin >> ops;
    cin.ignore();
    Node* head = nullptr;
    for (int i = 0; i < ops; i++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string op;
        ss >> op;
        if (op == "push"){
            if (head == nullptr){
                int x;
                ss >> x;
                head = new Node(x);
            }
            else {
                int x;
                ss >> x;
                insert(head, x);
            }
        }
        else if (op == "pop"){
            deleteNode(head);
        }
    }
    while (head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}