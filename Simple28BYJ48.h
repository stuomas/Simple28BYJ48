/* Simple library for controlling a 28BYJ-48 stepper motor.
 * Very effective and minimal, only one function for moving
 * to a certain position plus some helper functions.
 * 
 * Half-step mode (8 steps)
 * Step angle 5.625 -> 64 steps per revolution of the rotor
 * Gear ratio 63.68395:1
 * One full revolution of the shaft 64 * 63.68395 ~= 4076
 * 
 * Tuomas Salokanto
 * stuomas@protonmail.com
 */

#ifndef SIMPLE28BYJ48_H
#define SIMPLE28BYJ48_H

class Simple28BYJ48 {
public:
    const int in1, in2, in3, in4;
    Simple28BYJ48(int gpio_in1, int gpio_in2, int gpio_in3, int gpio_in4);
    void set_target_pos(int target) { target_pos = target; }
    void keep_target_pos();
    int get_current_position() { return current_pos; }
    bool is_at_target() { return current_pos == target_pos; }
    void deenergize();
private:
    void step(int step_num, int period_us);
    int step_num = 0;
    int target_pos = 0;
    int current_pos = 0;
};

#endif /* SIMPLE28BYJ48_H */