/*
Reverse a given Array

Problem Statement: You are given an array. The task is to reverse the array and print it.

Examples
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.
*/

#include<iostream>
#include<vector>
using namespace std;

void reverse(int arr[],int n,int l,int u){
    if(l>=u)
        return;
    int temp;
    temp=arr[l];
    arr[l]=arr[u];
    arr[u]=temp;
    reverse(arr,n,l+1,u-1);
}

void reverse_vector(vector<int>& arr){
    int l=0,u=arr.size()-1;
    while(l<u){
        swap(arr[l],arr[u]);
        l++;
        u--;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[50];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    reverse(arr,n,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    
    cout<<endl;

    
    vector<int> v;
    int e;
    for(int i=0;i<n;i++){
        cin>>e;
        v.push_back(e);
    }

    reverse_vector(v);

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    
}