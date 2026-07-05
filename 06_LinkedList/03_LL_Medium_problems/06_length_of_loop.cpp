/*
Length of Loop in Linked List

Problem Statement: Given the head of a linked list, determine the length of a loop present in the linked list. If there's no loop present, return 0.
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

int brute(Node *head){
    Node *temp=head;
    unordered_map<Node*,int> mpp;
    int timer=0;
    while(temp!=nullptr){
        timer++;
        if(mpp.find(temp)!=mpp.end())
            return timer-mpp[temp];
        mpp[temp]=timer;
        temp=temp->next;
    }
    return 0;
}

int optimal(Node *head){
    Node *slow=head,*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            fast=fast->next;
            int cnt=1;
            while(slow!=fast){
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);
    cout<<brute(head)<<endl;
    cout<<optimal(head)<<endl;
}