LCM from 1 to n LightOJ - 1289
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned int
#define ll1 unsigned int
#define inf 1000000010000

#define mx 100000000
ll arr[5761456];
ll dp[5761456];
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int status[(mx/32)+2];
inline ll1 big_mod ( ll1 a, ll1 p )
{
    ll1 res = 1, x = a ;
    while (p)
    {
        if (p & 1)
            res = (res * x);
        x = (x * x) ;
        p >>= 1;
    }
    return res;
}
void sieve()
{
    int i, j, sqrtN;
    int N=mx;
    sqrtN = int( sqrt( N ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( Check(status[i>>5],i&31)==0)
        {
            for( j = i*i; j <= N; j += (i<<1) )
            {
                status[j>>5]=Set(status[j>>5],j & 31)   ;
            }
        }
    }
    arr[0]=2;
    ll k=0;
    ll1 res=2;
    dp[0]=2;
    for(i=3; i<=N; i+=2)
    {
        if( Check(status[i>>5],i&31)==0)
        {
            res*=i;

            dp[++k]=res;
            arr[k]=i;
        }
    }
}
int main()
{

    sieve();
    ll ts;
    scanf("%u",&ts);
    for(ll t=1; t<=ts; t++)
    {
        ll val;
        scanf("%u",&val);
        ll1 ans=1;
        for(ll i=0; arr[i]*arr[i]<=val; i++)
        {
            ll temp=val;
            ll cnt=0;
            while(temp>=arr[i])
            {
                temp/=arr[i];
                cnt++;
            }
            cnt--;
            ans*=big_mod(arr[i],cnt);

        }
        ll pos=upper_bound(arr,arr+5761455,val)-arr;
        ans*=dp[pos-1];

        printf("Case %u: %u\n",t,ans);
    }
}
