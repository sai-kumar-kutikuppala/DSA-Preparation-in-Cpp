/*
Power Set | Bit Manipulation

Problem Statement: Given an array of numbers, print all subsets of it using bitwise operators.

Examples
Input: nums = [1, 2, 3]
Output: [[ ], [1], [2], [3], [1, 2], [2, 3], [3, 1], [1, 2, 3]]
Explanation:  A power set of an array is an array of all possible subarrays, including an empty array. It contains all combinations of elements from the original array. By iterating through all possible combinations of the elements in the input array we are able to get the power set of the array.

Input: nums = [5, 7, 8]
Output: [[ ], [5], [7], [8], [5, 7], [7, 8], [8, 5], [5, 7, 8]]
Explanation:  A power set of an array is an array of all possible subarrays, including an empty array. It contains all combinations of elements from the original array. By iterating through all possible combinations of the elements in the input array we are able to get the power set of the array.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> power_set(int arr[],int n){
    int subsets=1<<n;
    vector<vector<int>> ans;
    for(int num=0;num<subsets;num++){
        vector<int> list;
        for(int i=0;i<n;i++){
            if(num & (1<<i))
                list.push_back(arr[i]);
        }
        ans.push_back(list);
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<vector<int>> ans = power_set(arr,n);
    for(auto l:ans){
        cout<<"[";
        for(auto i:l){
            cout<<i<<" ";
        }
        cout<<"]"<<endl;
    }
    delete[] arr;
}