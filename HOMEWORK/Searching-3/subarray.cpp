#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>&ans,int mid,int s)
{
    int left=0;
    int sum=0;
    for(int i=0;i<mid;i++)
    {
        sum=sum+ans[i];
        if(sum>s)//greater
        {
            return false;
        }
    }
    for(int j=mid;j<ans.size()-1;j++)
    {
        sum=sum+ans[j]-ans[left];
        left++;
        if(sum>s)
        return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        cin>>ans[i];
    }
    cout<<"Enter the value of sum";
    int s;
    cin>>s;
    int low=0;
    int high=n-1;
    int a=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(possible(ans,mid,s))
        {
            a=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<endl;
cout<<a<<endl;
}