#include <extdll.h>
#include <meta_api.h>	

#include "../header/enginedef.h"
#include "../header/serverdef.h"
#include "../header/aslp.h"

void* g_aslpFlashLight = NULL;
void* g_aslpClientCommand = NULL;
void* g_aslpEntitySearched = NULL;

void RegisterAngelScriptHooks()
{
	g_aslpFlashLight = ASEXT_RegisterHook("Activate/Deactivate the flashlight", StopMode_CALL_ALL, 2, ASFlag_MapScript | ASFlag_Plugin, "Player", "FlashLight", "CBasePlayer @pPlayer, bool& out flashlightMode");
	g_aslpClientCommand = ASEXT_RegisterHook("Player has sent a command", StopMode_CALL_ALL, 2, ASFlag_MapScript | ASFlag_Plugin, "Player", "ClientCommand", "CBasePlayer @pPlayer, const string& in command");
	g_aslpEntitySearched = ASEXT_RegisterHook("A entity has been searched", StopMode_CALL_ALL, 2, ASFlag_MapScript | ASFlag_Plugin, "Game", "EntitySearched", "CBaseEntity @pEntity, const string& in pszField, const string& in pszValue");
}