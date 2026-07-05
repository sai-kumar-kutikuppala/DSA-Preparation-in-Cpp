/*
Search in a row and column-wise sorted matrix

Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order. But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Examples
Example 1:
Matrix=
1   4   7   11
2   5   8   12
3   6   9   16
10 13  14  17
Target: 9
Output: Found at (2,2) (0-indexed)


Example 2:
Matrix=
5   10  15
6   12  18
8   16  20
Target: 7
Output: Not Found
*/

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> brute(vector<vector<int>> &mat,int n,int m,int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==target)
                return {i,j};
        }
    }
    return {-1,-1};
}

int BS(vector<int> &arr,int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

pair<int,int> better(vector<vector<int>> &mat,int n,int m,int target){
    for(int i=0;i<n;i++){
        if(target>=mat[i][0] && target<=mat[i][m-1]){
            int ans=BS(mat[i],m,target);
            if(ans!=-1)
                return {i,ans};
        }
    }
    return {-1,-1};
}

pair<int,int> optimal(vector<vector<int>> &mat,int n,int m,int target){
    int row=0,col=m-1;
    while(row<n && col>=0){
        if(mat[row][col]==target)
            return {row,col};
        else if(mat[row][col]<target)
            row++;
        else
            col--;
    }
    return {-1,-1};
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
    int target;
    cin>>target;

    pair<int,int> p1=brute(mat,n,m,target);
    cout<<"{"<<p1.first<<","<<p1.second<<"}"<<endl;
    pair<int,int> p2=better(mat,n,m,target);
    cout<<"{"<<p2.first<<","<<p2.second<<"}"<<endl;
    pair<int,int> p3=optimal(mat,n,m,target);
    cout<<"{"<<p3.first<<","<<p3.second<<"}"<<endl;
}