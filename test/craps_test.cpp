#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE("Shooter throws dice between 2 and 12")
{
	Die d1;
	Die d2;
	Shooter shooter;

	for (int i=0; i<10; ++i){
		Roll* roll = shooter.throw_dice(d1,d2);
		int value= roll->roll_value();
		REQUIRE(value>=2);
		REQUIRE(value<=12);

	}
}

TEST_CASE ("Come out phase returns expected roll outcome"){
    ComeOutPhase come_out;
    Roll r1(7);
    REQUIRE(come_out.get_outcome(&r1) == RollOutcome::natural);
    Roll r2(11);
    REQUIRE(come_out.get_outcome(&r2) == RollOutcome::natural);
    Roll r3(2);
    REQUIRE(come_out.get_outcome(&r3) == RollOutcome::craps);
    Roll r4(3);
    REQUIRE(come_out.get_outcome(&r4) == RollOutcome::craps);
    Roll r5(12);
    REQUIRE(come_out.get_outcome(&r5) == RollOutcome::craps);
    Roll r6(4);
    REQUIRE(come_out.get_outcome(&r6) == RollOutcome::point);
}
TEST_CASE("Test PointPhase outcomes") {
    int point = 5;
    PointPhase phase(point);
    Roll r1(5);
    REQUIRE(phase.get_outcome(&r1) == RollOutcome::point);
    Roll r2(7);
    REQUIRE(phase.get_outcome(&r2) == RollOutcome::seven_out);
    Roll r3(8);
    REQUIRE(phase.get_outcome(&r3) == RollOutcome::nopoint);
}