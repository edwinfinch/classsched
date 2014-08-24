#pragma once
#include <pebble.h>
#include "elements.h"

Class get_class(bool isExtra, int toGet);
void set_class(Class class, int classNum, bool isExtra);
float get_class_time(int timeslot, Class class);
bool class_is_lecture(Class class);
void set_class_time(int timeslot, bool isExtra, int class, float data);
void set_professor(int class, bool isExtra, char prof[]);
void set_code(int class, bool isExtra, char code[]);
void set_name(int class, bool isExtra, char name[]);
void class_set_lecture(int class, bool isExtra, bool isLecture);
int save_data(int type);
int load_data(int type);
bool class_exists(int class);
void set_exists(int class, bool isExtra, bool exists);