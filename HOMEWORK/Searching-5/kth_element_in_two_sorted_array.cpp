int count(vector<int>arr1,vector<int>arr2,int mid){
        int count=0;
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]<=mid){
                count++;
            }
            else 
                break;
        }
        for(int i=0;i<arr2.size();i++){
            if(arr2[i]<=mid){
                count++;
            }
            else
                 break;
        }
        return count;
    }
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
     
    int low=min(arr1[0],arr2[0]);

    int high=max(arr1[n-1],arr2[m-1]);
    while(low<=high){
        int mid=low+(high-low)/2;
        int x=count(arr1,arr2,mid);
       
         if(x<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return low;
}