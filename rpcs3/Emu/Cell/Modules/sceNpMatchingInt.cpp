#include "stdafx.h"
#include "Emu/System.h"
#include "Emu/Cell/PPUModule.h"



LOG_CHANNEL(sceNpMatchingInt);

s32 sceNpMatchingGetRoomMemberList()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

// Parameter "unknown" added to distinguish this function
// from the one in sceNp.cpp which has the same name
s32 sceNpMatchingJoinRoomGUI(vm::ptr<void> unknown)
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingGetRoomListGUI()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingSendRoomMessage()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingInt_033D5BA0()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingInt_31B2B978()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingInt_4A18A89E()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingInt_92D5C77B()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingInt_B020684E()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingInt_C4100412()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

s32 sceNpMatchingInt_EADCB5CA()
{
	UNIMPLEMENTED_FUNC(sceNpMatchingInt);
	return CELL_OK;
}

DECLARE(ppu_module_manager::sceNpMatchingInt)("sceNpMatchingInt", []()
{
	REG_FUNC(sceNpMatchingInt, sceNpMatchingGetRoomMemberList);
	REG_FUNC(sceNpMatchingInt, sceNpMatchingJoinRoomGUI);
	REG_FUNC(sceNpMatchingInt, sceNpMatchingGetRoomListGUI);
	REG_FUNC(sceNpMatchingInt, sceNpMatchingSendRoomMessage);

	// Need find real name
	REG_FNID(sceNpMatchingInt, 0x033D5BA0, sceNpMatchingInt_033D5BA0);
	REG_FNID(sceNpMatchingInt, 0x31B2B978, sceNpMatchingInt_31B2B978);
	REG_FNID(sceNpMatchingInt, 0x4A18A89E, sceNpMatchingInt_4A18A89E);
	REG_FNID(sceNpMatchingInt, 0x92D5C77B, sceNpMatchingInt_92D5C77B);
	REG_FNID(sceNpMatchingInt, 0xB020684E, sceNpMatchingInt_B020684E);
	REG_FNID(sceNpMatchingInt, 0xC4100412, sceNpMatchingInt_C4100412);
	REG_FNID(sceNpMatchingInt, 0xEADCB5CA, sceNpMatchingInt_EADCB5CA);
});
