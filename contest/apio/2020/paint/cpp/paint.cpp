#include "paint.h"
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
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
bool cpaint[20005],spaint[2005][100005];
int ans[20005],k;
int minimumInstructions(int N, int M, int K, std::vector<int> C,std::vector<int> A, std::vector<std::vector<int>> B)
{
    for(int i=0;i<20005;i++)ans[i]=imx,cpaint[i]=false;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<B[i].size();j++)spaint[i][B[i][j]]=true;
    }
    for(int i=0;i<=N-M;i++)
    {
        bool cc=false;
        for(int st=0;st<M;st++)
        {
            bool p=true;
            for(int j=0;j<M;j++)
            {
                if(!spaint[(st+j)%M][C[i+j]])p=false;
                if(!p)break;
            }
            if(p)
            {
                cc=true;
                break;
            }
        }
        //printf("{%d}",i+M-1);
        cpaint[i+M-1]=cc;
    }
    for(int i=0;i<N;i++)
    {
        k=imx;
        if(!cpaint[i])continue;
        //printf("[%d]",i);
        for(int j=i-M;j<i;j++)
        {
            if(j<0)
            {
                k=0;
                continue;
            }
            k=min(k,ans[j]);
        }
        if(k!=imx)ans[i]=k+1;
    }
    if(ans[N-1]==imx)return -1;
    else return ans[N-1];
}
