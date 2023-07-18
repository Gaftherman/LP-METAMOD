#include <extdll.h>

#include <dllapi.h>
#include <meta_api.h>

#include <cl_entity.h>
#include <entity_state.h>

#include "enginedef.h"
#include "serverdef.h"
#include "aslp.h"

int SC_SERVER_DECL CASEngineFuncs__TestFunc(void* pthis SC_SERVER_DUMMYARG_NOCOMMA)
{
	return 114514;
}

void RegisterAngelScriptMethods()
{
	ASEXT_RegisterDocInitCallback([](CASDocumentation* pASDoc) {
		ASEXT_RegisterObjectMethod(pASDoc, "A Test Function", "CEngineFuncs", "int TestFunc()", (void*)CASEngineFuncs__TestFunc, 3);
	});
}