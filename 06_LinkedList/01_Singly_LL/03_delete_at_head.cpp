/*
Delete Last Node of Linked List

Problem Statement: Given a Linked List, delete the tail of the list and print the updated list.

Examples
Input: 0->1->2
Output: 0->1

Explanation: Last node of the Linked List is 2.
Input: 12->5->8->7
Output: 12->5->8
Explanation: Last node of the Linked List is 7.
*/

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data1,Node *next1){
            data=data1;
            next=next1;
        }
        Node(int data1){
            data=data1;
            next=nullptr;
        }
};

Node* convertArray2LL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}

void print(Node *head){
    Node *temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}

Node* deleteAtHead(Node *head){
    if(head==nullptr){
        return nullptr;
    }
    Node *temp=head;
    head=head->next;
    temp->next=nullptr;
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);

    head = deleteAtHead(head);
    print(head);
}