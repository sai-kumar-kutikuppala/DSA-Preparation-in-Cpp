/*
Rotate array by K elements

Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

Examples
Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 2, right
Output : [6, 7, 1, 2, 3, 4, 5]
Explanation : rotate 1 step to the right: [7, 1, 2, 3, 4, 5, 6]
rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5] 

Input : nums = [1, 2, 3, 4, 5, 6], k=2, left
Output : [3, 4, 5, 6, 1, 2]
Explanation :rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void left_rotate_brute(int arr[],int n,int k){
    k=k%n;
    vector<int> temp;
    for(int i=0;i<k;i++)
        temp.push_back(arr[i]);
    for(int i=k;i<n;i++)
        arr[i-k]=arr[i];
    for(int i=n-k;i<n;i++)
        arr[i]=temp[i-(n-k)];
}

void rev(int[],int,int);
void left_rotate_optimal(int arr[],int n,int k){
    k=k%n;
    //reverse(arr,arr+k);
    //reverse(arr+k,arr+n);
    //reverse(arr,arr+n);
    rev(arr,0,k-1);
    rev(arr,k,n-1);
    rev(arr,0,n-1);
}

void rev(int arr[],int start,int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;

    //left_rotate_brute(arr,n,k);
    //for(int i=0;i<n;i++)
    //    cout<<arr[i]<<" ";

    left_rotate_optimal(arr,n,k);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    delete[] arr;
}