/*
K-th Element of two sorted arrays
 
Problem Statement: Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

Examples
Example 1:
Input:
 a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5  
Output:
 6  
Explanation:
 The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Example 2:
Input:
 a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7  
Output:
 256  
Explanation:
 The final sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
*/

#include<iostream>
#include<vector>
using namespace std;

double brute(int arr1[],int n1,int arr2[],int n2,int k){
    int i=0,j=0;
    vector<int> temp;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }
        else{
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<n2){
        temp.push_back(arr2[j]);
        j++;
    }
    return temp[k-1];
}

double better(int arr1[],int n1,int arr2[],int n2,int k){
    int i=0,j=0;
    int cnt=0,el=-1;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(cnt==k-1) el=arr1[i];
            i++;
            cnt++;
        }
        else{
            if(cnt==k-1) el=arr2[j];
            j++;
            cnt++;
        }
    }
    while(i<n1){
        if(cnt==k-1) el=arr1[i];
        i++;
        cnt++;
    }
    while(j<n2){
        if(cnt==k-1) el=arr2[j];
        j++;
        cnt++;
    }
    return el;
}

int main(){
     int n1;
    cin>>n1;
    int *arr1 = new int[n1];
    for(int i=0;i<n1;i++)
        cin>>arr1[i];

    int n2;
    cin>>n2;
    int *arr2 = new int[n2];
    for(int i=0;i<n2;i++)
        cin>>arr2[i];

    int k;
    cin>>k;
    
    cout<<brute(arr1,n1,arr2,n2,k)<<endl;
    cout<<better(arr1,n1,arr2,n2,k)<<endl;

    delete[] arr1;
    delete[] arr2;
}