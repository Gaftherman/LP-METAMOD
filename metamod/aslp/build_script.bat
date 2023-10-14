@echo off

taskkill /f /im svencoop.exe

ping 127.0.0.1 -n 2 -w 2000 > nul

copy "C:\Users\Estefano\source\repos\metamod-fallguys\Release\aslp.dll" "C:\Program Files (x86)\Steam\steamapps\common\Sven Co-op\svencoop\addons\metamod\dlls"
