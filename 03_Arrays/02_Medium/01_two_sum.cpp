/*
Two Sum : Check if a pair with given sum exists in Array

Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Examples

Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
Output : YES
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for second variant output will be : [1,3].

Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
Output : NO.
Explanation: There exist no such two numbers whose sum is equal to the target. 
*/


#include<iostream>
#include<unordered_map>
using namespace std;

string brute1(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(arr[i]+arr[j]==target)
                return "YES";
        }
    }
    return "NO";
}

string brute2(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target)
                return "YES";
        }
    }
    return "NO";
}

string better(int arr[],int n,int target){
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int b = target-a;
        if(mpp.find(b)!=mpp.end())
            return "YES";
        mpp[a]=i;
    }
    return "NO";
}

string optimal(int arr[],int n,int target){
    int left=0;
    int right=n-1;
    while(left<right){
        if(arr[left]+arr[right]==target)
            return "YES";
        else if(arr[left]+arr[right]<target)
            left++;
        else    
            right--;
    }
    return "NO";
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int target;
    cin>>target;

    cout<<brute1(arr,n,target)<<endl;
    cout<<brute2(arr,n,target)<<endl;
    cout<<better(arr,n,target)<<endl;
    cout<<optimal(arr,n,target)<<endl;

    delete[] arr;
}