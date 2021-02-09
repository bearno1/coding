#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
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
typedef tree<double, null_type, less<double>, rb_tree_tag,
			tree_order_statistics_node_update>
	new_data_set;
new_data_set s;

int k[300005],x,n;
double co[300005];
vector<int>v[300005];
vector<pair<double,int> >ans;
void dfs(int N)
{
   // printf("[%d %d]",N,s.size());
	if(N==1)s.insert(0);
	else if(k[N]==0)
	{
		co[N]=(*s.begin())-N-12333;
		s.insert(co[N]);
	}
	else if(s.size()==k[N])
	{
		co[N]=(*s.find_by_order(k[N]))+N+9977;
		s.insert(co[N]);
	}
	else
	{
		co[N]=(*s.find_by_order(k[N]-1)+*s.find_by_order(k[N]))/2;
		//printf("+%d %d %lf %lf+\n",N,k[N],*s.find_by_order(k[N]),*s.find_by_order(k[N]+1));
		s.insert(co[N]);
	}
	for(int i=0;i<v[N].size();i++)
	{
		dfs(v[N][i]);
	}
	s.erase(s.find(co[N]));
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
	}
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		v[x].pb(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		//printf("{%d %lf}\n",i,co[i]);
		ans.pb({co[i],i});
	}
	sort(all(ans));
	for(int i=n-1;i>-1;i--)printf("%d ",ans[i].S);
}
