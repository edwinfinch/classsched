#include <pebble.h>
#include "services.h"
#include "elements.h"
#include "window_service.h"
#include "BLKS.h"
		
void bt_handler(bool connected){
	blks_bt(connected);
}

void bat_handler(BatteryChargeState state){
	blks_bat(state);
}

void tick_handler(struct tm *t, TimeUnits units){
	blks_tick(t, units);
}

void tap(AccelAxisType axis, int32_t direction){
	blks_tap();
}

void app_m_inbox(DictionaryIterator *iter, void *context){
	
}

void select(ClickRecognizerRef recognizer, void *context){
	window_push(2);
}

void down(ClickRecognizerRef recognizer, void *context){
	
}

void up(ClickRecognizerRef recognizer, void *context){
	
}

void config_provider(void *context){
	window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler)down);
	window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler)select);
	window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler)up);
}