#include <Simple28BYJ48.h>

Simple28BYJ48::Simple28BYJ48(int gpio_in1, int gpio_in2, int gpio_in3, int gpio_in4)
    : in1(gpio_in1)
    , in2(gpio_in2)
    , in3(gpio_in3)
    , in4(gpio_in4)
{
}

// Checks that the current position matches with the last
// acquired target. Call in the main loop. Handles one
// step at a time so it is essentially non-blocking and new
// target can be given mid-action.
void Simple28BYJ48::keep_target_pos()
{       
    if (current_pos != target_pos) {
        int start_pos = current_pos;
        if ((target_pos - start_pos) > 0) {
            step_num++;
            current_pos++;
        }
        else {
            step_num--;
            current_pos--;
        }
        step_num &= 7; // 8 steps
        step(step_num, 1200);
    } else {
        deenergize();
    }
}

// Moves one half-step
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

// Set all inputs to LOW to de-energize the motor
void Simple28BYJ48::deenergize()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
