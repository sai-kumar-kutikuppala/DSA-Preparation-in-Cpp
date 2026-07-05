/*
Aggressive Cows : Detailed Solution

Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls. You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible. Find the maximum possible minimum distance.

Examples
Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
 The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:
Input Format:
 N = 5, k = 2, arr[] = {4,2,1,3,6}
Result:
 5
Explanation:
 The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}. 
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool canWePlace(int arr[],int n,int k,int dist){
    int cntCows=1,lastCoord=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]-lastCoord>=dist){
            cntCows++;
            lastCoord=arr[i];
        }
    }
    if(cntCows>=k)
        return true;
    else
        return false;
}

int brute(int arr[],int n,int k){
    sort(arr,arr+n);
    int ans=-1;
    int mini=arr[0],maxi=arr[n-1];
    for(int d=1;d<=(maxi-mini);d++){
        if(canWePlace(arr,n,k,d)){
            ans=d;
        }
        else
            break;
    }
    return ans;
}

int optimal(int arr[],int n,int k){
    sort(arr,arr+n);
    int ans=-1;
    int mini=arr[0],maxi=arr[n-1];
    int low=1,high=maxi-mini;
    while(low<=high){
        int mid=(low+high)/2;
        if(canWePlace(arr,n,k,mid)){
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }    
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    
    cout<<brute(arr,n,k)<<endl;
    cout<<optimal(arr,n,k)<<endl;

    delete[] arr;
}