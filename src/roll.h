#ifndef ROLL_H
#define ROLL_H
#include "die.h"

class Roll
{
    public:
        Roll(Die& d1,Die& d2);
        Roll(int test_value);

        void roll_dice();
        int roll_value() const;
    private:
    Die& die1;
    Die& die2;
    int rolled_value{0};
    bool is_test{false};


};
#endif