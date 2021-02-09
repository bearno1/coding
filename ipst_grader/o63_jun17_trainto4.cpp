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
int n,k,pos[355],si[355],ss[355],val[355],ans,sw,nw,cc,a,b,o;
vector<int>v;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        v.pb(-val[i]);
        si[1]++;
        ss[1]+=val[i];
        pos[i]=1;
    }
    sort(all(v));
    for(int i=0;i<n;i++)
    {
        val[i+1]=-v[i];
    }
    ans=ss[1]*(si[1]-1);
    //printf("%d\n",ans);
    for(int t=1;t<355;t++)
    {
        for(int i=1;i<=n;i++)
        {
            nw=ans,sw=pos[i];
            if(pos[i]%2==0)o=pos[i]-1;
            else o=pos[i]+1;
            for(int j=1;j<=2*k;j++)
            {
                cc=ans;
                cc-=ss[pos[i]]*(si[pos[i]]-1);
                //printf("=%d %d %d=",ss[pos[i]],si[pos[i]],cc);
                a=si[pos[i]]-1;
                b=ss[pos[i]]-val[i];
                cc+=max(0,a-1)*b;
                //printf("+%d+",cc);
                cc-=ss[j]*(max(si[j]-1,0));
                a=si[j]+1;
                b=ss[j]+val[i];
                cc+=(a-1)*b;
                //printf("-%d %d-",j,cc);
                //printf("{%d %d %d}",i,j,cc);
                if(j==o)
                {
                    if(pos[i]%2==0)cc-=si[pos[i]-1]*2;
                    else cc-=si[pos[i]+1]*2;
                    //printf("+%d+",cc);
                    if(j%2==0)cc+=(si[j-1]-1)*2;
                    else cc+=(si[j+1]-1)*2;
                }
                else
                {
                    if(pos[i]%2==0)cc-=si[pos[i]-1]*2;
                    else cc-=si[pos[i]+1]*2;
                    //printf("+%d+",cc);
                    if(j%2==0)cc+=si[j-1]*2;
                    else cc+=si[j+1]*2;
                }
                //printf("[%d]",cc);
                if(cc<nw)nw=cc,sw=j;
            }
            ans=nw;
            si[pos[i]]--;
            ss[pos[i]]-=val[i];
            si[sw]++;
            ss[sw]+=val[i];
            pos[i]=sw;
            // printf("[%d]",ans);
            // for(int i=1;i<=n;i++)printf("%d ",pos[i]);
            // printf("\n");
        }
    }
    //for(int i=1;i<=n;i++)printf("%d ",pos[i]);
    printf("%d",ans);
}
