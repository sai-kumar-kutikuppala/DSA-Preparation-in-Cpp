/*
Sort a Linked List of 0's 1's and 2's by changing links

Problem Statement: Given a linked list containing only 0's, 1's, and 2's, sort the linked list by rearranging the links (not by changing the data values).

Examples
Input: 1 -> 2 -> 0 -> 1 -> 0 -> 2 -> NULL
Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
Input: 2 -> 1 -> 2 -> 0 -> 0 -> 1 -> NULL
Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
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
    int cnt0=0,cnt1=0,cnt2=0;
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==0)
            cnt0++;
        else if(temp->data==1)
            cnt1++;
        else
            cnt2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(cnt0){
            temp->data=0;
            cnt0--;
        }
        else if(cnt1){
            temp->data=1;
            cnt1--;
        }
        else{
            temp->data=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
}

Node* optimal(Node *head){
    Node *zeroHead=new Node(-1),*zero=zeroHead;
    Node *oneHead=new Node(-1),*one=oneHead;
    Node *twoHead=new Node(-1),*two=twoHead;
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=(oneHead->next)?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=nullptr;
    Node *newHead=zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}

int main(){
    vector<int> arr = {1,2,0,1,0,2};
    Node *head = convertArray2LL(arr);
    
    //print(brute(head));
    print(optimal(head));

}
