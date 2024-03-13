#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of elements"<<endl;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    int ans=INT_MAX;//if we consider constraint consist of negative num.
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[low]<=arr[mid])//pehle waala sorted
        {
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else if(arr[mid]<=arr[high])
        {
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
    cout<<"Minimum element present in the array is"<<endl;
    cout<<ans;
}