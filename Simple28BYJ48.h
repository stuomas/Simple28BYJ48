
/* Simple library for controlling a 28BYJ-48 stepper motor.
 * Very effective and minimal, only one function for moving
 * to a certain position plus some helper functions.
 * 
 * Tuomas Salokanto
 * stuomas@protonmail.com
 */
#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

class Simple28BYJ48 {
public:
    // 28BYJ-48 pin setup
    const int in1 = 18;
    const int in2 = 5;
    const int in3 = 4;
    const int in4 = 2;
    bool move_to_pos(int target_pos);
    void deenergize();
    void set_status(bool status) { finished = status; }
    int get_status() { return finished; }
    void set_position(int pos) { position = pos; }
    int get_position() { return position; }

private:
    void step(int step_num, int period_us);
    int position = 0;
    bool finished = false;
};
