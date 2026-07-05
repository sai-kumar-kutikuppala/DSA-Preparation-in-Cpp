/*
Reverse Linked List in groups of Size K

Problem Statement: Given the head of a singly linked list containing integers, reverse the nodes of the list in groups of k and return the head of the modified list. If the number of nodes is not a multiple of k, then the remaining nodes at the end should be kept as is and not reversed.
Do not change the values of the nodes, only change the links between nodes.

Examples
Input : head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2
Output :head -> 2 -> 1 -> 4 -> 3 -> 5
Explanation :The groups 1 -> 2 and 3 -> 4 were reversed as 2 -> 1 and 4 -> 3.

Input :head -> 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output :head -> 3 -> 2 -> 1 -> 4 -> 5
Explanation :The groups 1 -> 2 -> 3 were reversed as 3 -> 2 -> 1.
Note that 4 -> 5 was not reversed.
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

Node* findKthNode(Node *head,int k){
    Node *temp=head;
    k--;
    while(temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
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

Node* reverse_by_groups(Node *head,int k){
    Node *temp=head;
    Node *nextNode,*prevNode=nullptr;
    while(temp!=nullptr){
        Node *KthNode = findKthNode(temp,k);
        if(KthNode==nullptr){
            if(prevNode) prevNode->next=temp;
            break;
        }
        Node *nextNode=KthNode->next;
        KthNode->next=nullptr;
        reverse(temp);
        if(temp==head)
            head=KthNode;
        else
            prevNode->next=KthNode;
        prevNode=temp;
        temp=nextNode;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);
    int k;
    cin>>k;

    print(reverse_by_groups(head,k));
}