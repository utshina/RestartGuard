call CONFIG.BAT

reg delete %REGPATH% /v %NAME% /f
taskkill /f /im %EXE%
del "%DIR%\%EXE%"
rmdir "%DIR%"
