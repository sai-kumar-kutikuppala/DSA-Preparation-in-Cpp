/*
Search Element in a Rotated Sorted Array

Problem Statement: Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.

Examples
Input:nums = [4, 5, 6, 7, 0, 1, 2], k = 0
Output :4
Explanation : Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3
Output :-1
Explanation :Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.
*/

#include<iostream>
using namespace std;

int brute(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int optimal(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)
            return mid;
        // left sorted
        else if(arr[low]<=arr[mid]){
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
    return -1;
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