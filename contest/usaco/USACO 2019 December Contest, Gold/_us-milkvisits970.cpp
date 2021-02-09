#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
using namespace std;
int t,n,high,m,x,st,rr,q,a,b,aa,bb;
vector<int>pa[100005];
bitset<100005>go;
struct node
{
	int lv,boss,skip,slv,num;
	vector<int>V;
}tree[100005];
struct seq
{
    int val=0;
    seq *l=NULL,*r=NULL;
}ver[100005];
void build_seq(seq *N,int st,int ed)
{
    int mid=(st+ed)/2;
    if(st==ed)
    {
        if(st==tree[1].num);
        N->val++;
        return;
    }
    seq *nn=new seq;
    N->l=nn;
    build_seq(nn,st,mid);
    nn=new seq;
    N->r=nn;
    build_seq(nn,mid+1,ed);
    return;
}
void update_seq(seq *N,seq *P,int pos,int st,int ed)
{
    int mid=(st+ed)/2;
    if(st==ed)
    {
        N->val=P->val+1;
        return;
    }
    if(pos<=mid)
    {
        N->r=P->r;
        seq *nn=new seq;
        N->l=nn;
        update_seq(nn,P->l,pos,st,mid);
        N->val=N->l->val+N->r->val;
    }
    else
    {
        N->l=P->l;
        seq *nn=new seq;
        N->r=nn;
        update_seq(nn,P->r,pos,mid+1,ed);
        N->val=N->l->val+N->r->val;
    }
    return;
}
int sum_seq(seq *N,int a,int b,int st,int ed)
{
    int mid=(st+ed)/2;
    if(st>b||ed<a)return 0;
    if(st>=a&&ed<=b)return N->val;
    return sum_seq(N->l,a,b,st,mid)+sum_seq(N->r,a,b,mid+1,ed);
}
void hh(int pos,int ll)
{
    printf("%d\n",pos);
	go[pos]=true;
	tree[pos].lv=ll;
	for(int i=0;i<pa[pos].size();i++)
	{
		if(!go[pa[pos][i]])
		{
            tree[pa[pos][i]].boss=pos;
            tree[pos].V.push_back(pa[pos][i]);
			hh(pa[pos][i],ll+1);
		}
	}
	return;
}
void gen(int pos,int ll,int sp,int s)
{
	tree[pos].skip=sp;
	tree[pos].slv=s;
	if(ll%rr==1)sp=pos,s=ll;
	for(int i=0;i<tree[pos].V.size();i++)
	{
        //printf("%d ",tree[pos].V[i]);
        update_seq(&ver[tree[pos].V[i]],&ver[pos],tree[tree[pos].V[i]].num,1,100000);
		gen(tree[pos].V[i],ll+1,sp,s);
	}
	return;
}
int main()
{
    freopen("8.in","r",stdin);
    freopen("milkvisits.txt","w",stdout);
	high=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
        scanf("%d",&tree[i].num);
		tree[i].lv=0,tree[i].boss=i,tree[i].skip=0,tree[i].slv=0;
	}
    tree[1].boss=0;
    tree[0].num=0;
    build_seq(&ver[0],1,100000);
    build_seq(&ver[1],1,100000);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		pa[a].push_back(b);
		pa[b].push_back(a);
	}
	hh(1,1);
	for(int i=1;i<=n;i++)high=max(high,tree[i].lv);
	rr=(int)sqrt(high);
	gen(1,1,1,1);
    // for(int i=1;i<=n;i++)
    // {
    //     printf("[%d %d %d]\n",i,sum_seq(&ver[i],1,1,1,100000),sum_seq(&ver[i],2,2,1,100000));
    // }
    // printf("=============\n");
	while(m--)
	{
		scanf("%d %d %d",&aa,&bb,&x);
		a=aa;
		b=bb;
		if(tree[a].slv!=tree[b].slv)
		{
			while(tree[a].slv>tree[b].slv+rr)
			{
				a=tree[a].skip;
			}
			while(tree[a].slv+rr<tree[b].slv)
			{
				b=tree[b].skip;
			}
		}
        //printf("{%d %d}\n",a,b);
		while(tree[a].lv>tree[b].lv)
		{
			a=tree[a].boss;
		}
		while(tree[a].lv<tree[b].lv)
		{
			b=tree[b].boss;
		}
        //printf("{%d %d}\n",a,b);
		while(tree[a].skip!=tree[b].skip)
		{
			a=tree[a].skip;
			b=tree[b].skip;
		}
		while(a!=b)
		{
			a=tree[a].boss;
			b=tree[b].boss;
		}
        a=tree[a].boss;
        if(sum_seq(&ver[aa],x,x,1,100000)+sum_seq(&ver[bb],x,x,1,100000)-(sum_seq(&ver[a],x,x,1,100000)*2)>0)printf("1");
        else printf("0");
	}
}
/*
5 8
1 1 2 1 2
1 2
2 3
2 4
1 5
1 4 1
1 4 2
1 3 2
1 3 1
5 5 1
1 1 1
2 2 1
3 3 1
*/
