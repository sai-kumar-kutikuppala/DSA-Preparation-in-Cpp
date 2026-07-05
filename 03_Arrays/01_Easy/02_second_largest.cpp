/*
Find Second Smallest and Second Largest Element in an array

Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Examples
Example 1:
Input:
 [1, 2, 4, 7, 7, 5]  
Output:
  
Second Smallest : 2  
Second Largest : 5  
Explanation:
  The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.

Example 2:
Input:
 [1]  
Output:
  
Second Smallest : -1  
Second Largest : -1  
Explanation:
  Since there is only one element in the array, it is both the largest and smallest element.  
Therefore, there is no second smallest or second largest element present.
*/

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int secondLargest_brute(int arr[],int n){
    if(n==1)
        return -1;
    sort(arr,arr+n);
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=arr[n-1]){
            return arr[i];
        }
    }
}

int secondLargest_better(int arr[],int n){
    if(n==1)
        return -1;
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }

    int sLargest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>sLargest && arr[i]!=largest){
            sLargest=arr[i];
        }
    }

    return sLargest;
}

int secondLargest_optimal(int arr[],int n){
    if(n==1)
        return -1;
    int largest=arr[0];
    int sLargest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            sLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>sLargest){
            sLargest=arr[i];
        }
    }
    return sLargest;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<secondLargest_brute(arr,n)<<endl;
    cout<<secondLargest_better(arr,n)<<endl;
    cout<<secondLargest_optimal(arr,n)<<endl;

    delete[] arr;
}