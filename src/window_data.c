#include <pebble.h>
#include "window_data.h"
#include "extras.h"
#include "services.h"
#include "BLKS.h"
#include "main_menu.h"
#include "data_framework.h"
	
TextLayer *aboot_edwin, *aboot_daedgoco, *aboot_version;
InverterLayer *aboot_theme;
SimpleMenuLayer *main_menu;

#define NUM_MENU_SECTIONS 2
#define NUM_FIRST_MENU_ITEMS 6
#define NUM_SECOND_MENU_ITEMS 1

static Window *window;
static GBitmap *status_bar_icon;

static SimpleMenuLayer *simple_menu_layer;
static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];
static SimpleMenuItem first_menu_items[NUM_FIRST_MENU_ITEMS];
static SimpleMenuItem second_menu_items[NUM_SECOND_MENU_ITEMS];
	
void w_l_main(Window *w){
	//Debug
	//set_exists(0, 0, 1);
	//set_professor(0, 0, "Mr. Quosai");
	GRect frame = layer_get_frame(window_get_root_layer(w));
	/*
	All menu items will default have no data available
	but if persistent storage finds some data it will use that
	*/
	first_menu_items[0] = (SimpleMenuItem){
		.title = "Class 1/6",
		.subtitle = "No data available.",
		.callback = class_callback,
	};
	first_menu_items[1] = (SimpleMenuItem){
		.title = "Class 2/6",
		.subtitle = "No data available.",
		.callback = class_callback,
	};
	first_menu_items[2] = (SimpleMenuItem){
		.title = "Class 3/6",
		.subtitle = "No data available.",
		.callback = class_callback,
	};
	first_menu_items[3] = (SimpleMenuItem){
		.title = "Class 4/6",
		.subtitle = "No data available.",
		.callback = class_callback,
	};
	first_menu_items[4] = (SimpleMenuItem){
		.title = "Class 5/6",
		.subtitle = "No data available.",
		.callback = class_callback,
	};
	first_menu_items[5] = (SimpleMenuItem){
		.title = "Class 6/6",
		.subtitle = "No data available.",
		.callback = class_callback,
	};
	
	second_menu_items[0] = (SimpleMenuItem){
		.title = "Aboot",
		.callback = aboot_callback,
	};
	
	menu_sections[0] = (SimpleMenuSection){
		.title = "Classes",
		.num_items = NUM_FIRST_MENU_ITEMS,
		.items = first_menu_items,
    };
	
	menu_sections[1] = (SimpleMenuSection){
		.title = "Other",
		.num_items = NUM_SECOND_MENU_ITEMS,
		.items = second_menu_items,
    };

	int i;
	for(i = 0; i < 6; i++){
		APP_LOG(APP_LOG_LEVEL_INFO, "Scanning class #%d for existence", i);
		if(class_exists(i)){
			static char name_buffer[21] = "Physics";
			static char prof_buffer[21] = "Mr. Yourmom";
			Class temp;
			if(i > 2){
				//isExtra
				temp = get_class(i, 1);
			}
			else{
				temp = get_class(i, 0);
			}
			strcpy(name_buffer, temp.name[0]);
			strcpy(prof_buffer, temp.prof[0]);
			first_menu_items[i].title = name_buffer;
			first_menu_items[i].subtitle = prof_buffer;
			APP_LOG(APP_LOG_LEVEL_INFO, "%d exists: %s and %s", i, name_buffer, prof_buffer);
		}
	}

	main_menu = simple_menu_layer_create(frame, w, menu_sections, NUM_MENU_SECTIONS, NULL);
	layer_add_child(window_get_root_layer(w), simple_menu_layer_get_layer(main_menu));
}

void w_ul_main(Window *w){
	APP_LOG(APP_LOG_LEVEL_INFO, "Unloading main menu");
	simple_menu_layer_destroy(main_menu);
}

void w_l_wf(Window *w){
	APP_LOG(APP_LOG_LEVEL_INFO, "Loading watchface window");
	window_set_click_config_provider(w, config_provider);
	load_blks(w);
}

void w_ul_wf(Window *w){
	unload_blks();
}

void w_l_info(Window *w){

}

void w_ul_info(Window *w){
	
}

void w_l_class(Window *w){
	
}

void w_ul_class(Window *w){
	
}

void w_l_aboot(Window *w){
	Layer *window_layer = window_get_root_layer(w);
	aboot_edwin = text_layer_init(GRect(0, 10, 144, 168), GTextAlignmentCenter, fonts_get_system_font(FONT_KEY_GOTHIC_24));
	aboot_daedgoco = text_layer_init(GRect(0, 70, 144, 168), GTextAlignmentCenter, fonts_get_system_font(FONT_KEY_GOTHIC_24));
	aboot_version = text_layer_init(GRect(0, 110, 144, 168), GTextAlignmentCenter, fonts_get_system_font(FONT_KEY_GOTHIC_24));
	aboot_theme = inverter_layer_create(GRect(0, 0, 144, 168));
	
	text_layer_set_text(aboot_edwin, "Created by Edwin Finch");
	text_layer_set_text(aboot_daedgoco, "Idea by /u/daedgoco");
	text_layer_set_text(aboot_version, "v. 0.2-internal");
	
	layer_add_child(window_layer, text_layer_get_layer(aboot_edwin));
	layer_add_child(window_layer, text_layer_get_layer(aboot_daedgoco));
	layer_add_child(window_layer, text_layer_get_layer(aboot_version));
	layer_add_child(window_layer, inverter_layer_get_layer(aboot_theme));
}

void w_ul_aboot(Window *w){
	text_layer_destroy(aboot_edwin);
	text_layer_destroy(aboot_daedgoco);
	text_layer_destroy(aboot_version);
	inverter_layer_destroy(aboot_theme);
}