#include <iostream>
#include <fstream>
  /// algoritmul asta o luat doar 50 de puncte pe infoarena, deci probabil nu e bun. Pentru o sursa buna vizitati:
  /// https://github.com/rusucosmin/cplusplus/blob/master/Inel/inel.cpp
  /// you wouldn't download a car would you? Implement it by yourself if you want to go to the olympiad. I don't, so...
using namespace std;
ifstream fi("inel.in");
ofstream fo("inel.out");
int n,v[20],raspuns;
bool used[20],ok,prime;

bool Check(int i,int j)
{
    if(i==j)
        return false;

    for(int d=2;d*d<=i+j;d++)
    {
        if((i+j)%d==0)
            return false;
    }
    return true;
}

void permutari(int i=2)
{
    if(i>n)
    {
        ok=true;
        for(int j=1;j<n;j++)
        {
            if(!Check(v[j],v[j+1]))
                ok=false;
        }
        if(ok && Check(v[n],v[1]))
            raspuns++;
        return;
    }

    for(int j=2;j<=n;j++)
    {
        if(used[j]==false)
        {
            used[j]=true;
            v[i]=j;
            permutari(i+1);
            used[j]=false;
        }

    }
}

int main()
{

    fi>>n;
    if (n%2==1) { cout<<"0"; return 0;}
    v[1]=1;
    permutari();
    fo<<raspuns;
}
