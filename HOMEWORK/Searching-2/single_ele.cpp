#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout<<"Enter number of elements"<<endl;
    int n;
    cin>>n;
    //adjacent duplicate 
    //even index---first occurence--good to go
    //odd index---single element in left part 
    cout<<"Enter elements "<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    int ans=-1;
    if(arr.size()==1)
    {
        ans=arr[0];
        cout<<ans;
        return 0;
        
    }
    if(arr[0]!=arr[1])
    {
         ans=arr[0];
        cout<<ans;
        return 0;
    }
    if(arr[n-1]!=arr[n-2])
    {
        ans=arr[n-1];
       cout<<ans;
        return 0;
    }
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
        {
            ans=arr[mid];
            break;
        }
        else if(arr[mid]==arr[mid-1])//2nd occurence
        {
            if((mid-1)%2==0)//sab theek h
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        else if(arr[mid]==arr[mid+1])
        {
            if(mid%2==0)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
    }
    cout<<ans;
    return 0;



}