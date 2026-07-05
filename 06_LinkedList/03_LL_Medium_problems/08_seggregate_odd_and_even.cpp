/*
Segregate even and odd nodes in LinkedList

Problem Statement: Given the head of a singly linked list. Group all the nodes with odd indices followed by all the nodes with even indices and return the reordered list. Consider the 1st node to have index 1 and so on. The relative order of the elements inside the odd and even group must remain the same as the given input.
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
    if(head==nullptr || head->next==nullptr)
        return head;
    Node *temp=head;
    vector<int> ans;
    while(temp!=nullptr && temp->next!=nullptr){
        ans.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) ans.push_back(temp->data);
    
    temp=head->next;
    while(temp!=nullptr && temp->next!=nullptr){
        ans.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) ans.push_back(temp->data);

    temp=head;
    int i=0;
    while(temp!=nullptr){
        temp->data=ans[i];
        temp=temp->next;
        i++;
    }
    return head;
}

Node *optimal(Node *head){
    if(head==nullptr || head->next==nullptr)
        return head;
    Node *odd=head,*even=head->next,*evenHead=head->next;
    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node *head = convertArray2LL(arr);
    
    //print(brute(head));
    cout<<endl;
    print(optimal(head));
}