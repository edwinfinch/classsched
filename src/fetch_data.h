#pragma once

Class get_class(int toGet);
float get_class_time(int timeslot, Class class);
char get_professor(Class class);
char get_code(Class class);
bool class_is_lecture(Class class);
void set_class_time(int timeslot, int class, float data);
void set_professor(int class, char prof);
void set_code(int class, char code);
void class_set_lecture(int class, bool isLecture);