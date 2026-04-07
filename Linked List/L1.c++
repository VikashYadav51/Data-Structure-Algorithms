#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int element){
            this->data = element;
            this->next = nullptr;
        }
};


void insertAtHead(Node* &head, int element){
    if(head == nullptr){
        Node* temp = new Node(element);
        head = temp;
        return ;
    }

    Node* temp = new Node(element);

    temp->next = head;
    head = temp;

    return ;
}

void insertAtTail(Node* &head, int element){
    if(head == nullptr){
        Node* temp = new Node(element);
        head = temp;
        return ;
    }

    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* newNode = new Node(element);

    temp->next = newNode;
    temp = temp->next;

    return ;
}


void insertAtMiddle(Node* &head, int pos, int element){
    if(pos == 1){
        insertAtHead(head, element);
        return ;
    }

    Node* temp = head;
    int i = 1;

    while(temp != nullptr && i < pos - 1){
        temp = temp->next;
        i++;
    }

    if(temp!= nullptr){
        Node* newNode = new Node(element);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return ;
}

void printList(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data <<",  ";
        temp = temp->next;
    }

    return ;
}
int main(){
    Node* node = new Node(10);

    Node* head = node;
    Node* tail = node;

    insertAtHead(head, 8);
    insertAtTail(head, 12);
    insertAtTail(head, 14);

    insertAtMiddle(head, 1, 6);
    insertAtMiddle(head, 2, 88);
    insertAtMiddle(head, 7, 16);
    insertAtMiddle(head, 9, 18);

    printList(head);

    return 0;
}