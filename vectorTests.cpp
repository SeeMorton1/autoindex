//
// Created by Conner Morton on 9/17/2020.
//

#include "catch.hpp"
#include <string>
#include "DSVector.h"

TEST_CASE ("Vector class","[vector]"){
    DSVector<int> vInt;
    vInt.pushback(1);
    vInt.pushback(2);
    vInt.pushback(4);
    vInt.pushback(5);
    vInt.push(2,3);
    DSVector<char> vChar;
    vChar.pushback('c');
    vChar.pushback('h');
    vChar.pushback('a');
    vChar.pushback('r');
    DSVector<DSString> vString;
    DSString first = "This";
    DSString second = "is";
    DSString third = "a";
    DSString fourth = "test";
    vString.pushback(first);
    vString.pushback(third);
    vString.push(1,second);
    vString.pushback(fourth);
    DSVector<std::string> testString;
    testString.pushback("I");
    testString.pushback("hope");
    testString.pushback("this");
    testString.pushback("works");

    SECTION("Vector int operations"){
        REQUIRE(vInt.get(0)==1);
        REQUIRE(vInt.get(2)==3);
        vInt.popBack();
        REQUIRE(vInt.getCurrSize()==3);
        REQUIRE(vInt.getFront()==1);
        REQUIRE(vInt[0] ==1);
    }
    SECTION("Vector char operations"){

        REQUIRE(vChar.get(0)=='c');
        REQUIRE(vChar.get(vChar.getCurrSize()-1)=='r');
        vChar.popBack();
        REQUIRE(vChar.get(vChar.getCurrSize()-1)=='a');
        vChar.push(1,'h');
        REQUIRE(vChar.get(1)=='h');
    }
    SECTION("Vector String operations"){
        REQUIRE(vString.get(1) == "is");
        REQUIRE(vString.get(vString.getCurrSize()-1)=="test");
        REQUIRE(vString.get(0)=="This");
        vString.pushback("success");
        REQUIRE(vString.get(vString.getCurrSize()-1)=="success");
        vString.erase(vString.getCurrSize()-1);
        REQUIRE(vString.get(vString.getCurrSize()-1)=="test");


    }
    SECTION("STD String tester"){
        REQUIRE(testString.get(0)=="I");
        REQUIRE(testString.get(1) =="hope");
        REQUIRE(testString.getCurrSize()==4);
        testString.popBack();
        REQUIRE(testString.get(testString.getCurrSize()-1)=="this");
    }
}
