#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
const long long MOD ((long long)(1e9+7));
const long long LLX ((long long)(1e18));
using namespace std;
int n,m,gr,k,a,b;
set<int>s;
set<int>::iterator it;
map<pair<int,int>,bool>mm;
queue<int>q;
queue<int>de;
bitset<100005>vis;
int main()
{
   scanf("%d %d",&n,&m);
   gr=n;
   for(int i=1;i<=n;i++)s.insert(i);
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d",&a,&b);
      mm[{min(a,b),max(a,b)}]=true;
   }
   for(int i=1;i<=n;i++)
   {
      if(vis[i])continue;
      vis[i]=true;
      q.push(i);
      s.erase(i);
      while(!q.empty())
      {
         k=q.front();
         q.pop();
         it=s.begin();
         while(it!=s.end())
         {
            if(*it==k||vis[*it])
            {
               it++;
               continue;
            }
            if(!mm[{min(*it,k),max(*it,k)}])
            {
               q.push(*it);
               gr--;
               vis[*it]=true;
               de.push(*it);
               //printf("%d - %d\n",*it,k);
            }
            it++;
         }
         while(!de.empty())
         {
            s.erase(de.front());
            de.pop();
         }
      }
   }
   printf("%d",gr-1);
}
