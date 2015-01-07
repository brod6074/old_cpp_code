#ifndef   WEIGHTED_QUICK_UF_H
#define  WEIGHTED_QUICK_UF_H

class WeightedQuickUF {
public:
         WeightedQuickUF(int n);
         ~WeightedQuickUF();
   int   count();
   bool  connected(int p, int q);
   int   find  (int p);
   void  connect(int p, int q);
   void  dump();

private:
   int*  parentId;
   int*  rootSize;
   int   numComponents;

};

#endif