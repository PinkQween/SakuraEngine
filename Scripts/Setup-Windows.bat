@echo off

set "SCRIPT_DIR=%~dp0"

for /f "delims=" %%I in ("%SCRIPT_DIR%\..") do set "ROOT_DIR=%%~fI"

for %%A in ("%ROOT_DIR%") do set "SHORT_ROOT=%%~fsA"

cd /d "%SHORT_ROOT%"

echo [INFO] Project Root (Long):  %ROOT_DIR%
echo [INFO] Project Root (Short): %CD%
echo --------------------------------------------------

"Vendor\Binaries\Premake\Windows\premake5.exe" --file=Build.lua vs2022

echo --------------------------------------------------
echo [INFO] Execution finished.
pause
