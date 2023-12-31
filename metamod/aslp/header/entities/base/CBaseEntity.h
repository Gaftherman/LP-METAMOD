#pragma once

template <typename T>
class CBaseEntityTemplate
{
public:
	void SC_SERVER_DECL PreSpawn(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL Spawn(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL PostSpawn(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL Precache(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL KeyValue(T* pThis, SC_SERVER_DUMMYARG KeyValueData* pkvd);
	double SC_SERVER_DECL GetKeyValue(T* pThis, SC_SERVER_DUMMYARG char* szKey, int entvartype);
	void SC_SERVER_DECL OnKeyValueUpdate(T* pThis, SC_SERVER_DUMMYARG char* szKey);
	void SC_SERVER_DECL Save(T* pThis, SC_SERVER_DUMMYARG CSave* pSave);
	void SC_SERVER_DECL Restore(T* pThis, SC_SERVER_DUMMYARG CRestore* pRestore);
	int SC_SERVER_DECL ObjectCaps(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL Activate(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL SetObjectCollisionBox(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	int SC_SERVER_DECL GetClassification(T* pThis, SC_SERVER_DUMMYARG int classify);
	void SC_SERVER_DECL GetClassificationTag(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL GetClassificationName(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	int SC_SERVER_DECL SetClassification(T* pThis, SC_SERVER_DUMMYARG int classify);
	int SC_SERVER_DECL SetClassificationSpecial(T* pThis, SC_SERVER_DUMMYARG int classify, bool over);
	int SC_SERVER_DECL IRelationship(T* pThis, SC_SERVER_DUMMYARG CBaseEntity* pOther, bool friendly);
	int SC_SERVER_DECL Classify(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL DeathNotice(T* pThis, SC_SERVER_DUMMYARG entvars_t* pevChild);
	void SC_SERVER_DECL TraceAttack(T* pThis, SC_SERVER_DUMMYARG entvars_t* pevAttacker, float flDamage, Vector vecDir, TraceResult* ptr, int bitsDamageType);
	int SC_SERVER_DECL TakeDamage(T* pThis, SC_SERVER_DUMMYARG entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, int bitsDamageType);
	int SC_SERVER_DECL TakeHealth(T* pThis, SC_SERVER_DUMMYARG float flHealth, int bitsDamageType, int cap);
	int SC_SERVER_DECL TakeArmor(T* pThis, SC_SERVER_DUMMYARG float flHealth, int bitsDamageType, int cap);
	void SC_SERVER_DECL Killed(T* pThis, SC_SERVER_DUMMYARG entvars_t* pevAttacker, int iGib);
	int SC_SERVER_DECL BloodColor(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL TraceBleed(T* pThis, SC_SERVER_DUMMYARG float flDamage, Vector vecDir, TraceResult* ptr, int bitsDamageType);
	bool SC_SERVER_DECL IsTriggered(T* pThis, SC_SERVER_DUMMYARG CBaseEntity* pActivator);
	CBaseMonster* SC_SERVER_DECL MyMonsterPointer(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	CSquadMonster* SC_SERVER_DECL MySquadMonsterPointer(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	CCustomEntity* SC_SERVER_DECL MyCustomPointer(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	CBasePlayerItem* SC_SERVER_DECL MyItemPointer(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	int SC_SERVER_DECL GetToggleState(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL AddPoints(T* pThis, SC_SERVER_DUMMYARG int score, bool bAllowNegativeScore);
	void SC_SERVER_DECL AddPointsToTeam(T* pThis, SC_SERVER_DUMMYARG int score, bool bAllowNegativeScore);
	bool SC_SERVER_DECL AddPlayerItem(T* pThis, SC_SERVER_DUMMYARG CBasePlayerItem* pItem);
	bool SC_SERVER_DECL RemovePlayerItem(T* pThis, SC_SERVER_DUMMYARG CBasePlayerItem* pItem);
	int SC_SERVER_DECL GiveAmmo(T* pThis, SC_SERVER_DUMMYARG int iAmount, const char* szName, int iMax);
	float SC_SERVER_DECL GetDelay(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	int SC_SERVER_DECL IsMoving(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL OverrideReset(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	int SC_SERVER_DECL DamageDecal(T* pThis, SC_SERVER_DUMMYARG int bitsDamageType);
	void SC_SERVER_DECL SetToggleState(T* pThis, SC_SERVER_DUMMYARG int state);
	void SC_SERVER_DECL StartSneaking(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL StopSneaking(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL OnControls(T* pThis, SC_SERVER_DUMMYARG entvars_t* pev);
	bool SC_SERVER_DECL IsSneaking(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL IsAlive(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL IsBSPModel(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL ReflectGauss(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL HasTarget(T* pThis, SC_SERVER_DUMMYARG string_t targetname);
	bool SC_SERVER_DECL IsInWorld(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL IsMonster(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL IsPlayer(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL IsNetClient(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL IsPointEnt(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL IsBreakable(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL IsMachine(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	const char* SC_SERVER_DECL TeamID(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL CriticalRemove(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	CBaseEntity* SC_SERVER_DECL GetNextTarget(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL Think(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL Touch(T* pThis, SC_SERVER_DUMMYARG CBaseEntity* pOther);
	void SC_SERVER_DECL Use(T* pThis, SC_SERVER_DUMMYARG CBaseEntity* pActivator, CBaseEntity* pCaller, int useType, float value);
	void SC_SERVER_DECL Blocked(T* pThis, SC_SERVER_DUMMYARG CBaseEntity* pOther);
	void SC_SERVER_DECL UpdateOnRemove(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	CBaseEntity* SC_SERVER_DECL Respawn(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL SUB_UseTargets(T* pThis, SC_SERVER_DUMMYARG CBaseEntity* pActivator, CBaseEntity* pCaller, int useType, float value);
	void SC_SERVER_DECL IsLockedByMaster(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL UpdateOwner(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL FBecomeProne(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	Vector* SC_SERVER_DECL Center(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	Vector* SC_SERVER_DECL EyePosition(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	Vector* SC_SERVER_DECL EarPosition(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	Vector* SC_SERVER_DECL BodyTarget(T* pThis, SC_SERVER_DUMMYARG const Vector& posSrc);
	int SC_SERVER_DECL Illumination(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	bool SC_SERVER_DECL FVisible(T* pThis, SC_SERVER_DUMMYARG CBaseEntity* pEntity);
	bool SC_SERVER_DECL FVisibleVector(T* pThis, SC_SERVER_DUMMYARG const Vector& vecOrigin);
	bool SC_SERVER_DECL FVisibleFromPos(T* pThis, SC_SERVER_DUMMYARG Vector* pos, Vector* angle);
	bool SC_SERVER_DECL IsFacing(T* pThis, SC_SERVER_DUMMYARG entvars_t* pevOther, float dis);
	float SC_SERVER_DECL GetPointsForDamage(T* pThis, SC_SERVER_DUMMYARG float damage);
	void SC_SERVER_DECL GetDamagePoints(T* pThis, SC_SERVER_DUMMYARG entvars_t* pevAttacker, entvars_t* pevInfictor, float damage);
	void SC_SERVER_DECL SetPlayerAlly(T* pThis, SC_SERVER_DUMMYARG bool dunno);
	void SC_SERVER_DECL Deconstructor1(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
#ifndef WIN32
	void SC_SERVER_DECL Deconstructor2(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
#endif // !WIN32
	void SC_SERVER_DECL OnCreate(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL OnDestroy(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL OnSetOriginByMap(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	int SC_SERVER_DECL IsRevivable(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL BeginRevive(T* pThis, SC_SERVER_DUMMYARG float flRespawn);
	void SC_SERVER_DECL EndRevive(T* pThis, SC_SERVER_DUMMYARG float flRespawn);
	int SC_SERVER_DECL ShowHUDInfo(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	int SC_SERVER_DECL ShouldDisablePlayerCollisions(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	Vector* SC_SERVER_DECL GetAttackVectors(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL Teleport(T* pThis, SC_SERVER_DUMMYARG Vector vecPos, Vector vecAng);
	void SC_SERVER_DECL SetTopColor(T* pThis, SC_SERVER_DUMMYARG int color);
	void SC_SERVER_DECL SetBottomColor(T* pThis, SC_SERVER_DUMMYARG int color);
	void SC_SERVER_DECL SetColors(T* pThis, SC_SERVER_DUMMYARG int topcolor, int bottomcolor);
	int SC_SERVER_DECL GetTopColor(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	int SC_SERVER_DECL GetBottomColor(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
	void SC_SERVER_DECL UpdateColorMap(T* pThis SC_SERVER_DUMMYARG_NOCOMMA);
};