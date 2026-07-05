/*
Search Element in Rotated Sorted Array II

Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

Examples
Example 1:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Result: True
Explanation: The element 3 is present in the array. So, the answer is True.

Example 2:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Result: False
Explanation: The element 10 is not present in the array. So, the answer is False.
*/

#include<iostream>
using namespace std;

bool brute(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

bool optimal(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)
            return true;

        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++,high--;
            continue;
        }
        
        // left sorted
        if(arr[low]<=arr[mid]){
            if(target>=arr[low] && target<=arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        // right sorted
        else{
            if(target>=arr[mid] && target<=arr[high])
                low=mid+1;
            else
                high=mid-1;
        } 
    }
    return false;
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