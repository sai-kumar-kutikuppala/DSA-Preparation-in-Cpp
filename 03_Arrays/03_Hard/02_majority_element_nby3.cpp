/*
Majority Elements(&gt;N/3 times) | Find the elements that appears more than N/3 times in the array

Problem Statement: Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.

Examples
Example 1:
Input:
 nums = [1, 2, 1, 1, 3, 2]  
Output:
 [1]  
Explanation:
 Here, n / 3 = 6 / 3 = 2.  
Therefore, the elements appearing 3 or more times are: [1].

Example 2:
Input:
 nums = [1, 2, 1, 1, 3, 2, 2]  
Output:
 [1, 2]  
Explanation:
 Here, n / 3 = 7 / 3 = 2.  
Therefore, the elements appearing 3 or more times are: [1, 2].
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> brute(int arr[],int n){
    vector<int> ls;
    for(int i=0;i<n;i++){
        if(ls.size()==0 || ls[0]!=arr[i]){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(arr[i]==arr[j]){
                    cnt++;
                }
            }
            if(cnt>n/3)
                ls.push_back(arr[i]);
        }
        if(ls.size()==2)
            break;
    }
    return ls;
}

vector<int> better(int arr[],int n){
    vector<int> ls;
    unordered_map<int,int> mpp;
    int mini=(n/3)+1;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini)
            ls.push_back(arr[i]);
        if(ls.size()==2)
            break;
    }
    return ls;
}

vector<int> optimal(int arr[],int n){
    vector<int> ls;
    int cnt1=0,cnt2=0;
    int el1,el2;
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i]!=el2){
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && arr[i]!=el1){
            cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1)
            cnt1++;
        else if(arr[i]==el2)
            cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el1)
            cnt1++;
        if(arr[i]==el2)
            cnt2++;
    }
    if(cnt1>n/3)
        ls.push_back(el1);
    if(cnt2>n/3)
        ls.push_back(el2);

    return ls;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //vector<int> ans = brute(arr,n);
    //vector<int> ans = better(arr,n);
    vector<int> ans = optimal(arr,n);
    for(auto it:ans)
        cout<<it<<" ";

    delete[] arr;
}