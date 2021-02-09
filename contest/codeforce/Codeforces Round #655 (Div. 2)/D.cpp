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
typedef pair<LL,int> pii;
int n,bs1[200005],bs2[200005],op,tt,N;
LL val[200005];
bitset<200005>del;
priority_queue<pii>pq;
int main()
{
    scanf("%d",&n);
    op=n/2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        pq.push({-val[i],i});
        bs1[i]=i+1;
        bs2[i]=i-1;
    }
    bs1[n]=1;
    bs2[1]=n;
    while(tt<op)
    {
        //printf("%d %lld\n",pq.top().S,-pq.top().F);
        if(del[pq.top().S]||(-pq.top().F!=val[pq.top().S]))
        {
            pq.pop();
            continue;
        }
        tt++;
        N=pq.top().S;
        pq.pop();
        val[N]=val[bs1[N]]+val[bs2[N]];
        //printf("[%d %d]\n",bs1[N],bs2[N]);
        del[bs1[N]]=true,del[bs2[N]]=true;
        bs1[N]=bs1[bs1[N]];
        bs2[N]=bs2[bs2[N]];
        bs2[bs1[N]]=N;
        bs1[bs2[N]]=N;
        pq.push({-val[N],N});
        // for(int i=1;i<=n;i++)
        // {
        //     if(!del[i])printf("{%d %d %d}\n",i,bs1[i],bs2[i]);
        // }
    }
    for(int i=1;i<=n;i++)
    {
        if(!del[i])
        {
            printf("%lld",val[i]);
            return 0;
        }
    }
}
