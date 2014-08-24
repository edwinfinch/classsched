#include <pebble.h>
#include "services.h"
#include "window_data.h"
#include "elements.h"
#include "window_service.h"
#include "data_framework.h"

void services_handler(bool type){
	if(type == 1){
		tick_timer_service_subscribe(SECOND_UNIT, &tick_handler);
		bluetooth_connection_service_subscribe(bt_handler);
		battery_state_service_subscribe(bat_handler);
		accel_tap_service_subscribe(&tap);
		app_message_register_inbox_received(app_m_inbox);
		app_message_open(1028, 512);
	}
	//unsubscribe
	else{
		tick_timer_service_unsubscribe();
		bluetooth_connection_service_unsubscribe();
		battery_state_service_unsubscribe();
		accel_tap_service_unsubscribe();
	}
}

void launch(){
	int value = load_data(0);
	int value1 = load_data(1);
	int value2 = load_data(2);
	int value3 = load_data(3);
	APP_LOG(APP_LOG_LEVEL_INFO, "Loaded %d, %d, %d (class data) and %d (settings) bytes of data.", value, value1, value3, value2);
	
	window_push(0);
}

void deinit(){
	deinit_windows();
	
	int value = save_data(0);
	int value1 = save_data(1);
	int value2 = save_data(2);
	int value3 = save_data(3);
	APP_LOG(APP_LOG_LEVEL_INFO, "Saved %d, %d, %d (class data) and %d (settings) bytes of data.", value, value1, value3, value2);
}
	
int main(){
	define_windows();
	services_handler(1);
	launch();
	app_event_loop();
	services_handler(0);
	deinit();
}