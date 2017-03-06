#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("vila.in");
ofstream fo("vila.out");
int nr, vmax=0, v[6000], nc=0;
int a[120][120];
int x, y;
FILE *f;

void Fill()
{
    if (a[x][y] != -1)
        return;
    nr++;
    a[x][y]=nc;
    x++;Fill();x--;
    x--;Fill();x++;
    y++;Fill();y--;
    y--;Fill();y++;
}

int Suma(int i, int j)
{
    int s = 0;
    s += v[a[i-1][j]];
    if (a[i+1][j] != a[i-1][j])
        s += v[a[i+1][j]];
    if ( (a[i][j-1] != a[i-1][j]) && (a[i][j-1] != a[i+1][j]) )
        s += v[a[i][j-1]];
    if ( (a[i][j+1] != a[i-1][j]) && (a[i][j+1] != a[i+1][j]) && (a[i][j+1] != a[i][j-1]) )
        s += v[a[i][j+1]];
    s++;
    return s;
}

int main()
{
    int i, j, n, m;
    char ch;

    fi>>n>>m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            fi>>ch;
            if (ch == '1')
                a[i][j] = 0;
            else
                a[i][j] = -1;
        }
    }
    v[0] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i][j] == -1)
            {
                nc++;
                nr = 0;
                x = i;
                y = j;
                Fill();
                if (nr > vmax)
                    vmax = nr;
                v[nc] = nr;
            }
    fo<<nc<<"\n";
    fo<<vmax<<"\n";
    vmax = 0;
    int sx, sy;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i][j] == 0)
                if (Suma(i, j) > vmax)
                {
                    vmax = Suma(i, j);
                    sx = i;
                    sy = j;
                }
    fo<<sx<<" "<<sy<<" "<<vmax;
}



