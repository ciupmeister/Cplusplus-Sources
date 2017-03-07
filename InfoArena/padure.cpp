#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
ifstream fi("padure.in");
ofstream fo("padure.out");
int diri4[] ={-1, 0, 1, 0};
int dirj4[] ={ 0, 1, 0,-1};
int INF = 0x3f3f3f3f;
int n,m;
int padure[1005][1005];
int overLayer[1005][1005];
int pl,pc,cl,cc;
void Initialize()
{
    fi>>n>>m>>pl>>pc>>cl>>cc;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;j++)
            fi>>padure[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;j++)
            overLayer[i][j] = INF;
    }
}

int Lee(int x,int y)
{
    deque<pair<int,int> > dehue;
    dehue.push_back(make_pair(x,y));
    overLayer[x][y] = 0;
    int i,j,ii,jj;
    while(!dehue.empty())
    {
        i = dehue.front().first;
        j = dehue.front().second;
        dehue.pop_front();

        for(int k=0;k<4;k++)
        {
            ii = i + diri4[k];
            jj = j + dirj4[k];

            if(padure[i][j] == padure[ii][jj] && overLayer[i][j]<overLayer[ii][jj])
            {
                overLayer[ii][jj] = overLayer[i][j];
                dehue.push_front(make_pair(ii,jj));
            }
            else if(padure[i][j] != padure[ii][jj] && overLayer[i][j]+1<overLayer[ii][jj])
            {
                overLayer[ii][jj] = overLayer[i][j]+1;
                dehue.push_back(make_pair(ii,jj));
            }
        }
    }
}
int main()
{
    Initialize();
    Lee(pl,pc);
    fo<<overLayer[cl][cc];
}
