## Proceso de instalación
### Windows

1. Descargar MinGW, es un compilador de C y C++ para Windows
2. Instalarlo, para ello marquen las siguientes casillas:
    * `mingw-developer-toolkit`
    * `mingw32-base`
    * `mingw32-gcc-g++`
    * `msys-base`
3. En la pestaña `Installation` en la esquina superior izquierda hagan clic en *Apply changes*, por favor no utilicen `clang` u otro compilador de *C/C++*, la librería `avr-gcc` que van a utilizar es parte de la colleción *GNU*, por lo que no funcionará.
4. Clonar o descargar este repositorio.
5. Abrir PowerShell normalmente (NO LO ABRAN COMO ADMINISTRADOR)
6. **Corran el siguente comando en PowerShell:**

```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

7. Corran el *script* `INSTALL.ps1` (solo escriban el nombre del archivo en PowerShell), por defecto estarán en la carpeta raíz, para moverse a la carpeta en donde está el *script* pueden utilizar el comando `cd`, por ejemplo:

```powershell
cd .\Downloads\arduino-principios\ # aqui se estarian metiendo a la carpeta arduino-c en descargas
```