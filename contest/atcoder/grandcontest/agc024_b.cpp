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
int n,x,pos[200005],ans,k;
int main()
{
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++)scanf("%d",&x),pos[x]=i;
    for(int i=1;i<=n;i++)
    {
        if(pos[i]<pos[i-1])k=1;
        else k++;
        ans=min(ans,n-k);
    }
    printf("%d",ans);
}
