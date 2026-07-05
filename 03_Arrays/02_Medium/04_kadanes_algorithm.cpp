/*
Kadane's Algorithm : Maximum Subarray Sum in an Array

Problem Statement: Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.

Examples
Example 1:
Input:
 nums = [2, 3, 5, -2, 7, -4]  
Output:
 15  
Explanation:
 The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.

Example 2:
Input:
 nums = [-2, -3, -7, -2, -10, -4]  
Output:
 -2  
Explanation:
 The largest sum is -2, which comes from taking the element at index 0 or index 3 as the subarray. Since all numbers are negative, the subarray with the least negative number gives the largest sum.
*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;


int brute(int arr[],int n){ 
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum>maxi)
                maxi=sum;
        }
    }
    return maxi;
}

int better(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>maxi)
                maxi=sum;
        }
    }
    return maxi;
}

//Kadane's algorithm
int optimal1(int arr[],int n){
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi)
            maxi=sum;
        if(sum<0)
            sum=0;
    }
    return maxi;
}

//printing the sub array
vector<int> optimal2(int arr[],int n){
    int startIndex;
    int endIndex;
    int start;
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(sum==0)
            start=i;
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            startIndex=start;
            endIndex=i;
        }
        if(sum<0)
            sum=0;
    }
    return {startIndex,endIndex};
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<brute(arr,n)<<endl;
    cout<<better(arr,n)<<endl;
    cout<<optimal1(arr,n)<<endl;

    vector<int> v = optimal2(arr,n);
    cout<<v[0]<<" "<<v[1]<<endl;
    for(int i=v[0];i<=v[1];i++)
        cout<<arr[i]<<" ";

    delete[] arr;
}

