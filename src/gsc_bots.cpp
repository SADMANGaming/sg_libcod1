#include "gsc_bots.hpp"

extern customPlayerState_t customPlayerState[MAX_CLIENTS];

void gsc_bots_setbotstance(scr_entref_t ref)
{
    int id = ref.entnum;
    char *stance;

    if (!stackGetParams("s", &stance))
    {
        stackError("gsc_bots_setbotstance() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_bots_setbotstance() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if (client->netchan.remoteAddress.type != NA_BOT)
    {
        stackError("gsc_bots_setbotstance() player %i is not a bot", id);
        stackPushUndefined();
        return;
    }

    if (!strcmp(stance, "stand"))
    {
        customPlayerState[id].botUpMove &= ~(-KEY_MASK_JUMP | KEY_MASK_JUMP);
        customPlayerState[id].botWButtons &= ~(KEY_MASK_CROUCH | KEY_MASK_PRONE);
    }
    else if(!strcmp(stance, "crouch"))
        customPlayerState[id].botWButtons |= KEY_MASK_CROUCH;
    else if(!strcmp(stance, "prone"))
        customPlayerState[id].botWButtons |= KEY_MASK_PRONE;
    else if(!strcmp(stance, "jump"))
        customPlayerState[id].botUpMove |= KEY_MASK_JUMP;
    else
    {
        stackError("gsc_bots_setbotstance() invalid argument '%s'. Valid arguments are: 'stand' 'crouch' 'prone' 'jump'", stance);
        stackPushUndefined();
        return;
    }

    stackPushBool(qtrue);
}

void gsc_bots_meleeweapon(scr_entref_t ref)
{
    int id = ref.entnum;
    int melee;

    if (!stackGetParams("i", &melee))
    {
        stackError("gsc_bots_meleeweapon() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_bots_meleeweapon() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if (client->netchan.remoteAddress.type != NA_BOT)
    {
        stackError("gsc_bots_meleeweapon() player %i is not a bot", id);
        stackPushUndefined();
        return;
    }

    if(!melee)
        customPlayerState[id].botButtons &= ~KEY_MASK_MELEE;
    else
        customPlayerState[id].botButtons |= KEY_MASK_MELEE;

    stackPushBool(qtrue);
}

void gsc_bots_setaim(scr_entref_t ref)
{
    int id = ref.entnum;
    int ads;

    if (!stackGetParams("i", &ads))
    {
        stackError("gsc_bots_setaim() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_bots_setaim() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if (client->netchan.remoteAddress.type != NA_BOT)
    {
        stackError("gsc_bots_setaim() player %i is not a bot", id);
        stackPushUndefined();
        return;
    }

    if(!ads)
        customPlayerState[id].botButtons &= ~KEY_MASK_ADS_MODE;
    else
        customPlayerState[id].botButtons |= KEY_MASK_ADS_MODE;

    stackPushBool(qtrue);
}

void gsc_bots_fireweapon(scr_entref_t ref)
{
    int id = ref.entnum;
    int shoot;

    if (!stackGetParams("i", &shoot))
    {
        stackError("gsc_bots_fireweapon() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_bots_fireweapon() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if (client->netchan.remoteAddress.type != NA_BOT)
    {
        stackError("gsc_bots_fireweapon() player %i is not a bot", id);
        stackPushUndefined();
        return;
    }

    if(!shoot)
        customPlayerState[id].botButtons &= ~KEY_MASK_FIRE;
    else
        customPlayerState[id].botButtons |= KEY_MASK_FIRE;

    stackPushBool(qtrue);
}

void gsc_bots_setlean(scr_entref_t ref)
{
    int id = ref.entnum;
    char *lean;

    if (!stackGetParams("s", &lean))
    {
        stackError("gsc_bots_setlean() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_bots_setlean() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if (client->netchan.remoteAddress.type != NA_BOT)
    {
        stackError("gsc_bots_setlean() player %i is not a bot", id);
        stackPushUndefined();
        return;
    }

    if(!strcmp(lean, "none"))
        customPlayerState[id].botWButtons &= ~(KEY_MASK_LEANLEFT | KEY_MASK_LEANRIGHT);
    else if(!strcmp(lean, "left"))
        customPlayerState[id].botWButtons |= KEY_MASK_LEANLEFT;
    else if(!strcmp(lean, "right"))
        customPlayerState[id].botWButtons |= KEY_MASK_LEANRIGHT;
    else
    {
        stackError("gsc_bots_setlean() invalid argument '%s'. Valid arguments are: 'right' 'left'", lean);
        stackPushUndefined();
        return;
    }

    stackPushBool(qtrue);
}

void gsc_bots_reloadweapon(scr_entref_t ref)
{
    int id = ref.entnum;
    int reload;

    if (!stackGetParams("i", &reload))
    {
        stackError("gsc_bots_reloadweapon() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_bots_reloadweapon() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if (client->netchan.remoteAddress.type != NA_BOT)
    {
        stackError("gsc_bots_reloadweapon() player %i is not a bot", id);
        stackPushUndefined();
        return;
    }

    if(!reload)
        customPlayerState[id].botWButtons &= ~KEY_MASK_RELOAD;
    else
        customPlayerState[id].botWButtons |= KEY_MASK_RELOAD;

    stackPushBool(qtrue);
}

void gsc_bots_switchtoweaponid(scr_entref_t ref)
{
    int id = ref.entnum;
    int weaponid;

    if (!stackGetParams("i", &weaponid))
    {
        stackError("gsc_bots_switchtoweaponid() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_bots_switchtoweaponid() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if (client->netchan.remoteAddress.type != NA_BOT)
    {
        stackError("gsc_bots_switchtoweaponid() player %i is not a bot", id);
        stackPushUndefined();
        return;
    }

    customPlayerState[id].botWeapon = weaponid;

    stackPushBool(qtrue);
}

void gsc_bots_setwalkdir(scr_entref_t ref)
{
    int id = ref.entnum;
    char *dir;

    if (!stackGetParams("s", &dir))
    {
        stackError("gsc_bots_setwalkdir() argument is undefined or has a wrong type");
        stackPushUndefined();
        return;
    }

    if (id >= MAX_CLIENTS)
    {
        stackError("gsc_bots_setwalkdir() entity %i is not a player", id);
        stackPushUndefined();
        return;
    }

    client_t *client = &svs.clients[id];

    if (client->netchan.remoteAddress.type != NA_BOT)
    {
        stackError("gsc_bots_setwalkdir() player %i is not a bot", id);
        stackPushUndefined();
        return;
    }

    if (!strcmp(dir, "none"))
    {
        customPlayerState[id].botForwardMove = KEY_MASK_NONE;
        customPlayerState[id].botRightMove = KEY_MASK_NONE;
    }
    else if(!strcmp(dir, "forward"))
        customPlayerState[id].botForwardMove = KEY_MASK_FORWARD;
    else if(!strcmp(dir, "back"))
        customPlayerState[id].botForwardMove = KEY_MASK_BACK;
    else if(!strcmp(dir, "right"))
        customPlayerState[id].botRightMove = KEY_MASK_MOVERIGHT;
    else if(!strcmp(dir, "left"))
        customPlayerState[id].botRightMove = KEY_MASK_MOVELEFT;
    else
    {
        stackError("gsc_bots_setwalkdir() invalid argument '%s'. Valid arguments are: 'none' 'forward' 'back' 'right' 'left'", dir);
        stackPushUndefined();
        return;
    }

    stackPushBool(qtrue);
}

void gsc_bots_setwalkvalues(scr_entref_t ref)
{
    int id = ref.entnum;
    int fwcount;
    int rgcount;

    if (!stackGetParams("ii", &fwcount, &rgcount))
    {
        stackError("gsc_bots_setwalkvalues() arguments are undefined or have a wrong type");
        stackPushUndefined();
        return;
    }

    customPlayerState[id].botForwardMove = fwcount;
    customPlayerState[id].botRightMove = rgcount;

    stackPushBool(qtrue);
}

void gsc_bots_lookatenemy(scr_entref_t ref) {
    int botId = ref.entnum;
    gentity_t *bot = &g_entities[botId];
    gentity_t *enemy;

    if (!stackGetParams("e", &enemy) || !enemy) {
        stackPushBool(qfalse);
        stackError("gsc_bots_lookatenemy() one or more arguments is undefined");
        return;
    }

    vec3_t botPos, enemyPos, direction, angles;

    VectorCopy(bot->r.currentOrigin, botPos);
    VectorCopy(enemy->r.currentOrigin, enemyPos);

    direction[0] = enemyPos[0] - botPos[0];
    direction[1] = enemyPos[1] - botPos[1];
    direction[2] = enemyPos[2] - botPos[2];

    vectoangles(direction, angles);

    VectorCopy(angles, bot->client->ps.viewangles);
    VectorCopy(angles, bot->s.angles2); 

    stackPushBool(qtrue);
}
