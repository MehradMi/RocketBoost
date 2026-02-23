#include "player.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/property_info.hpp>
#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/engine.hpp>

void Player::_bind_methods() {
    godot::ClassDB::bind_method(
        godot::D_METHOD("_on_body_entered", "body"),
        &Player::_on_body_entered
    );
    
    godot::ClassDB::bind_method(
        godot::D_METHOD("set_thrust", "p_thrust"),
        &Player::set_thrust
    );
    godot::ClassDB::bind_method(
        godot::D_METHOD("get_thrust"),
        &Player::get_thrust
    );
    ADD_PROPERTY(
        godot::PropertyInfo(godot::Variant::FLOAT, "thrust"),  
        "set_thrust",
        "get_thrust"
    );
}

Player::Player() {}

Player::~Player() {}

void Player::_ready() {
    this->connect("body entered", godot::Callable(this, "_on_body_enered"));
}

void Player::_process(double delta) {
    godot::Input  *input = godot::Input::get_singleton();
    godot::Engine *engine = godot::Engine::get_singleton();
    
    // Check if we are currently inside the editor 
    if (engine->is_editor_hint()) return;

    if (input->is_action_pressed("boost")) {
        // NOTE: multiply the force by "delta" so it becomes "framerate independent"!
        this->apply_central_force(this->get_transform().basis.get_column(1) * delta * this->get_thrust()); 
    }

    if (input->is_action_pressed("rotate_left"))
        this->apply_torque(godot::Vector3(0.0f, 0.0f, 100.0f * delta));

    if (input->is_action_pressed("rotate_right"))
        this->apply_torque(godot::Vector3(0.0f, 0.0f, -1 * 100.0f * delta));
}

void Player::_on_body_entered(godot::Node *body) {
    godot::TypedArray<godot::StringName>body_groups = body->get_groups();
    if (body->is_in_group("Goal"))
        godot::print_line("Yay!!");
    else if (body->is_in_group("Lose")) 
        godot::print_line("Game Over :(");
}