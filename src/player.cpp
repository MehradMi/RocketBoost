#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input.hpp>

void godot::Player::_bind_methods() {}

godot::Player::Player() {}

godot::Player::~Player() {}

void godot::Player::_process(double delta) {
    godot::Input *input = godot::Input::get_singleton();
    if (input->is_action_just_pressed("ui_accept")) {
        godot::Vector3 cur_position = get_position();
        godot::Vector3 new_position = godot::Vector3(cur_position.x, cur_position.y + delta, cur_position.z);
        set_position(new_position); 
        godot::print_line(cur_position.x, " ", cur_position.y, " ", cur_position.z);
    }
}