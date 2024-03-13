#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the size of array"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=INT_MAX;
    int l=0;
    int h=n-1;
    int index=0;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[l]<=arr[mid])
        {
            if(arr[l]<ans)
            {
                ans=arr[l];
                index=l;
            }
            l=mid+1;

        }
        else if(arr[mid]<=arr[h])
        {
            if(ans<arr[mid])
            {
                ans=arr[mid];
                index=mid;
            }
            h=mid-1;
        }
    }
    cout<<"Number of times array rotated is"<<endl;
    cout<<index;
}