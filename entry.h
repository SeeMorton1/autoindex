//
// Created by Conner Morton on 10/1/2020.
//

#ifndef INC_20F_AUTO_IDX_ENTRY_H
#define INC_20F_AUTO_IDX_ENTRY_H
#include "DSString.h"
#include "DSVector.h"
#include "LinkedList.h"
#include <set>
class entry {
    DSString term;
    std::set<int> pageNumbers;
    //LinkedList<entry> child;



public:
    entry();
    entry(const DSString& copyTerm,int pageNum, const entry& aChild);
    entry(const DSString& copyTerm, int pageNum);
    entry(const DSString& copyTerm,const std::set<int>& pages);
    entry(const DSString& copyTerm);
    ~entry();
    entry(const entry& copy);
    void addChild(const entry& copy);

    void insertPage(int pageNum);
    void setTerm(const DSString& s);
    std::set<int> setPageSet(const std::set<int>& copy);
    std::set<int> getPageNumbers();
    DSString getTerm();
    //entry& operator=(const entry& e);
    friend bool operator<(const entry& LS, const entry& RS);
    friend bool operator==(const entry& LS,const entry& RS);
    friend bool operator!=(const entry& LS, const entry& RS);

};


#endif //INC_20F_AUTO_IDX_ENTRY_H
