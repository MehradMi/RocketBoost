#include "landing_pad.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/core/property_info.hpp>

using namespace godot;

void LandingPad::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_level_filepath"), &LandingPad::get_level_filepath);
	ClassDB::bind_method(D_METHOD("set_level_filepath", "p_path"), &LandingPad::set_level_filepath);
	
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "next_level", PROPERTY_HINT_FILE, "*.tscn,*.scn"), "set_level_filepath", "get_level_filepath");
}

/* Class Constructors and Destructors */
LandingPad::LandingPad() {}
LandingPad::~LandingPad() {}
/* ================================== */


/* Getters and Setters */
void LandingPad::set_level_filepath(const godot::String p_path) { this->level_filepath = p_path; }
godot::String LandingPad::get_level_filepath() const { return this->level_filepath; }
/* ============================ */	