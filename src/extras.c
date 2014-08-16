#include <pebble.h>
#include "extras.h"
	
TextLayer* text_layer_init(GRect location, GTextAlignment alignment, GFont font)
{
	TextLayer *layer = text_layer_create(location);
	text_layer_set_text_color(layer, GColorBlack);
	text_layer_set_background_color(layer, GColorClear);
	text_layer_set_text_alignment(layer, alignment);
	text_layer_set_font(layer, font);
	return layer;
}