/*
Peak element in Array

Problem Statement: Given an array of length N, peak element is defined as the element greater than both of its neighbors. Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i]. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Examples
Input: arr[] = {1,2,3,4,5,6,7,8,5,1}
Output: 7
Explanation: There is only 1 peak element, 8,  that is at index 7.
Input: arr[] = {1,2,1,3,5,6,4} 
Output: 1 
Explanation : There are 2 peak numbers that are at indices 1 and 5. We can return any of t
*/

#include<iostream>
using namespace std;

int brute(int arr[],int n){
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            return i;
    }
}

int optimal(int arr[],int n){
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;

    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            return mid;
        else if(arr[mid]>arr[mid-1])
            low=mid+1;
        else if(arr[mid]>arr[mid+1])
            high=mid-1;
        else
            low=mid+1;
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