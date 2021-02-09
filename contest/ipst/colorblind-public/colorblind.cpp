#include<bits/stdc++.h>
#include "colorblind.h"
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define all(x) ((x).begin(),(x).end())
#define F first
#define S second
typedef long long LL;
typedef pair<int,int> pii;
std::string investivate_colors(int N) {
	int nn=N*2,k=use_device(0,1),cc=1;
	char ans[520];
	for(int i=0;i<nn;i++)ans[i]='R';
	ans[nn]='\0';
	if(N==1)return "RB";
	if(N==2)
	{
		cc=0;
		for(int i=nn-1;i>1;i--)
		{
			if(use_device(0,i)!=k&&cc<N)
			{
				cc++;
				ans[i]='B';
			}
		}
		if(cc<N)ans[1]='B',cc++;
	}
	else
	{
		if(N%2==1)
		{
			int o=N/2;
			for(int i=nn-1;i>1;i--)
			{
				if(use_device(0,i)!=k)cc=max(cc,i);
			}
			if(k==(o*o)+((o+1)*(o+1))&&(k==use_device(nn-1,cc-N+1)))cc++;
			for(int i=cc;i>cc-N;i--)
			{
				ans[i]='B';
			}
		}
		else
		{
			for(int i=nn-1;i>1;i--)
			{
				if(use_device(0,i)!=k)cc=max(cc,i);
			}
			for(int i=cc;i>cc-N;i--)
			{
				ans[i]='B';
			}
		}
	}
	// for(int i=nn-1;i>1;i--)
	// {
	// 	if(use_device(0,i)!=k&&cc<N)
	// 	{
	// 		cc++;
	// 		ans[i]='B';
	// 	}
	// }
	// if(cc<N)ans[1]='B',cc++;
	//printf("%s\n",ans);
	return &ans[0];
}
// int main()
// {
//
// }
