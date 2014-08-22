#include <pebble.h>
#include "elements.h"
#include "data_framework.h"
	
#define SETTINGS_KEY 0
#define CLASS_DATA_KEY_1 1
#define CLASS_DATA_KEY_2 2
	
/*
Apparently you can have more than 5 courses a semester so I created 
extra_data to compensate for that incase someone needs an extra couple.

bool isExtra is referring to extra_data in any case.
*/
	
CD main_data = {
	.isLecture
	.prof = {"Mr. Quosai"},
	.code = {"Room 600"},
	.name = {"Computer sciences"},
	.times = {11.30, 11.45, 11.30, 12.20, 16.40},
	.exists = {0, 0, 0},
};
	
CD extra_data = {
	.isLecture
	.prof = {"Mr. Seigers"},
	.code = {"Room 601"},
	.name = {"Wood"},
	.times = {11.20, 13.45, 9.30, 12.20, 16.40},
	.exists = {0, 0, 0},
};

persist settings;

/*
50 bytes
typedef struct Class {
	bool isLecture; //1 byte
	char prof[21]; //21 bytes (?)
	char code[8]; //8 bytes
	char name[21];
	float times[5]; //5 bytes*4 == ??? :P
	bool exists[3];
} Class;
*/

Class get_class(bool isExtra, int toGet){
	Class data;
	if(!isExtra){
		data = main_data.classes[toGet];
	}
	else{
		data = extra_data.classes[toGet];
	}
	return data;
}

bool class_exists(int class){
	bool data = 0;
	if(class > 3){
		data = extra_data.classes[class-4].exists[class-4];
	}
	else{
		data = main_data.classes[class-1].exists[class-1];
	}
	return data;
}

float get_class_time(int timeslot, Class class){
	float data = 0.0;
	data = class.times[timeslot];
	return data;
}

bool class_is_lecture(Class class){
	bool lecture;
	lecture = class.isLecture;
	return lecture;
}

void set_class_time(int timeslot, bool isExtra, int class, float data){
	if(isExtra == 0){
		main_data.classes[class].times[timeslot] = data;
	}
	else{
		extra_data.classes[class].times[timeslot] = data;
	}
}

void set_exists(int class, bool isExtra, bool exists){
	if(class > 3){
		extra_data.classes[class-4].exists[class-4] = exists;
	}
	else{
		main_data.classes[class-1].exists[class-1] = exists;
	}
}

void set_professor(int class, bool isExtra, char prof[21]){
	if(isExtra == 0){	
		main_data.classes[class].prof[0] = prof;
	}
	else{
		extra_data.classes[class].prof[0] = prof;
	}
}

void set_code(int class, bool isExtra, char code[8]){
	if(isExtra == 0){	
		main_data.classes[class].code[0] = code;
	}
	else{
		extra_data.classes[class].code[0] = code;
	}
}

void set_name(int class, bool isExtra, char name[21]){
	APP_LOG(APP_LOG_LEVEL_INFO, "Got char %s", name);
	if(isExtra == 0){	
		main_data.classes[class].name = name;
	}
	else{
		extra_data.classes[class].name = name;
	}
}

void class_set_lecture(int class, bool isExtra, bool isLecture){
	if(isExtra == 0){	
		main_data.classes[class].isLecture = isLecture;
	}
	else{
		extra_data.classes[class].isLecture = isLecture;
	}
}

int save_data(int toSave){
	int returned = 0;
	if(toSave == 1){
		returned = persist_write_data(CLASS_DATA_KEY_2, &extra_data, sizeof(extra_data));
	}
	else if(toSave == 0){
		returned = persist_write_data(CLASS_DATA_KEY_1, &main_data, sizeof(main_data));
	}
	else if(toSave == 2){
		returned = persist_write_data(SETTINGS_KEY, &settings, sizeof(settings));
	}
	return returned;
}

int load_data(int toSave){
	int returned = 0;
	if(toSave == 1){
		returned = persist_read_data(CLASS_DATA_KEY_2, &extra_data, sizeof(extra_data));
	}
	else if(toSave == 0){
		returned = persist_read_data(CLASS_DATA_KEY_1, &main_data, sizeof(main_data));
	}
	else if(toSave == 2){
		returned = persist_read_data(SETTINGS_KEY, &settings, sizeof(settings));
	}
	return returned;
}