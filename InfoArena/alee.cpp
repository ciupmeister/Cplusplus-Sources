#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n;
bool copac[180][180];
int distanta[180][180];
pair<int,int> start,finish;
queue< pair<int,int> > stiva;
int INF = 0x3f3f3f3f;

int diri[] = {-1, 0, 1,  0};
int dirj[] = { 0, 1, 0, -1};

void input()
{
    ifstream fi("alee.in");
    int t;
    fi>>n>>t;
    int a,b;
    for(int i=1;i<=t;i++)
    {

        fi>>a>>b;
        copac[a][b]=1;
    }
    fi>>a>>b;
    start = make_pair(a,b);
    fi>>a>>b;
    finish = make_pair(a,b);
    fi.close();
}
void output()
{
    ofstream fo("alee.out");
    fo<<distanta[finish.first][finish.second];

}
void Lee();
bool check(int i,int j)
{
    return (i>=1 && i<=n && j>=1 && j<=n && copac[i][j] ==0);
}
int main()
{
    input();
    Lee();
    output();
}


void Lee()
{

    stiva.push(start);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            distanta[i][j]=INF;
    }
    distanta[start.first][start.second] = 1;
    while(!stiva.empty())
    {
        int i,j;
        i = stiva.front().first;
        j = stiva.front().second;
        stiva.pop();
        for(int d=0;d<4;d++)
        {
            int ii, jj;
            ii = i + diri[d];
            jj = j + dirj[d];
            if(check(ii,jj))
            {
                if(distanta[i][j]+1 < distanta[ii][jj])
                {
                    distanta[ii][jj] = distanta[i][j]+1;
                    stiva.push(make_pair(ii,jj));
                }

            }

        }
    }

}
