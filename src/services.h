#pragma once

void bt_handler(bool connected);
void bat_handler(BatteryChargeState state);
void tick_handler(struct tm *t, TimeUnits units);
void app_m_inbox(DictionaryIterator *iter, void *context);
void select(ClickRecognizerRef recognizer, void *context);
void down(ClickRecognizerRef recognizer, void *context);
void up(ClickRecognizerRef recognizer, void *context);
void config_provider(void *context);
void tap(AccelAxisType axis, int32_t direction);