#include<bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,m,boss[100005],u,w;
bool p=false;
vector<int>v[100005];
bitset<100005>vis;
stack<int>stk;
void dfs(int N,int b)
{
   vis[N]=true;
   boss[b]=b;
   for(int i=0;i<v[N].size();i++)
   {
      if(!vis[v[N][i]])
      {
         dfs(v[N][i],b);
      }
      else
      {
         if(boss[v[N][i]]==b)p=true;
      }
   }
   stk.push(N);
   return;
}
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d",&u,&w);
      v[u].push_back(w);
   }
   for(int i=1;i<=n;i++)
   {
      if(!vis[i])
      {
         dfs(i,i);
      }
   }
   if(p)
   {
      printf("no");
   }
   else
   {
      while(!stk.empty())
      {
         printf("%d\n",stk.top());
         stk.pop();
      }
   }
}
