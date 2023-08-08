#pragma once

#include <string>
#include "read_file.h"
#include "scheduler.h"

extern void* g_aslpFlashLight;
extern void* g_aslpClientCommand;
extern void* g_aslpEntitySearched;

void RegisterAngelScriptMethods();
void RegisterAngelScriptHooks();