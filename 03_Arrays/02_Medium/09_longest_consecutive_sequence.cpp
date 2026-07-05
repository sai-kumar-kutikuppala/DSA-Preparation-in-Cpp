/*
Longest Consecutive Sequence in an Array

Problem Statement: Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Examples
Example 1:
Input:
 nums = [100, 4, 200, 1, 3, 2]  
Output:
 4  
Explanation:
 The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Example 2:
Input:
 nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
Output:
 9  
Explanation:
 The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.
*/

#include<iostream>
#include<climits>
#include<algorithm>
#include<unordered_set>
using namespace std;

bool linear_search(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return true;
        }
    }
    return false;
}
int brute(int arr[],int n){
    int longest=INT_MIN;
    for(int i=0;i<n;i++){
        int x=arr[i];
        int cnt=1;
        for(int j=0;j<n;j++){
            if(linear_search(arr,n,x+1)){
                cnt++;
                x++;
            }
            else{
                break;
            }
        }
        if(cnt>longest)
            longest=cnt;
    }
    return longest;
}


int better(int arr[],int n){
    sort(arr,arr+n);
    int longest=INT_MIN;
    int lastSmallest=arr[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(lastSmallest==arr[i]-1){
            lastSmallest=arr[i];
            cnt++;
        }
        else if(lastSmallest==arr[i]){
                // do nothing
            }
        else if(lastSmallest!=arr[i]-1){
            lastSmallest=arr[i];
            cnt=1;
        }

        if(cnt>longest){
                longest=cnt;
            }
    }
    return longest;
}


int optimal(int arr[],int n){
    unordered_set<int> st;
    int longest=INT_MIN;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int x=it;
            int cnt=1;
            while(st.find(x+1)!=st.end()){
                cnt++;
                x++;
            }
            if(cnt>longest)
                longest=cnt;
        }
    }
    return longest;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<brute(arr,n)<<endl;
    cout<<better(arr,n)<<endl;
    cout<<optimal(arr,n)<<endl;
}