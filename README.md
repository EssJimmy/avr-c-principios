# Introducción
Se preguntarán porqué existe este repo, en mi semestre fue un relajo entenderle a ensamblador, y ya que se está quedando más obsoleto que otra cosa, tomé en mis manos el actualizar un poco el material del curso, haciendo *scripts* fáciles que deberían funcionar en cualquier situación, hay dos *scripts* por sistema operativo, excepto en el caso de *Linux*, donde existe un tercer *script* que pueden utilizar junto con `grep` para averiguar el puerto al que conectaron su arduino.

Esto también sirve para facilitar el proceso de instalación de las dependencias, para Windows se instalará `scoop` y para MacOS `homebrew` que realizarán la función *package manager* de *Linux*, no se preocupen, en los *scripts* ya se instalarán automáticamente.

Principios de Mecatrónica es una materia que disfrute mucho, con excepciones en algunos casos, por lo que me gustaría que todos la disfruten tanto como yo pero sin sufrir tanto como yo.

Mucha suerte :)

# Proceso de instalación
## Windows

1. Clonar o descargar este repositorio.
2. Abrir PowerShell normalmente (NO LO ABRAN COMO ADMINISTRADOR)
3. **Corran el siguente comando en PowerShell:**

```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```
4. Si ya tienen una instalación de MinGW configurada, abran el archivo `INSTALL.ps1` y quiten desde la línea 5 hasta la 18.
5. Corran el *script* `INSTALL.ps1` (solo escriban el nombre del archivo en PowerShell y denle a <kbd>tab</kbd>), por defecto estarán en la carpeta raíz, para moverse a la carpeta en donde está el *script* pueden utilizar el comando `cd`, por ejemplo:

```powershell
cd .\Downloads\arduino-principios\ # aqui se estarian metiendo a la carpeta arduino-c en descargas
```
6. Listo, ahora pueden utilizar C con arduino, traten de hacer el ejemplo `blink.c` dentro de la carpeta `examples`, para correr el archivo pueden utilizar el otro *script* dentro de la carpeta, `MAKE.ps1`

## Linux/MacOS

**Nota: Si no tienen XCode en su Mac, descarguénlo antes de comenzar, lo pueden hacer directamente desde el sitio de Apple para desarrolladores**

1. Corran el siguiente comando (si estan el linux, cambien el package manager, por defecto está *pacman*):

```bash
cd linux/macos 
chmod a+x INSTALL.sh 
sudo ./INSTALL.sh
```
2. Les debe de pedir una contraseña, si su laptop no tiene contraseña solo denle <kbd>enter</kbd>.
3. Listo, ahora pueden utilizar C con arduino

# Cargar código en el Arduino
1. Utilizaremos el *script* `MAKE.ps1`, funciona de la misma manera para todos los sistemas operativos (en *linux* tendrán que abrir el puerto de manera manual)
2. Conecten el Arduino a la computadora y averigüen el puerto al que se conectó, debe ser algo por el estilo de `COM#` o `dev/ttyACM#`
3. Una vez que conozcan el puerto pueden utilizar el siguiente comando en la terminal (recuerden estar en la carpeta donde se encuentra su código)

```bash
../os/MAKE.sh FILE PORT # reemplacen FILE por el nombre del archivo
# SIN EXTENSION, y PORT por el puerto que ya encontraron
```

4. Les deberán salir múltiples líneas donde al final deberá decir `device flashed sucessfully`, se crearan dos archivos que se borrarán automáticamente, son el código compilado y el hexadecimal, no afectan en mucho

## Ejemplos
### Linux/MacOS

```bash
../linux/MAKE.sh blink dev/ttyACM0
```

### Windows
```powershell
..\windows\MAKE.sh blink COM4
```

5. Eso es todo, prueben con el archivo `blink.c` en la carpeta `examples`

¡Mucho éxito en el curso :)!
