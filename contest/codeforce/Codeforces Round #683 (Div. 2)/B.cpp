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
int t,n,m,val[15][15],ans;
priority_queue<int>a,b;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        ans=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&val[i][j]);
                if(val[i][j]>=0)a.push(-val[i][j]);
                else b.push(-val[i][j]);
            }
        }
        while(b.size()>1)
        {
            ans+=b.top();
            b.pop();
            ans+=b.top();
            b.pop();
        }
        if(!a.empty()&&!b.empty())
        {
            if(-a.top()<b.top())
            {
                ans+=b.top();
                b.pop();
                ans+=a.top();
                a.pop();
            }
            else ans-=b.top(),b.pop();
        }
        else if(!b.empty())
        {
            ans-=b.top(),b.pop();
        }
        while(!a.empty())
        {
            ans-=a.top();
            a.pop();
        }
        printf("%d\n",ans);
    }
}
