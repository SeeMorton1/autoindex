//
// Created by Conner Morton on 9/17/2020.
//

#ifndef INC_20F_AUTO_IDX_DSSTRING_H
#define INC_20F_AUTO_IDX_DSSTRING_H
#include <iostream>
#include <bits/unique_ptr.h>
#include "DSVector.h"
class DSString {
    char* myStr = nullptr;
    unsigned length;
public:
    DSString();
    ~DSString();
    DSString(const DSString& source);
    DSString(const char* val);
    DSString(char c);

    friend std::istream& operator>>(std::istream& so, DSString& s);
    friend std::ostream& operator<<(std::ostream& os, DSString& s);

    DSString& operator+=(const DSString& s);
    DSString& operator+=(const char* c);
    DSString& operator+=(char c);
    DSString& operator =(const DSString& s);
    friend bool operator<(const DSString& LS, const DSString& RS);
    friend bool operator==(const DSString& LS, const DSString& RS);
    friend bool operator==(const DSString& LS,const char& RS);
    char* pop();
    char* excludePhrase();
    unsigned getBracketCount();
    void append(char c);
    void replaceSpace() const;
    void extractPage();
    char* removeArrows(const DSString& s);
    //friend bool operator> (const DSString& LS, const DSString& RS);
    char operator[] (unsigned i) const;
    char& operator[] (unsigned i);
    char* getcStr() const;
    DSString removeBrackets();
    unsigned getLength()const;
    unsigned getIndex(char getInd) const;
    DSVector<DSString> getIWord();
    DSString removeSpaces();
    DSString delim(unsigned st, unsigned num);
    void reverse(unsigned begin, unsigned end);
    void simplify();
    int stringToInt();
    DSString cleanupBrackets();
    void replacePeriod()const;
    void toLower()const;
    void toUpper()const;
};


#endif //INC_20F_AUTO_IDX_DSSTRING_H
