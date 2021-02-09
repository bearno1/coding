#include "stations.h"
#include <cstdio>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>
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
static int max_label = 0;
static int r, n, k, q;
static std::vector<int> u, v, labels, answers;
static std::map<int, int> reverse_labels;
static std::vector<std::vector<int>> adjlist;
static int s, t, w;
static std::vector<int> c;

int nn,co[1005];
bitset<1005>go;
vector<int>pa[1005];
void dfs(int N)
{
	go[N]=true;
	co[N]=nn*1000;
	for(int i=0;i<pa[N].size();i++)
	{
		if(!go[pa[N][i]])
		{
			dfs(pa[N][i]);
		}
	}
	co[N]+=nn;
	nn++;
	return;
}
vector<int>label(int n,int k,vector<int>a,vector<int>b)
{
	vector<int>labels(n);
	nn=0;
	for(int i=0;i<1005;i++)pa[i].clear(),go[i]=false;
	for(int i=0;i<a.size();i++)
	{
		pa[a[i]].pb(b[i]);
		pa[b[i]].pb(a[i]);
	}
	dfs(0);
	for(int i=0;i<n;i++)labels[i]=co[i],printf("==%d %d\n",i,co[i]);
	return labels;
}

int find_next_station(int s,int t,vector<int>c)
{
	int ss=s/1000,se=s%1000,ts=t/1000,te=t%1000,cs,ce,re;
	//printf("%d %d %d %d\n",ss,se,ts,te);
	if(ss<=ts&&se>=te)
	{
		for(int i=0;i<c.size();i++)
		{
			cs=c[i]/1000;
			ce=c[i]%1000;
			//printf("{%d %d}\n",cs,ce);
			if(ss<=cs&&se>=ce)
			{
				if(cs<=ts&&ce>=te)re=c[i];
			}
		}
	}
	else
	{
		for(int i=0;i<c.size();i++)
		{
			cs=c[i]/1000;
			ce=c[i]%1000;
			//printf("[%d %d]\n",cs,ce);
			if(cs<=ss&&ce>=se)re=c[i];
		}
	}
	return re;
}

int main() {
	freopen("in.txt","r",stdin);
	assert(scanf("%d", &r) == 1);
	for (int tc = 0; tc < r; tc++) {
		assert(scanf("%d%d", &n, &k) == 2);
		u.resize(n - 1);
		v.resize(n - 1);
		adjlist.clear();
		adjlist.resize(n);
		for (int i = 0; i < n - 1; i++) {
			assert(scanf("%d%d", &u[i], &v[i]) == 2);
			adjlist[u[i]].push_back(v[i]);
			adjlist[v[i]].push_back(u[i]);
		}
		labels = label(n, k, u, v);
		if ((int)labels.size() != n) {
			printf("Number of labels not equal to %d\n", n);
		}
		reverse_labels.clear();
		for (int i = 0; i < n; i++) {
			if (labels[i] < 0 || labels[i] > k) {
				printf("Label not in range 0 to %d\n", k);
			}
			if (reverse_labels.find(labels[i]) != reverse_labels.end()) {
				printf("Labels not unique\n");
			}
			reverse_labels[labels[i]] = i;
			if (labels[i] > max_label) {
				max_label = labels[i];
			}
		}
		assert(scanf("%d", &q) == 1);
		for (int i = 0; i < q; i++) {
			assert(scanf("%d%d%d", &s, &t, &w) == 3);
			c.clear();
			for (int v : adjlist[s]) {
				c.push_back(labels[v]);
			}
			std::sort(c.begin(), c.end());
			int answer = find_next_station(labels[s], labels[t], c);
			if (!std::binary_search(c.begin(), c.end(), answer)) {
				printf("Label %d returned by find_next_station not found in c\n", answer);
			}
			answers.push_back(reverse_labels[answer]);
		}
	}
	printf("%d\n", max_label);
	for (int index : answers) {
		printf("%d\n", index);
	}
}

/*
1
5 100000
0 1
1 2
1 3
2 4
2
2 0 1
1 3 3
*/
