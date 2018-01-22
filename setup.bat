@echo off

if not exist "build" mkdir build
if not exist "build/allegro.zip" (
	bitsadmin.exe /TRANSFER htmlget^
 	 http://cdn.allegro.cc/file/library/allegro/5.0.10/allegro-5.0.10-mingw-4.5.0.zip^
 	 %~dp0build\allegro.zip
) else (
	echo Zipped source was found. Skip downloading.
)

if not exist "build/allegro-*" (
	call win_unzip.js build\allegro.zip
) else echo Source zip was already unzipped. Skip unzipping.