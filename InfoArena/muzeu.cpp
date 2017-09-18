#include <iostream>
#include <fstream>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

int n, mat[255][255];

int diri[] = {-1, 0, 1, 0};
int dirj[] = { 0, 1, 0,-1};

queue<pair<int,int> > q;

bool checkBounds(int i, int j) {return i>0 && j>0 && i<=n && j<=n;}

void input()
{
    ifstream fi("muzeu.in");
    fi>>n;
    for(int i =1; i<=n; ++i)
    {
        for(int j=1; j<=n;++j)
        {
            char c;
            fi>>c;
            if(c == '#')
                mat[i][j] = -2;
            else if(c == 'P')
            {
                q.push(make_pair(i,j));
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = INF;
            }
        }
    }
    fi.close();
}
void output()
{
    ofstream fo("muzeu.out");
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            mat[i][j] == INF? fo<<"-1" : fo<<mat[i][j];
            fo<<" ";
        }
        fo<<"\n";
    }
    fo.close();
}

int main()
{
    input();
    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int d=0; d<4; ++d)
        {
            int ii = i + diri[d];
            int jj = j + dirj[d];
            if(checkBounds(ii,jj))
            {
                if( mat[i][j] +1 < mat[ii][jj] && mat[ii][jj] != -2)
                {
                    q.push(make_pair(ii,jj));
                    mat[ii][jj] = mat[i][j]+1;
                }
            }
        }
    }
    output();

}
