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
                               "iconPath=@TargetDir@/appIcon.ico");
							   
		// Start menu shortcut for readme
        component.addOperation("CreateShortcut", 
                               "@TargetDir@/readme.md", 
                               "@StartMenuDir@/readme.lnk", 
                               "workingDirectory=@TargetDir@/comPortScanner");
		
		// Start menu shortcut for maintenance tool
        component.addOperation("CreateShortcut", 
                               "@TargetDir@/MaintenanceTool.exe", 
                               "@StartMenuDir@/comPortScanner-maintenance.ink", 
                               "workingDirectory=@TargetDir@/comPortScanner");

       // Desktop Shortcut
       component.addOperation("CreateShortcut", 
                              "@TargetDir@/comPortScanner.exe",
                              "@DesktopDir@comPortScanner.lnk",
                              "workingDirectory=@TargetDir@/comPortScanner", 
                              "iconPath=@TargetDir@/comPortScanner.ico");
    }
}
