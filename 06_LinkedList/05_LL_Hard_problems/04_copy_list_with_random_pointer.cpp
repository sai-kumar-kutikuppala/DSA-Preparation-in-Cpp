/*
Clone Linked List with Random and Next Pointer

Problem Statement: Given a linked list where every node in the linked list contains two pointers:

‘next’ which points to the next node in the list.
‘random’ which points to a random node in the list or ‘null’.
Create a ‘deep copy’ of the given linked list and return it.

input:
   head
    |
    7 -> 13 -> 11 -> 10 -> 1 -> NULL

    Random pointers:
    7  -> NULL
    13 -> 7
    11 -> 1
    10 -> 11
    1  -> 7
*/

#include <iostream>
#include<unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = nullptr;
        random = nullptr;
    }
};

Node* create_random_pointer_list(){
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    Node* head = n1;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;
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
    unordered_map<Node*,Node*> mpp;
    Node *temp=head;
    while(temp!=nullptr){
        Node *copyNode = new Node(temp->data);
        mpp[temp]=copyNode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp=temp->next;
    }
    return mpp[head];
}

Node* optimal(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        Node *copyNode = new Node(temp->data);
        copyNode->next=temp->next;
        temp->next=copyNode;
        temp=temp->next->next;
    }

    temp=head;
    while(temp!=nullptr){
        Node *copyNode = temp->next;
        if(temp->random)
            copyNode->random = temp->random->next;
        else
            copyNode->random=nullptr;
        temp=temp->next->next;
    }

    Node *dNode = new Node(-1);
    Node *res = dNode;
    temp=head;
    while(temp!=nullptr){
        res->next=temp->next;
        temp->next=temp->next->next;

        res=res->next;
        temp=temp->next;
    }
    return dNode->next;
}

int main() {
    Node *head = create_random_pointer_list();

    //print(brute(head));
    print(optimal(head));
}