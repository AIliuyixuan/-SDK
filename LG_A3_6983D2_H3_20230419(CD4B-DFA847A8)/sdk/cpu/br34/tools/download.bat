@echo off
Setlocal enabledelayedexpansion
@echo ********************************************************************************
@echo 			SDK BR34			
@echo ********************************************************************************
@echo %date%

cd /d %~dp0

set OBJDUMP=C:\JL\pi32\bin\llvm-objdump.exe
set OBJCOPY=C:\JL\pi32\bin\llvm-objcopy.exe
set ELFFILE=sdk.elf
set bankfiles=
set LZ4_PACKET=lz4_packet

REM %OBJDUMP% -D -address-mask=0x1ffffff -print-dbg $1.elf > $1.lst
%OBJCOPY% -O binary -j .text %ELFFILE% text.bin
%OBJCOPY% -O binary -j .data %ELFFILE% data.bin
%OBJCOPY% -O binary -j .data_code %ELFFILE% data_code.bin
%OBJCOPY% -O binary -j .common %ELFFILE% common.bin
%OBJCOPY% -O binary -j .overlay_aec %ELFFILE% aec.bin
%OBJCOPY% -O binary -j .overlay_aac %ELFFILE% aac.bin

for /L %%i in (0,1,20) do (
	%OBJCOPY% -O binary -j .overlay_bank%%i %ELFFILE% bank%%i.bin
	set bankfiles=!bankfiles! bank%%i.bin 0x0 
)

%LZ4_PACKET% -dict text.bin -input common.bin 0 aec.bin 0 aac.bin 0 !bankfiles! -o bank.bin

%OBJDUMP% -section-headers -address-mask=0x1ffffff %ELFFILE%
REM %OBJDUMP% -t %ELFFILE% >  symbol_tbl.txt

copy /b text.bin + data.bin + data_code.bin + bank.bin app.bin

del !bankfiles! common.bin text.bin data.bin bank.bin

isd_download.exe -tonorflash -dev br34 -boot 0x20000 -div8 -wait 300 -uboot uboot.boot -app app.bin cfg_tool.bin  -res tone.cfg p11_code.bin -uboot_compress
:: -format all

::-uboot_compress
:: -format all
::-reboot 2500

::-format all
::-reboot 100







@rem 生成固件升级文件
fw_add.exe -noenc -fw jl_isd.fw  -add ota.bin -type 100 -out jl_isd.fw
@rem 添加配置脚本的版本信息到 FW 文件中
fw_add.exe -noenc -fw jl_isd.fw -add script.ver -out jl_isd.fw


ufw_maker.exe -fw_to_ufw jl_isd.fw
copy jl_isd.ufw update.ufw
del jl_isd.ufw

@REM 生成配置文件升级文件
::ufw_maker.exe -chip AC800X %ADD_KEY% -output config.ufw -res bt_cfg.cfg

::IF EXIST jl_693x.bin del jl_693x.bin 


@rem 常用命令说明
@rem -format vm        //擦除VM 区域
@rem -format cfg       //擦除BT CFG 区域
@rem -format 0x3f0-2   //表示从第 0x3f0 个 sector 开始连续擦除 2 个 sector(第一个参数为16进制或10进制都可，第二个参数必须是10进制)

ping /n 2 127.1>null
IF EXIST null del null
::pause
