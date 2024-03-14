#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 int mySqrt(int x) {
        int low=0;
        int ans=-1;
        long long int high=x;
        while(low<=high)
        {
            long long int mid=low+(high-low)/2;
            long long int sq=mid*mid;
            if(sq>x)
            {
                high=mid-1;
            }
            else if(sq<=x)
            {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
 }
int main()
{
 cout<<"Enter the number"<<endl;
 int n;
 cin>>n;
 int a=mySqrt(n);
 cout<<a;
}