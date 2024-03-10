#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

    bool search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
             if(nums[mid]==target)
            {
                return true;
            }
             if(nums[low]==nums[mid] && nums[mid]==nums[high]) //this is the new condition we added in this for searching 
            {
                low++;
                high--;
                continue;
               
            }
           
           else if(nums[mid]<=nums[high])
            {
                if(nums[mid]<=target && target<=nums[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            else
            {
                if(nums[low]<=target && target<=nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }

        }
        return false;
        
    }

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
   cout<<search(arr,key);

}