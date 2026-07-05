/*
Check if the given Linked List is Palindrome

Problem Statement: Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. Check whether the linked list values form a palindrome or not. Return true if it forms a palindrome, otherwise, return false. .

A palindrome is a sequence that reads the same forward and backwards.

Examples
Example 1:
Input: head -> 3 -> 7 -> 5 -> 7 -> 3
Output: true
Explanation: 37573 is a palindrome.

Example 2:
Input: head -> 1 -> 1 -> 2 -> 1
Output: false
Explanation: 1121 is not a palindrome.
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

bool brute(Node *head){
    stack<int> st;
    Node *temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=nullptr){
        if(temp->data != st.top())
            return false;
        st.pop();
        temp=temp->next;    
    }
    return true;
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

bool optimal(Node *head){
    Node *slow=head,*fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *newHead = reverse(slow->next);
    Node *first=head,*second=newHead;
    while(second!=nullptr){
        if(first->data != second->data){
            reverse(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse(newHead);
    return true;
}

int main(){
    vector<int> arr = {1,2,3,2,1};
    Node *head = convertArray2LL(arr);
    
    cout<<brute(head)<<endl;
    cout<<optimal(head)<<endl;
}
