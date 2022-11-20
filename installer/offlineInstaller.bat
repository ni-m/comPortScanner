set PATH=C:\Qt\Tools\QtInstallerFramework\4.4\bin;C:\Qt\6.2.4\mingw_64\bin;C:\Qt\Tools\mingw1120_64\bin;%PATH%
set PATH=C:\ProgramFiles\Qt\Tools\QtInstallerFramework\4.4\bin;C:\ProgramFiles\Qt\6.2.4\mingw_64\bin;C:\ProgramFiles\Qt\Tools\mingw1120_64\bin;%PATH%

:: Create offline installer with online update capabilities.
binarycreator.exe -c config\config.xml -p packages comPortScannerOffline_v0.1.0.exe

pause
