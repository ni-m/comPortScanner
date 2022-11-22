# Qt installer framework

```
comPortScanner
├───installer
│   ├───config
│   │   └───config.xml 1)
│   └───packages
│       └───ch.nim.comPortScanner
│           ├───data
│           │   └───comPortScanner.exe 2)
│           └───meta
│               ├───installscript.qs 3)
│               ├───LICENSE.md 4)
│               └───package.xml 5)
├───src
└───...
```

1) Config file for the entire installation
2) Compiled executable with all dependencies
3) Custom script for shortcuts within startMenu
4) End user license
5) Package file for each package

## Useful links

### Qt build
https://github.com/Mte90/GBAATM-Rebirth/blob/master/.github/workflows/main.yml

### Error with hyphen in path
https://stackoverflow.com/questions/58791830/qt-installer-framework-typeerror-cannot-read-property-name
