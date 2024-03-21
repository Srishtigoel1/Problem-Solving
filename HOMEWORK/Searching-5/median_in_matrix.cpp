class Solution{   
public:
bool possible(vector<vector<int>> &matrix,int mid,int size,int R,int C)
{
    int c=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(matrix[i][j]<=mid)
            {
                c++;
            }
        }
    }
    if(c>size)
    {
        return true;
    }
    return false;
}
    int median(vector<vector<int>> &matrix, int R, int C){
       int min=INT_MAX;
       for(int i=0;i<R;i++)
       {
           for(int j=0;j<C;j++)
           {
               if(matrix[i][j]<min)
               {
                   min=matrix[i][j];
               }
           }
       }
       int max=INT_MIN;
       for(int i=0;i<R;i++)
       {
           for(int j=0;j<C;j++)
           {
               if(matrix[i][j]>max)
               {
                   max=matrix[i][j];
               }
           }
       }
       
       int size=R*C;
       int low=min;
       int high=max;
       int ans=matrix[0][0];
       while(low<=high)
       {
           int mid=low+(high-low)/2;
           if(possible(matrix,mid,size/2,R,C))
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
