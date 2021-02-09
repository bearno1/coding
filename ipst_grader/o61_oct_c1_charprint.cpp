#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
using namespace std;
int n,aa,bb,r[30],fen[300005];
long long ans;
char a[300005],b[100005];
vector<int>v[30];
bool p=true;
void UP(int pos)
{
   while(pos<300005)
   {
      fen[pos]++;
      pos+=pos&(-pos);
   }
   return;
}
int SS(int pos)
{
   int re=0;
   while(pos>0)
   {
      re+=fen[pos];
      pos-=pos&(-pos);
   }
   return re;
}
int main()
{
   scanf("%d",&n);
   scanf("%s",a+1);
   scanf("%s",b+1);
   aa=strlen(a+1);
   bb=strlen(b+1);
   for(int i=1;i<=aa;i++)
   {
      v[a[i]-'a'].push_back(i);
   }
   for(int i=1;i<=bb;i++)
   {
      int k=b[i]-'a';
      if(r[k]==v[k].size())
      {
         p=false;
         break;
      }
      if(n==0)
      {
         ans+=v[k][r[k]];
      }
      else
      {
         ans+=v[k][r[k]]-SS(v[k][r[k]]);
         UP(v[k][r[k]]);
      }
      r[k]++;
   }
   if(p)printf("%lld",ans);
   else printf("-1");
}
