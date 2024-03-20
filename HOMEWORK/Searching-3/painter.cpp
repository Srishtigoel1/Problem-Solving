
long long int  possible(vector<int>& arr,int mid,int m)
{
    int s=1;
    long long int paint=0;
    for(int i=0;i<arr.size();i++)
    {
        if(paint+arr[i]<=mid)
        {
            paint=paint+arr[i];
        }
        else
        {
            s++;
            paint=arr[i];
        }
    }
    return s;

}
int painter(vector<int>& arr, int n, int n) {
    if(m>n)
    return -1; 

    long long int low=*max_element(arr.begin(),arr.end());
    long long int high=accumulate(arr.begin(),arr.end(),0);
   
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(possible(arr,mid,m)>m)
        {
            
          low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}
