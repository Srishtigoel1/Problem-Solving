int Solution::knight(int A, int B, int C, int D, int E, int F) {
   priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;  // dist,node
   C=C-1;
   D=D-1;
   pq.push({0,{C,D}});
   E=E-1;
   F=F-1;
   if(C==E && D==F)
   {
       return 0;
   }
   int X[]={-2,-2,-1,-1,1,1,2,2};
   int Y[]={-1,1,-2,2,-2,2,-1,1};
   vector<vector<int>> vis(A,vector<int>(B,0));
   vis[C][D]=1;
   while(!pq.empty())
   {
       auto x=pq.top();
       auto y=x.first;//distance
       auto r=x.second.first;//x coord
       auto s=x.second.second;//y coord
       pq.pop();
       if(r==E && s==F)
       {
           return y;
       }
       for(int i=0;i<8;i++)
       {
           auto nr=r+X[i];
           auto nc=s+Y[i];
           if(nr>=0 && nr<A && nc>=0 && nc<B &&  vis[nr][nc]==0)
           {
               pq.push({y+1,{nr,nc}});
               vis[nr][nc]=1;
           }
       }
       
   }
   return -1;
}
