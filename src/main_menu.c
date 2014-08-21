#include <pebble.h>
#include "window_service.h"
#include "info_window.h"

void aboot_callback(int index, void *ctx){
	window_push(1);
}

void class_callback(int index, void *ctx){
	set_load_info(index);
	window_push(3);
}