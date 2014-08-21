#pragma once

typedef struct persist {
	bool firstsetting;
} persist;

//50 bytes
typedef struct Class {
	bool isLecture; //1 byte
	char *prof; //21 bytes (?)
	char *code; //8 bytes
	char *name;
	float times[5]; //5 bytes*4 == ??? :P
	bool exists[3];
} Class;

//46*5 == 230 bytes
typedef struct CD {
	Class classes[3];
} CD;

//main_data.class1.isLecture;
//main_data.class3.time3;
//just testing my syntax