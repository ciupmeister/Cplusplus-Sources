#include <fstream>

using namespace std;
ifstream fi("modulo.in");
ofstream fo("modulo.out");
long long c;
long long putere(long long n,long long pow)
{
    if(pow==0)
        return 1;
    if(pow%2==1)
        return (putere(n, pow-1)*n)%c;
    return ((putere(n,pow/2)%c)*(putere(n,pow/2)%c))%c;
}


int main()
{
    long long a,b;
    fi>>a>>b>>c;
    fo<<putere(a,b);
    fi.close();
    fo.close();
}
