#include <extdll.h>			// always

#include <meta_api.h>		// of course

#include <map>

#include "enginedef.h"
#include "serverdef.h"
#include "aslp.h"

void* g_aslpFlashLight = NULL;
void* g_aslpClientCommand = NULL;

void RegisterAngelScriptHooks()
{
	g_aslpFlashLight = ASEXT_RegisterHook("Activate/Deactivate the flashlight", StopMode_CALL_ALL, 2, ASFlag_MapScript | ASFlag_Plugin, "Player", "FlashLight", "CBasePlayer @pPlayer, bool& out flashlightMode");
	g_aslpClientCommand = ASEXT_RegisterHook("Player has sent a command (typed, or from a bind)", StopMode_CALL_ALL, 2, ASFlag_MapScript | ASFlag_Plugin, "Player", "ClientCommand", "CBasePlayer @pPlayer, const string& in command");
}