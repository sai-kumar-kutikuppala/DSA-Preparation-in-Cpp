/*
Given an array arr[] of size n-1 with distinct integers in the range of [1, n]. This array represents a permutation of the integers from 1 to n with one element missing. Find the missing element in the array.

Examples: 

Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: Here the size of the array is 4, so the range will be [1, 5]. The missing number between 1 to 5 is 4
*/

#include<iostream>
using namespace std;

int missing_brute(int arr[],int n){
    for(int i=1;i<=n+1;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                flag=1;
            }
        }
        if(flag==0)
            return i;
    }
}

int missing_better(int arr[],int n){
    int *hash = new int[n+2]{}; // iniatialize with zeroes
    for(int i=0;i<n;i++){
        hash[arr[i]]=1;
    }

    for(int i=1;i<n+2;i++){
        if(hash[i]==0){
            return i;
        }
    }

    delete[] hash;
}

int missing_optimal_sum(int arr[],int n){
    int sum = (n+1)*(n+1+1)/2;
    int s=0;
    for(int i=0;i<n;i++)
        s+=arr[i];

    return sum-s;
}

int missing_optimal_xor(int arr[],int n){
    int XOR1 = 0;
    int XOR2 = 0;
    for(int i=1;i<=n+1;i++)
        XOR1 = XOR1 ^ i;
    for(int i=0;i<n;i++)
        XOR2 = XOR2 ^ arr[i];

    return XOR1 ^ XOR2;
}


int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<missing_brute(arr,n)<<endl;
    cout<<missing_better(arr,n)<<endl;
    cout<<missing_optimal_sum(arr,n)<<endl;
    cout<<missing_optimal_xor(arr,n)<<endl;

    delete[] arr;
}

/*
input.txt:
    sample1:
        5
        1 2 3 4 5
    sample2:
        5
        1 2 3 4 6
*/