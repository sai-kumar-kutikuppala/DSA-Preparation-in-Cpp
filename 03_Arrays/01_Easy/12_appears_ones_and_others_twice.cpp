/*
Find the number that appears once, and the other numbers twice

Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Examples
Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.


Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.
*/

#include<iostream>
#include<map>
using namespace std;

int appears_ones_brute(int arr[],int n){
    for(int i=0;i<n;i++){
        int e=arr[i];
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==e){
                cnt++;
            }
        }
        if(cnt==1)
            return e;
    }
}

int appears_ones_better(int arr[],int n){
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second==1){
            return it.first;
        }
    }
}

int appears_ones_optimal(int arr[],int n){
    int XOR=0;
    for(int i=0;i<n;i++){
        XOR = XOR ^ arr[i];
    }
    return XOR;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<appears_ones_brute(arr,n)<<endl;
    cout<<appears_ones_better(arr,n)<<endl;
    cout<<appears_ones_optimal(arr,n)<<endl;

    delete[] arr;
}