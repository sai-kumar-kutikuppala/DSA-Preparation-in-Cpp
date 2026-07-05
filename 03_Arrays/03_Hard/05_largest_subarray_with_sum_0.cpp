/*
Length of the longest subarray with zero Sum

Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Examples
Example 1:
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result:
 5  
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.

Example 2:
Input:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}  
Result:
 8  
Explanation:
 Subarrays with sum zero:
- {-2, 2}
- {-8, 1, 7}
- {-2, 2, -8, 1, 7}
- {6, -2, 2, -8, 1, 7, 4, -10}
The length of the longest subarray with sum zero is 8.
*/

#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int brute(int arr[],int n){
    int maxLen = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==0)
                maxLen=max(maxLen,j-i+1);
        }
    }
    return maxLen;
}

int better(int arr[],int n){
    int maxLen = INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==0)
                maxLen=max(maxLen,j-i+1);
        }
    }
    return maxLen;
}

int optimal(int arr[],int n){
    unordered_map<int,int> mpp;
    int presum=0;
    int maxLen=INT_MIN;
    for(int i=0;i<n;i++){
        presum+=arr[i];
        if(presum==0){
            maxLen = max(maxLen,i+1);
        }
        else if(mpp.find(presum)!=mpp.end()){
            maxLen = max(maxLen,i-mpp[presum]);
        }
        else{ // sum is seen first time
            mpp[presum]=i;
        }
    }
    return maxLen;
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