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
int n,t,go[100005],k,ans[100005],tp;
bitset<100005>vis;
map<int,int>mp;
int dfs(int N,int val)
{
    vis[N]=true;
    if(vis[go[N]])return val;
    else return(dfs(go[N],val+1));
}
int main()
{
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++)scanf("%d",&go[i]);
    for(int i=1;i<=n;i++)
    {
        if(!vis[go[i]])
        {
            int x=dfs(i,1);
            mp[x]++;
        }
    }
    for(int i=1;i<=100000;i++)
    {
        if(mp[i]!=0)
        {
            //printf("%d %d\n",i,mp[i]);
            for(int j=i-1;j>0;j--)
            {
                ans[j]+=(((i+j-1)/j)-1)*mp[i];
            }
        }
    }
    //for(int i=1;i<=10;i++)printf("=%d %d=\n",ans[i],i);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&k);
        int st=1,ed=n,pr=n,mid;
        while(st<=ed)
        {
            mid=(st+ed)/2;
            if(ans[mid]>k)st=mid+1;
            else pr=min(pr,mid),ed=mid-1;
        }
        printf("%d\n",pr);
    }
}
