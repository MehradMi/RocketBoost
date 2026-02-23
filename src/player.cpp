#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/engine.hpp>

void Player::_bind_methods() {}

Player::Player() {}

Player::~Player() {}

void Player::_process(double delta) {
    godot::Input  *input = godot::Input::get_singleton();
    godot::Engine *engine = godot::Engine::get_singleton();
    
    // Check if we are currently inside the editor 
    if (engine->is_editor_hint()) return;

    if (input->is_action_pressed("ui_accept")) {
        godot::Vector3 cur_position = get_position();
        godot::Vector3 new_position = godot::Vector3(cur_position.x, cur_position.y + delta, cur_position.z);
        set_position(new_position); 
    }

    if (input->is_action_pressed("ui_left")) {
        rotate_z(delta); 
    }

    if (input->is_action_pressed("ui_right")) {
        rotate_z(-delta);
    }
}