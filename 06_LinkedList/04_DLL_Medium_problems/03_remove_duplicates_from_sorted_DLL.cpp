/*
Remove duplicates from sorted DLL

Problem Statement: Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

Return the head of the modified linked list.

Examples
Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

Output: head -> 1 <-> 3 <-> 4 <-> 5
Explanation: Duplicate occurences of 1 and 3 are deleted
Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

Output: head -> 1 <-> 2
Explanation: All duplicate occurences of 1 is deleted
*/

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *back;
        Node(int data1,Node *next1,Node *back1){
            data=data1;
            next=next1;
            back=back1;
        }
        Node(int data1){
            data=data1;
            next=nullptr;
            back=nullptr;
        }
};

Node* convertArr2DLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next=temp;
        temp->back=mover;
        mover=mover->next;
    }
    return head;
}

void print(Node *head){
    Node *temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<temp->data;
}

Node* remove_duplicates(Node *head){
    Node *temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        Node *nextNode = temp->next;
        while(nextNode!=nullptr && nextNode->data == temp->data){
            Node *duplicate = nextNode;
            nextNode=nextNode->next;
            delete duplicate;
        }
        temp->next=nextNode;
        if(nextNode) nextNode->back=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,1,1,2,3,3,4};
    Node *head = convertArr2DLL(arr);

    print(remove_duplicates(head));
}