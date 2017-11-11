//http://www.lightoj.com/volume_showproblem.php?problem=1007
#include <list>
 
#include <set>
#include <map>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <limits>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <bitset>
#include <numeric>
#include <cassert>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
 
#define sf scanf
#define pf printf
#define pi 2*acos(0.0)
#define ull unsigned long long
#define all(v) v.begin(),v.end()
 
#define sii(t) scanf("%d",&t)
#define sll(t) scanf("%lld",&t)
#define sll(t) scanf("%lld",&t)
#define ssll(a,b) scanf("%lld%lld",&a,&b)
#define ssd(a,b) scanf("%lf%lf",&a,&b)
#define sssll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define ssslf(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define ssssll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define Case(no) printf("Case %lld: ",++no)
#define nl puts("")
#define pll(a) printf("%lld\n",a)
#define P(a) printf("%d ",a)
#define PLL(a) printf("%lld ",a)
 
 
#define ff first
#define pb push_back
#define mp make_pair
#define se second
#define pb push_back
#define ST(v) sort(all(v))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define cover(a,d) memset(a,d,sizeof(a))
#define popcount(i) __builtin_popcount(i)                       //count one
#define output freopen("out.txt","w",stdout)
#define input freopen("in.txt","r",stdin)
#define un(v) ST(v), (v).earse(unique(all(v)),v.end())
#define common(a,b) ST(a), ST(b), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b) ST(a), ST(b), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
#define flop(m,n,q)             for(ll i=m;i<=n;i+=q)
////============ CONSTANT ===============////
#define mx  (100010)
#define inf 5000100
#define eps 1e-4
#define mod1 10000000000
typedef unsigned long long ll;
 
////=====================================////
ll arr[5000010];
bool visited[5000010];
void prime_generator()
{
    for(ll i=3; i*i<=inf; i+=2)
    {
 
        for(ll j=i*i; j<=inf; j+=2*i)
        {
            visited[j]=1;
        }
    }
}
 
int main()
{
    // input;
    //  output;
    prime_generator();
    ll a,b;
    long long t=0;
    for(ll i=2; i<=5000000; i++)
        arr[i]=i;
    for(ll j=2; j<=5000000; j+=2)
    {
        arr[j]*=(2-1);
        arr[j]/=2;
    }
    for(ll i=3; i<=5000000; i+=2)
    {
        if(!visited[i])
        {
            for(ll j=i; j<=5000000; j+=i)
            {
                arr[j]*=(i-1);
                arr[j]/=i;
            }
 
        }
    }
    for(ll j=2; j<=5000000; j++)
    {
        arr[j]*=arr[j];
        arr[j]+=arr[j-1];
    }
    sll(a);
    while(a--)
    {
        ll c,d;
        sf("%llu%llu",&c,&d);
        Case(t);
        c=arr[d]-arr[c-1];
        pf("%llu\n",c);
    }
}
 
