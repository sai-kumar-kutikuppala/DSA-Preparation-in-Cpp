#include<iostream>
#include<algorithm>
using namespace std;

void brute(int arr1[],int n,int arr2[],int m){
    int *arr3 = new int[n+m];
    int left=0;
    int right=0;
    int index=0;
    while(left<n && right<m){
        if(arr1[left]<arr2[right]){
            arr3[index]=arr1[left];
            left++;
            index++;
        }
        else{
            arr3[index]=arr2[right];
            right++;
            index++;
        }
    }

    while(left<n){
        arr3[index]=arr1[left];
        left++;
        index++;
    }

    while(right<m){
        arr3[index]=arr2[right];
        right++;
        index++;
    }

    for(int i=0;i<n+m;i++){
        if(i<n)
            arr1[i]=arr3[i];
        else    
            arr2[i-n]=arr3[i];
    }
}


void optimal1(int arr1[],int n,int arr2[],int m){
    int left=n-1;
    int right=0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}


void swapIfGreater(int arr1[],int left,int arr2[],int right){
    if(arr1[left]>arr2[right]){
        swap(arr1[left],arr2[right]);
    }
}
void optimal2(int arr1[],int n,int arr2[],int m){  // gap method
    int len=n+m;
    int gap = (len/2) + (len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            if(left<n && right>=n){
                swapIfGreater(arr1,left,arr2,right-n);
            }
            else if(left<n && right<n){
                swapIfGreater(arr1,left,arr1,right);
            }
            else{
                swapIfGreater(arr2,left-n,arr2,right-n);
            }
            left++;
            right++;
        }
        if(gap==1)
        break;
        gap = (gap/2) + (gap%2);
    } 
}


int main(){
    int n;
    cin>>n;
    int *arr1 = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    int m;
    cin>>m;
    int *arr2 = new int[m];
    for(int i=0;i<m;i++)
        cin>>arr2[i];

    //brute(arr1,n,arr2,m);
    //optimal1(arr1,n,arr2,m);
    optimal2(arr1,n,arr2,m);

    for(int i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    for(int i=0;i<m;i++)
        cout<<arr2[i]<<" ";

    delete[] arr1;
    delete[] arr2;
}