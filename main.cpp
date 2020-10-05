#define CATCH_CONFIG_RUNNER
#include  <fstream>
#include <iostream>
#include "DSVector.h"
#include "LinkedList.h"
#include "entry.h"
#include "catch.hpp"
std::set<entry> removeDupes(const std::set<entry>& s){
    DSVector<entry> v;
    DSVector<int> dupeIndex;

    std::set<entry> newSet;
    for(const entry& w:s){
        v.pushback(w);
    }

    for(int i  =0;i<v.getCurrSize();i++) {
        for (int j = 0; j < v.getCurrSize(); j++) {
            DSString word0(v.get(i).getTerm());
            DSString word1(v.get(j).getTerm());
            std::set<int> set0 = v.get(i).getPageNumbers();
            std::set<int> set1 = v.get(j).getPageNumbers();
            if((word0==word1)&&v.get(j).getPageNumbers().size()>1){
                DSString word = v.get(j).getTerm();

                std::set<int> newPages=v.get(j).setPageSet(v.get(i).getPageNumbers());

                entry newEntry(word,newPages);

                newSet.insert(newEntry);
            }else if(!(word0==word1)){

                newSet.insert(v.get(i));
            }
        }
    }
    return newSet;
}

std::set<entry> combinePages(const std::set<entry>& s){
    DSVector<entry> v;
    std::set<entry> newSet;
    for(const entry& w:s){
        v.pushback(w);
    }
    for(int i  =0;i<v.getCurrSize();i++){
        for(int j = 0;j<v.getCurrSize();j++){
            DSString word0(v.get(i).getTerm()); DSString word1(v.get(j).getTerm());

            if(word0==word1){
                DSString word = v.get(j).getTerm();

                std::set<int> newPages=v.get(j).setPageSet(v.get(i).getPageNumbers());

                entry newEntry(word,newPages);

                newSet.insert(newEntry);
            }else{
                newSet.insert(v.get(i));
            }
        }
    }
    return newSet;
}
void processFile(std::ifstream &inFile,std::ofstream &of){
    char line[50];
    DSVector<entry> entryList;
    //DSVector<LinkedList<DSString>> vectorLists;
    DSString pageNumber;
    //populate file
    while(!inFile.eof()){

        inFile.getline(line,50);
        DSString s= line;
        s.toLower();
        if(s[0] !='<'){
            DSVector<DSString> words = s.getIWord();
            DSVector<DSString> cleanedWords;
            DSString cleanWord;
            for( DSString &word:words){


                if(word[0] == '['){

                    word.replacePeriod();//replace period with spaces again
                    cleanWord = word.cleanupBrackets();//remove brackets
                    cleanedWords.pushback(cleanWord);
                }else{
                    cleanedWords.pushback(word);
                }
            }

            for(int i = 0; i<cleanedWords.getCurrSize();i++){

                //LinkedList<DSString> ll;
                DSString word = cleanedWords.get(i);

                entry newEntry(word,pageNumber.stringToInt());
                entryList.pushback(newEntry);//populate entrylist
            }
        }else if(s[1]=='-'){
            break;

        }else{
            pageNumber = s.removeBrackets();//seperate number from brackets

        }
    }
    std::set<entry> final;
    DSVector<entry> entries;
    std::set<DSString> noDupe;
    DSVector<DSString> noDupeVec;
    for(entry& e:entryList){
        noDupe.insert(e.getTerm());
    }
    for(const DSString& e:noDupe){
        noDupeVec.pushback(e);
    }
    //Populate final set which is a set that removes the duplicates like before it was ALGOrithim :5 algorithim: 5,15
    for(int i = 0;i<noDupeVec.getCurrSize();i++){
        entry newEntry(noDupeVec.get(i));
        for(int j = 0;j<entryList.getCurrSize();j++){
            DSString word0 = noDupeVec.get(i);
            DSString word1 = entryList.get(j).getTerm();
            DSVector<int> dupeIndex;
            if(word0==word1){
                for(const auto& in:entryList.get(j).getPageNumbers()){
                    dupeIndex.pushback(in);
                }
            }
            for(int n = 0;n<dupeIndex.getCurrSize();n++){
                newEntry.insertPage(dupeIndex.get(n));

            }
        }
        final.insert(newEntry);
    }


    DSVector<DSString> indexLeads;
    DSVector<entry> entryVec;
    char curr;
    char prev;
    //fill up vector to easily rotate through
    for( entry e:final){
        entryVec.pushback(e);
    }
    for(int i = 0;i<entryVec.getCurrSize();i++){
        DSString word = entryVec.get(i).getTerm();
        curr = word[0];
        curr = toupper(curr);//Format outing correctly
        if(i>=1){
            DSString pch = entryVec.get(i-1).getTerm();
            prev = pch[0];
            prev = toupper(prev);
        }
        if(curr!=prev){
            of<<"["<<curr<<"]"<<std::endl;
        }
        DSString out = entryVec.get(i).getTerm();
        of<<out<<": ";
        int size = 1;
        for(const auto& e:entryVec.get(i).getPageNumbers()){
            if(size==entryVec.get(i).getPageNumbers().size()){
                of<<e<<" ";
            }else{
                of<<e<<", ";
                size++;
            }
        }

        of<<std::endl;
    }
}


int main(int argc, char** argv) {
    Catch::Session().run();
    std::ifstream in(argv[1]);
    std::ofstream of(argv[2]);
    processFile(in,of);



    in.close();
    return 0;
}
