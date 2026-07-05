/*
Starting point of loop in a Linked List

Problem Statement: Given the head of a linked list that may contain a cycle, return the starting point of that cycle. If there is no cycle in the linked list return null.
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

Node* brute(Node *head){
    unordered_map<Node*,int> mpp;
    Node *temp=head;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end())
            return temp;
        mpp[temp]=1;
        temp=temp->next; 
    }
    return nullptr;
}

Node* optimal(Node *head){
    Node *slow=head,*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);
    cout<<brute(head)<<endl;
    cout<<optimal(head)<<endl;
}