#include<iostream>//boj 1178 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn =10100;
const int maxv =10100;
int a[maxn],sa[maxn],container[maxn],wy[maxn],wv[maxn],wx[maxv],rk[maxn],h[maxn];

int cmp(int *r,int a,int b,int l)
{
	return (r[a]==r[b])	&&(r[a+l]==r[b+l]);
}
void suffix(int *r, int n,int *sa,int m)
{
	int i,j,*t,*x=wx,*y=wy,p;
	memset(container,0,sizeof(int)*m);
	for(i=0; i<n; i++)	container[x[i]=r[i]]++;
	for(i=1; i<m; i++)	container[i]+=container[i-1];
	for(i=n-1; i>=0; i--)	sa[--container[x[i]]]=i;
	for(p=0,j=1; p<n; j<<=1, m=p)
	{
		for(p=0,i=n-j; i<n; i++)	y[p++]=i;
		for(i=0; i<n; i++)	if(sa[i]>=j)	y[p++]=sa[i]-j;
		for(i=0; i<n; i++)	wv[i]=x[y[i]];
		memset(container,0,sizeof(int)*m);
		for(i=0; i<n; i++)	container[wv[i]]++;
		for(i=1; i<m; i++)	container[i]+=container[i-1];
		for(i=n-1;i>=0; i--)	sa[--container[wv[i]]]=y[i];
		for(t=x,x=y,y=t,x[sa[0]]=0,p=1,i=1;i<n; i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}

void cal(int *r,int *sa,int n)
{
	int i,j,k=0;
	for(i=1; i<=n; i++)	rk[sa[i]]=i;
	for(i=0; i<n; h[rk[i++]]=k)
		for(k?k--:0,j=sa[rk[i]-1]; r[i+k]==r[j+k]; k++);
}

char ch[10000];
int main()
{
	//freopen("in","r",stdin);
	//freopen("std","w",stdout);
	int i,j,k;
	int n,m;
	scanf("%d", &k);
	scanf("%s",ch);
	int len=strlen(ch);
	for(i=0,j=len; i<len; i++,j++)
		ch[j]=ch[i];
	ch[j]=0;
	n=len*2;
	for(i=0; i<n;i++)
	{
		a[i]=ch[i];	
	}
	for(i=0; i<len; i++)
	{
		int tp=a[i+k];
		a[i+k]=0;
		suffix(&a[i],k+1,sa,300);
		cal(&a[i],sa,k);
		int ans=0;
		for(j=1; j<=k; j++)
			ans+=h[j];
		ans=k*(k+1)/2-ans;
		cout<<ans;
		if(i==len-1)
			puts("");
		else
			printf(" ");
		a[i+k]=tp;
	}
}
