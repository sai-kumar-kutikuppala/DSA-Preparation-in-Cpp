/*
Koko Eating Bananas

Problem Statement: A monkey Koko is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

Examples
Input: N = 4, a[] = {7, 15, 6, 3}, h = 8
Output: 5
Explanation:  If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  
Input: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
Output: 25
Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly.
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int fun(int arr[],int n,int k){
    int time=0;
    for(int i=0;i<n;i++){
        time=time + ceil((double)arr[i]/(double)k);
    }
    return time;
}

int brute(int arr[],int n,int h){
    int maxi = *max_element(arr,arr+n);
    for(int i=1;i<=maxi;i++){
        int reqTime=fun(arr,n,i);
        if(reqTime<=h)
            return i;
    }
}

int optimal(int arr[],int n,int h){
    int maxi = *max_element(arr,arr+n);
    int low=1,high=maxi;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(fun(arr,n,mid)<=h){
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
    int h;
    cin>>h;

    cout<<brute(arr,n,h)<<endl;
    cout<<optimal(arr,n,h)<<endl;

    delete[] arr;
}