#include <pebble.h>
#include "services.h"
#include "elements.h"
#include "window_service.h"
#include "data_framework.h"
#include "BLKS.h"
	
Class temp;
int classnum_temp;
AppTimer *load_timer;
		
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

void t_callback(void *data){
	int i, extra_fix = 0;
	i = classnum_temp-1;
	if(i == 2 || i == 3){
		//isExtra
		extra_fix = 1;
	}
	else if(i == 0 || i == 1){
		extra_fix = 0;
	}
	else if(i == 4 || i == 5){
		extra_fix = 2;
	}
	//"Edwin, use a switch" - no. shutup.
	if(i == 2){
		i = 0;
	}
	else if(i == 3){
		i = 1;
	}
	else if(i == 4){
		i = 0;
	}
	else if(i == 5){
		i = 1;
	}
	temp.exists = true;
	set_class(temp, i, extra_fix);
	
	APP_LOG(APP_LOG_LEVEL_INFO, "%s (test). Callback sent. memory address %d, %d", temp.prof[0], i, extra_fix);
}

void process_tuple(Tuple *t)
{
	int key = t->key;
	int value = t->value->int32;
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Loaded key num: %d with value %d (string value: %s)", key, value, t->value->cstring);
  switch (key) {
	  case 0:
	  	classnum_temp = value;
	  	//Start a timer that waits about a 1/2 second for the rest of the data
	  	//to finish loading into temp storage then the callback loads it into
	  	//the actual data.
	  	load_timer = app_timer_register(500, (AppTimerCallback) t_callback, NULL);
	  	break;
	  case 1:
	  	strncpy(temp.prof[0], t->value->cstring, 21);
	  	break;
	  case 2:
	  	strncpy(temp.code[0], t->value->cstring, 8);
	  	break;
	  case 3:
	  	temp.isLecture = value;
	  	break;
	  case 4:
	  	strncpy(temp.name[0], t->value->cstring, 21);
	  	break;
	  case 5:
	  	strncpy(temp.start_times[0], t->value->cstring, 5);
	  	break;
	  case 6:
	  	strncpy(temp.start_times[1], t->value->cstring, 5);
	  	break;
	  case 7:
	  	strncpy(temp.start_times[2], t->value->cstring, 5);
	  	break;
	  case 8:
	  	strncpy(temp.start_times[3], t->value->cstring, 5);
	  	break;
	  case 9:
	  	strncpy(temp.start_times[4], t->value->cstring, 5);
	  	break;
	  case 10:
	  	strncpy(temp.end_times[0], t->value->cstring, 5);
	  	break;
	  case 11:
	  	strncpy(temp.end_times[1], t->value->cstring, 5);
	  	break;
	  case 12:
	  	strncpy(temp.end_times[2], t->value->cstring, 5);
	  	break;
	  case 13:
	  	strncpy(temp.end_times[3], t->value->cstring, 5);
	  	break;
	  case 14:
	  	strncpy(temp.end_times[4], t->value->cstring, 5);
	  	break;
  }
}

void app_m_inbox(DictionaryIterator *iter, void *context){
	(void) context;
	APP_LOG(APP_LOG_LEVEL_INFO, "Party snaps");
	Tuple *t = dict_read_first(iter);
	if(t)
	{
		process_tuple(t);
	}
	while(t != NULL)
	{
		t = dict_read_next(iter);
		if(t)
		{
			process_tuple(t);
		}
	}
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