#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool cows(vector<int>& stalls, int k,int d)
 { int c=0;
     int last=stalls[0];
     for(int i=1;i<stalls.size();i++)
     {
         if((stalls[i]-last)>=d)
         {
             c++;
             last=stalls[i];
            
         }
         
     }
     c++;
      if(c>=k)
             {
                 return true;
             }
             return false;
 }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int max=-1;
    for(int i=0;i<n;i++)
    {
        if(stalls[i]>max)
        {
            max=stalls[i];
        }
    }
    int l=0;
    int h=max;
    int ans=0;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(cows(stalls,k,mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return ans;
    }
int main()
{
    cout<<"Enter the number of elements"<<endl;
    int size;
    cin>>size;
    cout<<endl;
    vector<int>arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number of cows"<<endl;
    int p;
    cin>>p;
    //constraint...cow>=2 atleast
    int x=solve(size,p,arr);
    cout<<"Thus minimum dist. which is max is"<<endl;
    cout<<x;


    
}