//http://lightoj.com/volume_showproblem.php?problem=1109
#include<bits/stdc++.h>
using namespace std;
#define inf 1010
typedef long long ll;
ll visited[inf+10];
void prime_generator()
{
    for(ll i=3; i*i<=inf; i+=2)
    {

        for(ll j=i*i; j<=inf; j+=2*i)
        {
            visited[j]=1;
        }
    }
    visited[0]=2;
    ll j=1;
    for(ll i=3; i<=inf; i+=2)
    {
        if(visited[i]==0)
        {
            visited[j]=i;
            j++;
        }
    }
}
vector<pair<ll,ll> >v;
void count_divisor()
{
    v.push_back(make_pair(1,-1));

    for(ll i=2; i<=1000; i++)
    {
        ll sum=1;
        ll p=i;
        for(ll j=0; visited[j]<=p&&p!=1; j++)
        {
            if(p%visited[j]==0)
            {
                ll count=0;
                while(p%visited[j]==0)
                {
                    count++;
                    p/=visited[j];
                }
                sum*=(count+1);
            }
        }
        v.push_back(make_pair(sum,-i));
    }
    sort(v.begin(),v.end());
}
int main()
{
    prime_generator();
    count_divisor();
    ll a,b,t=1;
    scanf("%lld",&a);
    while(a--)
    {
        scanf("%lld",&b);
        printf("Case %lld: ",t++);
        cout<<-1*v[b-1].second<<endl;
    }
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

