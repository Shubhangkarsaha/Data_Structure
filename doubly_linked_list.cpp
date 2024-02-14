#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* link;
        node* prev;

    node(int d){
        this -> data = d;
        this -> link = NULL;
        this -> prev = NULL;
    }
};

//traversing the linked list
void print(node* &head){
    node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        cout << temp -> link << " ";
        temp = temp -> link;
    }
    cout << endl;
}

int getlength(node* &head){
    int len = 0;
    node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> link;
    }
    return len;
}

//inserting node at the begining of the linked list
void insertAthead(node* &head, int d){

    node* temp = new node(d);
    temp -> link = head;
    head -> prev = temp;
    head = temp;

}

void insertAttail(node* &tail, int d){
    node* temp = new node(d);
    tail -> link = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition(node* &head, node* &tail, int position, int d){

    if(position == 1){
        insertAthead(head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while(cnt < position-1 ){
        temp = temp -> link;
        cnt++;
    }

    if(temp -> link == NULL){
        insertAttail(tail, d);
        return;
    }
   
    node* nodeToinsert = new node(d);
    nodeToinsert -> link = temp -> link;
    temp -> link -> prev = nodeToinsert;
    temp -> link = nodeToinsert;
    nodeToinsert -> prev = temp;


}

int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    print(head);

    insertAthead(head, 11);
    print(head);

    insertAttail(tail, 12);
    print(head);

    insertAttail(tail, 56);
    print(head);

    insertAtPosition(head, tail, 1, 78);
    print(head);

    insertAtPosition(head, tail, 6, 578);
    print(head);

    cout << "Size: " << getlength(head) << endl;
    
    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;

    return 0;
}
