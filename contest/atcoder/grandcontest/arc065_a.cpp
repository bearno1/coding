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
int n;
char c[100005];
string k[4];
bitset<100005>uu;
int main()
{
    scanf("%s",c+1);
    n=strlen(c+1);
    k[0]="dream";
    k[1]="dreamer";
    k[2]="erase";
    k[3]="eraser";
    uu[0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        {
            int tp=k[j].size();
            if(tp>i)continue;
            bool p=true;
            for(int cur=0;cur<tp;cur++)
            {
                if(c[i-(tp-1-cur)]!=k[j][cur])p=false;
            }
            if(p&&uu[i-tp])uu[i]=true;
        }
    }
    if(uu[n])printf("YES");
    else printf("NO");
}
