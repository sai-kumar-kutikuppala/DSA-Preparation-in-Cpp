/*
Find the repeating and missing numbers

Problem Statement: Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

Note: You are not allowed to modify the original array.

Examples
Example 1:
Input:
 nums = [3, 5, 4, 1, 1]  
Output:
 [1, 2]  
Explanation:
 1 appears twice in the array, and 2 is missing from the array. So the output is [1, 2].

Example 2:
Input:
 nums = [1, 2, 3, 6, 7, 5, 7]  
Output:
 [7, 4]  
Explanation:
 7 appears twice in the array, and 4 is missing from the array. So the output is [7, 4].
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> brute(int arr[],int n){
    int repeating=-1,missing=-1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i)
                cnt++;
        }
        if(cnt==2)
            repeating=i;
        if(cnt==0)
            missing=i;
        if(repeating!=-1 && missing!=-1)
            break;
    }
    return {repeating,missing};
}

vector<int> better(int arr[],int n){
    int *hash = new int[n+1]();
    int repeating=-1,missing=-1;
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
     for(int i=1;i<=n;i++){
        if(hash[i]==0)
            missing=i;
        if(hash[i]==2)
            repeating=i;
    }
    return {repeating,missing};

    delete[] hash;
}

vector<int> optimal(int arr[],int n){
    long long sn = n*(n+1)/2;
    long long s2n = n*(n+1)*(2*n+1)/6;

    long long s = 0;
    long long s2 = 0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        s2+=arr[i]*arr[i];
    }

    long long val1 = s-sn; // x-y
    long long val2 = s2-s2n; // x^2-y^2
    val2 = val2/val1; // x+y
    int x = (val1+val2)/2;
    int y = x-val1;
    return {x,y};
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    //vector<int> ans = brute(arr,n);
    //vector<int> ans = better(arr,n);
    vector<int> ans = optimal(arr,n);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;

    delete[] arr;
}