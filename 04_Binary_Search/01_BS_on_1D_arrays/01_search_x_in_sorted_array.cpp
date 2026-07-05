/*
Binary Search: Explained

Problem statement: You are given a sorted array of integers and a target,
 your task is to search for the target in the given array. 
 Assume the given array does not contain any duplicate numbers.
*/

#include<iostream>
using namespace std;

int BS_iterative(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int BS_recursive(int arr[],int low,int high,int target){
    int mid = (low+high)/2;
    if(low > high)
        return -1;
    if(arr[mid]==target)
        return mid;
    else if(arr[mid]<target)
        return BS_recursive(arr,mid+1,high,target);
    return BS_recursive(arr,low,mid-1,target);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int target;
    cin>>target;
    
    cout<<BS_iterative(arr,n,target)<<endl;
    cout<<BS_recursive(arr,0,n-1,target)<<endl;

    delete[] arr;
}