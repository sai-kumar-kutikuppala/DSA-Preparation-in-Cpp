/*
Floor and Ceil in Sorted Array

Problem Statement: ou're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x

Examples

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int ceil(int arr[],int n,int x){
    int ind = lower_bound(arr,arr+n,x)-arr;
    return arr[ind];
}

int floor(int arr[],int n,int x){
    int low=0,high=n-1;
    int ans;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]<=x){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return arr[ans];
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;

    cout<<floor(arr,n,x)<<" ";
    cout<<ceil(arr,n,x);

    delete[] arr;
}