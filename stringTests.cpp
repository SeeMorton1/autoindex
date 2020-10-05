//
// Created by Conner Morton on 9/23/2020.
//

#include "catch.hpp"
#include "DSString.h"

TEST_CASE("DSString tests","[DSString]"){
    DSString s[10];
    s[0] = DSString("test");
    s[1] = DSString("");
    s[2] = DSString("A really good. string class!");
    s[3] = DSString("UPPERCASE");
    s[4] = DSString("uppercase");
    s[5] = DSString("\n");
    s[6] = DSString("I want THIS");
    s[7] = DSString("      ");
    s[8] = DSString("test");
    SECTION("bool operators"){
        REQUIRE(s[0] == s[8]);

    }
    SECTION("methods"){
        unsigned last = s[6].getLength()-1;
        REQUIRE(s[6][s[6].getLength()-1]==s[6][last]);
        unsigned getT = s[6].getIndex('T');
        REQUIRE(getT == 7);
        s[0].reverse(0,s[0].getLength()-1);
        REQUIRE(s[0]=="tset");
        s[0].reverse(0,s[0].getLength()-1);
    }
    SECTION("[] operator"){
        REQUIRE(s[0][0] =='t');
        REQUIRE(s[2][1] == ' ');
    }
}
