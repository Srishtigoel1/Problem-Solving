#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lcm(int a,int b)
{
return ((a*b)/__gcd(a,b));
}
int div(int a, int b,int c, int mid)
{
return ( (mid/a)+(mid/b)+(mid/c)-(mid/lcm(a,b))-(mid/lcm(b,c))-(mid/lcm(c,a))+(mid/lcm(a,lcm(b,c))));
}
int main()
{
cout<<"enter the numbers";
int a,b,c;
cin>>a>>b>>c;
cout<<"Enter the value of N";
int N;
cin>>N;
int low=0;
int high=INT_MAX;
int ans=0;
while(low<=high)
{
int mid=low+(high-low)/2;
if(div(a,b,c,mid)<N)
{
ans=mid;
low=mid+1;
}
else
{
high=mid-1;
}
}
cout<<ans;
}
