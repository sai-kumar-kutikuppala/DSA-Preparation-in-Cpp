/*
Delete Last Node of a Doubly Linked List

Problem Statement: Given a Doubly Linked List, delete the last node of the Doubly Linked List.

Examples
Input:  DLL: 1 <-> 3 <-> 4 <-> 1

Output: DLL: 1 <-> 3 <-> 4

Explanation: Last node of the Doubly Linked List to be deleted is 1.
Input: DLL: 7 <-> 5

Output: DLL: 7

Explanation: Last node of the Doubly Linked List to be deleted is 5.
*/

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *back;
        Node(int data1,Node *next1,Node *back1){
            data=data1;
            next=next1;
            back=back1;
        }
        Node(int data1){
            data=data1;
            next=nullptr;
            back=nullptr;
        }
};

Node* convertArr2DLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next=temp;
        temp->back=mover;
        mover=mover->next;
    }
    return head;
}

void print(Node *head){
    Node *temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<temp->data;
}

Node* deleteAtEnd(Node *head){
    if(head==nullptr || head->next==nullptr)
        return nullptr;
    Node *tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    Node *prev = tail->back;
    prev->next=tail->back=nullptr;
    delete tail;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArr2DLL(arr);

    head = deleteAtEnd(head);
    print(head);
}