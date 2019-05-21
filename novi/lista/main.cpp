#include "lista.h"


int main()
{
// Ovdje pišete vlastite testove klase.
    List<int> l;
    l.push_back(20);
l.push_back(29);
l.push_back(23);

l.push_back(4); l.insert(2,2);
    l.insert(3,9);
    l.insert(2,6);
    l.insert(0,3);

        l.insert(0,19);
        l.insert(1,5);

    l.insert(0,6);
    l.insert(1, 10);
    l.insert(0, 7);

    l.remove(0);
    l.remove(4);
    l.remove(2);


    for(int i=0;i<l.size();++i){
        l.setPosition(i);
cout<<l.current()<<endl;}

cout<<endl<<endl;

    l.sort();

    for(int i=0;i<l.size();++i){
        l.setPosition(i);
cout<<l.current()<<endl;
   }
    l.clear();
    for(int i=0;i<l.size();++i){
        l.setPosition(i);
cout<<l.current()<<endl;
   }
  return 0;
}
 
