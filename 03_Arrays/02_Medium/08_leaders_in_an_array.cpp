/*
Leaders in an Array

Problem Statement: .

Examples
Example 1:
Input:
 arr = [4, 7, 1, 0]  
Output:
 7 1 0  
Explanation:
 The rightmost element (0) is always a leader.  
7 and 1 are greater than the elements to their right, making them leaders as well.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]  
Output:
 22 12 6  
Explanation:
 6 is a leader because there are no elements after it.  
12 is greater than all the elements to its right (3, 0, 6), and 22 is greater than 12, 3, 0, 6, making them leaders as well.
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> brute(int arr[],int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> optimal(int arr[],int n){
    vector<int> ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
            maxi=arr[i];
        }
    }
    reverse(ans.begin(), ans.end());  // restore left-to-right order
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> v1 = brute(arr,n);
    for(auto it:v1)
        cout<<it<<" ";

    cout<<endl;

    vector<int> v2 = optimal(arr,n);
    for(auto it:v2)
        cout<<it<<" ";

    delete[] arr;
}