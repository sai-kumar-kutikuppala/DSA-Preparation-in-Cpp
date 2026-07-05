/*
Rotate Image by 90 degree

Problem Statement: Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
The rotation must be done in place, meaning the input 2D matrix must be modified directly..

Examples
Input :matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
            
Output :
matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]


Explanation :
First, we transpose the matrix: rows become columns.
Then, we reverse each row to simulate 90° clockwise rotation. So element at (0,0) goes to (0,2), (0,1) goes to (1,2), and so on, achieving the rotated layout.

Input :
matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]


Output :
matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]


Explanation :
First, the matrix is transposed: rows become columns. Then, each row is reversed.
This moves the last column to the first row, the second last column to the second row, and so on. The original position of each element is rotated 90° clockwise into its new location.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> brute(vector<vector<int>> &arr, int n,int m){
    vector<vector<int>> ans(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n-1-i]=arr[i][j];
        }
    }
    return ans;
}

void optimal(vector<vector<int>> &arr, int n,int m){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<n;i++)
        reverse(arr[i].begin(),arr[i].end());
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> ans=brute(arr,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    optimal(arr,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}