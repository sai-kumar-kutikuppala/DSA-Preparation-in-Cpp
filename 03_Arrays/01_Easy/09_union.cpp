/*
Union of Two Sorted Arrays

Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.

NOTE: Elements in the union should be in ascending order.

Examples

Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}

Input:n = 10,m = 7,arr1[] = {1,2,3,4,5,6,7,8,9,10}arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}
*/

#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

vector<int> union_set(int arr1[],int arr2[],int n1,int n2){
    set<int> st;
    vector<int> uni;
    for(int i=0;i<n1;i++)
        st.insert(arr1[i]);
    for(int i=0;i<n2;i++)
        st.insert(arr2[i]);
    for(auto it:st){
        uni.push_back(it);
    }
    return uni;
}

vector<int> union_map(int arr1[],int arr2[],int n1,int n2){
    map<int,int> mpp;
    vector<int> uni;
    for(int i=0;i<n1;i++)
       mpp[arr1[i]]++;
    for(int i=0;i<n2;i++)
        mpp[arr2[i]]++;
    for(auto it:mpp){
        uni.push_back(it.first);
    }
    return uni;
}

vector<int> union_optimal(int arr1[],int arr2[],int n1,int n2){
    vector<int> uni;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(uni.size()==0 || uni.back()!=arr1[i])
                uni.push_back(arr1[i]);
            i++;
        }
        else if(arr2[j]<arr1[i]){
            if(uni.size()==0 || uni.back()!=arr2[j])
                uni.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n1){
        if(uni.size()==0 || uni.back()!=arr1[i])
            uni.push_back(arr1[i]);
        i++;
    }

    while(j<n2){
        if( uni.size()==0 || uni.back()!=arr2[j])
            uni.push_back(arr2[j]);
        j++;
    }

    return uni;
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
    
    //vector<int> result = union_set(arr1,arr2,n1,n2);
    //for(int i=0;i<result.size();i++)
    //    cout<<result[i]<<" ";


    //vector<int> result = union_map(arr1,arr2,n1,n2);
    //for(int i=0;i<result.size();i++)
    //    cout<<result[i]<<" ";

    vector<int> result = union_optimal(arr1,arr2,n1,n2);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";

    delete[] arr1;
    delete[] arr2;
}