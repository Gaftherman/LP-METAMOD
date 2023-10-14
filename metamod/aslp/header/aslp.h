#pragma once

#include "angelscript.h"

void RegisterAngelScriptMethods();
void RegisterAngelScriptHooks();

void VtableUnhook();
void NewServerActivate(edict_t* pEdictList, int edictCount, int clientMax);