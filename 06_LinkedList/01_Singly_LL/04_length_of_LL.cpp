/*
Find the Length of a Linked List

Problem Statement: Given the head of a linked list, print the length of the linked list.

Examples
Input: 0->1->2 
Output: 3
Explanation: The list has a total of 3 nodes, thus the length of the list is 3.

Input: 12->5->8->7
Output: 4
Explanation: The list has a total of 4 nodes, thus the length of the list is 4.
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

int length(Node *head){
    Node *temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);

    cout<<length(head);
}