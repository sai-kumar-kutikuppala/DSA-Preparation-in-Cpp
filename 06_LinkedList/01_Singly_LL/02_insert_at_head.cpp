/*
Insert at the head of a Linked List

Problem Statement: Given a linked list and an integer value val, insert a new node with that value at the beginning (before the head) of the list and return the updated linked list.

Examples
Input: 0->1->2, val = 5 
Output: 5->0->1->2
Explanation: We need to insert the value 5 before the head of the given Linked List.

Input: 12->5->8->7, val = 4
Output: 4->12->5->8->7
Explanation: We need to insert the value 4 before the head of the given Linked List.
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

Node* insertBeforeHead(Node *head,int el){
    Node *temp = new Node(el,head);
    return temp;
}

void print(Node *head){
    Node *temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);

    int el;
    cin>>el;
    
    head = insertBeforeHead(head,el);
    print(head);
}

