/*
Remove N-th node from the end of a Linked List

Problem Statement: Given a linked list and an integer N, the task is to delete the Nth node from the end of the linked list and print the updated linked list.

Examples
Input:  5->1->2, N=2
Output: 5->2
Explanation: The 2nd node from the end of the linked list is 1. Therefore, we get this result after removing 1 from the linked list.

Input:  1->2->3->4->5, N=3
Output: 1->2->4->5
Explanation: The 3rd node from the end is 3, therefore, we remove 3 from the linked list.
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

Node* brute(Node *head,int N){
    Node *temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    if(cnt==N){
        Node *newHead=head->next;
        head->next=nullptr;
        delete head;
        return newHead;
    }
    int res=cnt-N;
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

Node* optimal(Node *head,int N){
    Node *slow=head,*fast=head;
    for(int i=1;i<=N;i++)
        fast=fast->next;
    if(fast==nullptr){
        Node *newHead=head->next;
        head->next=nullptr;
        delete head;
        return newHead;
    }
    while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    Node *delNode = slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);
    int N;
    cin>>N;
    
    //print(brute(head,N));
    cout<<endl;
    print(optimal(head,N));
}