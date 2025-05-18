
#include <iostream>
#include <ctime>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

using std::cout;
using std::endl;

int main() {
    srand(time(0)); 

    Die die1;
    Die die2;
    Shooter shooter;

    Roll* roll = shooter.throw_dice(die1, die2);
    int rolled_value = roll->roll_value();

    ComeOutPhase come_out_phase;

    while (come_out_phase.get_outcome(roll) == RollOutcome::natural || 
           come_out_phase.get_outcome(roll) == RollOutcome::craps) {
        cout << "Rolled " << rolled_value << " roll again" << endl;

        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
    }

    cout << "Rolled " << rolled_value << " start of point phase" << endl;
    cout << "Roll until " << rolled_value << " or a 7 is rolled" << endl;

    int point = rolled_value;
    roll = shooter.throw_dice(die1, die2);
    rolled_value = roll->roll_value();

    PointPhase point_phase(point);

    while (point_phase.get_outcome(roll) == RollOutcome::nopoint) {
        cout << "Rolled " << rolled_value << " roll again" << endl;

        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
    }

    cout << "Rolled " << rolled_value << " end of point phase" << endl;

    shooter.display_rolled_values();

    return 0;
}
