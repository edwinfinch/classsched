#pragma once
#include <pebble.h>
#include "elements.h"

Class get_class(int extra_type, int toGet);
void set_class(Class class, int classNum, int extra_type);
float get_start_time(int timeslot, Class class);
float get_end_time(int timeslot, Class class);
bool class_is_lecture(Class class);
int save_data(int type);
int load_data(int type);
bool class_exists(int class, int extra_type);