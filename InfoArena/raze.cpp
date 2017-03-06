#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fi("raze.in");
ofstream fo("raze.out");
int mat[140][140];
bool check(int i,int j,int n,int m)
{
    return (i>1&&j>1&&i<n&&j<m);
}

int main()
{
    int di[]={-1, -1, +1, +1};
    int dj[]={+1, -1, +1, -1};
    int n,m,t,i2,j2;
    fi>>t;
    for(;t--;)
    {
    fi>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fi>>mat[i][j];
            if(mat[i][j]==1) mat[i][j]=5;
        }
    }

    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
        {
            if(mat[i][j]==5)
            {
                for(int d=0;d<4;d++)
                {
                    for( i2=i+di[d],j2=j+dj[d];check(i2,j2,n,m);i2+=di[d],j2+=dj[d])
                    {
                        if(mat[i2][j2]!=5)
                            mat[i2][j2]++;
                        else break;
                    }

                }
            }
        }
    }

    int apar=0,minn=5;
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
        {
            if(mat[i][j]<minn)
            {
                minn=mat[i][j];
                apar=1;

            }
            else if(mat[i][j]==minn)
            {
                apar++;
            }


        }
    }

    fo<<4-minn<<" "<<apar<<"\n";
    }
}
