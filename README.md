# Documents

- [Working with Shell Extensions](https://docs.microsoft.com/en-us/windows/desktop/shell/shell-exts)

- [Codeproject.com - How to Write Windows Shell Extension with .NET Languages](https://www.codeproject.com/Articles/174369/How-to-Write-Windows-Shell-Extension-with-NET-Lang)

- [Codeproject.com - .NET Shell Extensions - Shell Context Menus](https://www.codeproject.com/Articles/512956/NET-Shell-Extensions-Shell-Context-Menus)

- [Stackoverflow.com - How to add a menu item in Windows right-click menu](https://stackoverflow.com/questions/18309300/how-to-add-a-menu-item-in-windows-right-click-menu)

- [10 Best Shortcuts to Add to Your Right-Click Menu](https://www.makeuseof.com/tag/10-best-shortcuts-add-right-click-menu/)

- [How to Add & Remove Entries from the Windows Right-Click Menu](https://www.makeuseof.com/tag/how-to-add-remove-entries-from-the-right-click-menu/)

# Repos

- [NirSoft - ShellMenuView](http://www.nirsoft.net/utils/shell_menu_view.html) - Disable/enable context menu items of Explorer

- [Babun - Github](https://github.com/babun/babun)

- [Babun - Home - A Windows shell Base on Cygwin](http://babun.github.io/)

- [ConEmu - Github](https://github.com/Maximus5/ConEmu)

- [ConEmu - Home - A Windows console emulator](https://conemu.github.io/)

- [CMDer - Github](https://github.com/cmderdev/cmder)

- [Cmder - Gist - Context Right-Click Menu for Windows](https://gist.github.com/jojobyte/66c8346ed8948b9b395f)

- [CMDer - Home - A Windows console emulator based on ConEmu](http://cmder.net/)

# Expand right-click menu on background

    SET REGPATH=HKEY_CLASSES_ROOT\Directory\Background\shell\CMDShell
    REG ADD "%REGPATH%" /ve /d "CMD Prompt" /f
    REG ADD "%REGPATH%\command" /ve /d "cmd.exe /K CD %%1" /f

# Expand right-click menu on folder

    SET REGPATH=HKEY_CLASSES_ROOT\Folder\shell
    REG ADD "%REGPATH%\zzdos" /ve /d "CMD Prompt" /f
    REG ADD "%REGPATH%\zzdos\command" /ve /d "cmd.exe /K CD %%1" /f
    REM
    REG ADD "%REGPATH%\zzexplorer" /ve /d "Open in new window" /f
    REG ADD "%REGPATH%\zzexplorer\command" /ve /d "explorer.exe /e,/root,%%L" /f

# Expand right-click menu

    Windows Registry Editor Version 5.00

    [HKEY_CLASSES_ROOT\Directory\shell\OpenCmdHere]
    @="Open CMD Here"
    "Icon"="cmd.exe"

    [HKEY_CLASSES_ROOT\Directory\shell\OpenCmdHere\command]
    @="cmd.exe /s /k pushd "%V""

    [HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHere]
    @="Open CMD Here"
    "Icon"="cmd.exe"

    [HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHere\command]
    @="cmd.exe /s /k pushd \"%V\""

    [HKEY_CLASSES_ROOT\Drive\shell\OpenCmdHere]
    @="Open CMD Here"
    "Icon"="cmd.exe"

    [HKEY_CLASSES_ROOT\Drive\shell\OpenCmdHere\command]
    @="cmd.exe /s /k pushd \"%V\""

    [HKEY_CLASSES_ROOT\LibraryFolder\background\shell\OpenCmdHere]
    @="Open CMD Here"
    "Icon"="cmd.exe"

    [HKEY_CLASSES_ROOT\LibraryFolder\background\shell\OpenCmdHere\command]
    @="cmd.exe /s /k pushd \"%V\""

**Previous Version**

    Windows Registry Editor Version 5.00

    [HKEY_CLASSES_ROOT\Directory\shell\OpenCmdHere]
    @="Open CMD Here"
    "Icon"="cmd.exe"

    [HKEY_CLASSES_ROOT\Directory\shell\OpenCmdHere\command]
    @="PowerShell -windowstyle hidden -Command \"Start-Process cmd.exe -ArgumentList '/s,/k, pushd,%V' -Verb RunAs\""

    [HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHere]
    @="Open CMD Here"
    "Icon"="cmd.exe"

    [HKEY_CLASSES_ROOT\Directory\Background\shell\OpenCmdHere\command]
    @="cmd.exe -noexit -command Set-Location -literalPath '%V'"

    [HKEY_CLASSES_ROOT\Drive\shell\OpenCmdHere]
    @="Open CMD Here"
    "Icon"="cmd.exe"

    [HKEY_CLASSES_ROOT\Drive\shell\OpenCmdHere\command]
    @="PowerShell -windowstyle hidden -Command \"Start-Process cmd.exe -ArgumentList '/s,/k, pushd,%V' -Verb RunAs\""

    [HKEY_CLASSES_ROOT\LibraryFolder\background\shell\OpenCmdHere]
    @="Open CMD Here"
    "Icon"="cmd.exe"

    [HKEY_CLASSES_ROOT\LibraryFolder\background\shell\OpenCmdHere\command]
    @="PowerShell -windowstyle hidden -Command \"Start-Process cmd.exe -ArgumentList '/s,/k, pushd,%V' -Verb RunAs\""

# 1. Edit with Vim

- [Mentioned GvimExt code on Github](https://github.com/vim/vim/tree/master/src/GvimExt)

- [Adding Vim to MS-Windows File Explorer Menu](http://vim.wikia.com/wiki/Adding_Vim_to_MS-Windows_File_Explorer_Menu)

- [Right click in Windows Explorer to open gvim in explorer mode](http://vim.wikia.com/wiki/Right_click_in_Windows_Explorer_to_open_gvim_in_explorer_mode)

- [Add Vim to the Windows Explorer context menu](http://vim.wikia.com/wiki/Add_Vim_to_the_Windows_Explorer_context_menu)

# 2. Cygwin Bash Here

- [Mintty official doc](https://github.com/mintty/mintty/wiki/Tips#starting-in-a-particular-directory)

**The `chere` command - official tool**

- [Stackoverflow - Open Cygwin at a specific folder](https://stackoverflow.com/questions/9637601/open-cygwin-at-a-specific-folder)

Open a Cygwin terminal **as Administrator** and type the command: `chere -i -t mintty -s bash`

**Cygwin-Bash-Here Repo**

- [Cygwin-Bash-Here on Github](https://github.com/olegcherr/Cygwin-Bash-Here)

How does it work? It adds a simple command to `HKCR\Directory\shell` and `HKCR\Directory\Background\shell`:
    
    C:\cygwin\bin\mintty.exe --dir "%V" -e /bin/env CHERE_INVOKING=1 /bin/bash --login

**Open cygwin bash shell from Windows context menu using Windows Registry Table**

- [Mentioned doc](http://shitwefoundout.com/wiki/Open_cygwin_bash_shell_from_Windows_context_menu)

#### **DIRECTORY** : Add option in the context menu for a directory

    [HKEY_CLASSES_ROOT\Directory\shell\bash]
    @="Open Bash Here"
    [HKEY_CLASSES_ROOT\Directory\shell\bash\command]
    @="c:\\cygwin\\bin\\mintty.exe bash --login -i -c 'cd \"`cygpath \"$*\"`\";bash' bash %L"

#### **DRIVE** : Add option in the context menu for a drive

    [HKEY_CLASSES_ROOT\Drive\shell\bash]
    @="Open Bash Here"
    [HKEY_CLASSES_ROOT\Drive\shell\bash\command]
    @="c:\\cygwin\\bin\\mintty.exe bash --login -i -c 'cd \"`cygpath \"$*\"`\";bash' bash %L"

#### **BACKGROUND** : Add option in the background context menu - This works in Windows 7, but requires the `chere` package

    [HKEY_CLASSES_ROOT\Directory\Background\shell\bash]
    @="Open Bash Here"
    [HKEY_CLASSES_ROOT\Directory\Background\shell\bash\command]
    @="c:\\cygwin\\bin\\mintty.exe -i /Cygwin-Terminal.ico -e /bin/xhere /bin/bash.exe"

#### **BACKGROUND** : Add option in the background context menu - This works in Windows 8, but **DONOT** requires the `chere` package

    [HKEY_CLASSES_ROOT\Directory\Background\shell\bash]
    @="Open Bash Here"
    [HKEY_CLASSES_ROOT\Directory\Background\shell\bash\command]
    @="c:\\cygwin\\bin\\mintty.exe -i /Cygwin-Terminal.ico bash -i -c 'cd \"`cygpath \"%V\"`\";bash'

#### **BACKGROUND-OF-LIBRARY** : Add option in the background context menu in the Library folders
    
    [HKEY_CLASSES_ROOT\LibraryFolder\Background\shell]
    [HKEY_CLASSES_ROOT\LibraryFolder\Background\shell\bash]
    @="Open Bash Here"
    [HKEY_CLASSES_ROOT\Directory\Background\shell\bash\command]
    @="c:\\cygwin\\bin\\mintty.exe -i /Cygwin-Terminal.ico bash -i -c 'cd \"`cygpath \"%V\"`\";bash'

# 3. Git Bash here

- [Can not find "Git Bash Here" in context menu](https://github.com/git-for-windows/git/issues/1229)

**Version 1** - Legacy command - Windows XP etc.

    Windows Registry Editor Version 5.00
    [HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\background\shell\git_gui]
    @="Git &GUI Here"
    "Icon"="C:\\Program Files\\Git\\cmd\\git-gui.exe"
    [HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\background\shell\git_gui\command]
    @="\"C:\\Program Files\\Git\\cmd\\git-gui.exe\" \"--working-dir\" \"%v.\""

    Windows Registry Editor Version 5.00
    [HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\background\shell\git_shell]
    @="Git Ba&sh Here"
    "Icon"="C:\\Program Files\\Git\\git-bash.exe"
    [HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\background\shell\git_shell\command]
    @="\"C:\\Program Files\\Git\\git-bash.exe\" \"--cd=%v.\""

**Version 2** - Legacy command - Windows XP etc.

    Windows Registry Editor Version 5.00
    [HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\shell\git_shell\command]
    @="\"C:\\Program Files\\Git\\git-bash.exe\" \"--cd=%1\""
    [HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\shell\git_gui\command]
    @="\"C:\\Program Files\\Git\\cmd\\git-gui.exe\" \"--working-dir\" \"%1\""

    Windows Registry Editor Version 5.00
    [HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\Background\shell\git_shell\command]
    @="\"C:\\Program Files\\Git\\git-bash.exe\" \"--cd=%v.\""
    [HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Directory\Background\shell\git_gui\command]
    @="\"C:\\Program Files\\Git\\cmd\\git-gui.exe\" \"--working-dir\" \"%v.\""

**Version 3**

    Windows Registry Editor Version 5.00
    [HKEY_CLASSES_ROOT\LibraryFolder\background\shell\git_gui]
    @="Git &GUI Here"
    "Icon"="C:\\Program Files\\Git\\cmd\\git-gui.exe"
    [HKEY_CLASSES_ROOT\LibraryFolder\background\shell\git_gui\command]
    @="\"C:\\Program Files\\Git\\cmd\\git-gui.exe\" \"--working-dir\" \"%v.\""
    
    [HKEY_CLASSES_ROOT\LibraryFolder\background\shell\git_shell]
    @="Git Ba&sh Here"
    "Icon"="C:\\Program Files\\Git\\git-bash.exe"
    [HKEY_CLASSES_ROOT\LibraryFolder\background\shell\git_shell\command]
    @="\"C:\\Program Files\\Git\\git-bash.exe\" \"--cd=%v.\""

