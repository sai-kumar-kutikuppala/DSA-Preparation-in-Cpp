/*
Sort an array of 0s, 1s and 2s

Problem Statement: Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array.

Examples
Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Input: nums = [0, 0, 1, 1, 1]
Output: [0, 0, 1, 1, 1]
Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos.
*/

#include<iostream>
#include<algorithm>
using namespace std;

void brute(int arr[],int n){
    // Use quick sort
    sort(arr,arr+n);
}

void better(int arr[],int n){
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
            cnt0++;
        else if(arr[i]==1)
            cnt1++;
        else
            cnt2++;
    }

    for(int i=0;i<cnt0;i++)
        arr[i]=0;
    for(int i=cnt0;i<cnt0+cnt1;i++)
        arr[i]=1;
    for(int i=cnt0+cnt1;i<n;i++)
        arr[i]=2;
}

void optimal(int arr[],int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //brute(arr,n);
    //for(int i=0;i<n;i++)
    //    cout<<arr[i]<<" ";

    //better(arr,n);
    //for(int i=0;i<n;i++)
    //    cout<<arr[i]<<" ";

    
    optimal(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    delete[] arr;
}