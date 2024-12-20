#include "gsc_player.hpp"

extern customPlayerState_t customPlayerState[MAX_CLIENTS];


void gsc_player_setvelocity(scr_entref_t ref)
{
    int id = ref.entnum;
    vec3_t velocity;

    if ( !stackGetParams("v", &velocity) )
    {
        stackError("gsc_player_setvelocity() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_setvelocity() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    playerState_t *ps = SV_GameClientNum(id);
    VectorCopy(velocity, ps->velocity);

    stackPushBool(qtrue);
}

void gsc_player_getvelocity(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_getvelocity() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    playerState_t *ps = SV_GameClientNum(id);

    stackPushVector(ps->velocity);
}

void gsc_player_getuserinfo(scr_entref_t ref)
{
    int id = ref.entnum;
    char *key;

    if ( !stackGetParams("s", &key) )
    {
        stackError("gsc_player_getuserinfo() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_getuserinfo() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];
    char *val = Info_ValueForKey(client->userinfo, key);

    if ( strlen(val) )
        stackPushString(val);
    else
        stackPushString("");
}

void gsc_player_setuserinfo(scr_entref_t ref)
{
    int id = ref.entnum;
    char *key, *value;

    if ( !stackGetParams("ss", &key, &value) )
    {
        stackError("gsc_player_setuserinfo() one or more arguments is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_setuserinfo() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];
    Info_SetValueForKey(client->userinfo, key, value);

    stackPushBool(qtrue);
}

void gsc_player_button_ads(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_ads() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.buttons & KEY_MASK_ADS_MODE ? qtrue : qfalse);
}

void gsc_player_button_left(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_left() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.rightmove == KEY_MASK_MOVELEFT ? qtrue : qfalse);
}

void gsc_player_button_right(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_right() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.rightmove == KEY_MASK_MOVERIGHT ? qtrue : qfalse);
}

void gsc_player_button_forward(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_forward() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.forwardmove == KEY_MASK_FORWARD ? qtrue : qfalse);
}

void gsc_player_button_back(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_back() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.forwardmove == KEY_MASK_BACK ? qtrue : qfalse);
}

void gsc_player_button_up(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_up() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.upmove == KEY_MASK_FORWARD ? qtrue : qfalse);
}

void gsc_player_button_down(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_down() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.upmove == KEY_MASK_BACK ? qtrue : qfalse);
}

void gsc_player_button_leanleft(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_leanleft() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];
    
    stackPushBool(client->lastUsercmd.wbuttons & KEY_MASK_LEANLEFT ? qtrue : qfalse);
}

void gsc_player_button_leanright(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_leanright() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.wbuttons & KEY_MASK_LEANRIGHT ? qtrue : qfalse);
}

void gsc_player_button_reload(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_button_reload() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    stackPushBool(client->lastUsercmd.wbuttons & KEY_MASK_RELOAD ? qtrue : qfalse);
}

void gsc_player_gettagangles(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_gettagangles() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }
    
    playerState_t *ps = SV_GameClientNum(id);

    stackPushVector(ps->viewangles);
}

void gsc_player_getstance(scr_entref_t ref)
{
    int id = ref.entnum;
    
    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_getstance() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }
    
    playerState_t *ps = SV_GameClientNum(id);
    if ( ps->eFlags & EF_CROUCHING )
        stackPushString("crouch");
    else if ( ps->eFlags & EF_PRONE )
        stackPushString("prone");
    else
        stackPushString("stand");
}

void gsc_player_getip(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_getip() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];
    char tmp[16];
    snprintf(tmp, sizeof(tmp), "%d.%d.%d.%d", client->netchan.remoteAddress.ip[0], client->netchan.remoteAddress.ip[1], client->netchan.remoteAddress.ip[2], client->netchan.remoteAddress.ip[3]);

    stackPushString(tmp);
}

void gsc_player_getping(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_getping() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];
    stackPushInt(client->ping);
}

void gsc_player_processclientcommand(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_processclientcommand() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    ClientCommand(id);

    stackPushBool(qtrue);
}

void gsc_player_dropclient(scr_entref_t ref)
{
    int id = ref.entnum;
    char *reason;

    if ( Scr_GetNumParam() > 0 && !stackGetParams("s", &reason) )
    {
        stackError("gsc_player_dropclient() argument has a wrong type");
        stackPushUndefined();
        return;
    }

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_dropclient() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if(Scr_GetNumParam() > 0)
        SV_DropClient(client, reason);
    else
        SV_DropClient(client, NULL);

    stackPushBool(qtrue);
}

void gsc_player_setspeed(scr_entref_t ref)
{
    int id = ref.entnum;
    int speed;

    if ( !stackGetParams("i", &speed) )
    {
        stackError("gsc_player_setspeed() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_setspeed() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    if ( speed < 0 )
    {
        stackError("gsc_player_setspeed() param must be equal or above zero");
        stackPushUndefined();
        return;
    }

    customPlayerState[id].speed = speed;

    stackPushBool(qtrue);
}

void gsc_player_getfps(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_getfps() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    stackPushInt(customPlayerState[id].fps);
}

void gsc_player_isonladder(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_isonladder() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    playerState_t *ps = SV_GameClientNum(id);

    stackPushBool(ps->pm_flags & PMF_LADDER ? qtrue : qfalse);
}

void gsc_player_setufo(scr_entref_t ref)
{
    int id = ref.entnum;
    int state;

    if ( !stackGetParams("i", &state) )
    {
        stackError("gsc_player_setufo() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_setufo() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    if (state != 0 && state != 1)
    {
        stackError("gsc_player_setufo() param must be 0 or 1");
        stackPushUndefined();
        return;
    }

    customPlayerState[id].ufo = state;

    stackPushBool(qtrue);
}

void gsc_player_connectionlesspackettoclient(scr_entref_t ref)
{
    int id = ref.entnum;
    char *cmd;

    if ( !stackGetParams("s", &cmd) )
    {
        stackError("gsc_player_connectionlesspackettoclient() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_connectionlesspackettoclient() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];
    NET_OutOfBandPrint(NS_SERVER, client->netchan.remoteAddress, cmd);

    stackPushBool(qtrue);
}

void gsc_player_isbot(scr_entref_t ref)
{
    int id = ref.entnum;

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_isbot() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];
    stackPushBool(client->bIsTestClient); // Use the bot field instead of bIsTestClient

    return;
}
void gsc_player_getlastconnecttime(scr_entref_t ref)
{
	int id = ref.entnum;

	if ( id >= MAX_CLIENTS )
	{
		stackError("gsc_player_getlastconnecttime() entity %i is not a player", id);
		stackPushUndefined();
		return;
	}

	client_t *client = &svs.clients[id];

	stackPushInt(client->lastConnectTime);
}

void gsc_player_setgravity(scr_entref_t ref)
{
	int id = ref.entnum;
    int gravity;

	if ( !stackGetParams("i", &gravity) )
	{
		stackError("gsc_player_setgravity() argument is undefined or has a wrong type");
		stackPushUndefined();
		return;
	}

	if ( id >= MAX_CLIENTS )
	{
		stackError("gsc_player_setgravity() entity %i is not a player", id);
		stackPushUndefined();
		return;
	}

	if ( gravity < 0 )
	{
		stackError("gsc_player_setgravity() param must be equal or above zero");
		stackPushUndefined();
		return;
	}

	customPlayerState[id].gravity = gravity;

	stackPushBool(qtrue);
}
void gsc_player_setjumpheight(scr_entref_t ref)
{
    int id = ref.entnum;
    float jump_height;

    if ( !stackGetParams("f", &jump_height) )
    {
        stackError("gsc_player_setjumpheight() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_setjumpheight() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    if ( jump_height < 0 )
        customPlayerState[id].overrideJumpHeight = false;
    else
    {
        customPlayerState[id].overrideJumpHeight = true;
        customPlayerState[id].jumpHeight = jump_height;
    }

    stackPushBool(qtrue);
}
void gsc_player_setairjumps(scr_entref_t ref)
{
    int id = ref.entnum;
    int airJumps;

    if (!stackGetParams("i", &airJumps))
    {
        stackError("gsc_player_setairjumps() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_player_setairjumps() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    customPlayerState[id].airJumpsAvailable = airJumps;

    stackPushBool(qtrue);
}


void gsc_player_setstance(scr_entref_t ref)
{
	int id = ref.entnum;
	char *stance;

	if ( !stackGetParams("s", &stance) )
	{
		stackError("gsc_player_setstance() argument is undefined or has a wrong type");
		stackPushUndefined();
		return;
	}

	gentity_t *entity = &g_entities[id];

	if ( entity->client == NULL )
	{
		stackError("gsc_player_setstance() entity %i is not a player", id);
		stackPushUndefined();
		return;
	}


	int event;

	if ( strcmp(stance, "stand") == 0 )
		event = EV_STANCE_FORCE_STAND;
	else if ( strcmp(stance, "crouch") == 0 )
		event = EV_STANCE_FORCE_CROUCH;
	else if ( strcmp(stance, "prone") == 0 )
		event = EV_STANCE_FORCE_PRONE;
	else
	{
		stackError("gsc_player_setstance() invalid argument '%s'. Valid arguments are: 'stand', 'crouch', 'prone'", stance);
		stackPushUndefined();
		return;
	}

	G_AddPredictableEvent(entity, event, 0);

	stackPushBool(qtrue);
}

void gsc_player_playscriptanimation(scr_entref_t ref)
{
    int id = ref.entnum;
    int scriptAnimEventType;
    int isContinue;
    int force;
    if ( !stackGetParams("iii", &scriptAnimEventType, &isContinue, &force) )
    {
        stackError("gsc_player_playscriptanimation() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }
    if ( id >= MAX_CLIENTS )
    {
        stackError("gsc_player_playscriptanimation() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }
    if ( scriptAnimEventType < 0 || scriptAnimEventType >= NUM_ANIM_EVENTTYPES )
    {
        stackError("gsc_player_playscriptanimation() argument is not a valid scriptAnimEventType");
        stackPushUndefined();
        return;
    }
    
    gentity_t *entity = &g_entities[id];
    stackPushInt(BG_AnimScriptEvent(&entity->client->ps, (scriptAnimEventTypes_t)scriptAnimEventType, isContinue, force));
}

void gsc_player_playfxforplayer(scr_entref_t ref)
{
	int id = ref.entnum;
	int args;
	qboolean error;
	int index;
	vec3_t origin;
	vec3_t forward_vec;
	vec3_t up_vec;
	vec3_t cross;
	double length;

	args = Scr_GetNumParam();
	error = qfalse;
	switch ( args )
	{
		case 2:
			if ( ! stackGetParams("iv", &index, &origin) )
				error = qtrue;
			break;
		case 3:
			if ( ! stackGetParams("ivv", &index, &origin, &forward_vec) )
				error = qtrue;
			break;
		case 4:
			if ( ! stackGetParams("ivvv", &index, &origin, &forward_vec, &up_vec) )
				error = qtrue;
			break;
		default:
			stackError("gsc_utils_playfxforplayer() incorrect number of parameters");
			stackPushUndefined();
			return;
	}

	if ( error )
	{
		stackError("gsc_utils_playfxforplayer() one or more arguments is undefined or has a wrong type");
		stackPushUndefined();
		return;
	}
	
	if ( id >= MAX_CLIENTS )
	{
		stackError("gsc_player_playfxforplayer() entity %i is not a player", id);
		stackPushUndefined();
		return;
	}

	gentity_t *ent = G_TempEntity(origin, EV_PLAY_FX);
    if(!ent){
        printf("gsc_player_playfxforplayer() cannot create entity");
        return;
    }
    printf("gsc_player_playfxforplayer() Entity created, index: %d\n", index);
	ent->s.eventParm = index & 0xff;
	ent->s.otherEntityNum = id + 1;
	if ( args == 2 )
	{
		ent->s.apos.trBase[0] = -90.0;
	}
	else
	{
		length = _VectorLength(forward_vec);
		if ( length == 0.0 )
		{
			Scr_Error("playFx called with (0 0 0) forward direction " + index); 
		}
		VectorScale(forward_vec, 1.0 / length, forward_vec);

		if ( args == 3 )
		{
			vectoangles(forward_vec, ent->s.apos.trBase);
		}
		else
		{
			length = _VectorLength(up_vec);
			if ( length == 0.0 )
			{
				Scr_Error("playFx called with (0 0 0) up direction " + index);
			}
			VectorScale(up_vec, 1.0 / length, up_vec);
			VectorCross(up_vec, forward_vec, cross);

			length = _VectorLength(cross);
			if ( length < 0.001 )
			{
				Scr_Error("playFx called an up direction 0 or 180 degrees from forward " + index);
			}
			else if ( length < 0.999 )
			{
				VectorScale(cross, 1.0 / length, cross);
				VectorCross(forward_vec, cross, up_vec);
			}
			AxisToAngles(forward_vec, ent->s.apos.trBase);
		}
	}

	stackPushBool(qtrue);
}

void gsc_player_lookatkiller(scr_entref_t ref)
{
	int id = ref.entnum;
	int inflictor, attacker;

	if ( !stackGetParams("ii", &inflictor, &attacker) )
	{
		stackError("gsc_player_lookatkiller() one or more arguments is undefined or has a wrong type");
		stackPushUndefined();
		return;
	}

	gentity_t *self_entity = Scr_GetEntity(id);
	if ( !self_entity )
	{
		stackError("gsc_player_lookatkiller() self_entity state is invalid");
		stackPushUndefined();
		return;
	}

	gentity_t *inflictor_entity = Scr_GetEntity(inflictor);
	if ( !inflictor_entity )
	{
		stackError("gsc_player_lookatkiller() inflictor_entity state is invalid");
		stackPushUndefined();
		return;
	}

	gentity_t *attacker_entity = Scr_GetEntity(attacker);
	if ( !attacker_entity )
	{
		stackError("gsc_player_lookatkiller() attacker_entity state is invalid");
		stackPushUndefined();
		return;
	}

	LookAtKiller(self_entity, inflictor_entity, attacker_entity);

	stackPushBool(qtrue);
}
void gsc_player_sethiddenfromscoreboard(scr_entref_t ref)
{
    int id = ref.entnum;
    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_player_sethiddenfromscoreboard() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }
    bool hidden = Scr_GetInt(0);
    customPlayerState[id].hiddenFromScoreboard = hidden;
    stackPushBool(true);
}
void gsc_player_ishiddenfromscoreboard(scr_entref_t ref)
{
    int id = ref.entnum;
    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_player_ishiddenfromscoreboard() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }
    stackPushBool(customPlayerState[id].hiddenFromScoreboard);
}
void gsc_player_renameclient(scr_entref_t ref)
{
	int id = ref.entnum;
	char *name;

	if ( !stackGetParams("s", &name) )
	{
		stackError("gsc_player_renameclient() argument is undefined or has a wrong type");
		stackPushUndefined();
		return;
	}

	if ( strlen(name) > 31 )
	{
		stackError("gsc_player_renameclient() player name is longer than 31 characters");
		stackPushUndefined();
		return;
	}

	if ( id >= MAX_CLIENTS )
	{
		stackError("gsc_player_renameclient() entity %i is not a player", id);
		stackPushUndefined();
		return;
	}

	client_t *client = &svs.clients[id];
	Info_SetValueForKey(client->userinfo, "name", name);
	strcpy(client->name, name);

	stackPushBool(qtrue);
}
