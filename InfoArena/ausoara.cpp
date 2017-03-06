#include <iostream>
#include <fstream>
using namespace std;
ifstream in("mxl.in");
ofstream out("mxl.out");
string s[41][41];
long long n,tabel[41][41],calcul[41][41],x,y,k,nr;
long long calculeaza(int i,int j);
int main()
{
    in>>n>>k;
    for(int  i=1;i<=k;++i)
    {
        in>>x>>y;
        in>>s[x][y];
        tabel[x][y]=1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(tabel[i][j]==1 && calcul[i][j]==0)calculeaza(i,j);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            out<<calcul[i][j]<<" ";
        }
        out<<'\n';
    }
    return 0;
}
long long calculeaza(int i,int j)
{
    if(calcul[i][j]==0)
    {
        long long sem=0,sum=0,nr1=0,nr2=0;
        for(int l=0;l<s[i][j].size();++l)
        {
            if(s[i][j][l]!='=')
            {
                if(isdigit(s[i][j][l]))nr1=nr1*10+(s[i][j][l]-'0');
                else
                {
                    if(s[i][j][l]==':')sem=1;
                    else
                    {
                        if(sem==1)
                        {
                            sum+=calculeaza(nr2,nr1);
                            sem=0;
                        }
                        else sum+=nr1;
                    }
                    nr2=nr1;
                    nr1=0;
                }
            }
        }
        if(sem==1)
        {
            sum+=calculeaza(nr2,nr1);
            sem=0;
        }
        else sum+=nr1;
        calcul[i][j]=sum;
    }
    return calcul[i][j];
}
