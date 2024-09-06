@echo off

:: Check if a file argument is provided
if "%~1"=="" (
    echo Usage: run.bat filename.cpp
    exit /b 1
)

:: Extract file details
set "input_file=%~1"
set "base_name=%~n1"
echo %base_name%
:: Check if the file exists
if not exist "%input_file%" (
    echo File %input_file% not found!
    exit /b 1
)

:: Check if it's a .cpp file
if /i not "%~x1"==".cpp" (
    echo Input file is not a .cpp file.
    exit /b 1
)

:: Compile the C++ file
g++ -Wall -std=c++14 -o main "%input_file%"
if errorlevel 1 (
    echo Compilation failed!
    exit /b 1
)

.\main.exe
:: If compilation succeeds, run the executable
echo Compilation successful. Running the program...
echo ---------------------------------------------

