#include<bits/stdc++.h>
#include<iostream>
#include<vector>
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
    cout<<"Enter the key to search"<<endl;
    int key;
    cin>>key;
    //using binary search
    int l=0;
    int h=arr.size()-1;
    int ans=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==key)
        {
           ans=mid;
            break;        
        }
        if(arr[l]<=arr[mid])
        {
            if(arr[l]<=key && key<=arr[mid])
            {
                h=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        else if(arr[mid]<=arr[h]){
            if(arr[mid]<=key && key<=arr[h])
            {
                l=mid+1;
            }
            else 
            {
               h=mid-1;
            }

        }

    }
    cout<<"Index of the element "<<ans<<endl;

}