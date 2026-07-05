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

vector<pair<int,int>> brute(Node *head,int sum){
    vector<pair<int,int>> ans;
    Node *temp1=head;
    while(temp1!=nullptr){
        Node *temp2=temp1->next;
        while(temp2!=nullptr && temp1->data + temp2->data <=sum){
            if(temp1->data + temp2->data == sum)
                ans.push_back({temp1->data,temp2->data});
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return ans;
}

Node* findTail(Node *head){
    Node *tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    return tail;
}

vector<pair<int,int>> optimal(Node *head,int sum){
    vector<pair<int,int>> ans;
    Node *left=head,*right=findTail(head);
    while(left->data<right->data){
        if(left->data+right->data==sum){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }
        else if(left->data+right->data==sum)
            left=left->next;
        else
            right=right->back;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,9};
    Node *head = convertArr2DLL(arr);
    int sum;
    cin>>sum;

    vector<pair<int,int>> ans1 = brute(head,sum);
    cout<<"{";
    for(auto it:ans1)
        cout<<"("<<it.first<<","<<it.second<<")";
    cout<<"}";

    cout<<endl;

    vector<pair<int,int>> ans2 = optimal(head,sum);
    cout<<"{";
    for(auto it:ans2)
        cout<<"("<<it.first<<","<<it.second<<")";
    cout<<"}";
}