#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"Enter the value of n"<<endl;
    int n;
    cin>>n;//nth root to be finded of m
    cout<<"Enter the value of m"<<endl;
    int m;
    cin>>m;
    //brute approach:- traverse and check for each iteration is it valid 
    //binary search 
    int low=1;
    int high=m;
    int ans=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(pow(mid,n)==m)
        {
            ans=mid;
            break;
        }
        else if(pow(mid,n)>m)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans;
    
}