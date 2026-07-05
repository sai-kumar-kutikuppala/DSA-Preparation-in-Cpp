/*
Last occurrence in a sorted array

Problem Statement: Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1. Note: Consider 0 based indexing

Examples
Example 1:
Input:
 N = 7, target = 13, array[] = {3, 4, 13, 13, 13, 20, 40}  
Output:
 4  
Explanation:
 The target value 13 appears for the first time at index number 2 in the array.  

Example 2:
Input:
 N = 7, target = 60, array[] = {3, 4, 13, 13, 13, 20, 40}  
Output:
 -1  
Explanation:
 Target value 60 is not present in the array, so the output is -1.
*/

#include<iostream>
#include<algorithm>
using namespace std;

pair<int,int> brute(int arr[],int n,int x){
    int first=-1,last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            if(first==-1) first=i;
            last=i;
        }
    }
    return {first,last};
}

pair<int,int> optimal1(int arr[],int n,int x){ // using upper and lower bound
    int first = lower_bound(arr,arr+n,x)-arr;
    if(first==n || arr[first]!=x)
        return {-1,-1};
    int last = (upper_bound(arr,arr+n,x)-arr)-1;
    return {first,last};
}
/*--------------------------------------------------------------------------------------------------------*/
int firstO(int arr[],int n,int x){
    int first=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x)
            first=mid,high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else    
            high=mid-1;
    }
    return first;
}

int lastO(int arr[],int n,int x){
    int last=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x)
            last=mid,low=mid+1;
        else if(arr[mid]<x)
            low=mid+1;
        else    
            high=mid-1;
    }
    return last;
}

pair<int,int> optimal2(int arr[],int n,int x){ // using pure binary search
    int first = firstO(arr,n,x);
    if(first==-1)
        return {-1,-1};

    int last = lastO(arr,n,x);
    return {first,last};
}

/*--------------------------------------------------------------------------------------------------------*/

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;

    //pair<int,int> ans = brute(arr,n,x);
    //pair<int,int> ans = optimal1(arr,n,x);
    pair<int,int> ans = optimal2(arr,n,x);
    cout<<ans.first<<" "<<ans.second<<endl;

    delete[] arr;
}