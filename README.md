Ready for compining, if you want to quick here is the code to put in .vscode/tasks.json

```
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: g++.exe build active file",
			"command": "\"C:/Users/alexg/Desktop/GCC/winlibs-x86_64-mcf-seh-gcc-13.2.0-llvm-16.0.6-mingw-w64ucrt-11.0.1-r2/mingw64/bin/g++.exe\"",
			"args": [
				"-g",
				"-std=c++17",
				"-I${workspaceFolder}/include",
				"-L${workspaceFolder}/lib",
				"${workspaceFolder}/src/*.cpp",
				"${workspaceFolder}/src/glad.c",
				"-lglfw3dll",
				"-o",
				"${workspaceFolder}/build.exe"
			],
			"options": {
				"cwd": "${workspaceFolder}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "compiler: C:/Users/alexg/Desktop/GCC/winlibs-x86_64-mcf-seh-gcc-13.2.0-llvm-16.0.6-mingw-w64ucrt-11.0.1-r2/mingw64/bin/g++.exe"
		}
	]
}
```
