#include "roll.h"

Roll::Roll(Die& d1, Die& d2) : die1(d1), die2(d2){}

Roll::Roll(int test_val) : die1(*(Die*)nullptr), die2(*(Die*)nullptr), rolled_value(test_val), is_test(true) {}
void Roll::roll_dice()
{
    if(!is_test){
        int value1 = die1.roll();
        int value2 = die2.roll();
        rolled_value = value1 + value2;
    }

}
int Roll::roll_value() const
{
    return rolled_value;
}