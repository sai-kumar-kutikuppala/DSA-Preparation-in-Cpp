/*
Detect a Cycle in a Linked List

Problem Statement: Given a Linked List, determine whether the linked list contains a cycle or not.

*/

#include<iostream>
#include<vector>
#include<unordered_map>
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
    mover->next = head->next->next; // loop from 5 to 3
    return head;
}


bool brute(Node *head){
    unordered_map<Node*,int> mpp;
    Node *temp = head;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end())
            return true;
        mpp[temp]=1;
        temp=temp->next;  
    }
    return false;
}

bool optimal(Node *head){
    Node *slow=head,*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);
    cout<<brute(head)<<endl;
    cout<<optimal(head)<<endl;
}