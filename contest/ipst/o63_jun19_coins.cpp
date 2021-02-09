#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define all(x) ((x).begin(),(x).end())
#define F first
#define S second
#define pb push_back
typedef long long LL;
typedef pair<LL,LL> pii;
int n,ty[1000005],rr,gr[1000005],a,b,bb,ru,vc,co,ko;
LL dis[1000005],dis2[1000005],aa,an,bn,ans=1e15;
map<int,int>mm;
priority_queue<int,vector<int>,greater<int> >pq;
vector<int>v[1000005];
vector<pii>vv[2][2];
deque<pii>dq[2];
LL dd(int x,int y)
{
    if(x>y)
    {
        return dd(x,n)+dd(1,y)+dis[n]-dis[n-1];
    }
    else
    {
        return dis[y-1]-dis[x-1];
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ty[i]);
        if(mm[ty[i]]==0)
        {
            mm[ty[i]]=1;
            pq.push(ty[i]);
        }
    }
    while(!pq.empty())
    {
        rr++;
        mm[pq.top()]=rr;
        pq.pop();
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&dis[i]);
    }
    for(int i=1;i<=n;i++)
    {
        ty[i]=mm[ty[i]];
        v[ty[i]].pb(i);
        gr[ty[i]]++;
        dis2[n-i+1]=dis2[n-i+2]+dis[n-i+1];
    }
    for(int i=1;i<=n;i++)
    {
        v[ty[i]].pb(i+n);
        dis[i]=dis[i-1]+dis[i];
    }
    for(int i=1;i<=n;i++)
    {
        vv[0][0].pb({i,0});
        vv[0][1].pb({i,0});
    }
    for(int i=1;i<=rr;i++)
    {
        //printf("%d",i);
        if(rr%2==0)vv[0][0].clear(),vv[0][1].clear(),vc=vv[1][0].size()-1,co=1,ko=0;
        else vv[1][0].clear(),vv[1][1].clear(),vc=vv[0][0].size()-1,ko=1,co=0;
        while(!dq[0].empty())dq[0].pop_front();
        while(!dq[1].empty())dq[1].pop_front();
        ru=0;
        for(int j=0;j<gr[i];j++)
        {
            //printf("(%d)",j);
            a=v[i][j];
            b=v[i][j+gr[i]];
            if(b>n)b-=n;
            if(ru<=vc)
            {
                bn=min(vv[co][0][ru].S,vv[co][1][ru].S);
                an=vv[co][0][ru].F;
                bn+=dis2[an+1];
                if(bn<=a)
                {
                    if(dq[0].empty())
                    {
                        dq[0].pb({bn,an});
                    }
                    else
                    {
                        while(dq[0].back().S>=bn)
                        {
                            dq[0].pop_back();
                            if(dq[0].empty())
                            {
                                break;
                            }
                        }
                        dq[0].pb({bn,an});
                    }
                    ru++;
                }
            }
            //printf("[[]]");
            //printf("P%d %dP",a,b);
            vv[ko][0].pb({b,dd(a,b)+dq[0].front().S-dis2[a+1]});
            //printf("--");
        }
        sort(vv[ko][0].begin(),vv[ko][0].end());
        ru=vc-1;
        for(int j=0;j<gr[i];j++)
        {
            a=v[i][j];
            b=v[i][j+gr[i]];
            if(b>n)b-=n;
            swap(a,b);
            if(ru>0)
            {
                bn=min(vv[co][0][ru].S,vv[co][1][ru].S);
                an=vv[co][1][ru].F;
                bn+=dis[an-1];
                if(bn>=a)
                {
                    if(dq[1].empty())
                    {
                        dq[1].pb({bn,an});
                    }
                    else
                    {
                        while(dq[1].back().S>=bn)
                        {
                            dq[1].pop_back();
                            if(dq[1].empty())
                            {
                                break;
                            }
                        }
                        dq[1].pb({bn,an});
                    }
                    ru++;
                }
            }
            vv[ko][1].pb({b,dd(a,b)+dq[1].front().S-dis[a-1]});
        }
        sort(vv[ko][1].begin(),vv[ko][1].end());
        // printf("(%d)\n",i);
        // for(int j=0;j<vv[ko][0].size();j++)
        // {
        //     printf("%lld %lld %lld %lld\n",vv[ko][0][j].F,vv[ko][0][j].S,vv[ko][1][j].F,vv[ko][1][j].S);
        // }
    }
    for(int i=0;i<vv[ko][0].size();i++)
    {
        ans=min(ans,min(vv[ko][0][i].S,vv[ko][1][i].S));
    }
    printf("%lld",ans);
}
