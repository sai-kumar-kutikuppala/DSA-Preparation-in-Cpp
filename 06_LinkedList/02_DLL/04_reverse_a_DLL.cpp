/*
Reverse a Doubly Linked List

Problem Statement: Given a doubly linked list of size ‘N’ consisting of positive integers, your task is to reverse it and return the head of the modified doubly linked list.

Examples
Input : DLL - 1 <-> 2 <-> 3 <-> 4


Output
: DLL - 4 <-> 3 <-> 2 <-> 1

Explanation
: The doubly linked list is reversed and its last node is returned at the new head pointer.

Input: DLL-10 <-> 20 <-> 30


Output
: DLL - 30 <-> 20 <-> 10

Explanation
: In this case, the doubly linked list is reversed and its former tail is returned as its new head.
*/

#include<iostream>
#include<vector>
#include<stack>
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

Node* brute_reverse(Node *head){
    if(head==nullptr || head->next==nullptr)
        return head;
    Node *temp=head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=head){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

Node* reverse(Node *head){
    if(head==nullptr || head->next==nullptr)
        return head;
    Node *current=head;
    Node *prev=nullptr;
    while(current!=nullptr){
        prev = current->back;
        current->back=current->next;
        current->next=prev;

        current=current->back;
    }
    return prev->back;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArr2DLL(arr);

    head = reverse(head);
    print(head);

    cout<<endl;

    head = brute_reverse(head);
    print(head);
}