#include <bits/stdc++.h>
#define NMAX 58

std::ifstream fi("suma4.in");
std::ofstream fo("suma4.out");
int n,k;
int piramid[NMAX][NMAX][NMAX];
int cost[NMAX][NMAX][NMAX];

void input()
{   int x;
    fi>>n;
    for(int i=1; i<=n; ++i)
    {
        while(n>0)
        {
            k++;
            for(int j=1; j<=k; ++j)
            {
                for(int c=1; c<=k; ++c)
                {
                    fi>>x;
                    cost[k][j][c]=x;
                    piramid[k][j][c]=x;
                }
            }
            n=n-k*k;
        }
    }

    fo<<k<<' ';
}
void suma()
{
    int x;
    for(int i=k-1; i; i--)
    {
        for(int j=1; j<=i; ++j)
        {
            for(int l=1; l<=i; ++l)
            {
                if( cost[i+1][j][l] <= cost[i+1][j][l+1] )
                    x=cost[i+1][j][l];
                else
                    x=cost[i+1][j][l+1];

                if(x > cost[i+1][j+1][l])
                    x=cost[i+1][j+1][l];

                if(x > cost[i+1][j+1][l+1])
                    x=cost[i+1][j+1][l+1];

                cost[i][j][l]=cost[i][j][l]+x;
            }
        }
    }
    fo<<cost[1][1][1]<<'\n';
}
void drum()
{
    int l=1, j=1, i=1, nr=0, s=cost[1][1][1];
    fo<<'1';
    do
    {   nr= nr + i*i;
        s = s-piramid[i][j][l];
        i++;
        if(s)
        {
            if(cost[i][j][l] != s)
            {
                if(cost[i][j][l+1] == s)
                    l++;
                else if(s==cost[i][j+1][l])
                    j++;
                else
                    j++, l++;
            }
            fo<<' '<< nr + (j-1) * i + l;
        }
    }
    while(s);
}

int main()
{
    input();
    suma();
    drum();
}
