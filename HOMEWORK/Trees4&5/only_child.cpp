#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool solve(vector<int>& a, int n)
{
    int next,last;
    for(int i=0;i<n-1;i++)
    {
        next=a[i]-a[i+1];
        last=a[i]-a[n-1];
        if(next*last<0)
        {
            return false;
        }
        
    }
    return true;
}
int main()
{
    cout<<"Enter the Preorder traversal of BST"<<endl;
    cout<<"Enter the size"<<endl;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(solve(a,n)==true)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"No";
    }
}