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
int ans[100005],k,col[100005],st;
bool cpaint[100005];
deque<pii>dq;
int minimumInstructions(int N, int M, int K, std::vector<int> C,std::vector<int> A, std::vector<std::vector<int>> B)
{
    for(int i=0;i<N;i++)ans[i]=imx;
    for(int i=0;i<M;i++)
    {
        //printf("%d\n",i);
        //if(B[i].size()>1)return -1;
        for(int j=0;j<B[i].size();j++)
        {
            col[B[i][j]]=i;
            //printf("=%d=",B[i][j]);
        }
        //printf("\n");
    }
    // for(int i=0;i<N;i++)printf("%d ",col[i]);
    // printf("\n");
    for(int i=0;i<N;i++)
    {
        if(i==0)st=1;
        else if((col[C[i-1]]+1)%M==col[C[i]])
        {
            st++;
        }
        else st=1;
        if(st>=M)cpaint[i]=true;
    }
    dq.pb({0,-1});
    for(int i=0;i<N;i++)
    {
        if(!dq.empty())if(dq.front().S<i-M)dq.pop_front();
        if(!cpaint[i])continue;
        if(!dq.empty())
        {
            if(dq.front().F!=imx)
            {
                ans[i]=dq.front().F+1;
                //printf("[%d %d]\n",ans[i],i);
                //printf("[%d %d]\n",dq.front().S,i);
            }
        }
        if(!dq.empty())
        {
            while(dq.back().F>ans[i])
            {
                dq.pop_back();
                if(dq.empty())break;
            }
            dq.pb({ans[i],i});
        }
    }
    if(ans[N-1]==imx)return -1;
    else return ans[N-1];
}
