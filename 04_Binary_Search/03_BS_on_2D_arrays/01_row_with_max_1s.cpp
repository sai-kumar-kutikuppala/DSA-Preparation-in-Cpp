/*
Find the row with maximum number of 1's

Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

Examples
Example 1:
Input Format: n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0
Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Example 2:
Input Format: n = 2, m = 2 , 
mat[] = 
0 0
0 0
Result: -1
Explanation:  The matrix does not contain any 1. So, -1 is the answer
*/

#include<iostream>
#include<vector>
using namespace std;

int brute(vector<vector<int>> &mat,int n,int m){
    int max_cnt=0;
    int ind=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            cnt+=mat[i][j];
        }
        if(cnt>max_cnt){
            max_cnt=cnt;
            ind=i;
        }
    }
    return ind;
}

int lowerBound(vector<int> &arr,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else   
            low=mid+1;
    }
    return ans;
}

int optimal(vector<vector<int>> &mat,int n,int m){
    int max_cnt=0;
    int ind=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            cnt+=m-lowerBound(mat[i],m,1);
        }
        if(cnt>max_cnt){
            max_cnt=cnt;
            ind=i;
        }
    }
    return ind;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    cout<<brute(mat,n,m)<<endl;
    cout<<optimal(mat,n,m)<<endl;
}