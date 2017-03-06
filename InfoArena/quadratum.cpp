#include <iostream>
#include <fstream>
#include <cstring>
#define DMAX 40
using namespace std;
ofstream fo("quadratum.out");
void adun(int x[], int y[])
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

void transfo (int v[], long long n)
{
    int i=0;
    while(n)
    {
        v[++i]=n%10;
        n/=10;
    }
    v[0]=i;
}

void afissir (int sir[])
{
    for(int i=1; i<=sir[0]; i++)
        cout<<sir[i];
    cout<<"\n";
}

void afissirInv(int sir[])
{
    for(int i=sir[0];i>=1;i--)
        fo<<sir[i];
    fo<<"\n";


}

void multiply_scalar(int x[], int y)
{
    int i=1, t=0;
    for(; i<=x[0] || t!=0; i++)
    {
        x[i]=(x[i]*y)+t;
        t=x[i]/10;
        x[i]%=10;
    }
    x[0]=i-1;
}

void copy_arrey(int x[], int y[])
{
    for(int i=0; i<=y[0]; i++)
        x[i]=y[i];
}

void putin(int x[], int zero)
{
    for(int i=x[0]; i>0; i--)
    {
        x[i+zero]=x[i];
    }
    for(int i=1;i<=zero;i++)
        x[i]=0;
    x[0]+=zero;

}
void multiply_AUTHENIC(int x[], int y[])
{
    int rez_part[DMAX]={0};
    int x_aux[DMAX]={0};

    for(int i=1; i<=y[0]; i++)
    {
    memset (x_aux, 0, sizeof (x_aux));
        copy_arrey(x_aux, x);
        multiply_scalar(x_aux, y[i]);
        putin(x_aux, i-1);
        adun(rez_part, x_aux);
    }
    copy_arrey(x, rez_part);
}




int main()
{
    ifstream fi("quadratum.in");

    long long n;
    long long n1, n2, n3;
    int vn1[DMAX]={0}, vn2[DMAX]={0}, vn3[DMAX]={0};

    int t;
    fi>>t;
    for(;t--;)
    {
        memset(vn1, 0, sizeof(vn1));
        memset(vn2, 0, sizeof(vn2));
        memset(vn3, 0, sizeof(vn3));
        fi>>n;
        n1=n;
        n2=n+1;
        n3=2*n+1;
        if(n1%3==0)
            n1/=3;
        else if(n2%3==0)
            n2/=3;
        else n3/=3;
        if(n1%2==0) n1/=2;
        else if(n2%2==0) n2/=2;
        else  n3/=2;
        transfo(vn1, n1);
        transfo(vn2, n2);
        transfo(vn3, n3);
        multiply_AUTHENIC(vn1, vn2);
        multiply_AUTHENIC(vn1, vn3);
        afissirInv(vn1);




    }
}
