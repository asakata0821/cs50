#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int isJPEG(BYTE buffer[]);

int main(int argc, char *argv[])
{
    //start
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    char filename[8];
    FILE *img;
    int i = 0;

    while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        if (isJPEG(buffer) == 1)
        {
            if (i != 0)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", i++);
            img = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
        else if (i > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }
    fclose(file);
    fclose(img);
}

int isJPEG(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}