#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 int maximum(vector<int>arr)
    {
         int max=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
            
        }
        return max;
    }
     int minimum(vector<int>arr)
    {
        int min=INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<min)
            {
                min=arr[i];
            }
        }
        return min;
    }
    bool fun(vector<int>b,int m,int k,int mid)
    {
        int count=0;
        int total=0;
        for(int i=0;i<b.size();i++)
        {
            if(b[i]<=mid)
            {
                count++;
            }
            else
            {
                total=total+(count/k);// to find ki kitne consecutive possible 
                count=0;
            }
        }
        total=total+(count/k);
       if(total>=m)
       return true;
       return false;
    }

    int minDays(vector<int>& b, int m, int k) 
    {
        int n=b.size();
       
        int low=minimum(b);
        int high=maximum(b);
        int ans=-1;
        while(low<=high)
        {
           int mid=low+(high-low)/2;
            bool possible =fun(b,m,k,mid);
            if(possible)
            {
                ans=mid;
                high=mid-1;// as we need to find min
            }
            else
            {
                low=mid+1;
            }
        
        }
        return ans;
      
    }
int main()
{
    cout<<"enter the number of elements"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"enter the number of bouquets to create"<<endl;
    int m;
    cin>>m;
    cout<<endl;
    cout<<"enter the no. of flower in each boquet"<<endl;
    int k;
    cin>>k;
    int y=minDays(arr,m,k);
    cout<<"Min. number of days"<<endl;
    cout<<y;

}