/*
Capacity to Ship Packages within D Days

Problem Statement: You are the owner of a Shipment company. 
You use conveyor belts to ship packages from one port to another. 
The packages must be shipped within 'd' days. 
The weights of the packages are given in an array 'of weights'. 
The packages are loaded on the conveyor belts every day in the same order as they appear in the array. 
The loaded weights must not exceed the maximum weight capacity of the ship. 
Find out the least-weight capacity so that you can ship all the packages within 'd' days .

Examples
n=10  wt[]= {1 2 3 4 5 6 7 8 9 10}  d=5
ans=15
*/

#include<iostream>
#include<algorithm>
#include<numeric> // for accumulate
using namespace std;

int fun(int arr[],int n,int cap){
    int load=0;
    int days=0;
    for(int i=0;i<n;i++){
        if(load+arr[i]>cap){
            days++;
            load=arr[i];
        }
        else
            load+=arr[i];
    }
    return days+1; // +1 to count last group
}

int brute(int arr[],int n,int d){
    int maxi = *max_element(arr,arr+n);
    int sum = accumulate(arr,arr+n,0);
    for(int i=maxi;i<=sum;i++){
        int daysReq = fun(arr,n,i);
        if(daysReq<=d)
            return i; 
    }
    return -1;
}

int optimal(int arr[],int n,int d){
    int maxi = *max_element(arr,arr+n);
    int sum = accumulate(arr,arr+n,0);
    int low=maxi,high=sum;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(fun(arr,n,mid)<=d){
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
    int d;
    cin>>d;

    cout<<brute(arr,n,d)<<endl;
    cout<<optimal(arr,n,d)<<endl;

    delete[] arr;
}