#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/rigid_body3d.hpp>

class Player : public godot::RigidBody3D {
    GDCLASS(Player, RigidBody3D);

    private:
        godot::Vector3 cur_position;

    protected:
        static void _bind_methods();

    public: 
        Player();
        ~Player();

        void _on_body_entered(godot::Node *body);
        void _ready();
        void _process(double delta) override;
};

#endif