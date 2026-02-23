#ifndef LANDINGPAD_H
#define LANDINGPAD_H

#include <godot_cpp/classes/csg_box3d.hpp>

class LandingPad : public godot::CSGBox3D {
	GDCLASS(LandingPad, godot::CSGBox3D);

	private:
		godot::String level_filepath;

	protected:
		static void _bind_methods();

	public:
		/* Constructors and Destructors */
		LandingPad();
		~LandingPad();
		/* ============================ */
		
		/* Getters and Setters */
		void set_level_filepath(const godot::String p_path);
		godot::String get_level_filepath() const;
		/* ============================ */	
};

#endif