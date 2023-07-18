void MapInit()
{
    g_Hooks.RegisterHook(Hooks::Player::ClientCommand, @ClientCommand);
}

HookReturnCode ClientCommand(CBasePlayer@ pPlayer, const string& in command)
{
	if(pPlayer is null || !pPlayer.IsConnected() || !pPlayer.IsAlive())
		return HOOK_CONTINUE;

	g_Game.AlertMessage( at_console, ""+pPlayer.pev.netname+" command is "+command+"\n" );

   return HOOK_CONTINUE;
}