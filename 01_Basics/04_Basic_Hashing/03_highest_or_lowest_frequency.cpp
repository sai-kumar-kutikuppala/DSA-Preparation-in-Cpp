/*
Find the highest/lowest frequency element

Problem Statement: Problem Statement: Given an array of size N. Find the highest and lowest frequency element.

Examples
Example 1:
Input: array[] = {10,5,10,15,10,5};
Output: 10 15
Explanation: The frequency of 10 is 3, i.e. the highest and the frequency of 15 is 1 i.e. the lowest.


Example 2:
Input: array[] = {2,2,3,4,4,2};
Output: 2 3
Explanation: The frequency of 2 is 3, i.e. the highest and the frequency of 3 is 1 i.e. the lowest.

*/

#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;

void h_and_l_frequency(int arr[],int n){
    int min_count = INT_MAX;
    int max_count = INT_MIN;
    int e1,e2;
    int *visited = new int[n](); // () initialise with zero
    for(int i=0;i<n;i++){
        if(visited[i]==1)
            continue;
        int cnt=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                visited[j]=1;
                cnt++;
            }
        }

        if(cnt<min_count){
            min_count=cnt;
            e1=arr[i];
        }

        if(cnt>max_count){
            max_count=cnt;
            e2=arr[i];
        }
    }

    cout<<e1<<" "<<e2<<endl;
}

void optimal(int arr[],int n){
    int min_count = INT_MAX;
    int max_count = INT_MIN;
    int e1,e2;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++)
        mpp[arr[i]]++;

    for(auto e:mpp){
        if(e.second<min_count){
            min_count=e.second;
            e1=e.first;
        }
        if(e.second>max_count){
            max_count=e.second;
            e2=e.first;
        }
    }

    cout<<e1<<" "<<e2<<endl;
}

int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    h_and_l_frequency(a,n);
    cout<<endl;
    optimal(a,n);
}