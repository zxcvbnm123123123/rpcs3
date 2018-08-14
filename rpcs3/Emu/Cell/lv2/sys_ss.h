#pragma once

#include "Emu/Memory/Memory.h"
#include "Emu/Cell/ErrorCodes.h"

struct CellSsOpenPSID
{
	be_t<u64> high;
	be_t<u64> low;
};

error_code sys_ss_random_number_generator(u32 arg1, vm::ptr<void> buf, u64 size);
s32 sys_ss_get_console_id(vm::ptr<u8> buf);
s32 sys_ss_get_open_psid(vm::ptr<CellSsOpenPSID> ptr);
s32 sys_ss_appliance_info_manager(u32 code, vm::ptr<u8> buffer);
s32 sys_ss_get_cache_of_product_mode(vm::ptr<u8> ptr);
s32 sys_ss_secure_rtc(u64 cmd, u64 a2, u64 a3, u64 a4);
s32 sys_ss_get_cache_of_flash_ext_flag(vm::ptr<u64> flag);
s32 sys_ss_get_boot_device(vm::ptr<u64> dev);
s32 sys_ss_update_manager(u64 pkg_id, u64 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6);
s32 sys_ss_virtual_trm_manager(u64 pkg_id, u64 a1, u64 a2, u64 a3, u64 a4);
