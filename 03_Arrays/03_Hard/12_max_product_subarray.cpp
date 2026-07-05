/*
Maximum Product Subarray in an Array

Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

Examples
Input: Nums = [1,2,3,4,5,0]
Output: 120
Explanation: 
In the given array, 1×2×3×4×5 gives maximum product value.
Input: Nums = [1,2,-3,0,-4,-5]
Output: 20
Explanation: 
In the given array, (-4)×(-5) gives maximum product value.
*/

#include<iostream>
#include<climits>
using namespace std;

int brute(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int prod=1;
            for(int k=i;k<=j;k++){
                prod=prod*arr[k];
            }
            maxi=max(maxi,prod);
        }
    }
    return maxi;
}

int better(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int prod=1;
        for(int j=i;j<n;j++){
            prod=prod*arr[j];
            maxi=max(maxi,prod);
        }
    }
    return maxi;
}

int  optimal(int arr[],int n){
    int maxi = INT_MIN;
    int pre=1;
    int suff=1;
    for(int i=0;i<n;i++){
        if(pre==0)
            pre=1;
        if(suff==0)
            suff=1;
        pre=pre*arr[i];
        suff=suff*arr[n-i-1];
        maxi=max(maxi,max(pre,suff));
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<brute(arr,n)<<endl;
    cout<<better(arr,n)<<endl;
    cout<<optimal(arr,n)<<endl;

    delete[] arr;
}