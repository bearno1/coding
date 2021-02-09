#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
char c[200005];
int len;
vector<int>v[30];
int main()
{
    scanf("%s",c+1);
    len=strlen(c+1);
    for(int i=1;i<=len;i++)
    {
        v[c[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<v[i].size();j++)
        {
            if(v[i][j]-v[i][j-1]<3)
            {
                printf("%d %d",v[i][j-1],v[i][j]);
                return 0;
            }
        }
    }
    printf("-1 -1");
}
