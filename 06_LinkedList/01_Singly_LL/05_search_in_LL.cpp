/*
Search an element in a Linked List

Problem Statement: Given the head of a linked list and an integer value, find out whether the integer is present in the linked list or not. Return true if it is present, or else return false.

Examples
Input: 0->1->2, val = 2
Output: True
Explanation: Since element 2 is present in the list, return true.

Input: 12->5->8->7, val = 6 
Output: False
Explanation: The list does not contain element 6. Therefore, return false.
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

bool search(Node *head,int val){
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==val)
            return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);

    int val;
    cin>>val;

    cout<<search(head,val);
}