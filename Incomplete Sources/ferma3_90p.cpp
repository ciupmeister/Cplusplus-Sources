#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fi("ferma3.in");
ofstream fo("ferma3.out");

int diri4[] ={-1, 0, 1, 0};
int dirj4[] ={ 0, 1, 0,-1};
char original[405][405];
int n,m;
int x,y;
int nc,co;
int maxx,bigs[405];
char originalColour;
int parceled[405][405], marimi[405][405];
int parcele[16010];
queue<pair<int,int> > hue,coords;
pair<int,int> fr;
bool Check(int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=m);
}
void HuePhil(int x,int y)
{
    int i,j,ii,jj;

    hue.push(make_pair(x,y));
    coords.push(make_pair(x,y));
    parceled[x][y] = nc;
    while(!hue.empty())
    {
        i = hue.front().first;
        j = hue.front().second;
        hue.pop();
        for(int k=0;k<4;k++)
        {
            ii = i + diri4[k];
            jj = j + dirj4[k];
            if(Check(ii,jj) && original[ii][jj] == original[x][y] && parceled[ii][jj] == 0)
            {
                co++;
                parceled[ii][jj] = nc;
                hue.push(make_pair(ii,jj));
                coords.push(make_pair(ii,jj));
            }
        }
    }
    while(!coords.empty())
    {
        fr = coords.front();
        marimi[fr.first][fr.second] = co;
        coords.pop();
    }
}




int main()
{
    int condition;
    fi>>condition;
    fi>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fi>>original[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(parceled[i][j]==0)
            {
                co=1;
                nc++;
                HuePhil(i,j);
                if(co>maxx) maxx = co;
                bigs[nc] = co;
            }
        }
    }

    if(condition==1)
    {
        fo<<maxx;
    }
    else if(condition == 2)
    {
        int newMax=0;
        char culor,cul;
        int ii,jj,i2,j2,ir,jr;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {

                for(int k=0;k<=3;k++)
                {
                    ii = i + diri4[k];
                    jj = j + dirj4[k];
                    int s=0;
                    if(Check(ii,jj) && original[ii][jj] != original[i][j])
                    {
                        cul = original[ii][jj];
                        int s = marimi[ii][jj]+1;
                        for(int q=0;q<=3;q++)
                        {
                            i2 = i+diri4[q];
                            j2 = j+dirj4[q];
                            if(Check(i2,j2) && q != k)
                            {
                                if(original[ii][jj] == original[i2][j2] && parcele[parceled[i2][j2]] == 0 && parceled[ii][jj] != parceled[i2][j2])
                                {
                                    s += marimi[i2][j2];
                                    coords.push(make_pair(i2,j2));
                                    parcele[parceled[i2][j2]]=1;
                                }
                            }
                        }
                        while(!coords.empty())
                        {
                            int g = coords.front().first;
                            int h = coords.front().second;
                            coords.pop();
                            parcele[parceled[g][h]] = 0;
                        }
                        if(newMax<s)
                        {
                            newMax = s;
                            culor = cul;
                            ir = i;
                            jr = j;
                        }
                    }
                }
            }
        }
        cout<<newMax;
        fo<<ir<<" "<<jr<<"\n";
        fo<<culor;
    }



}
