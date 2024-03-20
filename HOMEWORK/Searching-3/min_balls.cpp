class Solution {
public:
bool possible(vector<int>& nums, int maxoperations,int mid)
{
    int op=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mid)
        {
            if(nums[i]%mid==0)
            {
                op=op+(nums[i]/mid)-1;
            }
            else
            {
                op=op+(nums[i]/mid);//these much operation are applying for this mid
            }
        }
    }
    if(op<=maxoperations)
    {
        return true;
    }
    return false;
}
    int minimumSize(vector<int>& nums, int maxoperations) {
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            
            if(nums[i]>max)
            {
                max=nums[i];
            }
        }
        int low=1;//nums=[1] and maxoperatioons=1..so i started i=1;...as divison by zero 
        int high=max;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(nums,maxoperations,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;

        
    }
};