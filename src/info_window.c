#include <pebble.h>
#include "info_window.h"
	
int to_load_public = 0;
	
void set_load_info(int to_load){
	to_load_public = to_load;
}