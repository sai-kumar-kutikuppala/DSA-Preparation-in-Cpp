/*
Reverse a Linked List

Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

Examples
Input-  LL: 1   3   2   4 
Output: 3
Explanation: After reversing the linked list, the new head will point to the tail of the old linked list.
*/

#include<iostream>
#include<vector>
#include<stack>
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

Node* brute(Node *head){
    if(head == nullptr || head->next == nullptr)
        return head;

    stack<int> st;
    Node *temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=nullptr){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;  
}

Node* optimal(Node *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    
    Node *temp=head,*prev=nullptr,*front;
    while(temp!=nullptr){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);

    //print(brute(head));
    //cout<<endl;
    print(optimal(head)); 
}