#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;

        if(nums.size()==1){
            return 0;
        }

      if(nums[0]>nums[1] || nums.size()==1){
          return 0;
      }
      if(nums[high]>nums[high-1]){
          return high;
      }
        while(low<=high){

        int mid=low+(high-low)/2;

        if(mid>0 && mid<nums.size()-1 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;
        }

        else if(nums[mid]<nums[mid+1]){
            low=mid+1;
        }
        else if(nums[mid]<nums[mid-1]){
            high=mid-1;
        }
        }
        return -1;
 }
int main()
{
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x=findPeakElement(arr);
    cout<<"Peak element is at index"<<endl;
    cout<<x<<endl;
    cout<<"which is"<<endl;
    cout<<arr[x];

}