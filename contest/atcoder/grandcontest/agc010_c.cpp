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
int n,val[100005],a,b,st;
bool p=true;
vector<int>v[100005];
priority_queue<int>pq;
int dfs(int N,int pr)
{
    //printf("[%d %d]",n,pr);
    if(N==st||v[N].size()>2)
    {
        int mx=0,mi,ss,cal,al=0,k;
        for(int i=0;i<v[N].size();i++)
        {
            if(v[N][i]!=pr)
            {
                k=dfs(v[N][i],N);
                pq.push(k);
                al+=k;
            }
        }
        al=max(al-val[N],0);
        while(!pq.empty())
        {
            if(mx<pq.top())
            {
                pq.push(mx);
                mx=pq.top();
                pq.pop();
                continue;
            }
            mi=min(min(val[n],al),pq.top());
            val[N]-=mi;
            al-=mi;
            mx-=mi;
            if(mi<pq.top())ss+=pq.top()-mi;
            pq.pop();
        }
        if(val[N]!=ss)p=false;
    }
    else
    {
        for(int i=0;i<v[N].size();i++)
        {
            if(v[N][i]!=pr)
            {
                if(dfs(v[N][i],N)!=val[N])p=false;
            }
        }
    }
    //printf("[%d %d]\n",N,val[N]);
    return val[N];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>1)st=i;
    }
    if(n==2)
    {
        if(val[1]==val[2])printf("YES");
        else printf("NO");
        return 0;
    }
    if(p&&dfs(st,0)==0)printf("YES");
    else printf("NO");
}
