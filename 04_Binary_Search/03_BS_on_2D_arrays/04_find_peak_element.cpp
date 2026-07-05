/*
Find Peak Element (2D Matrix)

Problem Statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j]. A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.
Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

Examples
Example 1:
Input:
 mat = [[5, 10, 8], [4, 25, 7], [3, 9, 6]]
Output:
 [1, 1]
Explanation:
 The value at index [1, 1] is 25, which is a peak because all its neighbors (10, 7, 4, 9) are smaller.

Example 2:
Input:
 mat = [[1, 2, 3], [6, 5, 4], [7, 8, 9]]
Output:
 [2, 2]
Explanation:
 The value at index [2, 2] is 9, which is a peak as it is greater than its neighbors (8, 4).
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

pair<int,int> brute(vector<vector<int>> &mat,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int left = j-1>=0?mat[i][j-1]:-1;
            int right = j+1<m?mat[i][j+1]:-1;
            int top = i-1>=0?mat[i-1][j]:-1;
            int bottom = i+1<n?mat[i+1][j]:-1;
            if(mat[i][j]>left && mat[i][j]>right && mat[i][j]>top && mat[i][j]>bottom)
                return {i,j};
        }
    }
    return {-1,-1};
}

pair<int,int> better(vector<vector<int>> &mat,int n,int m){
    int row=-1,col=-1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]>maxi){
                maxi=mat[i][j];
                row=i;
                col=j;
            }
        }
    }
    return {row,col};
}

int maxElement(vector<vector<int>> &mat,int n,int m,int col){
    int maxi=INT_MIN,ind=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxi){
            maxi=mat[i][col];
            ind=i;
        }
    }
    return ind;
}

pair<int,int> optimal(vector<vector<int>> &mat,int n,int m){
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row = maxElement(mat,n,m,mid);
        int left = mid-1>=0?mat[row][mid-1]:-1;
        int right = mid+1<m?mat[row][mid+1]:-1;
        if(mat[row][mid]>left && mat[row][mid]>right)
            return {row,mid};
        else if(mat[row][mid]<left)
            high=mid-1;
        else
            low=mid+1;   
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

    pair<int,int> p1=brute(mat,n,m);
    cout<<"{"<<p1.first<<","<<p1.second<<"}"<<endl;
    pair<int,int> p2=better(mat,n,m);
    cout<<"{"<<p2.first<<","<<p2.second<<"}"<<endl;
    pair<int,int> p3=optimal(mat,n,m);
    cout<<"{"<<p3.first<<","<<p3.second<<"}"<<endl;
}
