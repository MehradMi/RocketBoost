#include "player.h"
#include <godot_cpp/core/class_db.hpp>
//#include <godot_cpp/classes/class_db_singleton.hpp>
#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/engine.hpp>

void Player::_bind_methods() {
    godot::ClassDB::bind_method(
        godot::D_METHOD("_on_body_entered", "body"),
        &Player::_on_body_entered
    );    
}

Player::Player() {}

Player::~Player() {}

void Player::_ready() {
    //set_contact_monitor(true);
    //set_max_contacts_reported(5);
    this->connect("body entered", godot::Callable(this, "_on_body_enered"));
}

void Player::_process(double delta) {
    godot::Input  *input = godot::Input::get_singleton();
    godot::Engine *engine = godot::Engine::get_singleton();
    
    // Check if we are currently inside the editor 
    if (engine->is_editor_hint()) return;

    if (input->is_action_pressed("boost")) {
        // NOTE: multiply the force by "delta" so it becomes "framerate independent"!
        this->apply_central_force(this->get_transform().basis.get_column(1) * delta * 1000.0f); 
    }

    if (input->is_action_pressed("rotate_left"))
        this->apply_torque(godot::Vector3(0.0f, 0.0f, 100.0f * delta));

    if (input->is_action_pressed("rotate_right"))
        this->apply_torque(godot::Vector3(0.0f, 0.0f, -1 * 100.0f * delta));
}

void Player::_on_body_entered(godot::Node *body) {
    godot::print_line(body->get_name());
}