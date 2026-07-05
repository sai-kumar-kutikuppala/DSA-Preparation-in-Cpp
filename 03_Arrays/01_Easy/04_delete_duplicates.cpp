/*
Remove Duplicates in-place from Sorted Array

Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Examples
Input: arr[]=[1,1,2,2,2,3,3]
Output: [1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.
Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
Output: [1,2,3,4,_,_,_,_,_,_,_]
Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.
*/

#include<iostream>
#include<set>
using namespace std;

int delete_duplicates_brute(int arr[],int n){
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int i=0;
    for(auto it:st){
        arr[i]=it;
        i++;
    }
    return i;
}

int delete_duplicates_optimal(int arr[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}


int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];


    //int n1=delete_duplicates_brute(arr,n);
    //for(int i=0;i<n1;i++)
    //    cout<<arr[i]<<" ";

    int n2=delete_duplicates_optimal(arr,n);
    for(int i=0;i<n2;i++)
        cout<<arr[i]<<" ";

    delete[] arr;

}