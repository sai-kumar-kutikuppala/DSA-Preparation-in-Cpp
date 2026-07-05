/*
Rotate a Linked List

Problem Statement: Given the head of a singly linked list containing integers, shift the elements of the linked list to the right by k places and return the head of the modified list. Do not change the values of the nodes, only change the links between nodes.

Examples
Input : head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2
Output : head -> 4 -> 5 -> 1 -> 2 -> 3
Explanation :List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.
List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

Input : head -> 1 -> 2 -> 3 -> 4 -> 5, k = 4
Output :head -> 2 -> 3 -> 4 -> 5 -> 1
Explanation :List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.
List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.
List after 3 shift to right: head -> 3 -> 4 -> 5 -> 1 -> 2.
List after 4 shift to right: head -> 2 -> 3 -> 4 -> 5 -> 1. 
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

Node* findKthNode(Node *head,int k){
    Node *temp=head;
    k--;
    while(k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node* rotate(Node *head,int k){
    Node *tail=head;
    int N=1;
    while(tail->next!=nullptr){
        tail=tail->next;
        N++;
    }
    if(k%N==0) return head;
    k=k%N;
    tail->next=head;
    Node *lastNode = findKthNode(head,N-k);
    head = lastNode->next;
    lastNode->next=nullptr;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);
    int k;
    cin>>k;

    print(rotate(head,k));
}