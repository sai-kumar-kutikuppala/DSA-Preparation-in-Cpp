/*
Find the Smallest Divisor Given a Threshold

Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

Examples
Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
Result: 3
Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.

Example 2:
Input Format: N = 4, arr[] = {8,4,2,3}, limit = 10
Result: 2
Explanation: If we choose 1, we get 17 as the sum. If we choose 2, we get 9(4+2+1+2) <= 10 as the answer. So, 2 is the answer.
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int sumOfD(int arr[],int n,int d){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)arr[i]/(double)d);
    }
    return sum;
}

int brute(int arr[],int n,int thresold){
    int maxi = *max_element(arr,arr+n);
    for(int d=1;d<=maxi;d++){
        int sum = sumOfD(arr,n,d);
        if(sum<=thresold)
            return d;
    }
    return -1;
}

int optimal(int arr[],int n,int thresold){
    int maxi = *max_element(arr,arr+n);
    int low=1,high=maxi;
    int ans=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(sumOfD(arr,n,mid)<=thresold){
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int thresold;
    cin>>thresold;

    cout<<brute(arr,n,thresold)<<endl;
    cout<<optimal(arr,n,thresold)<<endl;

    delete[] arr;
}