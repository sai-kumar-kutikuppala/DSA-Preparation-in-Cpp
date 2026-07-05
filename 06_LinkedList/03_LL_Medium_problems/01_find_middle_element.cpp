/*
Find middle element in a Linked List

Problem Statement: Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.

Examples
Example 1:
Input:
 LL: 1  2  3  4  5 
 
Output:
 3
                
Explanation: 
Node with value 3 is the middle node of this linked list.
                                         
Example 2:
Input:
 LL: 1  2  3  4  5  6
                          
Output: 
4
                
Explanation: 
 In this example, the linked list has an even number of nodes hence we return the second middle node which is 4.
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
    Node *temp=head;
    int N=0;
    while(temp!=nullptr){
        N++;
        temp=temp->next;
    }

    temp=head;
    int cnt=N/2+1;
    while(temp!=nullptr){
        cnt--;
        if(cnt==0)
            break;
        temp=temp->next;
    }
    return temp;
}

Node *optimal(Node *head){
    Node *slow=head;
    Node *fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);
    
    cout<<brute(head)->data<<endl;
    cout<<optimal(head)->data<<endl;
}
