class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int row=matrix.size();
        int column=matrix[0].size();
        int end=(column*row)-1;

        int mid=0;
        //binary search
        while(start<=end)
        { 
         mid=start+(end-start)/2;
        int element = matrix[mid/column][mid%column];
        if(element==target)
        {
            return true;
        }
        else if(element>target)
        {
            
            end=mid-1;
        }
        else
        {
            start=mid+1;
           
        }
      
        }  
        return false;
    }
};