#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/node3d.hpp>

class Player : public godot::Node3D {
    GDCLASS(Player, Node3D);

    private:
        godot::Vector3 cur_position;

    protected:
        static void _bind_methods();

    public: 
        Player();
        ~Player();

        void _process(double delta) override;
};

#endif