#include <stdio.h>
#include "stdlib.h"
#include "Person.h"
#include "Person.c"
#include "Table2.h"
#include "Table2.c"
#include "TableDLinkedList.h"
#include "TableDLinkedList.c"



int MyHashFunc(int k) {
    return k%100;
}

int main(void) {
    Table myTbl;
    Person *np;
    Person *sp;
    Person *rp;

    TBLInit(&myTbl, MyHashFunc);

    np = MakePersonData(900254, "LEE", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);
    np = MakePersonData(900139, "KIM", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);
    np = MakePersonData(900827, "HAN", "Gangwon");
    TBLInsert(&myTbl, GetSSN(np), np);

    sp = TBLSearch(&myTbl, 900254);
    if(sp != NULL) ShowPerInfo(sp);
    sp = TBLSearch(&myTbl, 900139);
    if(sp != NULL) ShowPerInfo(sp);
    sp = TBLSearch(&myTbl, 900827);
    if(sp != NULL) ShowPerInfo(sp);

    rp = TBLDelete(&myTbl, 900254);
    if(rp != NULL) free(rp);
    rp = TBLDelete(&myTbl, 900139);
    if(rp != NULL) free(rp);
    rp = TBLDelete(&myTbl, 900827);
    if(rp != NULL) free(rp);

    return 0;
}