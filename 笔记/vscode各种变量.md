# 文件相关

* `${workspaceRoot}` 当前打开的文件夹的绝对路径+文件夹的名字
* `${workspaceRootFolderName}`   当前打开的文件夹的名字
* `${file}` 当前打开正在编辑的文件名，包括绝对路径，文件名，文件后缀名
* `${relativeFile}` 从当前打开的文件夹到当前打开的文件的路径
  * 如：当前vscode打开的是`test`文件夹，当前的打开的是main.c，并有`test / first / second / main.c`那么此变量代表的是  `first / second / main.c`
* `${fileBasename}` 当前打开的文件名+后缀名，不包括路径
* `${fileBasenameNoExtension}` 当前打开的文件的文件名，不包括路径和后缀名
* `${fileDirname}` 当前打开的文件所在的绝对路径，不包括文件名
* `${fileExtname} `当前打开的文件的后缀名
* `${cwd}` the task runner's current working directory on startup
* `${lineNumber}` 当前打开的文件，光标所在的行数