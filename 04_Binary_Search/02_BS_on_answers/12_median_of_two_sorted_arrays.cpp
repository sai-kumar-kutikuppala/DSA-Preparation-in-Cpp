/*
Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.

The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.


Example 1

Input: arr1 = [2, 4, 6], arr2 = [1, 3, 5]

Output: 3.5

Explanation: The array after merging arr1 and arr2 will be [ 1, 2, 3, 4, 5, 6 ]. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

Example 2

Input: arr1 = [2, 4, 6], arr2 = [1, 3]

Output: 3.0

Explanation: The array after merging arr1 and arr2 will be [ 1, 2, 3, 4, 6 ]. The median is simply 3.
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

double brute(int arr1[],int n1,int arr2[],int n2){
    int i=0,j=0;
    vector<int> temp;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }
        else{
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<n2){
        temp.push_back(arr2[j]);
        j++;
    }
    int n=n1+n2;
    if(n%2==1) return temp[n/2];
    else return (temp[n/2]+temp[n/2-1])/2.0;
}

double better(int arr1[],int n1,int arr2[],int n2){
    int i=0,j=0;
    int n=n1+n2;
    int ind1=n/2-1;
    int ind2=n/2;
    int cnt=0;
    int el1=-1,el2=-1;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(cnt==ind1) el1=arr1[i];
            if(cnt==ind2) el2=arr1[i];
            i++;
        }
        else{
            if(cnt==ind1) el1=arr2[j];
            if(cnt==ind2) el2=arr2[j];
            j++;
        }
        cnt++;
    }

    while(i<n1){
        if(cnt==ind1) el1=arr1[i];
        if(cnt==ind2) el2=arr1[i];
        i++;
        cnt++;
    }

    while(j<n2){
        if(cnt==ind1) el1=arr2[j];
        if(cnt==ind2) el2=arr2[j];
        j++;
        cnt++;
    }

    if(n%2==0) return (el1+el2)/2.0;
    else return el2;
}

double optimal(int arr1[],int n1,int arr2[],int n2){
    if(n1>n2) return optimal(arr2,n2,arr1,n1);
    int low=0,high=n1;
    int left=(n1+n2+1)/2;
    int n=n1+n2;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN,r1=INT_MAX;
        int l2=INT_MIN,r2=INT_MAX;
        if(mid1<n1) r1=arr1[mid1];
        if(mid2<n2) r2=arr2[mid2];
        if(mid1-1>=0) l1=arr1[mid1-1];
        if(mid2-1>=0) l2=arr2[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1,l2);
            return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2)
            high=mid1-1;
        else 
            low=mid1+1;   
    }
}

int main(){
     int n1;
    cin>>n1;
    int *arr1 = new int[n1];
    for(int i=0;i<n1;i++)
        cin>>arr1[i];

    int n2;
    cin>>n2;
    int *arr2 = new int[n2];
    for(int i=0;i<n2;i++)
        cin>>arr2[i];
    
    cout<<brute(arr1,n1,arr2,n2)<<endl;
    cout<<better(arr1,n1,arr2,n2)<<endl;
    cout<<optimal(arr1,n1,arr2,n2)<<endl;

    delete[] arr1;
    delete[] arr2;
}