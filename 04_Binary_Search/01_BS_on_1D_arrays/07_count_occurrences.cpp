/*
Count Occurrences in Sorted Array

Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Examples
Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output
: 4
Explanation:
 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input:
 N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output
: 5
Explanation:
 2 is occurring 5 times in the given array so it is our answer.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int count_occurrences(int arr[],int n,int x){ // using upper and lower bound
    int first = lower_bound(arr,arr+n,x)-arr;
    if(first==n || arr[first]!=x)
        return 0;
    int last = (upper_bound(arr,arr+n,x)-arr)-1;
    return last-first+1;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;

    cout<<count_occurrences(arr,n,x)<<endl;

    delete[] arr;
}