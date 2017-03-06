#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

ll a[305],b[305];
int main()
{

    a[1]=1;
    b[1]=1;
    ll amax,bmax,sa,sb;
    int n;
    cin>>n;
    cin>>amax>>bmax;

    for(int k=2;k<=n;k++)
    {
        sa=0; sb=0;
        for(ll i=amax;i>=1;i--) sa+=a[i];
        for(ll i =bmax;i>=1;i--) sb+= b[i];
        for(ll i = amax;i>=1;i--) a[i]=a[i-1];
        for(ll i= bmax;i>=1;i--) b[i]=b[i-1];
        a[1] = sb % 1000000007;
        b[1] = sa % 1000000007;
    }
    sa=0; sb=0;
    for(ll i=amax;i>=1;i--) sa+=a[i];
    for(ll i=bmax;i>=1;i--) sb+= b[i];
    cout<<(sa+sb)% 1000000007;

}
