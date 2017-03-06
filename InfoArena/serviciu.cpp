#include <iostream>
#include <fstream>
using namespace std;
int mod(int a)
{
    if(a>0) return a;
    else return a*(-1);
}

int main()
{
    ifstream fi("serviciu.in");
    ofstream fo("serviciu.out");
    int n, a, b,maxi=0;
    fi>>n;
    for(int i=1;i<=n;i++)
    {
        fi>>a >>b;
        maxi = max(min(mod(a-b),(n*2-max(a,b))+min(a,b)),maxi);
    }
    fo<<maxi;
}
