Ready for compining, if you want to quick here is the code to put in .vscode/tasks.json

```
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: g++.exe build active file",
			"command": "\"C:/path/to/copmiler\"",
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
			"detail": "compiler: C:/path/to/copmiler"
		}
	]
}
```
