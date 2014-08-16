#pragma once

/*
'l' stands for load
'ul' stands for unload
the last word in each function is the load/unload function for that
specified window.
*/
	
void w_l_main(Window *w);
void w_ul_main(Window *w);
void w_l_wf(Window *w);
void w_ul_wf(Window *w);
void w_l_info(Window *w);
void w_ul_info(Window *w);
void w_l_class(Window *w);
void w_ul_class(Window *w);
void w_l_aboot(Window *w);
void w_ul_aboot(Window *w);