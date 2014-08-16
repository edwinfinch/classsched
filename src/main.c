#include <pebble.h>
#include "main.h"
#include "services.h"
#include "window_data.h"
	
void define_windows(){
	wf_window = window_create();
	main_window = window_create();
	class_window = window_create();
	info_window = window_create();
	settings_window = window_create();
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
	window_set_window_handlers(settings_window, (WindowHandlers){
		.load = w_l_settings,
		.unload = w_ul_settings,
	});
	window_set_window_handlers(aboot_window, (WindowHandlers){
		.load = w_l_aboot,
		.unload = w_ul_aboot,
	});
}

void services_handler(bool type){
	if(type == 1){
		tick_timer_service_subscribe(SECOND_UNIT, &tick_handler);
		bluetooth_connection_service_subscribe(bt_handler);
		battery_state_service_subscribe(bat_handler);
		app_message_register_inbox_received(app_m_inbox);
	}
	//unsubscribe
	else{
		tick_timer_service_unsubscribe();
		bluetooth_connection_service_unsubscribe();
		battery_state_service_unsubscribe();
	}
}

void launch(){
	window_stack_push(wf_window, true);
}

void deinit(){
	window_destroy(main_window);
	window_destroy(wf_window);
	window_destroy(class_window);
	window_destroy(info_window);
	window_destroy(settings_window);
	window_destroy(aboot_window);
}
	
int main(){
	define_windows();
	services_handler(1);
	launch();
	app_event_loop();
	services_handler(0);
	deinit();
}