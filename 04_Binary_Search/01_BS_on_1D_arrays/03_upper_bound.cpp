/*
Implement Upper Bound

Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

What is Upper Bound?
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

Examples
Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.

Example 2:
Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
Result: 4
Explanation: Index 4 is the smallest index such that arr[4] > x.
*/

#include<iostream>
using namespace std;

int brute(int arr[],int n,int x){
    int ans=n;
    for(int i=0;i<n;i++){
        if(arr[i]>x){
            ans=i;
            break;
        }
    }
    return ans;
}

int optimal(int arr[],int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else   
            low=mid+1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;

    cout<<brute(arr,n,x)<<endl;
    cout<<optimal(arr,n,x)<<endl;

    delete[] arr;
}