#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
#define mm make_pair
using namespace std;
ifstream in("ferma3.in");
ofstream out("ferma3.out");
int v,n,m,a[405][405],viz[405][405],parcela,ii,jj,s,smax,i1,j1,i2,j2,sact,parcele[160010],ifin,jfin;
char c[405][405],init,cul,aux;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
queue <pair<int,int> > q,coords;
pair<int,int> fr;
int ok(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=m);
}
int main()
{
    in>>v;
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)in>>c[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(viz[i][j]==0)
            {
                s=1;
                ++parcela;
                viz[i][j]=parcela;
                init=c[i][j];
                q.push(mm(i,j));
                coords.push(mm(i,j));
                while(!q.empty())
                {
                    fr=q.front();
                    q.pop();
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(ok(ii,jj) && viz[ii][jj]==0 && c[ii][jj]==init)
                        {
                            ++s;
                            q.push(mm(ii,jj));
                            coords.push(mm(ii,jj));
                            viz[ii][jj]=parcela;
                        }
                    }
                }
                while(!coords.empty())
                {
                    fr=coords.front();
                    a[fr.x][fr.y]=s;
                    coords.pop();
                }
                smax=max(s,smax);
            }
        }
    }///bine
    if(v==1)out<<smax;
    else
    {
        smax=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                for(int d1=0;d1<4;++d1)
                {
                    i1=i+dx[d1];
                    j1=j+dy[d1];
                    if(c[i1][j1]!=c[i][j] && ok(i1,j1))
                    {
                        aux=c[i1][j1];
                        sact=a[i1][j1]+1;
                        for(int d2=0;d2<4;++d2)
                        {
                            i2=i+dx[d2];
                            j2=j+dy[d2];
                            if(d1!=d2)
                            {
                                if(ok(i2,j2))if(c[i1][j1]==c[i2][j2] && viz[i1][j1]!=viz[i2][j2] && parcele[viz[i2][j2]]==0)
                                {
                                    sact+=a[i2][j2];
                                    coords.push(mm(i2,j2));
                                    parcele[viz[i2][j2]]=1;
                                }
                            }
                        }
                        while(!coords.empty())
                        {
                            fr=coords.front();
                            coords.pop();
                            parcele[viz[fr.x][fr.y]]=0;
                        }
                        if(sact>smax)
                        {
                            smax=sact;
                            cul=aux;
                            ifin=i;
                            jfin=j;
                        }
                    }
                }
            }
        }
        cout<<smax;
        out<<ifin<<" "<<jfin<<'\n'<<cul;
    }
    return 0;
}
