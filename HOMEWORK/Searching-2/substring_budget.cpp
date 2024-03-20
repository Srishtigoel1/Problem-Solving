class Solution {
public:
bool possible(string s, string t, int mid, int maxCost)
{
    int maxi=0;
    int window=0;
    int left=0;
    for(int i=0;i<s.size();i++)
    {
        window=window+(abs(s[i]-t[i]));
        if(window>maxCost)
        {
            window=window-(abs(s[left]-t[left]));
            left++;
        }
        maxi=max(maxi,i-left+1);
        
    }
    if(maxi>=mid)
        {
            return true;
        }
        return false;
}
    int equalSubstring(string s, string t, int maxCost) 
    {
        int low=0;
        int high=s.size();
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(s,t,mid,maxCost))
            {
                ans=mid;
                low=mid+1;//need to find maximum store potential answer
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
        
    }
};