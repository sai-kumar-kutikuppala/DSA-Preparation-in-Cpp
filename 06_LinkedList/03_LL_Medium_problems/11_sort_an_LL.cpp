/*
Sort a Linked List

Problem Statement: Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.

Examples
Input: 3->4->2->1->5 

Output: 1->2->3->4->5

Explanation: The input linked list when sorted from [3, 4, 2, 1, 5] results in a linked list with values [1, 2, 3, 4, 5].
Input: 40->20->60->10->50->30

Output: 10->20->30->40->50->60

Explanation: The input linked list when sorted from [40, 20, 60, 10, 50, 30] results in a linked list with values [10, 20, 30, 40, 50, 60].
*/

#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<int> ds;
    while(temp!=nullptr){
        ds.push_back(temp->data);
        temp=temp->next;
    }

    sort(ds.begin(),ds.end());

    temp=head;
    int i=0;
    while(temp!=nullptr){
        temp->data=ds[i];
        temp=temp->next;
        i++;
    }
    return head;
}

/*---------------------------------------------------------------------------------------------------*/
Node* findMiddle(Node *head){
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* merge2Lists(Node *list1,Node *list2){
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<list2->data){
            res->next=list1;
            list1=list1->next;
            res=res->next;
        }
        else{
            res->next=list2;
            list2=list2->next;
            res=res->next;
        }
    }
    if(list1) res->next=list1;
    else res->next=list2;
    return dummyNode->next;
}

Node* MS(Node *head){
    if(head==nullptr || head->next==nullptr)
        return head;
    
    Node *middle = findMiddle(head);
    Node *leftHead = head;
    Node *rightHead = middle->next;
    middle->next=nullptr;

    leftHead = MS(leftHead);
    rightHead = MS(rightHead);

    return merge2Lists(leftHead,rightHead);
}
/*---------------------------------------------------------------------------------------------------*/


int main(){
    vector<int> arr = {5,4,3,2,1};
    Node *head = convertArray2LL(arr);

    //print(brute(head));
    print(MS(head));
}