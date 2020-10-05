//
// Created by Conner Morton on 10/1/2020.
//

#include "entry.h"
entry::entry() {
    term = "";
    //child = ;
}
entry::entry(const entry &copy) {
    term = copy.term;
    pageNumbers = copy.pageNumbers;
    //child = copy.child;
}
entry::~entry()= default;
entry::entry(const DSString& copyTerm, int pageNum, const entry& aChild){
    term = copyTerm;
    pageNumbers.insert(pageNum);
    //child.pushback(aChild);
}
entry::entry(const DSString &copyTerm, int pageNum) {
    term = copyTerm;
    pageNumbers.insert(pageNum);
}

void entry::setTerm(const DSString &s) {
    term = s;
}
void entry::insertPage(int pageNum){
    pageNumbers.insert(pageNum);
}

void entry::addChild(const entry& copy) {
    //child.pushback(copy);
}
std::set<int> entry::getPageNumbers(){
    return pageNumbers;
}
DSString entry::getTerm() {
    return term;
}


bool operator<(const entry &LS, const entry &RS) {
    if(LS.term==RS.term){
        for(int pg:LS.pageNumbers){
            for(int pg1:RS.pageNumbers){
                return pg>pg1;
            }
        }
    }
    return !(LS.term<RS.term);
}

bool operator==(const entry &LS, const entry &RS) {
    if((LS.term==RS.term)&&(LS.pageNumbers.size()==RS.pageNumbers.size()))return true;
}

std::set<int> entry::setPageSet(const std::set<int>& copy) {
    std::set<int> newSet;
    for(int n:pageNumbers){
        newSet.insert(n);
    }

    for(int c:copy){
        newSet.insert(c);
    }
    return newSet;
}

bool operator!=(const entry &LS, const entry &RS) {
    return(!(LS==RS));
}

entry::entry(const DSString &copyTerm, const std::set<int>& pages) {
    term = copyTerm;
    for(int c:pages){
        pageNumbers.insert(c);
    }
}

entry::entry(const DSString &copyTerm) {
    term = copyTerm;
}


/*entry &entry::operator=(const entry &e) {
    term = e.term;
    for(int aPg:e.pageNumbers){
        pageNumbers.insert(aPg);
    }
    for(const auto& c:e.child){
        child.pushback(c);
    }
}*/



