//
// Created by Conner Morton on 9/20/2020.
//
#include "catch.hpp"
#include "LinkedList.h"
#include "DSString.h"

TEST_CASE("Linked List Tests","[linked list"){
    LinkedList<int> intList;
    LinkedList<char> charList;
    LinkedList<DSString> stringList;

    SECTION("LinkedList of ints"){
        intList.pushBack(1);
        intList.pushBack(2);
        intList.pushBack(3);
        intList.pushBack(4);
        REQUIRE(intList.search(1)->getData()==1);
        //intList.pop();

    }
    SECTION("LinkedList of charList"){
        charList.pushBack('c');
        REQUIRE(charList.search('c')->getData()=='c');
    }
    SECTION("LinkedList of strings"){
        stringList.pushBack("test");
        stringList.pushBack("testindexing");



    }



}
