#include <pebble.h>
#include "elements.h"
	
#define SETTINGS_KEY 0
#define CLASS_DATA_KEY_1 1
#define CLASS_DATA_KEY_2 2
	
/*
Apparently you can have more than 5 courses a semester so I created 
extra_data to compensate for that incase someone needs an extra couple.

bool isExtra is referring to extra_data in any case.
*/
	
CD main_data, extra_data;

/*
50 bytes
typedef struct Class {
	bool isLecture; //1 byte
	char prof[21]; //21 bytes (?)
	char code[8]; //8 bytes
	float times[5]; //20 bytes
} Class;
*/

Class get_class(bool isExtra, int toGet){
	Class data;
	data = main_data.classes[toGet];
	return data;
}

float get_class_time(int timeslot, Class class){
	float data = 0.0;
	data = class.times[timeslot];
	return data;
}

char get_professor(Class class){
	char prof[21] = "Mr. NULL";
	prof = class.prof;
	return prof;
}

char get_code(Class class){
	char code[8] = "060898";
	code = class.code;
	return code;
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

void set_professor(int class, bool isExtra, char prof){
	if(isExtra == 0){	
		main_data.classes[class].prof = prof;
	}
	else{
		extra_data.classes[class].prof = prof;
	}
}

void set_code(int class, bool isExtra, char code){
	if(isExtra == 0){	
		main_data.classes[class].prof = prof;
	}
	else{
		extra_data.classes[class].prof = prof;
	}
}

void class_set_lecture(int class, bool isExtra, bool isLecture){
	if(isExtra == 0){	
		main_data.classes[class].isLecture = isLecture;
	}
	else{
		extra_data.classes[class].isLecture = prof;
	}
}

int save_data(bool isExtra){
	int returned = 0;
	if(isExtra){
		returned = persist_write_data(CLASS_DATA_KEY_2, &extra_data, sizeof(extra_data));
	}
	else{
		returned = persist_write_data(CLASS_DATA_KEY_1, &main_data, sizeof(main_data));
	}
	return returned;
}

int load_data(bool isExtra){
	int returned = 0;
	if(isExtra){
		returned = persist_read_data(CLASS_DATA_KEY_2, &extra_data, sizeof(extra_data));
	}
	else{
		returned = persist_read_data(CLASS_DATA_KEY_1, &main_data, sizeof(main_data));
	}
	return returned;
}