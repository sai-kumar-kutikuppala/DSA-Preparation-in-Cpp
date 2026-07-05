/*
Quick Sort Algorithm

Problem Statement: Given an array of n integers, sort the array using the Quicksort method.

Examples
Input: N = 5, Arr[] = {4,1,7,9,3}
Output: {1, 3, 4, 7, 9}
Explanation: After sorting the array in ascending order it becomes 1, 3, 4, 7, 9
Input: N = 8, Arr[] = {4,6,2,5,7,9,1,3}
Output: {1, 2, 3, 4, 5, 6, 7, 9}
Explanation: After sorting the array in ascending order it becomes 1, 2, 3, 4, 5, 6, 7, 9
*/

#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int i=low;
    int j=high;
    int pivot=arr[low];
    while(i<j){
        while(arr[i]<=pivot && i<=high-1)
            i++;
        while(arr[j]>pivot && j>=low+1)
            j--;
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[j];
    arr[j]=arr[low];
    arr[low]=temp;
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int parti = partition(arr,low,high);
        quickSort(arr,low,parti-1);
        quickSort(arr,parti+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    delete []arr;
}