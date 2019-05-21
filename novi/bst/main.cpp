#include <iostream>

#include "bin_stablo.h"


int main()
{
    BinarySTree<int> t;


    t.insert(10);
    t.insert(8);
    t.insert(17);
    t.insert(3);
    t.insert(12);
    t.insert(11);
    t.insert(14);
    t.insert(6);
    t.insert(9);


t.remove(17);
    std::vector<int> v;
    t.inOrder([&v](int x){v.push_back(x);});


    for(auto x : v)
        cout<<x<<endl;





    return 0;
}
