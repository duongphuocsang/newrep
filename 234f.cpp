#include<bits/stdc++.h>
using namespace std;
const int N=203;
const int M=4e4+3;
long long n,a,b,h[N];
long long f[N][M],g[N][M],res=1e18;
long long sum=0;
void mo()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
void nhap()
{
    long long res=1e9;
    cin>>n>>a>>b;
    for (long long i=1;i<=n;++i)
    {
        cin>>h[i];
    }
    //s[0]=0;s[1]=h[1];
    for (long long i=1;i<=n;++i)
    {
        sum+=h[i];
    }
    /*for (long long i=1;i<=n;++i)
    {
        for (long long j=0;j<=a;++j)
        {
            for (long long k=0;k<=1;++k)
            {
                dp[i][j][t]=1e9;
            }
        }
    }*/
    memset(f,20,sizeof f);
    memset(g,20,sizeof g);
    f[1][h[1]]=0;
    g[1][0]=0;
    for (long long i=1;i<=n;++i)
    {
        for (long long j=h[i];j<=a;++j)
        {
            f[i][j]=f[i-1][j - h[i]];
			f[i][j]=min(f[i][j],g[i-1][j-h[i]]+min(h[i],h[i-1]));
        }
        for (long long j=0;j<=b;++j)
        {
            g[i][j]=g[i-1][j];
			g[i][j]=min(g[i][j],f[i-1][j]+min(h[i],h[i-1]));
        }
    }
}
void xuat()
{
    for(int j=0;j<=a;++j)
    {
        if (j+b>=sum)
        {
            res=min({res,f[n][j],g[n][j]});
        }
	}
	if(res<=sum )
    {
        cout<<res;
    }
	else cout<<-1;
}
int main()
{
    //mo();
    nhap();
    xuat();
}
