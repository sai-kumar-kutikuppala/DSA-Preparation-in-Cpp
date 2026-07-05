/*
Find the Largest element in an array

Problem Statement: Given an array, we have to find the largest element in the array.

Examples
Example 1:
Input:
 arr[] = {2, 5, 1, 3, 0}  
Output:
 5  
Explanation:
  
5 is the largest element in the array.

Example 2:
Input:
 arr[] = {8, 10, 5, 7, 9}  
Output:
 10  
Explanation:
  
10 is the largest element in the array.
*/

#include<iostream>
#include<algorithm>
using namespace std;


int largest_brute(int arr[],int n){
    sort(arr,arr+n);
    return arr[n-1];
}

int largest_optimal(int arr[], int n){
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<largest_brute(arr,n)<<endl;
    cout<<largest_optimal(arr,n)<<endl;
   
    delete[] arr;
}