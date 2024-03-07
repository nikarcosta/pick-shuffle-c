#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int numGuesses;
char guessedLetters[26];
char words[MAX_WORDS][MAX_WORD_LENGTH];
int numWords = 0;

void readDatabaseFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%s", words[numWords]) == 1)
    {
        numWords++;
    }

    fclose(file);
}

void shuffleWords()
{
    srand(time(NULL));
    for (int i = numWords - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

char *getRandomWord()
{
    int randomIndex = rand() % numWords;
    return words[randomIndex];
}

int main()
{
    readDatabaseFile("word_list.txt");
    shuffleWords();

    char *wordToGuess = getRandomWord();

    printf("Random word selected: %s\n", wordToGuess);

    return 0;
}