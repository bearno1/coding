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
int t,lla,llb,ll,k,hh[1000];
bool p,sw;
char a[5005],b[5005];
vector<pair<string,int> >v;
int main()
{
    inI(t);
    while(t--)
    {
        p=false;
        scanf("%s",a+1);
        scanf("%s",b+1);
        lla=strlen(a+1);
        llb=strlen(b+1);
        ll=5001;
        v.clear();
        v.push_back({a+1,5});
        v.push_back({b+1,0});
        sort(all(v));
        if(v[1].S==0)p=true;
        if(p)
        {
            printf("%s\n",a+1);
            continue;
        }
        for(int i=1;i<=lla;i++)
        {
            if(p)break;
            for(int j=i+1;j<=lla;j++)
            {
                v.clear();
                swap(a[i],a[j]);
                v.push_back({a+1,5});
                v.push_back({b+1,0});
                sort(all(v));
                if(v[1].S==0)p=true;
                if(p)
                {
                    printf("%s\n",a+1);
                    break;
                }
            }
        }
        if(!p)printf("---\n");
    }
}
