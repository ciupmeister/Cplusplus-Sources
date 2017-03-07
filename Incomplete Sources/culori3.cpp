/*#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fi("culori3.in");
ofstream fo("culori3.out");

int pre[5][10000], curr[5][10000];
int nrMar[10000],rez[10000];

void AdunNrMari(int x[], int y[])
{
    int i=1, t=0;
    for(; i<=max(x[0], y[0])|| t!=0; i++)
    {
        x[i]+=y[i]+t;
        t=x[i]/10;
        x[i]%=10;
    }
    x[0]=i-1;
}

void FoNrMari(int a[])
{
    for(int i=a[0];i>=1;i--)
        fo<<a[i];
}

void RefreshNrMari(int a[])
{
    int k=a[0];
    for(int i=0;i<=k;i++)
    {
        a[i]=0;
    }
}

int main()
{
    int n;
    fi>>n;
    pre[0][1]=1;
    pre[1][1]=1;
    pre[2][1]=1;
    pre[3][1]=1;
    pre[4][1]=1;
    pre[0][0]=1;
    pre[1][0]=1;
    pre[2][0]=1;
    pre[3][0]=1;
    pre[4][0]=1;

    for(int i=2;i<=n;i++)
    {
        memcpy(curr[0],pre[1],sizeof(pre[1]));

        memcpy(nrMar,pre[0],sizeof(pre[0]));
        AdunNrMari(nrMar,pre[2]);
        memcpy(curr[i],nrMar,sizeof(nrMar));

        memcpy(nrMar,pre[1],sizeof(pre[1]));
        AdunNrMari(nrMar,pre[3]);
        memcpy(curr[2],nrMar,sizeof(nrMar));

        memcpy(nrMar,pre[2],sizeof(pre[2]));
        AdunNrMari(nrMar,pre[4]);
        memcpy(curr[3],nrMar,sizeof(nrMar));

        memcpy(curr[4],pre[3],sizeof(pre[3]));

        memcpy(pre[0],curr[0],sizeof(curr[0]));
        memcpy(pre[1],curr[1],sizeof(curr[0]));
        memcpy(pre[2],curr[2],sizeof(curr[0]));
        memcpy(pre[3],curr[3],sizeof(curr[0]));
        memcpy(pre[4],curr[4],sizeof(curr[0]));
    }


    for(int i=0;i<5;i++)
        AdunNrMari(rez,curr[i]);
    FoNrMari(rez);
} */
///^bulita

#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("culori3.in");
ofstream fo("culori3.out");


int pre[5][10000], curr[5][10000];
int nrMar[10000],rez[10000];

void AdunNrMari(int x[],int y[])
{
    int i=1, t=0;
    for(; i<=max(x[0], y[0])|| t!=0; i++)
    {
        x[i]+=y[i]+t;
        t=x[i]/10;
        x[i]%=10;
    }
    x[0]=i-1;
}
void FoNrMari(int sir[])
{
     for(int i=sir[0];i>=1;i--)
        fo<<sir[i];
}

 void RefreshNrMari(int a[])
{
    int k =a[0];
    int i=-1;
    while(a[i]!= 0 || i<k)a[++i]=0;
}
void MoveNrMari(int x[],int y[])
{
    RefreshNrMari(x);
    for(int i=0; i<=y[0]; i++)
        x[i]=y[i];
}
int main()
{
    int n;
    fi>>n;
    pre[0][1]=1;
    pre[1][1]=1;
    pre[2][1]=1;
    pre[3][1]=1;
    pre[4][1]=1;
    pre[0][0]=1;
    pre[1][0]=1;
    pre[2][0]=1;
    pre[3][0]=1;
    pre[4][0]=1;

    for(int i=2;i<=n;i++)
    {
        MoveNrMari(curr[0],pre[1]);

        MoveNrMari(nrMar,pre[0]);
        AdunNrMari(nrMar,pre[2]);
        MoveNrMari(curr[1],nrMar);

        MoveNrMari(nrMar,pre[1]);
        AdunNrMari(nrMar,pre[3]);
        MoveNrMari(curr[2],nrMar);

        MoveNrMari(nrMar,pre[2]);
        AdunNrMari(nrMar,pre[4]);
        MoveNrMari(curr[3],nrMar);

        MoveNrMari(curr[4],pre[3]);

        MoveNrMari(pre[0],curr[0]);
        MoveNrMari(pre[1],curr[1]);
        MoveNrMari(pre[2],curr[2]);
        MoveNrMari(pre[3],curr[3]);
        MoveNrMari(pre[4],curr[4]);
    }

    for(int i=0;i<5;i++)
        AdunNrMari(rez,curr[i]);

    FoNrMari(rez);
}
