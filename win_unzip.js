 var objShell = new ActiveXObject("shell.application");
 var fso = new ActiveXObject("Scripting.FileSystemObject");

 var objFolder = objShell.NameSpace(fso.getParentFolderName(WScript.ScriptFullName) + "\\build");
 var objInput = objShell.NameSpace(fso.getParentFolderName(WScript.ScriptFullName) + "\\"+ WScript.arguments(0));

 objFolder.CopyHere(objInput.items());