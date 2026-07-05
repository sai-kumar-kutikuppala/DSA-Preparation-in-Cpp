/*
Move all Zeros to the end of the array

Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Examples
Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
Input : 1,2,0,1,0,4,0
Output: 1,2,1,4,0,0,0
Explanation : All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
*/

#include<iostream>
#include<vector>
using namespace std;

void move_zero_brute(int arr[],int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    int n1=temp.size();
    for(int i=0;i<n1;i++){
        arr[i]=temp[i];
    }
    for(int i=n1;i<n;i++){
        arr[i]=0;
    }
}

void move_zero_optimal(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==0){
            break;
        }
    }

    for(int j=i+1;j<n;j++){
        if(arr[j]!=0){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }

    while(i<n){
        arr[i]=0;
        i++;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //move_zero_brute(arr,n);
    //for(int i=0;i<n;i++)
    //    cout<<arr[i]<<" ";

    move_zero_optimal(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    delete[] arr;
}