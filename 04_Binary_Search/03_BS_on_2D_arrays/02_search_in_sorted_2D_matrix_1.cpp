/*
Search in a sorted 2D matrix

Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Examples
Input :mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
Output :True.
Explanation :The target = 8 exists in the 'mat' at index (1, 3).

Input :mat = [ [1, 2, 4], [6, 7, 8], [9, 10, 34] ], target = 78
Output :false.
Explanation :The target = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.
*/

#include<iostream>
#include<vector>
using namespace std;

bool brute(vector<vector<int>> &mat,int n,int m,int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==target)
                return true;
        }
    }
    return false;
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

bool better(vector<vector<int>> &mat,int n,int m,int target){
    for(int i=0;i<n;i++){
        if(target>=mat[i][0] && target<=mat[i][m-1]){
            int ans=BS(mat[i],m,target);
            if(ans!=-1)
                return true;
        }
    }
    return false;
}

bool optimal(vector<vector<int>> &mat,int n,int m,int target){
    int low=0,high=n*m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(mat[row][col]==target)
            return true;
        else if(mat[row][col]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
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

    cout<<brute(mat,n,m,target)<<endl;
    cout<<better(mat,n,m,target)<<endl;
    cout<<optimal(mat,n,m,target)<<endl;
}