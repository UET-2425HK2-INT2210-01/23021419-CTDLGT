#include <iostream>
#include <string>
using namespace std;

struct Node{
    int value;
    int priority;
    Node* next;
    Node* prev;
    Node(int val, int pri) : value(val), priority(pri), next(nullptr), prev(nullptr){}
};
class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList(): head(nullptr), tail(nullptr){}
    void enqueue(int value, int priority){
        Node* newNode = new Node(value, priority);
        if(!head){
            head = tail =newNode;
        }else{
            Node* current = head;
            Node* prev = nullptr;
            while (current && current->priority > priority) {
                prev = current;
                current = current->next;
            }
            if (!prev) {
                newNode->next = head;
                head->prev = newNode;
               head = newNode;
            } else if (!current) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                prev->next = newNode;
                newNode->prev = prev;
                newNode->next = current;
                current->prev = newNode;
            }
        }
    }
    void dequeue(){
        if(!head){
            cout<<"Khong co gi!!"<<endl;
            return;
        }
        Node* current = head;
        Node* MaxPriorityNode = head;
        int MaxPriority = head->priority;
        while(current){
            if(current->priority >= MaxPriority){
                MaxPriority = current->priority;
                MaxPriorityNode = current;
            }
            current = current->next;
        }
        if (MaxPriorityNode == head){
            head = head->next;
            if(head){
                head->prev = nullptr;
            }else tail = nullptr;
        }else if(MaxPriorityNode == tail){
            tail = tail->prev;
            tail->next = nullptr;
        }else {
            MaxPriorityNode->prev->next = MaxPriorityNode->next;
            MaxPriorityNode->next->prev = MaxPriorityNode->prev;
        }
    }
    void printDoublyLinkedList(){
        Node* current = head;
        while (current) {
            cout << "(" << current->value << ", " << current->priority << ")";
            if (current->next) {
                cout << "; ";
            }
            current = current->next;
        }
        cout << ";" << endl;
    }
};
int main(){
    DoublyLinkedList list;
    string command;
    int value, priority;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "enqueue") {
            cin >> value >> priority;
            list.enqueue(value, priority);
        } else if (command == "dequeue") {
            list.dequeue();
        }
    }
    list.printDoublyLinkedList();
    return 0;
}