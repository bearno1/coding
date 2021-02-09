//#include "colorblind.h"
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define all(x) ((x).begin(),(x).end())
#define F first
#define S second
typedef long long LL;
typedef pair<int,int> pii;

int NUMBER_OF_MONKEYS, NUMBER_OF_CALLS;

int use_device(int a, int b) {

	if(a < 0 || NUMBER_OF_MONKEYS <= a || b < 0 || NUMBER_OF_MONKEYS <= b) {
		printf("Wrong Answer: illegal call\n");
		exit(0);
	}

	if(a == b) {
		printf("Wrong Answer: illegal call\n");
		exit(0);
	}

	NUMBER_OF_CALLS++;

	printf("Swap %d and %d: ",a,b);
	int res; scanf("%d", &res);
	return res;
}
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
int main() {

	//////////// run multiple tests ////////////

	int T; scanf("%d",&T);

	while(T--) {

		//////////////// get input ////////////////

		int N; std::string S;
		std::cin >> N >> S;

		NUMBER_OF_MONKEYS = 2 * N;

		////////////////// solve //////////////////

		NUMBER_OF_CALLS = 0;
		std::string ret = investivate_colors(N);

		if(ret != S) {
			printf("%s\n",ret);
			printf("Wrong Answer: incorrect\n");
			exit(0);
		}

		printf("Accepted: %d\n",NUMBER_OF_CALLS);
	}

	return 0;
}
