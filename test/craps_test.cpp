#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Die roll returns value between 1 and 6 ") {
	Die die;
	for(int i=0; i<10; i++){
		int result=die.roll();
		REQUIRE(result >= 1);
		REQUIRE (result <= 6);
	}
}

TEST_CASE("rolls returns value between 2 and 12"){
	Die d1;
	Die d2;
	Roll roll(d1,d2);
	for (int i =0 ; i < 10; ++i)
	{
		roll.roll_dice();
		int result=roll.roll_value();
		REQUIRE(result>=2);
		REQUIRE(result<=12);
		
	}
}