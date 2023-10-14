@echo off

taskkill /f /im svencoop.exe

copy "C:\Users\Estefano\source\repos\metamod-fallguys\Release\aslp.dll" "C:\Program Files (x86)\Steam\steamapps\common\Sven Co-op\svencoop\addons\metamod\dlls"
