#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/rigid_body3d.hpp>

class Player : public godot::RigidBody3D {
    GDCLASS(Player, RigidBody3D);

    private:
        float thrust = 1000.0f;

    protected:
        static void _bind_methods();

    public: 
        // Constructors and Destructors
        Player();
        ~Player();
        
        // Getters and Setters
        void  set_thrust(const float p_thrust) { this->thrust = p_thrust; }
        float get_thrust() { return this->thrust; }

        // Signals
        void _on_body_entered(godot::Node *body);
        
        // 
        void _ready();
        void _process(double delta) override;
};

#endif