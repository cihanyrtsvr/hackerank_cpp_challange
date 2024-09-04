@echo off
:: Display debug information
echo Arguments count: %*
echo Argument 1: %~1

:: Extract the base name (file name without extension)
set "base_name=%~n1"
echo Base name: %base_name%

:: Check if the input file exists and is a .cpp file
if not exist "%~1" (
    echo Input file "%~1" not found.
    exit /b 1
)

if /i not "%~x1"==".cpp" (
    echo Input file is not a .cpp file.
    exit /b 1
)

:: Compile the C++ code
g++ -Wall -std=c++14 -o %base_name% %~1

:: Check if the compilation was successful
if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
) else (
    echo Compilation successful. Executable created: %base_name%
    .\%base_name%
    :: Run the executable
    echo Running the executable:
    echo -----------------------
    "%base_name%"
)

:: Pause the script so the console window stays open
pause
