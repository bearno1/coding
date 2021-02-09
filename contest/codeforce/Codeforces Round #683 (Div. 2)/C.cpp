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
int t,n;
LL x,kp,kp2,ss;
vector<int>ans;
priority_queue<pair<LL,int> >pq;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        ans.clear();
        ss=0;
        scanf("%d %lld",&n,&kp);
        kp2=(kp+1)/2;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            pq.push({x,i});
        }
        while(!pq.empty())
        {
            if(ss+pq.top().F<=kp)
            {
                ss+=pq.top().F;
                ans.pb(pq.top().S);
            }
            pq.pop();
        }
        sort(all(ans));
        if(ss<kp2)printf("-1\n");
        else
        {
            printf("%d\n",ans.size());
            for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
            printf("\n");
        }
    }
}
