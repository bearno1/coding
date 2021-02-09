#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
#define L (index*2)
#define R ((index*2)+1)
const long long MOD ((long long)(1e9+7));
using namespace std;
int seq[400005][4],lazy[400005],a,b,n,m,op;
void up(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(lazy[index]!=0)
   {
      seq[index][0]+=lazy[index];
      seq[index][1]+=lazy[index];
      if(st!=ed)
      {
         lazy[L]+=lazy[index];
         lazy[R]+=lazy[index];
      }
      lazy[index]=0;
   }
   if(st>b||ed<a)return;
   if(a<=st&&b>=ed)
   {
      seq[index][0]+=1;
      seq[index][1]+=1;
      if(st!=ed)
      {
         lazy[L]+=1;
         lazy[R]+=1;
      }
      lazy[index]=0;
      return;
   }
   up(st,mid,L);
   up(mid+1,ed,R);
   seq[index][0]=seq[L][0];
   seq[index][1]=seq[R][1];
   seq[index][2]=seq[L][2]+seq[R][2];
   seq[index][3]=seq[L][3]+seq[R][3];
   if(seq[L][1]<seq[R][0])seq[index][2]++;
   if(seq[L][1]>seq[R][0])seq[index][3]++;
   return;
}
int FIND(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(lazy[index]!=0)
   {
      seq[index][0]+=lazy[index];
      seq[index][1]+=lazy[index];
      if(st!=ed)
      {
         lazy[L]+=lazy[index];
         lazy[R]+=lazy[index];
      }
      lazy[index]=0;
   }
   if(a<st||a>ed)return 0;
   if(a<=st&&a>=ed)return seq[index][0];
   return max(FIND(st,mid,L),FIND(mid+1,ed,R));
}
pair<int,pair<int,bool> > climb(int st,int ed,int index)
{
   int mid=(st+ed)/2;
   if(lazy[index]!=0)
   {
      seq[index][0]+=lazy[index];
      seq[index][1]+=lazy[index];
      if(st!=ed)
      {
         lazy[L]+=lazy[index];
         lazy[R]+=lazy[index];
      }
      lazy[index]=0;
   }
   //printf("{%d %d %d %d}\n",st,ed,seq[index][2],seq[index][3]);
   if(b<st||a>ed)return {0,{0,false}};
   if(a<=st&&b>=ed)return {seq[index][2],{seq[index][3],true}};
   pair<int,pair<int,bool> >x,y;
   x=climb(st,mid,L),y=climb(mid+1,ed,R);
   seq[index][2]=seq[L][2]+seq[R][2];
   seq[index][3]=seq[L][3]+seq[R][3];
   if(seq[L][1]<seq[R][0])seq[index][2]++;
   if(seq[L][1]>seq[R][0])seq[index][3]++;
   if(x.S.S&&y.S.S)
   {
      if(seq[L][1]<seq[R][0])x.F++;
      if(seq[L][1]>seq[R][0])x.S.F++;
   }
   return {x.F+y.F,{x.S.F+y.S.F,true}};
}
int main()
{
   scanf("%d %d",&n,&m);
   while(m--)
   {
      scanf("%d",&op);
      /*for(int i=1;i<=n;i++)
      {
         a=i;
         printf("%d ",FIND(1,n,1));
      }
      printf("\n");*/
      if(op==1)
      {
         scanf("%d %d",&a,&b);
         up(1,n,1);
      }
      else if(op==2)
      {
         scanf("%d %d",&a,&b);
         printf("%d ",FIND(1,n,1));
         a=b;
         printf("%d\n",FIND(1,n,1));
      }
      else
      {
         scanf("%d %d",&a,&b);
         int tem=a;
         printf("%d ",FIND(1,n,1));
         a=b;
         printf("%d ",FIND(1,n,1));
         a=tem;
         pair<int,pair<int,bool> >p=climb(1,n,1);
         printf("%d %d\n",p.F,p.S.F);
      }
   }
}
/*
10 10
1 2 5
2 1 10
3 1 10
1 4 5
2 1 10
3 3 6
1 8 8
3 5 8
1 5 10
2 5 6
*/
