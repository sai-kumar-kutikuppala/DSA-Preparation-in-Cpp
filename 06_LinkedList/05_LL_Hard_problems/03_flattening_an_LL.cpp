/*
Flattening a Linked List

Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head

Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.

HEAD
 |
 v
[3] -> [2] -> [1] -> [4] -> [5] -> NULL
        |      |      |      |
        v      v      v      v
       [10]   [7]    [9]    [6]
        |      |      |      |
       NULL    v     NULL    v
              [11]          [8]
               |             |
               v            NULL
              [12]
               |
              NULL
              
Output: 1 2 3 4 5 6 7 8 9 10 11 12 
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* child;

    Node(int val) {
    data  = val;
    next  = nullptr;
    child = nullptr;
    }
};

Node* create_multilevel_LL(){
     // Main level nodes
    Node* n3  = new Node(3);
    Node* n2  = new Node(2);
    Node* n1  = new Node(1);
    Node* n4  = new Node(4);
    Node* n5  = new Node(5);

    // Level 2 nodes
    Node* n10 = new Node(10);
    Node* n7  = new Node(7);
    Node* n9  = new Node(9);
    Node* n6  = new Node(6);

    // Level 3 nodes
    Node* n11 = new Node(11);
    Node* n8  = new Node(8);

    // Level 4 node
    Node* n12 = new Node(12);

    // Main list: 3 -> 2 -> 1 -> 4 -> 5 -> NULL
    n3->next = n2;
    n2->next = n1;
    n1->next = n4;
    n4->next = n5;

    // Children
    n2->child = n10;           // 2's child: 10
    n1->child = n7;            // 1's child: 7
    n4->child = n9;            // 4's child: 9
    n5->child = n6;            // 5's child: 6

    // 7's child chain: 7 -> child -> 11 -> child -> 12
    n7->child  = n11;
    n11->child = n12;

    // 6's child: 8
    n6->child = n8;

    // Print
    Node* head = n3;
}

void print(Node *head){
    Node *temp=head;
    while(temp->child!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->child;
    }
    cout<<temp->data;
}

/*---------------------------------------------------------------------------------------------------*/
Node* convertArray2LL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->child=temp;
        mover=mover->child;
    }
    return head;
}

Node* brute(Node *head){
    vector<int> ds;
    Node *temp1=head;
    while(temp1!=nullptr){
        Node *temp2=temp1;
        while(temp2!=nullptr){
            ds.push_back(temp2->data);
            temp2=temp2->child;
        }
        temp1=temp1->next;
    }
    sort(ds.begin(),ds.end());
    return convertArray2LL(ds);
}
/*---------------------------------------------------------------------------------------------------*/
Node* merge2Lists(Node *list1,Node *list2){
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<list2->data){
            res->child=list1;
            res=res->child;
            list1=list1->child;
        }
        else{
            res->child=list2;
            res=res->child;
            list2=list2->child;
        }
        res->next=nullptr;
    }
    if(list1) res->child=list1;
    else res->child=list2;
    return dummyNode->child;
}

Node* optimal(Node *head){
    if(head==nullptr || head->next==nullptr)
        return head;
    Node *mergeHead = optimal(head->next);
    return merge2Lists(head,mergeHead);
}
/*---------------------------------------------------------------------------------------------------*/

int main() {
    Node *head = create_multilevel_LL();

    //print(brute(head));
    print(optimal(head));
}