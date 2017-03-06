#include <iostream>
#include <fstream> // initialize with infinit
#include <queue>      // check n,n
#include <utility>
#define DMAX 105
#define x first
#define y second
#define infinit 2000009
using namespace std;
typedef short int si;

si  mat_cartof[DMAX][DMAX], n;
int dist[DMAX][DMAX];

bool check(si i, si j)
{
    return (i>=1 && i<=n && j>=1 && j<=n);
}

void init()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            dist[i][j]=infinit;
    }
}


void solve()
{
    si di[]={-1, 0, 1, 0};
    si dj[]={ 0,-1, 0, 1};
    si i,j;
    queue < pair<si, si> > q;
    dist[1][1]=mat_cartof[1][1];
    pair<si,si> curent;
    q.push(make_pair(1, 1));

    while(!q.empty())
    {
        curent=q.front();

        for(int d=0; d<4; d++)
        {
            i=curent.x+di[d];
            j=curent.y+dj[d];

            if(check(i,j) && dist[curent.x][curent.y]+mat_cartof[i][j]< dist[i][j])
            {
                q.push(make_pair(i, j));
                dist[i][j]=dist[curent.x][curent.y]+mat_cartof[i][j];

            }

        }
        q.pop();
    }

}



int main()
{
    ifstream fi("taxe2.in");
    ofstream fo("taxe2.out");
    int S;
    fi>>S>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            fi>>mat_cartof[i][j];
        }
    }

    init();
    solve();
    if(S-dist[n][n]<0)
        fo<<-1;
    else
        fo<<S-dist[n][n];


}
