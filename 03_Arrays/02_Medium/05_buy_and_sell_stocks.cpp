/*
Stock Buy And Sell

Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Examples
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include<iostream>
using namespace std;

int brute(int arr[],int n){
    int maxProfit=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           int profit = arr[j]-arr[i];
           maxProfit=max(profit,maxProfit);
        }
    }
    return maxProfit;     
}

int optimal(int arr[],int n){
    int maxProfit=0;
    int mini=arr[0];
    for(int i=1;i<n;i++){
        int profit=arr[i]-mini;
        maxProfit=max(maxProfit,profit);
        mini=min(mini,arr[i]);
    }
    return maxProfit;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<brute(arr,n)<<endl;
    cout<<optimal(arr,n)<<endl;

    delete[] arr;
}

