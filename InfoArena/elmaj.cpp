#include <bits/stdc++.h>

using namespace std;
ifstream fi("elmaj.in");
ofstream fo("elmaj.out");
int a[1000005];

int main()
{
    int k = 0, n;
    int curr, nr=0;
    fi>>n;
    for(int i = 1; i <= n; ++i)
        fi>>a[i];
    for(int i = 1; i <= n; ++i)
    {
        if(k == 0)
        {
            curr = a[i];
            k = 1;
        }
        else if( a[i] == curr)
            ++k;
        else
            --k;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] == curr)
            nr++;
    }
    fo<<curr<<" "<<nr;
}
