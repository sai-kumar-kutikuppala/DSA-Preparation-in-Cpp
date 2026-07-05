/*
Search Single Element in a sorted array

Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

Examples
Input : arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Output: 4
Explanation: Only the number 4 appears once in the array.

Input: arr[] = {1,1,3,5,5}
Output : 3
Explanation: Only the number 3 appears once in the array.
*/

#include<iostream>
using namespace std;

int brute(int arr[],int n){
    if(n==1)
        return arr[0];
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[i]!=arr[i+1])
                return arr[i];  
        }
        else if(i==n-1){
            if(arr[n-1]!=arr[n-2])
                return arr[i];
        }
        else{
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])
                return arr[i];
        }
    }
}

int optimal(int arr[],int n){
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=1,high=n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }

        else if((mid%2==0 && arr[mid]==arr[mid+1]) || (mid%2==1 && arr[mid]==arr[mid-1])){
            low=mid+1;
        }

        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<brute(arr,n)<<endl;
    cout<<optimal(arr,n)<<endl;

    delete[] arr;
}
