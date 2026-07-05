/*
Insert at end of Doubly Linked List

Problem Statement: Given a doubly linked list, and a value ‘k’, insert a node having value ‘k’ at the end of the doubly linked list.

Examples
Example 1:
Input Format:
  
DLL: 1 <-> 2 <-> 3 <-> 4  
Value to be Inserted: 6  
Result:
  DLL: 1 <-> 2 <-> 3 <-> 4 <-> 6  
Explanation:
  A new node with value 6 has been inserted at the end of the doubly linked list after the tail node.

Example 2:
Input Format:
  
DLL: 10 <-> 20 <-> 30  
Value to be Inserted: 40  
Result:
  DLL: 10 <-> 20 <-> 30 <-> 40  
Explanation:
  In this case, a new node with value 40 is inserted after 30, which is at the end of the doubly linked list.
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

Node* insertAtEnd(Node *head,int el){
    if(head==nullptr)
        return new Node(el);
    Node *tail=head;
    while(tail->next!=nullptr)
        tail=tail->next;
    Node *newNode = new Node(el,nullptr,tail);
    tail->next=newNode;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArr2DLL(arr);

    int val;
    cin>>val;
    head = insertAtEnd(head,val);

    print(head);
}