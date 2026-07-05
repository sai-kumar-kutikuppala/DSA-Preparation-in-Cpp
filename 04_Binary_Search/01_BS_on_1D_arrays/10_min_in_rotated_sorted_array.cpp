/*
Minimum in Rotated Sorted Array

Problem Statement:
Given an integer array arr of size N, sorted in ascending order (with distinct values), the array is rotated at any index which is unknown. Find the minimum element in the array.

Examples
Input: arr = [4,5,6,7,0,1,2,3]
Output: 0
Explanation: The minimum element in the array is 0.
Input : arr = [3,4,5,1,2]
Output: 1
Explanation : The minimum element in the array is 1.
*/

#include<iostream>
#include<climits>
using namespace std;

int brute(int arr[],int n){
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(mini,arr[i]);
    }
    return mini;
}

int optimal(int arr[],int n){
    int low=0,high=n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[low]<=arr[high]){
            ans = min(ans,arr[low]);
            break;
        }

        if(arr[low]<=arr[mid]){
            ans = min(ans,arr[low]);
            low=mid+1;
        }
        else{
            ans = min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;
}

int optimal_duplicates(int arr[],int n){
    int low=0,high=n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++,high--;
            continue;
        }

        if(arr[low]<=arr[high]){
            ans = min(ans,arr[low]);
            break;
        }

        if(arr[low]<=arr[mid]){
            ans = min(ans,arr[low]);
            low=mid+1;
        }
        else{
            ans = min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<brute(arr,n)<<endl;
    cout<<optimal(arr,n)<<endl;

    delete[] arr;
}