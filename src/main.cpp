#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_random.h>
#include <bn_vector.h>
#include <bn_log.h>

#include "bn_sprite_items_dot.h"

// Set max/min x position to be the edges of the display
static constexpr int HALF_SCREEN_WIDTH = bn::display::width() / 2;
static constexpr bn::fixed MIN_X = -HALF_SCREEN_WIDTH;
static constexpr bn::fixed MAX_X = HALF_SCREEN_WIDTH;

static constexpr int HALF_SCREEN_HEIGHT = bn::display::height() / 2;
static constexpr bn::fixed MIN_Y = -HALF_SCREEN_HEIGHT;
static constexpr bn::fixed MAX_Y = HALF_SCREEN_HEIGHT;

// Starting speed of a bouncer
static constexpr bn::fixed BASE_SPEED = 2;

// Maximum number of bouncers on screen at once
static constexpr int MAX_BOUNCERS = 20;

//our bouncer class
class Bouncer {
    public:
        bn::sprite_ptr sprite;
        bn::fixed x_speed;

        //constructor, everytime we make a BOUNCER we make a sprite with a speed
        Bouncer(bn::fixed x_start, bn::fixed y_start) : 
            sprite(bn::sprite_items::dot.create_sprite(x_start, y_start)),
            x_speed(BASE_SPEED) {
        }

        void update() {
            bn::fixed x = sprite.x();

            // Update x position by adding speed
            x += x_speed;

            // If we've gone off the screen on the right
            if(x > MAX_X) {
                // Snap back to screen and reverse direction
                x = MAX_X;
                x_speed *=-1;
            }
            // If we've gone off the screen on the left
            if(x < MIN_X) {
                // Snap back to screen and reverse direction
                x = MIN_X;
                x_speed *= -1;
            }

            sprite.set_x(x);
        }

    private:
};

//the & gives you access to the actual item in memory as opposed to making a copy
bn::fixed average_x(bn::vector<bn::sprite_ptr, MAX_BOUNCERS>& sprites) {
    // Add all x positions together        
    bn::fixed x_sum = 0;
    for(bn::sprite_ptr sprite : sprites) {
        x_sum += sprite.x();
    }

    bn::fixed x_average= x_sum;

    // Only divide if we have 1 or more
    // Prevents division by 0
    if(sprites.size() > 0) {
        x_average /= sprites.size();
    }

    return x_average;
}

void add_bouncer(bn::vector<Bouncer, MAX_BOUNCERS>& bouncers, bn::fixed start_x, bn::fixed start_y) {
    // Only add if we're below the maximum
    if(bouncers.size() < bouncers.max_size()) {
        bouncers.push_back(Bouncer(start_x, start_y));
    }
}

/*--- MAIN METHOD BEGINS HERE ---*/

int main() {
    bn::core::init();

    // Sprites and x speeds of bouncers
    // Items with the same index correspond to each other
    // bn::vector<bn::sprite_ptr, MAX_BOUNCERS> sprites = {};
    // bn::vector<bn::fixed, MAX_BOUNCERS> x_speeds = {};

    bn::fixed y_spawn = 0;

    bn::vector<Bouncer, MAX_BOUNCERS> bouncers = {};

    //make our first manual bouncer
    // Bouncer manual = Bouncer(-30, 25);

    //our game loop
    while(true) {
        // // if B is pressed print the average to the console
        // if(bn::keypad::b_pressed()) {
        //     bn::fixed x_average = average_x(sprites);
        //     BN_LOG("Average x: ", x_average);
        // }

        if(bn::keypad::a_pressed()) {
            add_bouncer(bouncers, 0, y_spawn);
        }

        //for each bouncer(& the actual bouncers) in the vector
        for(Bouncer& b : bouncers) {
            b.update();
        }

        y_spawn += 1;
        if(y_spawn > MAX_Y) {
            y_spawn = MIN_Y;
        }

        // manual.update();
        bn::core::update();
    }
}