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
int n,a,b,hi[100005],st=1,ed=1e9,ans=-1,mid,ls;
bitset<100005>m;
queue<int>q;
int main()
{
    scanf("%d %d %d",&n,&a,&b);
    for(int i=1;i<=n;i++)scanf("%d",&hi[i]);
    while(st<=ed)
    {
        while(!q.empty())q.pop();
        for(int i=1;i<=n;i++)m[i]=false;
        m[0]=true;
        mid=(st+ed)/2;
        ls=-1;
        for(int i=1;i<=n;i++)
        {
            if(hi[i]>=mid)ls=i;
            if(i-b-1>=0)if(m[i-b-1])q.pop();
            if(i-a>=0)if(m[i-a])q.push(i-a);
            if(!q.empty())if(q.front()<ls)m[i]=true;
        }
        // printf("%d\n",mid);
        // for(int i=1;i<=n;i++)if(m[i])printf("%d ",i);
        // printf("\n");
        if(m[n])st=mid+1,ans=max(ans,mid);
        else ed=mid-1;
    }
    printf("%d",ans);
}
/*
10 3 4
10
20
15
18
1
2
1
2
4
30
10 6 7
10
20
15
18
1
2
1
2
4
30
*/
