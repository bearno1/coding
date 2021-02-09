#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n,m,Q,a,b,cc;
vector<int>v[100005][2];
set<int>S[100005][2];
set<int>::iterator it;
queue<int>q;
bitset<100005>cr;
bitset<100005>go[2];
int main()
{
   scanf("%d %d %d",&n,&m,&Q);
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d",&a,&b);
      v[a][0].push_back(b);
      v[b][1].push_back(a);
   }
   q.push(1);
   go[0][1]=true;
   while(!q.empty())
   {
      a=q.front();
      q.pop();
      for(int i=0;i<v[a][0].size();i++)
      {
         if(!go[0][v[a][0][i]])
         {
            go[0][v[a][0][i]]=true;
            q.push(v[a][0][i]);
         }
         S[v[a][0][i]][0].insert(a);
      }
   }
   q.push(n);
   go[1][n]=true;
   while(!q.empty())
   {
      a=q.front();
      q.pop();
      for(int i=0;i<v[a][1].size();i++)
      {
         if(!go[1][v[a][1][i]])
         {
            go[1][v[a][1][i]]=true;
            q.push(v[a][1][i]);
         }
         S[v[a][1][i]][1].insert(a);
      }
   }
   while(Q--)
   {
      scanf("%d %d",&a,&b);
      if(a==2)
      {
         if(go[0][b]&&go[1][b])printf("1\n");
         else printf("0\n");
      }
      else
      {
         go[0][b]=false;
         go[1][b]=false;
         S[b][0].clear();
         S[b][1].clear();
         q.push(b);
         while(!q.empty())
         {
            a=q.front();
            q.pop();
            for(int i=0;i<v[a][1].size();i++)
            {
               if(!go[1][v[a][1][i]])continue;
               it=S[v[a][1][i]][1].find(a);
               if(it==S[v[a][1][i]][1].end())continue;
               S[v[a][1][i]][1].erase(it);
               if(S[v[a][1][i]][1].size()==0)go[1][v[a][1][i]]=false,q.push(v[a][1][i]);
            }
         }
         q.push(b);
         while(!q.empty())
         {
            a=q.front();
            q.pop();
            for(int i=0;i<v[a][0].size();i++)
            {
               if(!go[0][v[a][0][i]])continue;
               it=S[v[a][0][i]][0].find(a);
               if(it==S[v[a][0][i]][0].end())continue;
               S[v[a][0][i]][0].erase(a);
               if(S[v[a][0][i]][0].size()==0)go[0][v[a][0][i]]=false,q.push(v[a][0][i]);
            }
         }
      }
   }
}
