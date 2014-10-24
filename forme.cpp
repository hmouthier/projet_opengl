#include "forme.h"
#include "point.h"
#include "QList"

forme::forme(QList<point> mylist )
{
    _mylist=mylist;
}
point forme::getPoint(int i){
   if(i<_mylist.size()&&i>=0)
   return _mylist[i];
   else
       return point(-9999,-9999);

}
int forme::tailleForme(){
    return _mylist.size();
}
