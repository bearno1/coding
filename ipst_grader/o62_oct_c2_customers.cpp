#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n,m,Q,sq,x,con,op,cc,mon[120005],k,a,b,nnw,l,r;
queue<pair<int,int> >up[400];
long long val[120005];
vector<int>sh[120005];
vector<int>::iterator it;
int main()
{
   scanf("%d %d %d",&n,&m,&Q);
   sq=sqrt(n);
   cc=n/sq;
   for(int i=1;i<=m;i++)
   {
      scanf("%d",&x);
      for(int j=1;j<=x;j++)
      {
         scanf("%d",&con);
         sh[i].push_back(con);
      }
      sh[i].push_back(1000000);
      sort(sh[i].begin(),sh[i].end());
   }
   for(int t=1;t<=Q;t++)
   {
      scanf("%d",&op);
      if(op==1)
      {
         scanf("%d %d",&x,&con);
         k=con-mon[x];
         for(int i=0;i<=cc;i++)
         {
            up[i].push({x,k});
         }
         mon[x]=con;
      }
      else
      {
         scanf("%d",&x);
         nnw=x/sq;
         l=sq*nnw,r=min((sq*(nnw+1))-1,n);
         //printf("===%d %d %d\n",nnw,l,r);
         while(!up[nnw].empty())
         {
            a=up[nnw].front().F;
            b=up[nnw].front().S;
            up[nnw].pop();
            it=lower_bound(sh[a].begin(),sh[a].end(),l);
            if(it==sh[a].end())continue;
            //printf("[%d]\n",*it);
            while(*it<=r)
            {
               val[*it]+=b;
               //printf("------%d %d\n",*it,b);
               it++;
               if(it==sh[a].end())break;
            }
         }
         printf("%lld\n",val[x]);
      }
   }
}
