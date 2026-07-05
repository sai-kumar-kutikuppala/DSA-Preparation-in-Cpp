/*
Insertion Sort Algorithm

Problem Statement: Given an array of integers called nums, sort the array in non-decreasing order using the insertion sort algorithm and return the sorted array.

A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

Examples
Example 1:
Input:
  nums = [7, 4, 1, 5, 3]  
Output:
  [1, 3, 4, 5, 7]  
Explanation:
  The array is sorted in non-decreasing order: 1 ≤ 3 ≤ 4 ≤ 5 ≤ 7.

Example 2:
Input:
  nums = [5, 4, 4, 1, 1]  
Output:
  [1, 1, 4, 4, 5]  
Explanation:
  The array is sorted in non-decreasing order: 1 ≤ 1 ≤ 4 ≤ 4 ≤ 5.

*/

#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    delete []arr;
}
