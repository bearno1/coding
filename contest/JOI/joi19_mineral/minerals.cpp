#include "minerals.h"
#include<bits/stdc++.h>
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
int ls,tp,isin[86005];
vector<int>a,b;

void find_ans(vector<int>A,vector<int>B)
{
    int si=A.size(),ch,re;
    vector<int>na1,nb1,na2,nb2;
    if(A.size()==1)
    {
        Answer(A[0],B[0]);
        return;
    }
    for(int i=0;i<si/2;i++)
    {
        if(isin[B[i]]==0)
        {
            ch=Query(B[i]);
            isin[B[i]]=(isin[B[i]]+1)%2;
        }
        nb1.pb(B[i]);
    }
    for(int i=(si/2);i<si;i++)
    {
        if(isin[B[i]]==1)
        {
            ch=Query(B[i]);
            isin[B[i]]=(isin[B[i]]+1)%2;
        }
        nb2.pb(B[i]);
    }
    for(int i=0;i<si;i++)
    {
        if(na1.size()==nb1.size())
		{
			na2.pb(A[i]);
		}
		else if(na2.size()==nb2.size())
		{
			na1.pb(A[i]);
		}
		else
		{
			re=Query(A[i]);
			//printf("[%d %d]\n",re,ch);
	        isin[A[i]]=(isin[A[i]]+1)%2;
	        if(ch!=re)
	        {
	            na2.pb(A[i]);
	        }
	        else
	        {
	            na1.pb(A[i]);
	        }
			ch=re;
		}
    }
    find_ans(na1,nb1);
    find_ans(na2,nb2);
    return;
}

void Solve(int N)
{
    for(int i=1;i<=2*N;i++)
    {
        tp=Query(i);
        isin[i]=(isin[i]+1)%2;
        if(tp!=ls)
        {
            a.pb(i);
        }
        else
        {
            b.pb(i);
        }
        ls=tp;
    }
    find_ans(a,b);
    return;
}
