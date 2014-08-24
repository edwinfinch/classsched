#pragma once

typedef struct persist {
	bool firstsetting;
} persist;

//50 bytes
typedef struct Class {
	bool isLecture; //1 byte
	char prof[1][21]; //17 bytes
	char code[1][8]; //8 bytes
	char name[1][21]; //17
	char start_times[5][5]; //5 bytes*5 == ??? :P
	char end_times[5][5]; //25 bytes
	bool exists; //1
} Class;

//255 bytes
//#PushingIt
typedef struct CD {
	Class classes[2];
} CD;

//main_data.class1.isLecture;
//main_data.class3.time3;
//just testing my syntax