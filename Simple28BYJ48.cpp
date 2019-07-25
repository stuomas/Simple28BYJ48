
#include "Simple28BYJ48.h"

bool Simple28BYJ48::move_to_pos(int target_pos)
{
    // Half-step mode (8 steps)
    // Step angle 5.625 -> 64 steps per revolution of the rotor
    // Gear ratio 63.68395:1
    // One full revolution of the shaft 64 * 63.68395 ~= 4076
    int step_num = 0;
    int start_pos = get_position();
    int current_pos = start_pos;
    int i = 1200;
    while (current_pos != target_pos) {
        if ((target_pos - start_pos) > 0) {
            step_num++;
            current_pos++;
        }
        else {
            step_num--;
            current_pos--;
        }
        step_num &= 7; // 8 steps
        step(step_num, i);
        set_position(current_pos);
    }
    deenergize();
    return true;
}

void Simple28BYJ48::step(int step_num, int period_us)
{
    switch (step_num) {
    case 0:
        digitalWrite(in4, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in1, LOW);
        break;
    case 1:
        digitalWrite(in4, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in1, LOW);
        break;
    case 2:
        digitalWrite(in4, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in1, LOW);
        break;
    case 3:
        digitalWrite(in4, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in1, LOW);
        break;
    case 4:
        digitalWrite(in4, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in1, LOW);
        break;
    case 5:
        digitalWrite(in4, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in1, HIGH);
        break;
    case 6:
        digitalWrite(in4, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in1, HIGH);
        break;
    case 7:
        digitalWrite(in4, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in1, HIGH);
        break;
    }
    delayMicroseconds(period_us);
}

void Simple28BYJ48::deenergize()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
