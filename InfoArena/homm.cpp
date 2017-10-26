#include <fstream>
#define NMAX 100
using namespace std;
 
ifstream fi("homm.in");
ofstream fo("homm.out");
 
int N, M, K;
int diri[] = {0,0,-1, 1};
int dirj[] = {-1, 1, 0, 0};
int mat[NMAX][NMAX];
int ways[NMAX][NMAX][NMAX];
int endX, endY, startX, startY;
 
 
int main()
{
    fi>>N>>M>>K;
    for(int i=1; i<=N; ++i)
    {
        for(int j=1; j<=M; ++j)
        {
            fi>>mat[i][j];
        }
    }
    fi>>startX>>startY>>endX>>endY;
 
    for (int i=0; i<=N+1; ++i)
        mat[i][0] = mat[i][M+1] = 1;
 
    for (int i=0; i<=M+1; ++i)
        mat[0][i] = mat[N+1][i] = 1;
 
    ways[startX][startY][0] = 1;
     
    for(int p=1; p<=K; ++p)
    {
        for(int i=1; i<=N; ++i)
        {
            for(int j=1; j<=M; ++j)
            {
                for(int d=0; d<4; ++d)
                {
                    int ii = i + diri[d];
                    int jj = j + dirj[d];
                    if(mat[i][j] == 0)
                        ways[i][j][p] += ways[ii][jj][p-1];
                }
            }
        }
    }
    int rez = 0;
    for(int p=0; p<=K; ++p)
    {
        rez += ways[endX][endY][p];
    }
    fo<<rez;
}
