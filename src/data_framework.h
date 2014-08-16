#pragma once
#include <pebble.h>
#include "elements.h"

Class get_class(bool isExtra, int toGet);
float get_class_time(int timeslot, Class class);
char* get_professor(Class class);
char* get_code(Class class);
bool class_is_lecture(Class class);
void set_class_time(int timeslot, bool isExtra, int class, float data);
void set_professor(int class, bool isExtra, char *prof);
void set_code(int class, bool isExtra, char *code);
void class_set_lecture(int class, bool isExtra, bool isLecture);
int save_data(int type);
int load_data(int type);