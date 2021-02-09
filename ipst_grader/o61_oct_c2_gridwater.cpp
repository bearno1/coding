#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define F first
#define S second
struct node
{
   vector<pair<int,int> >V;
   int lv=0,boss,goB,skip,slv,boxMX;
}node[170005];
const long long MOD ((long long)(1e9+7));
int boss[170005],n,m,k,cc,x,a,b,c,HH,block,P,ans=INT_MAX;
priority_queue<pair<int,pair<int,int> > >pq;
priority_queue<pair<int,pair<int,int> > >DD;
int FIND(int f)
{
   if(boss[f]==f)
      return f;
   else
      return boss[f]=FIND(boss[f]);
}
void UN(int f,int s)
{
   boss[FIND(f)]=FIND(s);
   return;
}
void hh(int pos,int l)
{
   node[pos].lv=l;
   HH=max(HH,l);
	//printf("+++ %d %d\n",ll,pos);
	for(int i=0;i<node[pos].V.size();i++)
	{
      if(node[node[pos].V[i].S].lv==0)hh(node[pos].V[i].S,l+1);
	}
	return;
}
void gen(int pos,int l,int sp,int s,int mx,int las)
{
   node[pos].skip=sp;
	node[pos].slv=s;
   node[pos].boxMX=mx;
   node[pos].goB=las;
	if(l%block==1)sp=pos,s=l,mx=0;
	for(int i=0;i<node[pos].V.size();i++)
	{
		if(node[node[pos].V[i].S].lv==l+1)
      {
         node[node[pos].V[i].S].boss=pos;
         gen(node[pos].V[i].S,l+1,sp,s,max(mx,node[pos].V[i].F),node[pos].V[i].F);
      }
	}
	return;
}
int main()
{
   scanf("%d %d",&m,&n);
   k=(n*m)-1,cc=(m*2)-1;
   for(int i=0;i<170005;i++)boss[i]=i;
   for(int i=1;i<=cc;i++)
   {
      P=i/2;
      if(i%2==1)
      {
         for(int j=1;j<n;j++)
         {
            scanf("%d",&x);
            //printf("==%d== %d %d\n",j+(P*n),i,x);
            pq.push({-x,{j+(P*n),j+(P*n)+1}});
         }
      }
      else
      {
         for(int j=1;j<=n;j++)
         {
            scanf("%d",&x);
            pq.push({-x,{j+((P-1)*n),j+(P*n)}});
         }
      }
   }
   //printf("[%d]\n",pq.size());
   while(k)
   {
      a=-pq.top().F;
      b=pq.top().S.F;
      c=pq.top().S.S;
      pq.pop();
      //printf("%d %d %d\n",a,b,c);
      if(FIND(b)!=FIND(c))
      {
         UN(b,c);
         k--;
         node[b].V.push_back({a,c});
         node[c].V.push_back({a,b});
      }
      else
      {
         DD.push({-a,{b,c}});
      }
   }
   while(!pq.empty())
   {
      a=-pq.top().F;
      b=pq.top().S.F;
      c=pq.top().S.S;
      pq.pop();
      DD.push({-a,{b,c}});
   }
   hh(1,1);
   block=(int)sqrt(HH);
   gen(1,1,1,1,0,0);
   //printf("[%d]\n",DD.size());
   while(!DD.empty())
   {
      a=-DD.top().F;
      b=DD.top().S.F;
      c=DD.top().S.S;
      //printf("%d %d %d\n",a,b,c);
      DD.pop();
      k=-1;
      if(node[b].slv!=node[c].slv)
      {
         while(node[b].slv>node[c].slv+block)
         {
            k=max(k,node[b].boxMX);
            b=node[b].skip;
         }
         while(node[b].slv+block<node[c].slv)
         {
            k=max(k,node[c].boxMX);
            c=node[c].skip;
         }
      }
      while(node[b].lv>node[c].lv)
      {
         k=max(k,node[b].goB);
         b=node[b].boss;
      }
      while(node[b].lv<node[c].lv)
      {
         k=max(k,node[c].goB);
         c=node[c].boss;
      }
      while(node[b].skip!=node[c].skip)
      {
         k=max(k,node[b].boxMX);
         k=max(k,node[c].boxMX);
         b=node[b].skip;
         c=node[c].skip;
      }
      while(b!=c)
      {
         k=max(k,node[b].goB);
         k=max(k,node[c].goB);
         b=node[b].boss;
         c=node[c].boss;
      }
      ans=min(ans,a-k);
   }
   printf("%d",ans);
}
