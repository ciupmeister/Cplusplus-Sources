#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("date.in");  ///incomplete
ofstream fo("date.out");

long long Multiplic(long long a, long long b, long long c)
{
    if(b==1)
        return a%c;
    long long aux=Multiplic(a,b/2,c);
    if(b%2==0)
    {
        return (aux+aux)%c
    }
    return((a+aux)%c+aux)%c;
}


long long RidicPut(long long a,long long b, long long c)
{
    if(b==1)
        return a%c;
    long long aux=RidicPut(a,b/2,c);
    long long aux2=Multiplic(aux,aux,c);

    if(b%2==0)
        return aux2;

    return Multiplic(aux2,a,c);

}


int main()
{
    long long a,b,c;
    fi>>a>>b>>c;
    cout<<RidicPut(a,b,c);
}
