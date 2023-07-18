void MapInit()
{
	g_Hooks.RegisterHook(Hooks::Player::FlashLight, @FlashLight);
}

HookReturnCode FlashLight(CBasePlayer@ pPlayer, bool& out flashlightMode)
{
	if(pPlayer is null || !pPlayer.IsConnected() || !pPlayer.IsAlive())
		return HOOK_CONTINUE;

    g_Game.AlertMessage( at_console, ""+pPlayer.pev.netname+" trying to "+(flashlightMode ? "activated" : "deactivated")+" his flashlight\n" );

    //Force a mode 
        //flashlightMode = false; -> always off 
        //flashlightMode = true; -> always true

    return HOOK_CONTINUE;
}