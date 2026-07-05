/*
Count the number of subarrays with given xor K

Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

Examples
Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Input: A = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int brute(int arr[],int n,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xr=0;
            for(int k=i;k<=j;k++){
                xr = xr^arr[k];
            }
            if(xr==k)
               cnt++;
        }
    }
    return cnt;
}

int better(int arr[],int n,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        int xr=0;
        for(int j=i;j<n;j++){
            xr = xr^arr[j];
            if(xr==k)
               cnt++;
        }
    }
    return cnt;
}

int optimal(int arr[],int n,int k){
    unordered_map<int,int> mpp;
    int cnt=0,xr=0;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
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