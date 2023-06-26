# Keylogger en C para Windows

Este repositorio contiene un simple keylogger escrito en C para sistemas Windows. El keylogger registra las teclas presionadas por el usuario y las guarda en un archivo .MD.

## Contenido

El repositorio contiene los siguientes archivos:

- `keylogger3.c` - El código fuente en C del keylogger.
- `Keylogger.exe` - El ejecutable del keylogger.

## Cómo utilizar

Para ejecutar el keylogger:

1. Abra la línea de comandos o la terminal.
2. Navegue hasta el directorio que contiene el archivo `Keylogger.exe`.
3. Ejecute `Keylogger.exe`. No aparecerá ninguna ventana en su pantalla, ya que el keylogger está diseñado para funcionar en segundo plano.

El keylogger comenzará a registrar las teclas presionadas por el usuario. Las teclas se registran en un archivo llamado `keylogs.MD`, que se crea en el mismo directorio donde se ejecutó el archivo `Keylogger.exe`.

Para terminar la sesión del keylogger, simplemente presione la tecla `ESC`.

## Advertencias

**Este keylogger se proporciona solo con fines educativos. No se debe usar para actividades maliciosas. Recuerde que registrar las pulsaciones de teclas de alguien sin su consentimiento explícito es ilegal y éticamente incorrecto.**

Si decides utilizar este keylogger, asegúrate de tener el permiso del usuario cuyas pulsaciones de teclas estás registrando.

## Compilación

Para compilar el código fuente `keylogger3.c`, necesitarás un compilador C para Windows como GCC. Luego puedes usar el siguiente comando para compilar:
gcc keylogger3.c -o Keylogger.exe -mwindows


Este comando crea un archivo ejecutable `Keylogger.exe` a partir del código fuente que se ejecuta en segundo plano sin abrir el símbolo del sistema o cualquier otra ventana.
