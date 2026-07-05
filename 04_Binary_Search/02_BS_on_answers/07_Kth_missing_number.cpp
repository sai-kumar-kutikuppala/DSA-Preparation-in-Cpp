/*
Kth Missing Positive Number

Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

Examples
Example 1:
Input Format: vec[]={4,7,9,10}, k = 1
Result: 1
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.

Example 2:
Input Format: vec[]={4,7,9,10}, k = 4
Result: 5
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.
*/

#include<iostream>
using namespace std;

int brute(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]<=k)
            k++;
        else
            break;
    }
    return k;
}

int optimal(int arr[],int n,int k){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing = arr[mid]-(mid+1);
        if(missing<k)
            low=mid+1;
        else
            high=mid-1;
    }
    return low+k;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    
    cout<<brute(arr,n,k)<<endl;
    cout<<optimal(arr,n,k)<<endl;

    delete[] arr;
}