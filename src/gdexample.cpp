#include "gdexample.h"
#include "godot_cpp/core/property_info.hpp"
#include "godot_cpp/variant/variant.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &GDExample::set_speed);
    ClassDB::add_property("GDExample", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

GDExample::GDExample() {
  // Initialize any variables here.
  time_passed = 0.0;
}

GDExample::~GDExample() {
  // Add your cleanup here.
}

void GDExample::_process(double delta) {
  time_passed += delta;

  Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)),
                                 10.0 + (10.0 * cos(time_passed * 1.5)));
  set_position(new_position);
}

void GDExample::set_speed(const double speed) { this->speed = speed; }
