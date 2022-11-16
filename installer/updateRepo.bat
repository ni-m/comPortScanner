set PATH=C:\Qt\Tools\QtInstallerFramework\4.4\bin;C:\Qt\6.2.4\mingw_64\bin;C:\Qt\Tools\mingw1120_64\bin;%PATH%
set PATH=C:\ProgramFiles\Qt\Tools\QtInstallerFramework\4.4\bin;C:\ProgramFiles\Qt\6.2.4\mingw_64\bin;C:\ProgramFiles\Qt\Tools\mingw1120_64\bin;%PATH%

repogen --update-new-components --ac 9 -p packages repo
pause
