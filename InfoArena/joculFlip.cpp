#include <iostream>
#include <fstream>
using namespace std;
int n,m,v[20][20],sPartAux[20];
int s,sMax,sPart[20],a=0;
ifstream fi("flip.in");
ofstream fo("flip.out");

int main()
{
    fi>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            fi>>v[i][j];
            sPartAux[i]+=v[i][j];
        }

    }


    for(a=0; a <(1<<m); ++a)
    {
        s=0;
        for(int i=0;i<n;++i)
            sPart[i]=sPartAux[i];

        for(int j=0;j<m;++j)
        {
            if(a & 1<<j)
            {
                for(int i=0;i<n;++i)
                {
                    sPart[i]-= v[i][m-j-1]*2;
                }
            }
        }

        for(int i=0;i<n;++i)
        {
            s+= max(sPart[i],-sPart[i]);
        }

        sMax = max(sMax, s);
    }
    fo<<sMax;
    fi.close();
    fo.close();
}


