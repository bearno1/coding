#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
vector<int>v[500005];
vector<int>bl[500005];
int ans[500005],n,m,a,b,k,r=0,fen[500005],to[500005];
bool p=true;
map<int,bool>mm;
queue<int>q;
void up(int pos,int val)
{
    while(pos<500005)
    {
        fen[pos]+=val;
        pos+=pos&(-pos);
    }
    return;
}
int ss(int pos)
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
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=1;i<=n;i++)scanf("%d",&to[i]),bl[to[i]].pb(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<bl[i].size();j++)
        {
            mm.clear();
            k=bl[i][j];
            r++;
            //printf("[%d]\n",k);
            for(int ii=0;ii<v[k].size();ii++)
            {
                //printf("%d ",to[v[k][ii]]);
                if(to[v[k][ii]]==i)p=false;
                if(!mm[to[v[k][ii]]]&&to[v[k][ii]]<i)
                {
                    q.push(to[v[k][ii]]);
                    mm[to[v[k][ii]]]=true;
                    up(to[v[k][ii]],1);
                }
            }
            //printf("\n");
            if(i==1)
            {
                ans[r]=k;
                while(!q.empty())
                {
                    up(q.front(),-1);
                    q.pop();
                }
            }
            else if(ss(i-1)==i-1)
            {
                ans[r]=k;
                while(!q.empty())
                {
                    up(q.front(),-1);
                    q.pop();
                }
            }
            else
            {
                p=false;
                while(!q.empty())
                {
                    up(q.front(),-1);
                    q.pop();
                }
            }
        }
    }
    if(!p)
    {
        printf("-1");
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
    }
}
