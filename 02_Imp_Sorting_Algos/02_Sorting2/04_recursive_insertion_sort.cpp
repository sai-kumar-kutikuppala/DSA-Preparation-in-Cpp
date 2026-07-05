#include<iostream>
using namespace std;

void insertion_sort(int arr[],int i,int n){
    if(i>=n)
        return;
    int j=i;
    while(j>0 && arr[j-1]>arr[j]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
    }

    insertion_sort(arr,i+1,n);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    insertion_sort(arr,0,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    delete []arr;
}