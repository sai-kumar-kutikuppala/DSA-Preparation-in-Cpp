/*
Delete the Middle Node of the Linked List

Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

Examples
Input: 1->2->3->4->5 

Output: 1->2->4->5

Explanation: Node with value 3 is at the middle node and deleted.
Input: 1->2->3->4

Output: 1->2->4

Explanation: The linked list has an even number of nodes hence we delete the second middle node which is 3.
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

Node* brute(Node *head){
    if(head==nullptr || head->next==nullptr)
        return nullptr;
    Node *temp=head;
    int N=0;
    while(temp!=nullptr){
        N++;
        temp=temp->next;
    }
    int res=N/2;
    temp=head;
    while(temp!=nullptr){
        res--;
        if(res==0)
            break;
        temp=temp->next;    
    }
    Node *delNode=temp->next;
    temp->next=temp->next->next;
    delete delNode;
    return head;
}

Node* optimal(Node *head){
    if(head==nullptr || head->next==nullptr)
        return nullptr;
    Node *slow=head,*fast=head;
    fast=fast->next->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node *head = convertArray2LL(arr);
    
    //print(brute(head)); 
    print(optimal(head));
}
