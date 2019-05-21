#include "zadatak.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <fstream>
// Ubaciti potrebne include datoteke

using namespace std;
// Zadan je raspon iteratora unutar stringa. Pročitati i vratiti prvu riječ iz stringa.
// Postaviti iterator it na prvu interpunkciju/bjelinu iza pročitane riječi ili na itend
// (end-iterator) ako takve nema.
// Riječi su cjeline međusobno odvojene bjelinama i/ili interpunkcijama: ,.!?:;()
// Bjeline su  \n\t\v.
std::string procitaj_rijec(std::string::const_iterator & it, std::string::const_iterator itend)
{
    // implementacija

    string s;
    while(( isspace(*it) || ispunct(*it)) && it!=itend )
    {
        it++;

    }
    for(auto itt=it;;++itt)
    {

        if(isspace(*itt) || ispunct(*itt) || itt==itend)
        {

            copy(it,itt,back_inserter(s));

        if(itt!=itend) itt++;

            it=itt;
           break;

        }


    }

    return s;

}

// Otvoriti datoteku file_name za čitanje, učitati tekst (npr. liniju po liniju)
// i smjestiti riječi u mapu. Riječ je ključ, a vrijednost je broj pnavljanja riječi.
// Riječ se učitava pomoću rutine ucitaj_rijec.


void procitaj_datoteku(std::string file_name, std::map<std::string,int> & word_list){
  // implementacija
    ifstream dat(file_name);
       if(!dat) throw runtime_error("Datoteka nije otvorena. \n");


       string s;

       while(getline(dat,s))
       {


           const string ja=s;
           auto ii=ja.begin();
            auto predzadnji=ja.end(); predzadnji--;
while(ii!=ja.end()){
           string rijec=procitaj_rijec(ii,ja.end());

           auto iterator=word_list.find(rijec);

           if(iterator!=word_list.end())
               (iterator->second)++;
           else
             if(!rijec.empty()) word_list.insert(make_pair(rijec,1));
       }}

}

// Vrati listu riječi koje se najčešće pojavljuju u mapi (std::list) i broj ponavljanja (int).
std::pair<std::list<std::string>, int> naj(std::map<std::string,int> const & word_list){
  // implementacija
    int max=-1;
   list<string> s;
   pair<list<string>,int> pp;
    for(auto it : word_list)
     if(it.second>max) max=it.second;

    for(auto itt : word_list)
    if(itt.second==max) s.push_back(itt.first);

   pp=make_pair(s,max);

return pp;

}

// Argument grupe sadrži grupe riječi (ključ je ime grupe, a vrijednosti
// su riječi koje pripadaju grupi).
// Funkcija treba za svaku grupu riječi sumirati broj pojavljivanja svih riječi
// iz grupe u tekstu te vratiti vrijednosti u vektoru. Na i-tom mjestu u povratnom vektoru
// je broj pojavljivanja riječi iz i-te grupe (prema uređaju u multimap varijabli).
// Argument word_list je std::map svih riječi s brojem njihovih pojavljivanja.


std::vector<int>
broj_iz_grupe(std::map<std::string,int> const & word_list,
              std::multimap<std::string, std::string> const & grupe){

    list<string> l;
    for(auto it=grupe.begin();it!=grupe.end();++it){
        int br=0;
        for(auto il=l.begin();il!=l.end();++il)
            if(it->first==*il) ++br;
        if(br==0) l.push_back(it->first);
    }
    vector<int> v (l.size());
    int br=0;
    for(auto il=l.begin();il!=l.end();++il){
        for(auto it=grupe.begin();it!=grupe.end();++it){

            if(*il==it->first){
                auto im=word_list.begin();
                for(;im!=word_list.end();++im)
                    if(it->second==im->first)break;
                int b=br;
                auto iv=v.begin();
                while(b){
                    iv++;
                    --b;
                }
                *(iv)=*(iv)+im->second;
            }

          }
        br++;
        }

    return v;
}







