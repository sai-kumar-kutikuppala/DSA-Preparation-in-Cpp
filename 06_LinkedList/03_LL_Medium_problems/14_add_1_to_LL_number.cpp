/*
Add 1 to a number represented by LL

Problem Statement: Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

The number will contain no leading zeroes except when the value represented is zero itself.

Examples
Input: 4->5->6

Output: 4->5->7
Explanation: 456 + 1 = 457
Input: 9->9->9

Output: 1->0->0->0
Explanation: 999 + 1 = 1000
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

Node* reverse(Node *head){
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

Node* iterative(Node *head){
    head=reverse(head);
    int carry=1;
    Node *temp=head;
    while(temp!=nullptr){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        head=reverse(head);
        Node *newHead = new Node(1);
        newHead->next=head;
        return newHead;
    }
    head=reverse(head);
    return head;
}

int helper(Node *temp){
    if(temp==nullptr)
        return 1;
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10)
        return 0;
    temp->data=0;
    return 1;
}

Node* recursive(Node *head){
    int carry=helper(head);
    if(carry==1){
        head=reverse(head);
        Node *newHead = new Node(1);
        newHead->next=head;
        return newHead;
    }
    return head;
}

int main(){
    vector<int> arr = {4,5,6};
    Node *head = convertArray2LL(arr);

    //print(iterative(head));
    print(recursive(head));
}