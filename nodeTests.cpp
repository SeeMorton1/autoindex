//
// Created by Conner Morton on 9/19/2020.
//
#include "catch.hpp"
#include "Node.h"
#include "DSString.h"

TEST_CASE("Node class","[node]"){
    Node n = Node(DSString("hello"));
    REQUIRE(n.getData()=="hello");
}



