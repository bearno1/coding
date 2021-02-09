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
int main()
{
    freopen("in.txt","w",stdout);
    printf("%d %d\n",200,10);
    for(int i=1;i<=200;i++)printf("%d ",abs((((i*174922)%12314)*225523)%20000));
}
