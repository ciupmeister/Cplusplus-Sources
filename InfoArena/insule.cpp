#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
#define DMAX 105
using namespace std;

const short int infinit = (1 << 15) - 1;

short int n, m, mat_dist[DMAX][DMAX];
char mat_ori[DMAX][DMAX];

pair<short int,short int> start[DMAX*DMAX];

bool mat_viz[DMAX][DMAX];

bool check(int i, int j)
{
    if(i>=1 && i<=n && j>=1 && j<=m)
        return true;
    else
        return false;
}


void start_BFS(int i, int j)
{
    queue < pair<short int, short int> > hue;
    hue.push(make_pair(i, j));
    mat_viz[i][j]=1;
    int di[]={-1, 0, +1,  0};
    int dj[]={ 0,+1,  0, -1};

    while(!hue.empty())
    {

        for(int k=0; k<4; k++)
        {

            i=hue.front().first+di[k];
            j=hue.front().second+dj[k];
            if(check(i, j) && mat_viz[i][j]==0 && mat_ori[i][j]==1)
            {
                mat_viz[i][j]=1;
                hue.push(make_pair(i, j));
            }
        }
        hue.pop();

    }
}

void start_DFS(int i, int j, int regat)
{
    mat_viz[i][j]=1;
    int di[]={-1, 0, +1,  0};
    int dj[]={ 0,+1,  0, -1};
    for(int d=0; d<4; d++)
    {
        int ii=i+di[d];
        int jj=j+dj[d];
        if(check(ii, jj) && mat_viz[ii][jj]==0 && mat_ori[ii][jj]==regat)
        {
            mat_viz[ii][jj]=1;
            start_DFS(ii, jj, regat);
        }
    }
}

bool check_pod(pair<short int, short int> k)
{
    if(k.first<1 || k.first>n || k.second<1 || k.second>m)
        return 0;
    if(mat_ori[k.first][k.second]!=0)
        return 0;

    return 1;
}
bool look_around(int i, int j, int k)
{
    int di[]={-1, +0, +1, -0};
    int dj[]={-0, +1, +0, -1};
    for(int e=0; e<4; e++)
    {
        if(mat_ori[i+di[e]][j+dj[e]]==k && check(i+di[e],j+dj[e]))
            return 1;
    }
    return 0;
}
void refresh_dist()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mat_dist[i][j]=infinit;
        }
    }
}

void solve(int cont)
{

    int di[]={-1, +0, +1, -0};
    int dj[]={-0, +1, +0, -1};
    queue< pair<short int, short int> > q;
    pair<short int, short int> curent;
    for(int i=1;i<=cont;i++)
    {
        mat_dist[start[i].first][start[i].second]=0;
        q.push(start[i]);
    }
    while(!q.empty())
    {

        for(int d=0; d<4; d++)
        {
              curent.first=q.front().first+di[d];
              curent.second=q.front().second+dj[d];

              if(check_pod(curent) && mat_dist[curent.first][curent.second]>mat_dist[q.front().first][q.front().second]+1)
              {
                  q.push(curent);
                  mat_dist[curent.first][curent.second]=mat_dist[q.front().first][q.front().second]+1;
              }
        }
        q.pop();
    }
}


int main()
{
    ifstream fi("insule.in");
    ofstream fo("insule.out");

    int nr_insul[4]={0};
    char c;

    fi>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fi>>c;
            mat_ori[i][j]=c-'0';

        }
    }



    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(mat_ori[i][j]!=0 && mat_viz[i][j]==0)
            {

                start_DFS(i, j, mat_ori[i][j]);
                nr_insul[mat_ori[i][j]]++;
            }

        }
    }

    int lungime_pod=infinit,cont=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(look_around(i,j,1) && mat_ori[i][j]==0)
            {
                start[++cont].first=i;
                start[cont].second=j;
            }
        }
    }
    refresh_dist();
    solve(cont);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(look_around(i,j,2) && mat_ori[i][j]==0)
            {
                if(mat_dist[i][j]<lungime_pod)
                    lungime_pod=mat_dist[i][j];
            }
        }
    }

    fo<<nr_insul[1]<<" "<<nr_insul[2]<<" "<<nr_insul[3]<<" "<<lungime_pod+1;


}
