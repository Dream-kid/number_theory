#  extended euclidean algorithm
void EE(ll a, ll b, ll& x, ll& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    ll temp = x;
    x = y;
    y = temp - y*(a/b);
}
ll inverse(ll a, ll m)
{
    ll x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}
