@echo off
if not exist ".\out" mkdir ".\out"
pushd out

set libs= kernel32.lib user32.lib gdi32.lib shell32.lib winmm.lib
set compiler_opts= /nologo /FC /W4 /I
set linker_opts= /nologo /INCREMENTAL:NO %libs%


set debug_compiler_opts= /DUSER_DEBUG=1 /Z7
set debug_linker_opts= /subsystem:console

set release_compiler_opts= /O2 /GS-
set release_linker_opts= /subsystem:console

set src=../src/ttf_to_lslug.c


set release= 0
for %%a in (%*) do set "%%~a=1"
if "%release%"=="1" echo [release mode]
if not "%release%"=="1" echo [debug mode]

if not "%release%"=="1" call clang-cl %compiler_opts% %debug_compiler_opts% %src% /link %linker_opts% %debug_linker_opts%
if "%release%"=="1" call clang-cl %compiler_opts% %release_compiler_opts% %src% /link %linker_opts% %release_linker_opts%

popd
