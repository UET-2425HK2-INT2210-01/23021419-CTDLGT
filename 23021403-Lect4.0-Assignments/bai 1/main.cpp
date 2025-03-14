#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr){}
};

class LinkedList{
public:
    Node* head;
    int size;
    LinkedList() : head(nullptr), size(0){}
    void append(int value){
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    int search(int value){
        int count=0;
        Node* current = head;
        while(current){
            if(current->data == value)  count++;
            current = current->next;
        }
        return count;
    }
    void reverse(){
        Node *prev = nullptr, *current = head, *next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void printLinkedList(){
        Node* current = head;
        while(current){
            cout<<current->data;
            if(current->next){
                cout<<" ";
            }
            current = current->next;
        }
        cout<<endl;
    }
};
int main() {
    LinkedList list;
    string command;
    int value;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin >> command;
        if (command == "append") {
            cin >> value;
            list.append(value);
        } else if (command == "search") {
            cin >> value;
            cout << list.search(value) << endl;
        } else if (command == "reverse") {
            list.reverse();
        }
    }
    list.printLinkedList();
    return 0;
}