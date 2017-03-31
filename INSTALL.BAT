call CONFIG.BAT

taskkill /f /im %EXE%
mkdir "%DIR%"
copy %EXE% "%DIR%"
c:
cd "%DIR%"
start %EXE%
reg add %REGPATH% /v %NAME% /t REG_SZ /d "%DIR%\%EXE%" /f
