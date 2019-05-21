#include "zadatak.h"
// Ubaciti potrebne include datoteke
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip> //za set precision
#include <numeric>
#include <sstream>

using namespace std;



template<typename T>
void print(T const & t)
{
    for(auto const &x : t)

        cout<<showpos <<setprecision(6)<<scientific<<x<<",";
    cout<<endl;


}

std::vector<int> zadatak1(std::string const & file_name){
  // Implementacija zadatka 1
    ifstream in(file_name);
    if(!in)
            throw runtime_error(" otvaranje datoteke neuspjelo.");

    istream_iterator<int> isi(in); // ovo ce procitat file
        istream_iterator<int> isi_end;



        vector<int> vec(isi, isi_end);

        replace(vec.begin(), vec.end(), 0, 9);



        return vec;


}

void zadatak2(std::string const & file_name){
   // Implementacija zadatka 2
    ifstream in(file_name);
    if(!in)
            throw runtime_error(" otvaranje datoteke neuspjelo.");



    istream_iterator<float> isi(in); // ovo ce procitat file
        istream_iterator<float> isi_end;
           vector<float> vec;
       copy(isi,isi_end,back_inserter(vec));


//print(vec);

        ofstream out("3cols.txt");
        if(!out) throw runtime_error("datoteka za ispis neotvorena.");

        ostream_iterator<float> osi(out,"\n"); //drugi argument sluzi za razmak medu elementima
           // copy(vec.begin(), vec.end(), osi);
int n=vec.size();
for(auto i=0; i<n;++i)
{
    out<<showpos <<setprecision(6)<<scientific<<vec[i]<<" ";
    out<<showpos <<setprecision(6)<<scientific<<sin(vec[i])<<" ";
    out<<showpos <<setprecision(6)<<scientific<<exp(vec[i]);
    out<<endl;
}










}

std::list<int> zadatak3(){
  // Implementacija zadatka 3

    list<int> li{1,2,3,4,5,6,7,8,9};
    list<int> lj{1,2,3,4,5,6,7,8,9};

    while(li.front()!=5 )
            next_permutation(li.begin(),li.end());


    while(lj.front()!=9)
        next_permutation(lj.begin(),lj.end());

    auto it = find(li.begin(),li.end(),3);
    if(it == li.end()) throw runtime_error("Element nije naden.");


    auto itt1 = find(lj.begin(),lj.end(),4);
    auto itt2 = find(lj.begin(),lj.end(),7);

    int p;
    for(auto ittt=lj.begin();ittt!=lj.end();++ittt){
        if(ittt==itt1) {p=1; break;}
        if(ittt==itt2) {p=2; break;}




       }



    if(p==1)
    li.splice(it,lj,itt1,itt2);
    if(p==2)
    li.splice(it,lj,itt2,itt1);


    return li;
    }

























