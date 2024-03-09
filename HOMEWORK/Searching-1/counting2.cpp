#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
// Sample Input 
//
// 3 1
// 100 160 130
// 120
// Sample Output ...element which are >=
// 
// 2
int main()
{
  int n;
  cin>>n;
  int p;
  cin>>p;
  vector<int>pp(p);
  
  vector<int>ans(n);
  
  for(int i=0;i<n;i++)
    {
      cin>>ans[i];
    }
    for(int i=0;i<p;i++)
  {
    cin>>pp[i];
  }
 sort(ans.begin(),ans.end());
 int x=-1;
   for(int i=0;i<p;i++)
   {
     int l=0;
     int h=ans.size()-1;
     x=-1;
     while(l<=h)
     {
       int mid=l+(h-l)/2;
       if(ans[mid]>=pp[i])
       {
         x=mid;
         h=mid-1;
       }
       else if(ans[mid]<pp[i])
       {
         l=mid+1;
       }
      
       
     }
     if(x==-1)
     {
       cout<<0<<endl;
     }
     else{
     cout<<ans.size()-x<<endl;
     }
   }
   return 0;
}