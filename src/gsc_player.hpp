#ifndef _GSC_PLAYER_HPP_
#define _GSC_PLAYER_HPP_

#include "gsc.hpp"



void gsc_player_setvelocity(scr_entref_t ref);
void gsc_player_getvelocity(scr_entref_t ref);
void gsc_player_button_ads(scr_entref_t ref);
void gsc_player_button_left(scr_entref_t ref);
void gsc_player_button_right(scr_entref_t ref);
void gsc_player_button_forward(scr_entref_t ref);
void gsc_player_button_back(scr_entref_t ref);
void gsc_player_button_up(scr_entref_t ref);
void gsc_player_button_down(scr_entref_t ref);
void gsc_player_button_leanleft(scr_entref_t ref);
void gsc_player_button_leanright(scr_entref_t ref);
void gsc_player_button_reload(scr_entref_t ref);
void gsc_player_gettagangles(scr_entref_t ref);
void gsc_player_getstance(scr_entref_t ref);
void gsc_player_getuserinfo(scr_entref_t ref);
void gsc_player_setuserinfo(scr_entref_t ref);
void gsc_player_getip(scr_entref_t ref);
void gsc_player_getping(scr_entref_t ref);
void gsc_player_processclientcommand(scr_entref_t ref);
void gsc_player_dropclient(scr_entref_t ref);
void gsc_player_setspeed(scr_entref_t ref);
void gsc_player_setjumpheight(scr_entref_t ref);
void gsc_player_setairjumps(scr_entref_t ref);
void gsc_player_getfps(scr_entref_t ref);
void gsc_player_isonladder(scr_entref_t ref);
void gsc_player_setufo(scr_entref_t ref);
void gsc_player_connectionlesspackettoclient(scr_entref_t ref);


void gsc_player_setstance(scr_entref_t ref);
void gsc_player_setgravity(scr_entref_t ref);
void gsc_player_isbot(scr_entref_t ref);
void gsc_player_getlastconnecttime(scr_entref_t ref);


#endif