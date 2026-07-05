#include<iostream>
#include<climits>
using namespace std;

void number_hashing(){  // Brute force
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // Finding max element
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(maxi<arr[i])
            maxi = arr[i];
    }

    // hash size is maximum element+1
    int *hash = new int[maxi+1](); // () initialises all element with zeroes
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    // finding frequency
    int q;
    cin>>q;
    while(q>0){
        int e;
        cin>>e;
        cout<<e<<"->"<<hash[e]<<endl;
        q--;
    }

    delete []arr;
    delete []hash;
}


void lower_character_hashing(){
    string s;
    getline(cin,s);

    int hash[26]={0};

    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while(q>0){
        char ch;
        cin>>ch;
        cout<<ch<<"->"<<hash[ch-'a']<<endl;
        q--;
    }
}

void all_character_hashing(){
    string s;
    getline(cin,s);

    int hash[256]={0};

    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }

    int q;
    cin>>q;
    while(q>0){
        char ch;
        cin>>ch;
        cout<<ch<<"->"<<hash[ch]<<endl;
        q--;
    }
}

int main(){
    //number_hashing();
                        /* input:
                        6
                        10 20 10 20 30 10
                        3
                        10 20 30
                        */
   //lower_character_hashing();
                        /*
                        aabbbcccc
                        4
                        a b c d
                        */
    all_character_hashing();
                        /*
                        aabbbcccc%^&%^&
                        5
                        a % ^ & *
                        */
}