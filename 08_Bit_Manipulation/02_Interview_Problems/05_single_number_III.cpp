/*
Find the two numbers appearing odd number of times

Problem Statement: Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.

For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

Examples
Example 1:
Input:
 nums = [1, 2, 1, 3, 5, 2]
Output:
 [3, 5]
Explanation:

The integers 3 and 5 have appeared only once.

Example 2:
Input:
 nums = [-1, 0]
Output:
 [-1, 0]
Explanation:

The integers -1 and 0 have appeared only once.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

pair<int,int> brute(int arr[],int n){
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++)
        mpp[arr[i]]++;

    vector<int> ans;
    for(auto it:mpp){
        if(it.second==1)
            ans.push_back(it.first);
    }
    return {ans[0],ans[1]};
}

pair<int,int> optimal(int arr[],int n){
    int XOR=0;
    for(int i=0;i<n;i++)
        XOR=XOR^arr[i];
    int rightMost = (XOR & (XOR-1)) & XOR;
    int b1=0,b2=0;
    for(int i=0;i<n;i++){
        if(arr[i] & rightMost)
            b1=b1^arr[i];
        else
            b2=b2^arr[i];
    }
    return {b1,b2};
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    pair<int,int> p1 = brute(arr,n);
    cout<<p1.first<<" "<<p1.second<<endl;

    pair<int,int> p2 = optimal(arr,n);
    cout<<p2.first<<" "<<p2.second<<endl;

    delete[] arr;
}