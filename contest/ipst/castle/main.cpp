#include<bits/stdc++.h>
#include "castle.h"
//#include "castle.cpp"
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define all(x) ((x).begin(),(x).end())
#define F first
#define S second
#define pb push_back
typedef long long LL;
typedef pair<int,int> pii;
using namespace std;

int N,M,Q,Y,T,X,boss[100005],cc,h[100005];
bool ans;
vector<int> a,b,pa[100005],v[100005];
bitset<100100>del;
bitset<100005>vis;
int fi(int p)
{
    if(p==boss[p])return p;
    else return fi(boss[p]);
}
void un(int x,int y)
{
    boss[fi(x)]=y;
    return;
}
void dfs(int n,int pr)
{
    vis[n]=true;
    if(n==Y)ans=true;
    for(int i=0;i<pa[n].size();i++)
    {
        if(!vis[pa[n][i]])dfs(pa[n][i],n);
    }
    return;
}
void dfs1(int n,int lv)
{
    vis[n]=true;
    h[n]=lv;
    for(int i=0;i<pa[n].size();i++)
    {
        if(!vis[pa[n][i]])dfs(pa[n][i],lv+1);
    }
    return;
}
void dfs2(int n,int ch)
{
    vis[n]=true;
    if(n==ch)ans=true;
    for(int i=0;i<v[n].size();i++)
    {
        if(!vis[v[n][i]])dfs2(v[n][i],ch);
    }
    return;
}
int main()
{
    castle_init(N,M,Q,Y);
    castle_read_map(a,b);
    if(N<=1000&&Q<=1000)
    {
        for(int t=1;t<=Q;t++)
        {
            castle_read_event(T,X,Y);
            if(T==1)
            {
                del[X]=true;
            }
            else
            {
                ans=false;
                for(int i=0;i<N;i++)
                {
                    vis[i]=false;
                    pa[i].clear();
                }
                for(int i=0;i<M;i++)
                {
                    if(!del[i])
                    {
                        pa[a[i]].pb(b[i]);
                        pa[b[i]].pb(a[i]);
                    }
                }
                dfs(X,-1);
                if(ans)castle_answer(1);
                else castle_answer(0);
            }
        }
    }
    else if(Y==1)
    {
        for(int i=0;i<N;i++)
        {
            boss[i]=i;
        }
        for(int i=0;i<N-1;i++)
        {
            if(a[i]>b[i])
            {
                un(a[i],b[i]);
            }
            else
            {
                un(b[i],a[i]);
            }
        }
        for(int t=1;t<=Q;t++)
        {
            castle_read_event(T,X,Y);
            if(T==1)
            {
                del[X]=true;
                if(X<N-1)
                {
                    if(a[X]>b[X])
                    {
                        boss[a[X]]=a[X];
                    }
                    else
                    {
                        boss[b[X]]=b[X];
                    }
                }
            }
            else
            {
                if(fi(X)==fi(Y))castle_answer(1);
                else
                {
                    // if(!del[M-1])
                    // {
                    //     if((fi(X)==fi(a[M-1]))&&(fi(Y)==fi(b[M-1])))castle_answer(1);
                    //     else if((fi(X)==fi(b[M-1]))&&(fi(Y)==fi(a[M-1])))castle_answer(1);
                    //     else castle_answer(0);
                    // }
                    // else castle_answer(0);
                    // ans=false;
                    ans=false;
                    v[fi(X)].clear(),v[fi(X)].clear();
                    vis[fi(Y)]=false,vis[fi(Y)]=false;
                    for(int i=N-1;i<M;i++)
                    {
                        v[fi(a[i])].clear(),v[fi(b[i])].clear();
                        vis[fi(a[i])]=false,vis[fi(b[i])]=false;
                    }
                    for(int i=N-1;i<M;i++)
                    {
                        if(!del[i])v[fi(a[i])].pb(fi(b[i])),v[fi(b[i])].pb(fi(a[i]));
                    }
                    dfs2(fi(X),fi(Y));
                    if(ans)castle_answer(1);
                    else castle_answer(0);
                }
            }
        }
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            boss[i]=i;
        }
        for(int i=0;i<N-1;i++)
        {
            pa[a[i]].pb(b[i]);
            pa[b[i]].pb(a[i]);
        }
        for(int i=0;i<N;i++)
        {
            if(pa[i].size()==2)cc=i;
        }
        if(Y==1)cc=0;
        dfs1(cc,1);
        for(int i=0;i<N-1;i++)
        {
            del[X]=true;
            if(h[a[i]]>h[b[i]])
            {
                un(a[i],b[i]);
            }
            else
            {
                un(b[i],a[i]);
            }
        }
        for(int t=1;t<=Q;t++)
        {
            castle_read_event(T,X,Y);
            if(T==1)
            {
                if(h[a[X]]>h[b[X]])
                {
                    boss[a[X]]=a[X];
                }
                else
                {
                    boss[b[X]]=b[X];
                }
            }
            else
            {
                if(fi(X)==fi(Y))castle_answer(1);
                else castle_answer(0);
            }
        }
    }
  // castle_init(N,M,Q,Y);
  // castle_read_map(A,B);
  //
  // while (Q--) {
  //   int T,X,Y;
  //   castle_read_event(T,X,Y);
  //
  //   if (T == 2) {
  //     castle_answer(0);
  //   }
  // }
}
