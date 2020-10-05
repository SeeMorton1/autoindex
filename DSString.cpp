//
// Created by Conner Morton on 9/17/2020.
//

#include "DSString.h"
#include "DSVector.h"
#include <cstring>
#include <sstream>

// TODO: Check the CSString to make sure it is optimized completely.
DSString::DSString(){
    length =0;
    myStr = new char[1];
    myStr[0]='\0';
}
DSString::DSString (const DSString& s)
{
    length = s.getLength();
    myStr   = new char[length+1];
    for (unsigned j=0; j < length; j++){
        myStr[j] = s[j];
    }
    myStr[length]='\0';
}
DSString::DSString(char c){
    length = 1;
    myStr = new char(c);
}
DSString::~DSString(){
    delete[] myStr;
}
DSString::DSString(const char* val){
    if(val){
        unsigned c = 0;
        while(val[c]!='\0')c++; //Find length of the char array
        length= c;
        myStr = new char[length];
        for(unsigned i =0;i<c;i++){
            myStr[i]=val[i];
        }
    }else{
        length = 0;
        myStr = new char[0];

    }
}
bool operator==(const DSString& LS, const char& RS){
    return (LS==DSString(RS));
}
std::ostream &operator<<(std::ostream &os, DSString &s) {
    if(s.getLength()>0){
        for(unsigned i = 0; i <s.getLength();i++){
            os<<s[i];
        }
    }else{
        os<<"";
    }

    return os;
}
std::istream& operator>> (std::istream& is, DSString& s)
{
    char* c = new char[1024];
    is >> c;
    s = DSString(c);
    delete[] c;

    return is;
}

DSString& DSString::operator+= (const DSString& s){
    unsigned len = length+s.getLength();
    char* str=new char[len];
    for(unsigned i = 0;i<length;i++){
        str[i]=myStr[i];

    }
    for(unsigned j = 0;j<s.length;j++){
        str[length+j]=s[j];
    }
    delete myStr;
    length = len;
    myStr= str;
    return *this;

}
DSString& DSString::operator+=(char c){
    length = length+1;
    myStr+=c;

    return *this;
}
bool operator<(const DSString &LS, const DSString &RS) {
    return strcmp(LS.getcStr(),RS.getcStr())>0;
}
DSString& DSString::operator+=(const char *c) {
    unsigned l =0;
    while(c[l] !='\0'){
        l++;
    }
    unsigned len =length+l;//new length of new DSString
    char* str = new char[len];
    for(unsigned i = 0;i<getLength();i++) {
        str[i] = myStr[i];
    }
    for(unsigned j = 0; j<l;j++){
        str[length+j]=c[j];
    }
    delete myStr;
    length = len;
    myStr = str;
    return *this;
}
DSString& DSString::operator=(const DSString& s){
    if(this == &s){
        return *this;
    }
    delete myStr;
    length = s.getLength();
    myStr = new char[length+1];
    for(unsigned i = 0;i<length;i++){
        myStr[i]=s[i];
    }
    myStr[length]= '\0';
    return *this;
}
bool operator==(const DSString &LS, const DSString& RS) {
    if(LS.getLength()!=RS.getLength())return false;
    unsigned len = LS.getLength();
    unsigned n = 0;
    while((n<len)&&(LS[n]==RS[n]))n++;
    return(n==len);
}
unsigned DSString::getLength() const{
    return length;
}
char& DSString::operator[](unsigned i){
    return myStr[(i > (length - 1) ? (length - 1) : i)];

}
char DSString::operator[] (unsigned j) const
{

    return myStr[(j > (length - 1) ? (length - 1) : j)];
}


DSString DSString::delim(unsigned begin, unsigned end){
    std::unique_ptr<char[]> substr(new char[end +1]);//https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/
    for(unsigned i = 0;i<end;i++){
        substr[i]=myStr[i+begin];
    }
    substr[end] = '\0';
    return substr.get();


}
DSString DSString::removeSpaces() {
    unsigned c;
    for(unsigned i = 0;i<length;i++){
        if(myStr[i] == ' ')c++;
    }
    unsigned len = length-c;
    char *cs = new char[len];
    for(unsigned i =0;i<length;i++){
        if(myStr[i]!=' '){
            cs[i] = myStr[i];
        }
    }
    return DSString(cs);
}
unsigned DSString::getIndex(char toFind) const {
    for(unsigned i =0;i<getLength();i++){
        if(myStr[i] == toFind){
            return i;
        }
    }
    return 0;
}
char* DSString:: getcStr() const{
    return myStr;
}
void DSString::reverse(unsigned begin, unsigned end){
    if(begin==end||length<2||end>(length-1)||begin>(length-1))return;
    while(begin<end){
        char t = myStr[begin];
        myStr[begin]=myStr[end];
        myStr[end] = t;
        ++begin,--end;
    }

}
void DSString::simplify() {
    //First lowercase everything by checking if the value is in A-Z and then if it is, change it to lowercase by increasing the difference of any letter
    //For example, it could also be ('z'-'Z') and it would still yield the result.


    for(unsigned i = 0;i<length;i++){
        if(myStr[i] =='.'||myStr[i] ==','||myStr[i]=='?'||myStr[i]=='/'||myStr[i]==';'||myStr[i]==':'||myStr[i]=='('||myStr[i]==')'||myStr[i]=='-'||myStr[i]=='|'||myStr[i] =='_'||myStr[i]=='['
           ||myStr[i]==']'||myStr[i]=='{'||myStr[i]=='}'||myStr[i]=='='||myStr[i]=='+'||myStr[i]=='!'||myStr[i] =='"'||myStr[i] =='<'||myStr[i] =='>'){
            myStr[i] = ' ';

        }

        if('A'<=myStr[i]&&myStr[i] <='Z') {
            myStr[i] += ('a' - 'A');

        }
    }


}
char* DSString::pop(){
    char *c = new char[length-1];
    for(unsigned i = 0;i<length-1;i++){
        c[i] = myStr[i];
    }
    return c;
}
unsigned DSString::getBracketCount(){
    unsigned bracketCount;
    for(unsigned i = 0;i<length;i++){
        if(myStr[i]=='['){
            bracketCount++;
        }
    }
    return bracketCount-1;
}
char* DSString::excludePhrase(){
    unsigned bracketCount = getBracketCount();

    unsigned len = getLength()-bracketCount;

    char* c = new char[len];
    unsigned right = getIndex(']');
    unsigned left = getIndex('[');
    for(unsigned i = 0;i<left;i++){
        c[i] = myStr[i];
    }
    for(unsigned i = right;i<getLength();i++){
        c[i] = myStr[i];
    }
    return c;
}
void DSString::append(char c){
    length++;
    myStr[length] = c;
}
void DSString::replaceSpace() const {
    char*c = new char [getLength()];
    for(unsigned i = 0;i<getLength();i++){
        c[i] = myStr[i];
    }
    for(unsigned i  =0 ;i<getLength();i++){
        if(c[i] =='['){
            while(c[i] !=']'){
                if(c[i]==' '){
                    c[i] = '.';
                }
                i++;
            }
        }
    }
    for(unsigned i = 0;i<getLength();i++){
        myStr[i] = c[i];
    }
    delete[] c;
}
void DSString::replacePeriod() const {
    char *c = new char[getLength()];
    for(unsigned i = 0;i<getLength();i++){
        c[i] = myStr[i];
    }
    for(unsigned i = 0;i<getLength();i++){
        if(c[i] =='['){
            while(c[i]!=']'){
                if(c[i]=='.'){
                    c[i] = ' ';
                }
                i++;
            }
        }
    }
    for(unsigned i = 0;i<getLength();i++){
        myStr[i] = c[i];
    }
    delete[] c;
}
DSString DSString::removeBrackets() {
    DSString number;
    char *arr = new char[length];
    for (int i = 0; i < length; i++) {
        arr[i] = myStr[i];
    }
    int counter = 0;
    char *temp = new char[length-2];
    for (int i = 1; i < length; i++) {
        if (arr[i] != '>') {
            temp[counter] = arr[i];
            counter++;
        }
    }
    length = length-2;
    delete[] myStr;
    myStr = new char[length];
    for (int i = 0; i < length; i++) {
        myStr[i] = temp[i];
    }
    delete[] temp;
    delete[] arr;
    myStr[length] = '\0';
    number = myStr;
    return number;
}
DSString DSString::cleanupBrackets(){
    DSString phrase;
    char *arr = new char[length];
    for(unsigned i = 0;i<length;i++){
        arr[i] = myStr[i];
    }
    int counter = 0;

    char* temp = new char[length-2];
    for(unsigned i = 1;i<length;i++){
        if(arr[i] !=']'){
            temp[counter] = arr[i];
            counter++;
        }
    }
    length = length-2;
    delete[] myStr;
    myStr = new char[length];
    for(unsigned i =0;i<length;i++){
        myStr[i] = temp[i];
    }
    delete[] temp;
    delete[] arr;
    myStr[length] ='\0';
    phrase = myStr;
    return phrase;
}

//TODO: FIGURE OUT HOW TO GET PHRASES CONSIDERED
DSVector<DSString> DSString::getIWord(){
    DSVector<DSString> words;
    replaceSpace();
    char *str = myStr;
    char* word = strtok(str," ");
    while(word!= nullptr){
        DSString temp = word;
        words.pushback(temp);
        word=strtok(nullptr," ");
    }
    //words.pushback(str);
    return words;
}
int DSString::stringToInt() {
    int a;
    char* ptr;
    a =(int)strtol(myStr,&ptr,10);
    return a;

}
void DSString::toLower() const {
    for(unsigned i = 0;i<length;i++){
        myStr[i] = tolower(myStr[i]);
    }

}

void DSString::toUpper() const {
    for(unsigned i =0;i<length;i++){
        myStr[i]= toupper(myStr[i]);
    }
}
