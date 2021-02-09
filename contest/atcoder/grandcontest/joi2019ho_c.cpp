#include<bits/stdc++.h>
#define MOD ((long long)(1e9+7))
#define F first
#define S second
using namespace std;
struct ch
{
   char cc[405];
}st,*pos;
char c[405],temp[405],tem;
int l,n[5],k,t;
long long hs;
bool p;
map<int,int>mp;
priority_queue<pair<int,*ch> >pq;
void swap(int a,int b)
{
   tem=c[a];
   c[a]=c[b];
   c[b]=tem;
   return;
}
int main()
{
   scanf("%d",&l);
   scanf("%s",st.cc);
   for(int i=0;i<l;i++)
   {
      if(st.cc[i]=='R')st.cc[i]=1;
      else if(st.cc[i]=='G')st.cc[i]=2;
      else st.cc[i]=3;
      n[st.cc[i]]++;
   }
   k=(l+1)/2;
   if(n[1]>k||n[2]>k||n[3]>k)
   {
      printf("-1");
      return 0;
   }
   for(int i=0;i<l;i++)
   {
      hs+=st.cc[i]-1;
      hs*=3;
      hs%=MOD;
   }
   mp[hs]=0;
   pq.push({0,*st});
   while(!pq.empty())
   {
      t=pq.top().F;
      pos=pq.top().S;
      pq.pop();
      for(int i=1;i<=l;i++);
   }
}
