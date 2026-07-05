/*
Count frequency of each element in the array

Problem Statement: Given an array, we have found the number of occurrences of each element in the array.

Examples
Example 1:
Input: arr[] = {10,5,10,15,10,5};
Output:         10  3
	            5  2
                15  1
Explanation: 10 occurs 3 times in the array
	      5 occurs 2 times in the array
              15 occurs 1 time in the array

Example2: 
Input: arr[] = {2,2,3,4,4,2};
Output:         2  3
	            3  1
                4  2
Explanation: 2 occurs 3 times in the array
	     3 occurs 1 time in the array
             4 occurs 2 time in the array

*/

#include<iostream>
#include<unordered_map>
using namespace std;

void count_frequency(int arr[],int n){
    int *visited = new int[n](); // () initialise with zero
    for(int i=0;i<n;i++){

        if(visited[i]==1)
            continue;

        int cnt=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cnt++;
                visited[j]=1;
            }
        }

        cout<<arr[i]<<"->"<<cnt<<endl;
    }    
}

void count_frequency_optimal(int arr[],int n){
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++)
        mpp[arr[i]]++;

    for(auto e:mpp)
        cout<<e.first<<"->"<<e.second<<endl;
}


int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    count_frequency(a,n);
    cout<<endl;
    count_frequency_optimal(a,n);
}