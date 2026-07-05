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

Node* remove_occurrences(Node *head,int key){
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            if(temp==head)
                head=head->next;
            Node *prevNode = temp->back;
            Node *nextNode = temp->next;
            if(prevNode) prevNode->next=nextNode;
            if(nextNode) nextNode->back=prevNode;
            delete temp;
            temp=nextNode;
        }
        else
            temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {10,4,10,10,6,10};
    Node *head = convertArr2DLL(arr);
    int key;
    cin>>key;

    print(remove_occurrences(head,key));
}