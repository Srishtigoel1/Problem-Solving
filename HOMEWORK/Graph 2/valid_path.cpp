string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    //c->no of circle
    //d->radius
    vector<vector<int>> vis(A+1,vector<int>(B+1,0));//visited array
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            bool flag= false;
            //inn main se kissi bhi circle main hain kya 
            for(int k=0;k<E.size();k++)
            {
                if((E[k]-i)*(E[k]-i)+(F[k]-j)*(F[k]-j)<= D*D)
                {
                    flag=true;
                    break;
                    //agar ek main bhi true aaya toh wo point circle ke andar aayega hi 
                    //aur humhe nhi lena usse
                    
                }
            }
            if(flag==true)
            vis[i][j]=1;
        }
        
    }
    int X[]={-1,-1,-1,0,0,1,1,1};
    int Y[]={-1,0,1,-1,1,-1,0,1};
    queue<pair<int,int>>q;
    q.push({0,0});
    if(vis[0][0]==1 || vis[A][B]==1)
    {
        return "NO";//pehle se visited h 
    }
    vis[0][0]=1;
    while(!q.empty())
    {
        auto o=q.front();
        auto x=o.first;
        auto y=o.second;
        q.pop();
        if(x==A && y==B)
        {
            return "YES";
        }
        for(int i=0;i<8;i++)
        {
            auto ncr=x+X[i];
            auto ncc=y+Y[i];
            if(ncr>=0 && ncc>=0 && ncr<=A && ncc<=B && vis[ncr][ncc]==0)
            {
                q.push({ncr,ncc});
                vis[ncr][ncc]=1;
            }
        }
        
    }
    return "NO";
    
    
    
}
