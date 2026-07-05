/*
Minimum days to make M bouquets

Problem Statement: You are given 'N’ roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day. You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet. Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

Examples
Example 1:
Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
Result: 12
Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

Example 2:
Input Format: N = 5, arr[] = {1, 10, 3, 10, 2}, m = 3, k = 2
Result: -1
Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool possible(int arr[],int n,int days,int m,int k){
    int cnt=0;
    int maxB=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=days){
            cnt++;
        }
        else{
            maxB+=cnt/k;
            cnt=0;
        }
    }
    maxB+=cnt/k;
    if(maxB>=m)
        return true;
    else
        return false;
}

int brute(int arr[],int n,int m,int k){

    if(n<m*k) return -1;

    int maxi = *max_element(arr,arr+n);
    int mini = *min_element(arr,arr+n);
    for(int i=mini;i<=maxi;i++){
        if(possible(arr,n,i,m,k)){
            return i;
        }
    }
    return -1;
}

int optimal(int arr[],int n,int m,int k){

    if(n<m*k) return -1;
    
    int maxi = *max_element(arr,arr+n);
    int mini = *min_element(arr,arr+n);
    int low=mini,high=maxi;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(arr,n,mid,m,k)){
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int m,k;
    cin>>m>>k;

    cout<<brute(arr,n,m,k)<<endl;
    cout<<optimal(arr,n,m,k)<<endl;

    delete[] arr;
}