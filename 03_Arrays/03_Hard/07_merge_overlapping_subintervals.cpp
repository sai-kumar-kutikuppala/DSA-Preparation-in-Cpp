/*
Merge Overlapping Sub-intervals

Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

Examples
Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]
Explanation : Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.
Input : [[1,4],[4,5]]
Output :  [[1,5]]
Explanation :  Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> brute(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!ans.empty() && end<=ans.back()[1])
            continue;
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

vector<vector<int>> optimal(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}

int main(){
    int n; // number of intervals
    cin>>n;
    int start,end;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        arr.push_back({start,end});
    }

    //vector<vector<int>> ans = brute(arr);
    vector<vector<int>> ans = optimal(arr);
    for(auto e:ans){
        cout<<"{ ";
        for(auto el:e){
            cout<<el<<" ";
        }
        cout<<"}"<<endl;
    }
}