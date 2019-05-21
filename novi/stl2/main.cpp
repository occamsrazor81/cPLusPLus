#include <iostream>
#include "zadatak.h"

using namespace std;

int main()
{
    const string a("Ovo je jako dosadno, i uzima mi puno vremena.");

    auto it = a.begin();
   //const auto itend=a.end();
    string s = procitaj_rijec(it, a.end());
    cout<<s<<endl;
    string l = procitaj_rijec(it, a.end());
    cout<<l<<endl;

    map<string,int> m;
    procitaj_datoteku("1.txt",m);
    for(auto x : m)
        cout<<x.first<<"->"<<x.second<<endl;

    pair<list<string>,int> par=naj(m);
    cout<<"par"<<endl;
    for(auto x: par.first)
    cout<<x<<"<<<<"<<par.second<<endl;




    multimap<string, string> grupe;
    grupe.insert(make_pair("Grupa1", "b"));
    grupe.insert(make_pair("Grupa1", "a"));

    grupe.insert(make_pair("Grupa2", "tt"));
    grupe.insert(make_pair("Grupa2", "e"));

    map<string,int>  word_list;
    procitaj_datoteku("5.txt", word_list);

    for(auto e : grupe)
        cout<<e.first<<" "<<e.second<<endl;
    for(auto e : word_list)
            cout<<e.first<<" "<<e.second<<endl;

    vector<int> broj;
    broj = broj_iz_grupe(word_list, grupe);

    for(auto q : broj)
        cout<<q<<endl;
    return 0;
}
