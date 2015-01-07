#include "WeightedQuickUF.h"
#include <iostream>
using namespace std;

WeightedQuickUF::WeightedQuickUF(int n) : numComponents(n) {
   parentId = new int[n];
   for (int i = 0; i < n; i++)
      parentId[i] = i;
   
   rootSize = new int[n];
   for(int i = 0; i < n; i++)
      rootSize[i] = 1;
}

WeightedQuickUF::~WeightedQuickUF() {
   delete [] parentId; parentId = nullptr;
   delete [] rootSize; rootSize = nullptr;
}

int   WeightedQuickUF::count() { return numComponents; }

bool  WeightedQuickUF::connected(int p, int q) { return find(p) == find(q); }

int   WeightedQuickUF::find(int p) {
   while (p != parentId[p])
      p = parentId[p];
   return p;
}

void  WeightedQuickUF::connect(int p, int q) {
   int pParent = find(p);
   int qParent = find(q);
   if (pParent == qParent)
      return;
      
   if (rootSize[pParent] < rootSize[qParent]) {
      parentId[pParent] = qParent;
      rootSize[qParent] += rootSize[pParent];
   } else {
      parentId[qParent] = pParent;
      rootSize[pParent] += rootSize[qParent];
   }
   --numComponents;
}

void  WeightedQuickUF::dump() {
   for (int i = 0; i < 10; i++)
      cout << i << ": parent = " << find(i) << endl;
}
