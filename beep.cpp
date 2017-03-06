#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream fi("beep.in");
ofstream fo("beep.out");
///splituim sirul pe cuvinte
/*
    Folosim getline()

    splituim un sir. avem delimitatori =".,|-!?" .
    actual //cuvant actual
    parcurgem sirul din fisier si copiem caracter cu caracter pana dam de un delimitator
    string v[100]; //punem stringu pana la intalnirea primului caracter delimitator in pozitia corespunzatoare in v
    actual="";
    v[0] ="ana";
    v[1] ="are";
    v[2] ="mere";
*/

///calculam cat de lung e sirul (memorywise)
/*
    s.size() bytes
*/
/// cautam un string intr-un string
//if(s.find("ana")!=s.end()) fo<<<gasit

const string delim=" ,.!?|-";

inline bool find(string s,char c)
{
    for(int i=0;i<s.size();++i)
        if(s[i] == c)
            return 1;
    return 0;
}

int main()
{
    string cuvantInterzis,cuv,line;
    string v[1000];
    int cnt=0;
    getline(fi,cuvantInterzis);
    while(getline(fi,line))///pune linia din fisierul fi in stringul line
    {
        fo<<line;
        for(int i=1;i<=line.size();++i)
           {
               if(find(delim,line[i]))
               {
                   if( cuv=="") continue;
                   string x;
                   x.push_back(line[i]);
                   if(delim.find(x))
                   {
                       v[++cnt]=cuv;
                       cuv="";
                   }
               }
               else
               {
                   cuv.push_back(linie[i]);
               }

           }
    }

    ///uita-te pe grup pt problema completa. :(

   /* while(fi>>cititor)
    {
        if(cuvantInterzis==cititor)
            fo<<"beep"<<" ";
        else
            fo<<cititor<<" ";

    } */
}
