/*
Longest Subarray with given Sum K(Positives)

Problem Statement: Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Examples
Example 1:
Input:
 nums = [10, 5, 2, 7, 1, 9], k = 15  
Output:
 4  
Explanation:
 The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

Example 2:
Input:
 nums = [-3, 2, 1], k = 6  
Output:
 0  
Explanation:
 There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int brute1(int arr[],int n,int k){
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==k)
                len = max(len,j-i+1);
        }
    }

    return len;
}

int brute2(int arr[],int n,int k){
    int len=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k)
                len=max(len,j-i+1);
        } 
    }
    return len;
}

int better(int arr[],int n,int k){ // it is recommended to keep k as long long
    long long sum=0;
    int maxLen=0;
    unordered_map<long long,int> mpp;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==k){
            maxLen = max(maxLen,i+1);
        }
        long long rem = sum-k;

        if(mpp.find(rem)!=mpp.end()){
            int len = i-mpp[rem];
            maxLen = max(maxLen,len);
        }

        if(mpp.find(sum) == mpp.end()){
            mpp[sum]=i;
        }
    }
    return maxLen;
}

int optimal(int arr[],int n,int k){ // it is recommended to keep k as long long
    long long sum=arr[0];
    int right = 0;
    int left = 0;
    int maxLen = 0;
    while(right<n){

        while(sum>k && left<=right){
            sum-=arr[left];
            left++;
        }

        if(sum==k){
            maxLen = max(maxLen,right-left+1);
        }

        right++;
        if(right<n){
            sum+=arr[right];
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
    int k;
    cin>>k;

    cout<<brute1(arr,n,k)<<endl;
    cout<<brute2(arr,n,k)<<endl;
    cout<<better(arr,n,k)<<endl;
    cout<<optimal(arr,n,k)<<endl;

    delete[] arr;
}