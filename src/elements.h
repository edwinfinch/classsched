#pragma once

typedef struct persist {
	bool firstsetting;
} persist;

//50 bytes
typedef struct Class {
	bool isLecture; //1 byte
	char prof[21]; //21 bytes (?)
	char code[8]; //8 bytes
	char name[21]; //21
	float times[5]; //5 bytes*4 == ??? :P
	bool exists[3]; //3
} Class;

//49*5 == 245 bytes
typedef struct CD {
	Class classes[4];
} CD;

//main_data.class1.isLecture;
//main_data.class3.time3;
//just testing my syntax