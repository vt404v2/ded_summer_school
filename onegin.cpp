#include "onegin.h"

int main()
{
    const char *filename = "onegin.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == nullptr)
    {
        perror("Unable to open file!");
        exit(1);
    }
    Text text = readFile(fp);
    fclose(fp);

    qSort(text.lines, text.length, compareStr);
    printFile(&text, "sorted.txt");

    qSort(text.lines, text.length, compareStrBack);
    printFile(&text, "sorted_back.txt");

    size_t numParts = 3;
    Poem poem = {generatePoem(&text, numParts), numParts, ShakespeareNumLines};

    printPoem(&poem);

    printFile(&text, "not_sorted.txt", false);
    //TODO:free memory
    return 0;
}
