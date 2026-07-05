/*
Median of Row Wise Sorted Matrix

Problem Statement:
Given a row-wise sorted matrix of size M*N, where M is no. of rows and N is no. of columns, find the median in the given matrix.
Note: M*N is odd.

Examples
Input: M = 3, N = 3, matrix[][] =

1 4 9 
2 5 6
3 8 7
Output: 5
Explanation: 
If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. Therefore, median = 5

Input: M = 3, N = 3, matrix[][] =

1 3 8 
2 3 4
1 2 5
Output: 3
Explanation: 
If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. Therefore, median = 3.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int brute(vector<vector<int>> &mat,int n,int m){
    vector<int> ls;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ls.push_back(mat[i][j]);
        }
    }
    sort(ls.begin(),ls.end());
    return ls[n*m/2];
}

int min_element_in_col0(vector<vector<int>> &mat,int n,int m){
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        if(mat[i][0]<mini)
            mini=mat[i][0];
    }
    return mini;
}

int max_element_in_last_col(vector<vector<int>> &mat,int n,int m){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(mat[i][m-1]>maxi)
            maxi=mat[i][m-1];
    }
    return maxi;
}

int blackBox(vector<vector<int>> &mat,int n,int m,int x){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upper_bound(mat[i].begin(),mat[i].end(),x) - mat[i].begin();
    }
    return cnt;
}

int optimal(vector<vector<int>> &mat,int n,int m){
    int low = min_element_in_col0(mat,n,m);
    int high = max_element_in_last_col(mat,n,m);
    int ans=-1;
    int req=n*m/2; // median index (0-based count) -> number of elements < median
    while(low<=high){
        int mid=(low+high)/2;
        int nums = blackBox(mat,n,m,mid);
        if(nums<=req)
            low=mid+1;
        else{
            high=mid-1;
            ans=mid;
        }
    }
    return ans;
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