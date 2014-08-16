#include <pebble.h>
#include "window_data.h"
#include "extras.h"
#include "services.h"
	
TextLayer *aboot_edwin, *aboot_daedgoco, *aboot_version;
InverterLayer *aboot_theme;
	
void w_l_main(Window *w){
	
}

void w_ul_main(Window *w){
	
}

void w_l_wf(Window *w){
	window_set_click_config_provider(w, config_provider);
}

void w_ul_wf(Window *w){
	
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