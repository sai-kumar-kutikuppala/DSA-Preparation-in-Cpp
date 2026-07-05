/*
Add two numbers represented as Linked Lists

Problem Statement: Add two numbers represented as Linked Lists.

Examples

Example 1:
Input: num1 = 243, num2 = 564
Output:sum = 807; L = [7,0,8]

Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the or original number and then add them as → 342 + 465 = 807. 

Example 2:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: Result: [8,9,9,9,0,0,0,1]

Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the original number and then add them as → 9999999 + 9999 = 8999001. Refer to the image below.
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

Node* fun(Node *head1,Node *head2){
    Node *t1=head1,*t2=head2;
    Node *dummyNode = new Node(-1);
    Node *current=dummyNode;
    int carry=0,sum;
    while(t1!=nullptr || t2!=nullptr){
        sum=carry;
        if(t1) sum=sum+t1->data;
        if(t2) sum=sum+t2->data;
        Node *newNode = new Node(sum%10);
        carry=sum/10;
        current->next=newNode;
        current=current->next;
        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    if(carry){
        Node *newNode = new Node(carry);
        current->next=newNode;
    }
    return dummyNode->next;
}

int main(){
    vector<int> arr1 = {2,4,3};
    Node *head1 = convertArray2LL(arr1);
    vector<int> arr2 = {5,6,4};
    Node *head2 = convertArray2LL(arr2);

    print(fun(head1,head2)); 
}