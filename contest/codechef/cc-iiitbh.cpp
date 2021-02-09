#include<bits/stdc++.h>
#define F first
#define S second
#define L (index*2)
#define R ((index*2)+1)
using namespace std;
int seq[55][400005][2],n,m,x,score[100005],op,a,b,ans;
pair<int,int>pp;
void UP(int pos,int id,int stat,int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(st>pos||ed<pos)return;
   if(st==ed)
   {
      if(stat==1)
      {
         seq[id][index][0]=pos;
         seq[id][index][1]=pos;
      }
      else
      {
         seq[id][index][0]=INT_MAX;
         seq[id][index][1]=0;
      }
      return;
   }
   UP(pos,id,stat,st,mid,L);
   UP(pos,id,stat,mid+1,ed,R);
   seq[id][index][0]=min(seq[id][L][0],seq[id][R][0]);
   seq[id][index][1]=min(seq[id][L][1],seq[id][R][1]);
   return;
}
pair<int,int> SS(int id,int A,int B,int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(st>B||ed<A)return {INT_MAX,0};

}
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<55;i++)
   {
      for(int j=0;j<400005;j++)
      {
         seq[i][j][0]=INT_MAX;
         seq[i][j][1]=0;
      }
   }
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&score[i]);
      UP(i,score[i],1,1,n,1);
   }
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %d",&op,&a,&b);
      if(op==1)
      {
         UP(a,score[i],-1,1,n,1);
         UP(a,b,1,1,n,1);
         score[a]=b;
      }
      else
      {
         ans=0;
         for(int j=1;j<=50;j++)
         {
            pp=SS(j,a,b,1,n,1);
            if(pp.F==INT_MAX||pp.S==0)continue;
            ans=max(pp.S-pp.F,ans);
         }
         printf("%d\n",ans);
      }
   }
}
