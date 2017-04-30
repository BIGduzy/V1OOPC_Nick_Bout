#include "ostream"
#include "rational.hpp"
#include "vector.hpp"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"


/*
 * VECTOR CLASS TEST CASES 
*/
//TEST_CASE("Vector: constructor, zero_parameters") {
//    Vector v();
//    std::stringstream s;
//    s << v;
//    REQUIRE(s.str() == "(0,0)");
//}

TEST_CASE("Vector: constructor, two_parameters") {
    Vector v(6, 9);
    std::stringstream s;
    s << v;
    REQUIRE(s.str() == "(6, 9)");
}

TEST_CASE("Vector: Operator, Unary plus") {
    Vector v(4, 2);
    Vector v1(+v);
    REQUIRE(v == v1);
}

TEST_CASE("Vector: Operator, Binary plus") {
    Vector v(3, 5);
    Vector v1(3, 5);
    REQUIRE((v + v1) == Vector(6, 10));
}

TEST_CASE("Vector: Operator, Plus-assignment") {
    Vector v(3, 5);
    Vector v1(3, 5);
    v += v1;
    REQUIRE(v == Vector(6, 10));
}

TEST_CASE("Vector: Operator, multiply right hand interger") {
    Vector v(3, 5);
    int i = 2;
    REQUIRE((v * i) == Vector(6, 10));
}

TEST_CASE("Vector: Operator, multiply left hand interger") {
    Vector v(3, 5);
    int i = 2;
    REQUIRE((i * v) == Vector(6, 10));
}

TEST_CASE("Vector: Operator, multiply assignment (vector)") {
    Vector v(3, 5);
    Vector v1(3, 5);
    v *= v1;
    REQUIRE(v == Vector(9, 25));
}

TEST_CASE("Vector: Operator, multiply assignment (interger)") {
    Vector v(3, 5);
    int i = 2;
    v *= i;
    REQUIRE(v == Vector(6, 10));
}



/*
 * RATIONAL CLASS TEST CASES 
*/

TEST_CASE( "constructor, two_parameters" ){
   rational v( 14, 17 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "[14/17][0x000E/0x0011]" );   
}

TEST_CASE( "equality, equal" ){
   rational v( 1, 2 );
   REQUIRE( v == rational( 1, 2 ) ); 
}

TEST_CASE( "equality, unequal" ){
   rational v( 1, 2 );
   REQUIRE( ! ( v == rational( 1, 3 )) ); 
}

TEST_CASE( "constructor, two_parameters; reduction" ){
   rational v( 10, 2 );
   REQUIRE( v == rational( 5, 1 ) ); 
}

TEST_CASE( "constructor, one parameter" ){
   rational v( 6 );
   REQUIRE( v == rational( 6, 1 ) );   
}

TEST_CASE( "multiply by integer" ){
   rational v( 3, 4 );
   rational x = v * 7;
   REQUIRE( v == rational( 3, 4 ) );   
   REQUIRE( x == rational( 21, 4 ) );   
}

TEST_CASE( "multiply by integer; reduction" ){
   rational v( 3, 10 );
   rational x = v * 5;
   REQUIRE( v == rational( 3, 10 ) );   
   REQUIRE( x == rational( 3, 2 ) );   
}

TEST_CASE( "multiply by rational" ){
   rational v( 3, 4 );
   rational x = v * rational( 9, 7 );
   REQUIRE( v == rational( 3, 4 ) );   
   REQUIRE( x == rational( 27, 28 ) );   
}

TEST_CASE( "multiply by rational; reduction" ){
   rational v( 3, 10 );
   rational x = v * rational( 4, 6 );
   REQUIRE( v == rational( 3, 10 ) );   
   REQUIRE( x == rational( 1, 5 ) );   
}

TEST_CASE( "add rational into rational" ){
   rational v( 3, 10 );
   v += rational( 6, 7 ); 
   REQUIRE( v == rational( 81, 70 ) );     
}

TEST_CASE( "add rational into rational; reduction" ){
   rational v( 23, 147 );
   v += rational( 5, 91 ); 
   REQUIRE( v == rational( 404, 1911 ) );     
}

TEST_CASE( "add rational into rational; return value" ){
   rational v( 1, 2 );
   rational x = ( v += rational( 1, 4 )); 
   REQUIRE( v == rational( 3, 4 ) );     
   REQUIRE( x == rational( 3, 4 ) );     
}

TEST_CASE( "multiply rational into rational" ){
   rational v( 3, 10 );
   v *= rational( 1, 2 ); 
   REQUIRE( v == rational( 3, 20 ) );     
}

TEST_CASE( "multiply rational into rational; reduction" ){
   rational v( 2, 3 );
   v *= rational( 3, 2 ); 
   REQUIRE( v == rational( 1, 1 ) );     
}

TEST_CASE( "multiply rational into rational; return value" ){
   rational v( 3, 10 );
   rational x = ( v *= rational( 1, 2 )); 
   REQUIRE( x == rational( 3, 20 ) );     
}






