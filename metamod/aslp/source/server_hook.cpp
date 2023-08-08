#include <extdll.h>
#include <dllapi.h>
#include <meta_api.h>

#include <cl_entity.h>
#include <entity_state.h>

#include "../header/enginedef.h"
#include "../header/serverdef.h"
#include "../header/aslp.h"
#include "../header/angelscript/angelscriptlib.h"

void SC_SERVER_DECL CASEngineFuncs_Test(void* pthis SC_SERVER_DUMMYARG_NOCOMMA)
{

}

void SC_SERVER_DECL CASGame__PlayBackEvent(void* pthis, SC_SERVER_DUMMYARG int flags, const edict_t* pInvoker, int eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2)
{
	g_engfuncs.pfnPlaybackEvent(flags, pInvoker, eventindex, delay, origin, angles, fparam1, fparam2, iparam1, iparam2, bparam1, bparam2);
}

int SC_SERVER_DECL CASGame__PrecacheEvent(void* pthis, SC_SERVER_DUMMYARG int type, CString* path)
{
	return g_engfuncs.pfnPrecacheEvent(type, path->c_str());
}

void SC_SERVER_DECL CASEngineFuncs__Delay(void* pthis, SC_SERVER_DUMMYARG double delay_time, aslScriptFunction* aslfn)
{
	Scheduler::SetScheduler(delay_time, aslfn);
}

ReadFileParams_t* SC_SERVER_DECL CASEngineFuncs__SetFile(void* pthis, SC_SERVER_DUMMYARG CString* path)
{
	auto pParams = std::make_unique<ReadFileParams_t>();
	pParams->SetFile(path);

	return pParams.release();
}
 
bool SC_SERVER_DECL CASReadFileParams_t__IsValid(ReadFileParams_t* pthis SC_SERVER_DUMMYARG_NOCOMMA)
{
	return pthis->IsValid();
}

bool SC_SERVER_DECL CASReadFileParams_t__ReadFile(ReadFileParams_t* pthis SC_SERVER_DUMMYARG_NOCOMMA)
{
	return pthis->ReadFile();
}

void SC_SERVER_DECL CASReadFileParams_t__FreeFile(ReadFileParams_t* pthis SC_SERVER_DUMMYARG_NOCOMMA)
{
	pthis->FreeFile();
	pthis = nullptr;
}

void RegisterAngelScriptMethods()
{
	ASEXT_RegisterDocInitCallback([](CASDocumentation* pASDoc) 
	{
			/* ReadFileParams_t */
		ASEXT_RegisterObjectType(pASDoc, "Entity readfile info", "ReadFileParams", 0, asOBJ_REF | asOBJ_NOCOUNT);
		ASEXT_RegisterObjectProperty(pASDoc, "", "ReadFileParams", "string pPath", offsetof(ReadFileParams_t, pPath));
		ASEXT_RegisterObjectProperty(pASDoc, "", "ReadFileParams", "string pMessage", offsetof(ReadFileParams_t, pMessage));
		ASEXT_RegisterObjectMethod(pASDoc, "¿El archivo es valido?", "ReadFileParams", "bool IsValid()", (void*)CASReadFileParams_t__IsValid, asCALL_THISCALL);
		ASEXT_RegisterObjectMethod(pASDoc, "¿Se puede seguir leyendo?", "ReadFileParams", "bool ReadFile()", (void*)CASReadFileParams_t__ReadFile, asCALL_THISCALL);
		ASEXT_RegisterObjectMethod(pASDoc, "Liberar la memoria del archivo", "ReadFileParams", "void FreeFile()", (void*)CASReadFileParams_t__FreeFile, asCALL_THISCALL);

			/* Test */
		ASEXT_RegisterObjectMethod(pASDoc, "Test", "CEngineFuncs", "void Test()", (void*)CASEngineFuncs_Test, asCALL_THISCALL);

			/* CGame */
		ASEXT_RegisterObjectMethod(pASDoc, "Prueba de funcionamiento del precache event", "CGame", "int PrecacheEvent( int type, string& in path )", (void*)CASGame__PrecacheEvent, asCALL_THISCALL);
		//ASEXT_RegisterObjectMethod(pASDoc, "Prueba de funcionamiento del PlayBackEvent", "CGame", "void PlaybackEvent( int flags, const edict_t* pInvoker, int eventindex, float delay, Vector origin, Vector angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2 )", (void*)CASGame__PlayBackEvent, asCALL_THISCALL);

			/* CEngineFuncs */
		ASEXT_RegisterObjectMethod(pASDoc, "Prueba de funcionamiento del read", "CEngineFuncs", "ReadFileParams @SetFile(string& in path)", (void*)CASEngineFuncs__SetFile, asCALL_THISCALL);
		ASEXT_RegisterFuncDef(pASDoc, "Callback", "void GetDelay()");
		ASEXT_RegisterObjectMethod(pASDoc, "Prueba de funcionamiento del delay", "CEngineFuncs", "void Delay( double delay_time, GetDelay @callback )", (void*)CASEngineFuncs__Delay, asCALL_THISCALL);
	});
}