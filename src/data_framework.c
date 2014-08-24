#include <pebble.h>
#include "elements.h"
#include "data_framework.h"
	
#define SETTINGS_KEY 0
#define CLASS_DATA_KEY_1 1
#define CLASS_DATA_KEY_2 2
#define CLASS_DATA_KEY_3 3
	
CD main_data, extra_data, extra_data_2;

persist settings;

Class get_class(int extra_type, int toGet){
	Class data;
	if(extra_type == 0){
		data = main_data.classes[toGet];
	}
	else if(extra_type == 1){
		data = extra_data.classes[toGet];
	}
	else{
		data = extra_data_2.classes[toGet];
	}
	return data;
}

void set_class(Class class, int classNum, int extra_type){
	if(extra_type == 1){
		extra_data.classes[classNum] = class;
	}
	else if(extra_type == 0){
		main_data.classes[classNum] = class;
	}
	else{
		extra_data_2.classes[classNum] = class;
	}
}

bool class_exists(int class, int extra_type){
	bool data = 0;
	if(extra_type == 1){
		data = extra_data.classes[class].exists;
	}
	else if(extra_type == 0){
		data = main_data.classes[class].exists;
	}
	else{
		data = extra_data_2.classes[class].exists;
	}
	return data;
}

bool class_is_lecture(Class class){
	bool lecture;
	lecture = class.isLecture;
	return lecture;
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
	else if(toSave == 3){
		returned = persist_write_data(CLASS_DATA_KEY_3, &extra_data_2, sizeof(extra_data_2));
	}
	return returned;
}

int load_data(int toSave){
	int returned = 0;
	//yes I could use a switch but I'm not doing that right now, okay?
	if(toSave == 1){
		returned = persist_read_data(CLASS_DATA_KEY_2, &extra_data, sizeof(extra_data));
	}
	else if(toSave == 0){
		returned = persist_read_data(CLASS_DATA_KEY_1, &main_data, sizeof(main_data));
	}
	else if(toSave == 2){
		returned = persist_read_data(SETTINGS_KEY, &settings, sizeof(settings));
	}
	else if(toSave == 3){
		returned = persist_read_data(CLASS_DATA_KEY_3, &extra_data_2, sizeof(extra_data_2));
	}
	return returned;
}