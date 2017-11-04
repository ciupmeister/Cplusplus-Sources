#include <bits/stdc++.h>
#define NMAX 1030
using namespace std;

ifstream fi("alpin.in"); void Input();
ofstream fo("alpin.out"); void Output(int i, int j);
int N;
int fatheri[NMAX][NMAX], fatherj[NMAX][NMAX];
int altitude[NMAX][NMAX], DP[NMAX][NMAX];
int lmax = -1, sourcei, sourcej;
int diri[] = {-1, 0, 1, 0};
int dirj[] = { 0, 1, 0,-1};

bool ok(int i, int j) {return i > 0 && j > 0 && i <= N && j <= N;}

int DFS(int i, int j)
{
    if(!ok(i,j)) return 0;
    if(DP[i][j]) return DP[i][j];

    for(int d = 0; d < 4; ++d)
    {
        int ii = i + diri[d];
        int jj = j + dirj[d];
        if(altitude[ii][jj] > altitude[i][j])
        {
            int k = DFS(ii,jj);
            if(k > DP[i][j])
            {
                DP[i][j] = k;
                fatheri[i][j] = ii; 
                fatherj[i][j] = jj;
            }

        }
    }
    DP[i][j]++;
    return DP[i][j];

}

int main()
{
    Input();
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            int d;
            d = DFS(i,j);
            if(d > lmax)
            {
                lmax = d;
                sourcei = i;
                sourcej = j;
            }
        }
    }
    fo<<lmax<<'\n';
    Output(sourcei,sourcej);
}

void Input()
{
    fi>>N;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            fi>>altitude[i][j];
        }
    }
}

void Output(int i, int j)
{
    if(i == 0 || j == 0) return;
    fo<<i<<' '<<j<<'\n';
    Output(fatheri[i][j], fatherj[i][j]);
}
