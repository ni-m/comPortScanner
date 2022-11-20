function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
    // This actually installs the files
    component.createOperations();

    if (systemInfo.productType == "windows") {
        // Start menu shortcut
        component.addOperation("CreateShortcut", 
                               "@TargetDir@/comPortScanner.exe", 
                               "@StartMenuDir@/comPortScanner.lnk", 
                               "workingDirectory=@TargetDir@/comPortScanner", 
                               "iconPath=@TargetDir@/comPortScanner.exe", "iconId=0");

        // Add desktop shortcut
        component.addOperation("CreateShortcut", 
                            "@TargetDir@/comPortScanner.exe",// target
                            "@DesktopDir@/comPortScanner.lnk",// link-path
                            "workingDirectory=@TargetDir@",// working-dir
                            "iconPath=@TargetDir@/comPortScanner.exe", "iconId=0",// icon
                            "description=Start comPortScanner");// description

        // Start menu shortcut for maintenance tool
        component.addOperation("CreateShortcut", 
                               "@TargetDir@/maintenancetool.exe", 
                               "@StartMenuDir@/comPortScanner-maintenance.lnk", 
                               "workingDirectory=@TargetDir@/comPortScanner");
    }
}
