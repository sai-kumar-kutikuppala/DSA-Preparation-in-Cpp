/*
Count Subarray sum Equals K

Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k. A subarray is a contiguous non-empty sequence of elements within an array.

Examples
Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
Output: 2
Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

Input: N = 3, array[] = {1,2,3}, k = 3
Output: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int brute(int arr[],int n,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==k)
                cnt++;
        }
    }
    return cnt;
}

int better(int arr[],int n,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k)
                cnt++;
        }
    }
    return cnt;
}

int optimal(int arr[],int n,int k){
    unordered_map<int,int> mpp;
    mpp[0]=1;
    int preSum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        preSum+=arr[i];
        int rem = preSum-k;
        if(mpp.find(rem)!=mpp.end()){
            cnt+=mpp[rem];
        }
        mpp[preSum]++;
    }
    return cnt;
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
    cout<<better(arr,n,k)<<endl;
    cout<<optimal(arr,n,k)<<endl;
    
    delete[] arr;
}