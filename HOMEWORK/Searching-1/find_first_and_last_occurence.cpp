#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int first(vector<int>& arr,int l,int h,int key)
{
    int ans=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==key)
        {
            ans=mid;//could be a potential ans.
            h=mid-1;//but still find in left part
        }
        if(arr[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return ans;
}
int last(vector<int>& arr,int l,int h,int key)
{
    int ans=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==key)
        {
            ans=mid;//could be a potential ans.
            l=mid+1;//but still find in right part
        }
        if(arr[mid]<key)
        {
            l=mid+1;
        }
        else if( arr[mid]>key)
        {
            h=mid-1;
        }
    }
    return ans;
}
int main()
{
    cout<<"Enter the size of element"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter key element"<<endl;
    int key;
    cin>>key;
    int firstoccur=first(arr,0,n-1,key);
    int lastoccur=last(arr,0,n-1,key);
    cout<<"element occuring firstly at "<<firstoccur<<endl;
    cout<<"element occuring lastly at "<<lastoccur<<endl;

}