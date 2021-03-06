#include <pebble.h>
#include "main.h"
#include "window_data.h"
	
bool window_is_blks = 0;
	
void window_push(int window){
	switch(window){
		case 0:
			window_stack_push(wf_window, true);
			break;
		case 1:
			window_stack_push(aboot_window, true);
			break;
		case 2:
			window_stack_push(main_window, true);
			break;
		case 3:
			window_stack_push(info_window, true);
			break;
	}
}

void define_windows(){
	wf_window = window_create();
	main_window = window_create();
	class_window = window_create();
	info_window = window_create();
	aboot_window = window_create();
	
	window_set_window_handlers(main_window, (WindowHandlers){
		.load = w_l_main,
		.unload = w_ul_main,
	});
	window_set_window_handlers(wf_window, (WindowHandlers){
		.load = w_l_wf,
		.unload = w_ul_wf,
	});
	window_set_window_handlers(class_window, (WindowHandlers){
		.load = w_l_class,
		.unload = w_ul_class,
	});
	window_set_window_handlers(info_window, (WindowHandlers){
		.load = w_l_info,
		.unload = w_ul_info,
	});
	window_set_window_handlers(aboot_window, (WindowHandlers){
		.load = w_l_aboot,
		.unload = w_ul_aboot,
	});
	window_set_fullscreen(wf_window, true);
}

void deinit_windows(){
	window_destroy(wf_window);
}

Window* window_get_window(int window){
	Window *returned;
	switch(window){
		case 0:
			returned = main_window;
			break;
		default:
			returned = main_window;
			break;
	}
	return returned;
}