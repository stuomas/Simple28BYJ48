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
<<<<<<< HEAD

#ifndef SIMPLE28BYJ48_H
#define SIMPLE28BYJ48_H
=======
 
#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif
>>>>>>> 54244254203abda62a864efe075918719140cbd3

class Simple28BYJ48 {
public:
    const int in1, in2, in3, in4;
    Simple28BYJ48(int gpio_in1, int gpio_in2, int gpio_in3, int gpio_in4);
<<<<<<< HEAD
    void set_target_pos(int target) { target_pos = target; }
    void keep_target_pos();
    int get_current_position() { return current_pos; }
    bool is_at_target() { return current_pos == target_pos; }
    void deenergize();
=======
    bool move_to_pos(int target_pos);
    void deenergize();
    void set_status(bool status) { finished = status; }
    int get_status() { return finished; }
    void set_position(int pos) { position = pos; }
    int get_position() { return position; }
>>>>>>> 54244254203abda62a864efe075918719140cbd3
private:
    void step(int step_num, int period_us);
    int step_num = 0;
    int target_pos = 0;
    int current_pos = 0;
};

#endif /* SIMPLE28BYJ48_H */