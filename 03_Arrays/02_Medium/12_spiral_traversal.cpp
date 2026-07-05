/*
Spiral Traversal of Matrix

Problem Statement: Given a Matrix, print the given matrix in spiral order.

Examples
Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Input: Matrix[][] = { { 1, 2, 3 }, { 4, 5, 6 },{ 7, 8, 9 } }
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> spiral(vector<vector<int>> &arr,int n,int m){
    int left=0,right=n-1;
    int top=0,bottom=n-1;
    vector<int> ans;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++)
            ans.push_back(arr[top][i]);
        top++;
        for(int i=top;i<=bottom;i++)
            ans.push_back(arr[i][right]);
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--)
                ans.push_back(arr[bottom][i]);
            bottom--;
        }
        if(left<=right){
        for(int i=bottom;i>=top;i--)
            ans.push_back(arr[i][left]);
        left++;
        }
    }
    return ans;
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

    vector<int> ans = spiral(arr,n,m);
    for(auto it:ans)
        cout<<it<<" ";
}