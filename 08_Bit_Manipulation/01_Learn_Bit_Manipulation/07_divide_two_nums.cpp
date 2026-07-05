/*
Divide two integers without using multiplication, division and mod operator

Problem Statement: Given the two integers, dividend and divisor. Divide without using the mod, division, or multiplication operators and return the quotient.

The fractional portion of the integer division should be lost as it truncates toward zero.

As an illustration, 8.345 and -2.7335 would be reduced to 8 and -2 respectively.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

Examples
Example 1:
Input:
 Dividend = 10, Divisor = 3
Output:
 3
Explanation:
 10/3 = 3.33, truncated to 3.

Example 2:
Input:
 Dividend = 7, Divisor = -3
Output:
 -2
Explanation:
 7/-3 = -2.33, truncated to -2.
*/

#include<iostream>
#include<climits>
using namespace std;

int brute(int dividend,int divisor){
    if(dividend==divisor) return 1;

    bool sign=true;
    if((dividend<0 && divisor>0) || (dividend>=0 && divisor<0)) sign=false;

    dividend=abs(dividend);
    divisor=abs(divisor);

    int sum=0,cnt=0;
    while(sum+divisor <= dividend){
        sum+=divisor;
        cnt++;
    }
    return sign?cnt:-cnt;
}

int optimal(int dividend,int divisor){
    if(dividend==divisor) return 1;
    
    bool sign=true;
    if((dividend<0 && divisor>0) || (dividend>=0 && divisor<0)) sign=false;

    int n=abs(dividend);
    int d=abs(divisor);
    int ans=0;
    while(n>=d){
        int cnt=0;
        while(d*(1<<(cnt+1)) <= n)
            cnt++;
        ans=ans+(1<<cnt);
        n=n-d*(1<<cnt);  
    }

    if(ans>=INT_MAX && sign==true)
        return INT_MAX;
    if(ans>=INT_MAX && sign==false)
        return INT_MIN;

    return sign?ans:-ans;  
}

int main(){
    int dividend,divisor;
    cin>>dividend>>divisor;

    cout<<brute(dividend,divisor)<<endl;
    cout<<optimal(dividend,divisor)<<endl;

}