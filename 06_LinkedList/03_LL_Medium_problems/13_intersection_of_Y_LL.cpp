/*
Find intersection of Two Linked Lists

Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Examples
Example 1:
Input:

List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:

2
Explanation:
 Here, both lists intersecting nodes start from node 2.

Example 2:
Input:

 List1 = [1,2,7], List 2 = [2,8,1]
Output:

 Null
Explanation:
 Here, both lists do not intersect and thus no intersection node is present.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
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

Node* brute(Node *head1,Node *head2){
    unordered_map<Node*,int> mpp;
    Node *temp=head1;
    while(temp!=nullptr){
        mpp[temp]=1;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end())
            return temp;
        temp=temp->next;
    }
    return nullptr;
}

Node* collisionPoint(Node *t1,Node *t2,int d){
    while(d){
        t2=t2->next;
        d--;
    }
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;
}

Node* better(Node *head1,Node *head2){
    Node *temp=head1;
    int N1=0;
    while(temp!=nullptr){
        N1++;
        temp=temp->next;
    }
    int N2=0;
    temp=head2;
    while(temp!=nullptr){
        N2++;
        temp=temp->next;
    }
    if(N1<N2) return collisionPoint(head1,head2,N1-N2);
    return collisionPoint(head2,head1,N2-N1);
}

Node* optimal(Node *head1,Node *head2){
    Node *t1=head1,*t2=head2;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1==t2)
            return t1;
        if(t1==nullptr)
            t1=head2;
        if(t2==nullptr)
            t2=head1;
    }
    return t1; // if first node is the collision point
}


int main(){
    vector<int> arr1 = {1,2,3,4,5};
    Node *head1 = convertArray2LL(arr1);
    vector<int> arr2 = {10,20};
    Node *head2 = convertArray2LL(arr2);
    head2->next->next=head1->next->next; // [1,2,3,4,5] [10,20,3,4,5] 3 is the intersection
    
    cout<<brute(head1,head2)->data<<endl;
    cout<<better(head1,head2)->data<<endl;
    cout<<optimal(head1,head2)->data<<endl;
}
