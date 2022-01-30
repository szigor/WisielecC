#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menuPrinter(); //drukuje menu

void categoryPrinter(); //drukuje spis kategorii

void openReadFile(char filename[],char buf[]); //otwiera, wczytuje i zamyka dany plik

int choiceScanner(); //otwiera i wczytuje plik w zaleznosci od wyboru jezyka i kategorii

void wordPicker(int choices); //wybiera

void pattern(int g1, int g2, int n, char reader[], char hidden[],char hint[], int hintLength); //tok gry dla wprowadzonego slowa i kategorii

void polskiSport(); //gra w tej kategorii

void polskiZwierze(); //gra w tej kategorii

void niemieckiSport(); //gra w tej kategorii

void niemieckiZwierze(); //gra w tej kategorii

void angielskiSport(); //gra w tej kategorii

void angielskiZwierze(); //gra w tej kategorii

void wisielecPrinter(int mistakeCounter); //drukuje poszczegolne etapy powieszenia gracza

int randomNumber(int bound); //zwraca losowa liczbe w zakresie <1 - bound>

void updateRanking(char filename[]); //aktualizuje ranking

char readPolskiSport[100]; //slowa w tej kategorii
char readPolskiZwierze[100]; //slowa w tej kategorii
char readNiemieckiSport[100]; //slowa w tej kategorii
char readNiemieckiZwierze[100]; //slowa w tej kategorii
char readAngielskiSport[100]; //slowa w tej kategorii
char readAngielskiZwierze[100]; //slowa w tej kategorii
char rankingW[100]; //ranking wygranych
char rankingP[100]; //ranking przegranych

int mistakeCounter = 0; //ilosc niepoprawnych guessow
char guess = ' '; //zgadywana litera wprowadzana przez uzytkownika
int correct = 0; //ilosc zgadajacych sie liter w slowie
int correctCounter = 0;
int g1 = 0; //granica1 indeksow slow
int g2 = 0; //granica2 indeksow slow

int main() {
    menuPrinter();
    wordPicker(choiceScanner());
    return 0;
}

void pattern(int g1, int g2, int n, char reader[], char hidden[],char hint[], int hintLength) {

    while (mistakeCounter <= 5) {
        correct = 0;
        for (int i = g1; i <= g2; ++i) { //boks
            printf("%c", hidden[i - g1]);
        }

        correctCounter = 0;
        for (int i = g1; i <= g2; ++i) {
            if (hidden[i - g1] != '_') {
                ++correctCounter;
            }
        }
        if (correctCounter == n) {
            printf("\nBrawo, wygrales!");
            updateRanking("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\rankingW.txt");
            break;
        }

        printf("\nTwoj strzal:");
        scanf(" %c", &guess);
        if (guess == '!') {
            printf("\nPodpowiedz: ");
            for (int i = 0; i <= hintLength; ++i) {
                printf("%c", hint[i]);
            }
            printf("\n");
        }
        for (int i = g1; i <= g2; ++i) {
            if (guess == reader[i]) {
                hidden[i - g1] = guess;
                ++correct;
            }
        }
        if (correct == 0) {
            ++mistakeCounter;
            wisielecPrinter(mistakeCounter);
            printf("\n");
        }
        if (mistakeCounter == 6) {
            printf("\nNiestety przegrales :((");
            updateRanking("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\rankingP.txt");
            break;
        }
    }
}

void angielskiZwierze() {

    switch (randomNumber(3)) {
        case 1:
            printf("");
            char hidden[9] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
            char hint[] = "zielony";
            pattern(0, 8, 9, readAngielskiZwierze, hidden,hint,6);
            break;
        case 2:
            printf("");
            char hidden2[5] = {'_', '_', '_', '_', '_'};
            char hint2[] = "parkour";
            pattern(9, 13, 5, readAngielskiZwierze, hidden2,hint2,6);
            break;
        case 3:
            printf("");
            char hidden3[3] = {'_', '_', '_'};
            char hint3[] = "przyjaciel";
            pattern(14, 16, 3, readAngielskiZwierze, hidden3,hint3,9);
            break;
    }

}

void angielskiSport() {

    switch (randomNumber(3)) {
        case 1:
            printf("");
            char hidden[6] = {'_', '_', '_', '_', '_', '_'};
            char hint[] = "Manny Pacquiao";
            pattern(0, 5, 6, readAngielskiSport, hidden,hint,13);
            break;
        case 2:
            printf("");
            char hidden2[8] = {'_', '_', '_', '_', '_', '_', '_', '_'};
            char hint2[] = "wodny sport";
            pattern(6, 13, 8, readAngielskiSport, hidden2,hint2,10);
            break;
        case 3:
            printf("");
            char hidden3[8] = {'_', '_', '_', '_', '_', '_', '_', '_'};
            char hint3[] = "Camp nou";
            pattern(14, 21, 8, readAngielskiSport, hidden3,hint3,7);
            break;
    }

}

void niemieckiZwierze() {

    switch (randomNumber(3)) {
        case 1:
            printf("");
            char hidden[4] = {'_', '_', '_', '_'};
            char hint[] = "przyjaciel";
            pattern(0, 3, 4, readNiemieckiZwierze, hidden,hint,9);
            break;
        case 2:
            printf("");
            char hidden2[5] = {'_', '_', '_', '_', '_'};
            char hint2[] = "male zwierze domowe";
            pattern(4, 8, 5, readNiemieckiZwierze, hidden2,hint2,18);
            break;
        case 3:
            printf("");
            char hidden3[5] = {'_', '_', '_', '_', '_'};
            char hint3[] = "reiten";
            pattern(9, 13, 5, readNiemieckiZwierze, hidden3,hint3,5);
            break;
    }

}

void niemieckiSport() {

    switch (randomNumber(3)) {
        case 1:
            printf("");
            char hidden[9] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
            char hint[] = "Michael Phelps";
            pattern(0, 8, 9, readNiemieckiSport,hidden,hint,13);
            break;
        case 2:
            printf("");
            char hidden2[5] = {'_', '_', '_', '_', '_'};
            char hint2[] = "Muhammad Ali";
            pattern(9, 13, 5, readNiemieckiSport, hidden2,hint2,11);
            break;
        case 3:
            printf("");
            char hidden3[6] = {'_', '_', '_', '_', '_', '_'};
            char hint3[] = "kon";
            pattern(14, 19, 6, readNiemieckiSport, hidden3,hint3,2);
            break;
    }

}

void polskiZwierze() {

    switch (randomNumber(3)) {
        case 1:
            printf("");
            char hidden[3] = {'_', '_', '_'};
            char hint[] = "krol";
            pattern(0, 2, 3, readPolskiZwierze, hidden,hint,3);
            break;
        case 2:
            printf("");
            char hidden2[6] = {'_', '_', '_', '_', '_', '_'};
            char hint2[] = "chude nogi";
            pattern(3, 8, 6, readPolskiZwierze, hidden2,hint2,9);
            break;
        case 3:
            printf("");
            char hidden3[6] = {'_', '_', '_', '_', '_', '_'};
            char hint3[] = "bokser";
            pattern(9, 14, 6, readPolskiZwierze, hidden3,hint3,5);
            break;
    }
}

void polskiSport() {

    switch (randomNumber(3)) {
        case 1:
            printf("");
            char hidden[4] = {'_', '_', '_', '_'};
            char hint[] = "Mike Tyson";
            pattern(0, 3, 4, readPolskiSport, hidden, hint,9);
            break;
        case 2:
            printf("");
            char hint2[] = "Wilfredo Leon";
            char hidden2[9] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
            pattern(4, 12, 9, readPolskiSport, hidden2,hint2,12);
            break;
        case 3:
            printf("");
            char hint3[] = "zima";
            char hidden3[5] = {'_', '_', '_', '_', '_'};
            pattern(13, 17, 5, readPolskiSport, hidden3,hint3,3);
            break;
    }
}

void wordPicker(int choices) {

    switch (choices) {
        case 11:
            polskiSport();
            break;
        case 12:
            polskiZwierze();
            break;
        case 21:
            niemieckiSport();
            break;
        case 22:
            niemieckiZwierze();
            break;
        case 31:
            angielskiSport();
            break;
        case 32:
            angielskiZwierze();
            break;
    }
}

void openReadFile(char filename[],char buf[]) {
    FILE *f;
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Nie znaleziono pliku");
        exit(1);
    }
    while (!feof(f)) {
        fgets(buf, 100, f);
    }
    fclose(f);
}

int choiceScanner() {
    int languagePick;
    scanf("%d", &languagePick);

    switch (languagePick) {
        case 1: //polski jezyk

            categoryPrinter();
            int categoryPick1;
            scanf("%d", &categoryPick1);

            switch (categoryPick1) {
                case 1: //polskiSport
                    openReadFile("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\polskiSport.txt",readPolskiSport);
                    return 11;
                case 2: //polskiZwierze
                    openReadFile("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\polskiZwierze.txt",readPolskiZwierze);
                    return 12;
            }
            break;

        case 2: //niemiecki jezyk
            categoryPrinter();
            int categoryPick2;
            scanf("%d", &categoryPick2);

            switch (categoryPick2) {
                case 1: //niemieckiSport
                    openReadFile("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\niemieckiSport.txt",readNiemieckiSport);
                    return 21;
                case 2: //niemieckiZwierze
                    openReadFile("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\niemieckiZwierze.txt",readNiemieckiZwierze);
                    return 22;
            }
            break;

        case 3: //angielski jezyk
            categoryPrinter();
            int categoryPick3;
            scanf("%d", &categoryPick3);

            switch (categoryPick3) {
                case 1: //angielskiSport
                    openReadFile("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\angielskiSport.txt",readAngielskiSport);
                    return 31;
                case 2: //angielskiZwierze
                    openReadFile("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\angielskiZwierze.txt",readAngielskiZwierze);
                    return 32;
            }
            break;

        case 4: //wyswietla ranking
            openReadFile("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\rankingW.txt",rankingW);
            openReadFile("C:\\Users\\minec\\CLionProjects\\Iwisielec\\txts\\rankingP.txt",rankingP);
            printf("\n\nWygrane: %c%c%c",rankingW[0], rankingW[1], rankingW[2]);
            printf("\nPrzegrane: %c%c%c",rankingP[0], rankingP[1], rankingP[2]);
            break;
    }
}

int randomNumber(int bound) {
    srand(time(NULL));
    return rand() % (bound) + 1;
}

void updateRanking(char filename[]) {
    int liczba;
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nie znaleziono pliku");
        exit(1);
    }
    fscanf(file,"%d",&liczba);

    file = fopen(filename, "w");
    fprintf(file,"%d",++liczba);
    fclose(file);
}

void wisielecPrinter(int mistakeCounter) {
    switch (mistakeCounter) {
        case 1:
            printf("  _ _ _  \n |     | \n |     | \n       |\n       |\n       |\n       |\n       |\n     __|__ ");
            break;
        case 2:
            printf("  _ _ _  \n |     | \n |     | \n( )    |\n       |\n       |\n       |\n       |\n     __|__ ");
            break;
        case 3:
            printf("  _ _ _  \n |     | \n |     | \n( )    |\n/      |\n       |\n       |\n       |\n     __|__ ");
            break;
        case 4:
            printf("  _ _ _  \n |     | \n |     | \n( )    |\n/ \\    |\n       |\n       |\n       |\n     __|__ ");
            break;
        case 5:
            printf("  _ _ _  \n |     | \n |     | \n( )    |\n/|\\    |\n |     |\n |     |\n       |\n     __|__ ");
            break;
        case 6:
            printf("  _ _ _  \n |     | \n |     | \n( )    |\n/|\\    |\n |     |\n |     |\n/ \\    |\n     __|__ ");
            break;
    }
}

void categoryPrinter() {
    printf("--- Kategoria ---\n");
    printf("1. Sport\n");
    printf("2. Zwierze\n");
}

void menuPrinter() {
    printf("--- Wisielec ---\n");
    printf("\n--- Zasady gry ---\n");
    printf("- tylko male litery\n");
    printf("- bez polskich znakow\n");
    printf("- wpisywanie liter pojedynczo\n");
    printf("- \"!\" daje podpowiedz do hasla\n");
    printf("- 6 prob\n");
    printf("\n--- Menu gry ---\n");
    printf("-- jezyk hasel --\n");
    printf("1. polski\n");
    printf("2. niemiecki\n");
    printf("3. angielski\n");
    printf("\n4. wyswietl ranking\n");
}
