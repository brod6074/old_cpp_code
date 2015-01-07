#include "WeightedQuickUF.h"
#include <iostream>
using namespace std;

int main() {
   WeightedQuickUF uf(10);
   uf.dump();
   uf.connect(1, 3);
   uf.connect(9, 2);
   uf.connect(6, 1);
   uf.connect(2, 1);
   cout << endl << endl;
   uf.dump();
}
