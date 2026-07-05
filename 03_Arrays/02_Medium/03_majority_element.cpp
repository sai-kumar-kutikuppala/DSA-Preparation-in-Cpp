/*
Find the Majority Element that occurs more than N/2 times

Problem Statement: Given an integer array nums of size n, return the majority element of the array.

The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

Examples
Example 1:
Input:
 nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
Output:
 7  
Explanation:
 The number 7 appears 5 times in the 9-sized array, making it the most frequent element.

Example 2:
Input:
 nums = [1, 1, 1, 2, 1, 2]  
Output:
 1  
Explanation:
 The number 1 appears 4 times in the 6-sized array, making it the most frequent element.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int brute(int arr[],int n){
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j])
                cnt++;
        }
        if(cnt>n/2)
            return arr[i];
    }
}

int better(int arr[],int n){
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto i:mpp){
        if(i.second>n/2){
            return i.first;
        }
    }
}

int optimal(int arr[],int n){
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }

    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el)
            cnt1++;
    }

    if(cnt1>n/2)
        return el;
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