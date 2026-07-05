/*
Painter's Partition Problem

Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

Examples
Example 1:
Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
Result: 10
Explanation: We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.

Example 2:
Input Format: N = 4, boards[] = {10, 20, 30, 40}, k = 2
Result: 60
Explanation: We can divide the first 3 boards for one painter and the last board for the second painter.
*/

#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int fun(int arr[],int n,int maxArea){
    int painters=0,area=0;
    for(int i=0;i<n;i++){
        if(area+arr[i]<=maxArea)
            area+=arr[i];
        else{
            painters++;
            area=arr[i];
        }
    }
    return painters+1;
}

int brute(int arr[],int n,int k){
    int maxi = *max_element(arr,arr+n);
    int sum = accumulate(arr,arr+n,0);
    for(int i=maxi;i<=sum;i++){
        if(fun(arr,n,i)==k)
            return i;
    }
}

int optimal(int arr[],int n,int k){
    int maxi = *max_element(arr,arr+n);
    int sum = accumulate(arr,arr+n,0);
    int low=maxi,high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        if(fun(arr,n,mid)>k)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
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