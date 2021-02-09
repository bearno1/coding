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
int n,m,qr[300005][3],st,ed,mid,ans,boss[300005],ze,gr[15];
bool a1=true;
bitset<300005>vis,col;
vector<int>v[300005];
int F(int x)
{
	if(boss[x]==x)return x;
	else return boss[x]=F(boss[x]);
}
void un(int x,int y)
{
	boss[F(x)]=F(y);
	return;
}
LL pow_2(int N)
{
	LL re=2;
	if(N==1)return re;
	re=pow_2(N/2);
	if(N%2==0)
	{
		return (re*re)%MOD;
	}
	else
	{
		return (re*re*2)%MOD;
	}
}
bool dfs(int N,bool p)
{
	bool re=false;
	vis[N]=true;
	col[N]=!p;
	for(int i=0;i<v[N].size();i++)
	{
		if(!vis[v[N][i]])
		{
			if(dfs(v[N][i],col[N]))re=true;
		}
		else
		{
			if(col[N]==col[v[N][i]])re=true;
		}
	}
	return re;
}
void gen(int lv,int cp)
{
    if(lv==n+1)
    {
        int re=1;
        for(int i=1;i<=cp;i++)
        {
            if(qr[i][0]==0)
            {
                if(gr[qr[i][1]]==gr[qr[i][2]])re=0;
            }
            else
            {
                if(gr[qr[i][1]]!=gr[qr[i][2]])re=0;
            }
        }
        ans+=re;
    }
    else
    {
        gr[lv]=0,gen(lv+1,cp);
        gr[lv]=1,gen(lv+1,cp);
    }
    return;
}
bool che(int rr)
{
	bool re=true;
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		vis[i]=false;
		col[i]=false;
		boss[i]=i;
	}
	for(int i=1;i<=rr;i++)
	{
		if(qr[i][0]==1)
		{
			un(qr[i][1],qr[i][2]);
		}
	}
	for(int i=1;i<=rr;i++)
	{
		if(qr[i][0]==0)
		{
			v[F(qr[i][1])].pb(F(qr[i][2]));
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[F(i)])
		{
			if(dfs(F(i),false))
			{
				re=false;
			}
		}
	}
	return re;
}
int main()
{
	scanf("%d %d",&n,&m);
	ans=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&qr[i][0],&qr[i][1],&qr[i][2]);
        if(qr[i][0]==0)a1=false;
	}
    if(n<=10&&m<=10)
    {
        for(int i=1;i<=m;i++)
        {
            ans=0;
            gen(1,i);
            printf("%d\n",ans);
        }
    }
    else if(a1)
    {
        for(int i=1;i<=n;i++)boss[i]=i;
        for(int i=1;i<=ze;i++)
    	{
    		if(F(qr[i][1])!=F(qr[i][2]))un(qr[i][1],qr[i][2]),ans--;
    		printf("%lld\n",pow_2(ans));
    	}
    }
    else
    {
        st=1,ed=m;
    	while(st<=ed)
    	{
    		mid=(st+ed)/2;
    		if(che(mid))
    		{
    			st=mid+1;
    			ze=max(ze,mid);
    		}
    		else
    		{
    			ed=mid-1;
    		}
    	}
    	for(int i=1;i<=n;i++)boss[i]=i;
    	for(int i=1;i<=ze;i++)
    	{
    		if(F(qr[i][1])!=F(qr[i][2]))un(qr[i][1],qr[i][2]),ans--;
    		printf("%lld\n",pow_2(ans));
    	}
    	for(int i=ze+1;i<=m;i++)printf("0\n");
    }
}
