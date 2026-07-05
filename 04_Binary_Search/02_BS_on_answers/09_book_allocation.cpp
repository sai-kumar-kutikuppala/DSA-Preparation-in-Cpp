/*
Allocate Minimum Number of Pages

Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

Examples
Example 1:

Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.


Example 2:
Input Format:
 n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result:
 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
*/

#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int fun(int arr[],int n,int pages){
    int stu=0,cntPages=0;
    for(int i=0;i<n;i++){
        if(arr[i]+cntPages<=pages)
            cntPages+=arr[i];
        else{
            stu++;
            cntPages=arr[i];
        }
    }
    return stu+1;
}

int brute(int arr[],int n,int m){
    if(m>n)
        return -1;

    int maxi = *max_element(arr,arr+n);
    int sum = accumulate(arr,arr+n,0);
    for(int pages=maxi;pages<=sum;pages++){
        int cntStu = fun(arr,n,pages);
        if(cntStu==m)
            return pages;
    }
}

int optimal(int arr[],int n,int m){
    if(m>n)
        return -1;

    int maxi = *max_element(arr,arr+n);
    int sum = accumulate(arr,arr+n,0);
    int low=maxi,high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        if(fun(arr,n,mid)>m)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int m;
    cin>>m;
    
    cout<<brute(arr,n,m)<<endl;
    cout<<optimal(arr,n,m)<<endl;

    delete[] arr;
}