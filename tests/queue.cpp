#include <catch.hpp>
#include <sstream>
#include <fstream>
#include "queue.hpp"
using namespace std;

TEST_CASE("queue ini with other queue data")
{
    Queue <int> b1;
    Queue <int> b2 = {1, 2, 3, 4};
    Queue <int> b3{b2};
    REQUIRE( b2 == b3);
}

TEST_CASE("swap")
{
    Queue <int> b1;
    Queue <int> b2 = {1, 2, 3, 4};
    Queue <int> b3{b2};
    Queue <int> temp = b3;
    b1.swap(b3);
    REQUIRE( b1 == temp);
    REQUIRE( b3.empty() == true);
    REQUIRE( b1.size() == 4);
}

TEST_CASE("push")
{
    Queue <int> b1;
    Queue <int> b2 = {1, 2, 3, 4};
    Queue <int> b3{b2};
    b3.push(5);
    REQUIRE( b3.size() == 5);
}
TEST_CASE("pop#1")
{
    Queue<int> b4;
    //if the queue is empty
    b4.pop();
    REQUIRE( b4.size() == 0);
}
TEST_CASE("pop#2")
{
    Queue<int> b4 = {1};
    // if queue 1 el
    a4.pop();
    REQUIRE( b4.size() == 0);
}
TEST_CASE("pop#3")
{
    Queue<int> b4 = {1, 2, 3, 4, 5};
    // if queue 5 el
    a4.pop();
    REQUIRE( b4.size() == 4);
}

TEST_CASE("eq")
{
    Queue <int>  b1;
    Queue <int>  b2 = {1, 2, 3, 4};
    Queue <int>  b3{b2};
    a3.push(5);
    ofstream output{ "queue.bin" };
    output << b3;
    Queue <int> b4;
    ifstream input{ "queue.bin" };
    input >> b4;
    REQUIRE(! b4.empty() );
}
