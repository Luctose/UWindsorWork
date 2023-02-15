#include <stdio.h>
#include <sqlite3.h>
#include <wchar.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Prompts user then returns input from the user
int promptInput();

// Select kanji by it's meaning in english
void kanjiByMeaning(sqlite3 * db);

// Select kanji by it's kunyomi pronunciation
void kanjiByKunyomi(sqlite3 * db);

// Select kanji by it's onyomi pronunciation
void kanjiByOnyomi(sqlite3 * db);

// Select kanji by it's stroke number
void kanjiByStrokes(sqlite3 * db);

// Select kanji by it's JLPT Level
void kanjiByLevel(sqlite3 * db);

// Select the kunyomi pronunciation of a kanji
void kunyomiOfKanji(sqlite3 * db);

// Select the onyomi pronunciation of a kanji
void onyomiOfKanji(sqlite3 * db);

// Select the meaning of a kanji
void meaningOfKanji(sqlite3 * db);

// Select the stroke number of a kanji
void strokeOfKanji(sqlite3 * db);

// Select any radicals of a kanji
void radicalsOfKanji(sqlite3 * db);

// Select an example sentence of a kanji
void kanjiExampleSentence(sqlite3 * db);

// Callback for SELECT statements
static int callback(void* data, int argc, char** argv, char** ColName);

int main(int argc, char* argv[]){

    setlocale(LC_ALL, "en_US.UTF-8");

    sqlite3* db;
    int c;
    c = sqlite3_open_v2("./MyKanjis.db", &db, SQLITE_OPEN_READWRITE, NULL);
    if(c != SQLITE_OK){
        printf("Can’t open database! %s\n", sqlite3_errmsg(db));
        return(0);
    } else{
        printf("Connect to database successfully.\n");
    }
    printf("Welcome to My Kanji database.\n");

    int input = 0;
    
    do{
        input = promptInput();

        if(input == 1){
            kanjiByMeaning(db);

        }else if(input == 2){
            kanjiByKunyomi(db);

        }else if(input == 3){
            kanjiByOnyomi(db);

        }else if(input == 4){
            kanjiByStrokes(db);

        }else if(input == 5){
            kanjiByLevel(db);

        }else if(input == 6){
            kunyomiOfKanji(db);

        }else if(input == 7){
            onyomiOfKanji(db);

        }else if(input == 8){
            meaningOfKanji(db);

        }else if(input == 9){
            strokeOfKanji(db);

        }else if(input == 10){
            radicalsOfKanji(db);

        }else if(input == 11){
            kanjiExampleSentence(db);

        }else if(input == 0){
            printf("Bye\n");
        
        }else{
            printf("Invalid input\n");
        }
    }while(input);

    sqlite3_close(db);
}

int promptInput(){
    char str[5];
    int ans;
    printf("Please select an option:\n"
    "0) Exit\n"
    "1) Lookup kanji by its meaning in English\n"
    "2) Lookup kanji(s) by its kunyomi\n"
    "3) Lookup kanji(s) by its onyomi\n"
    "4) Lookup kanji by the number of strokes\n"
    "5) Lookup kanji by its level for the JLPT (N5 - N1)\n"
    "6) What is a kanjis kunyomi\n"
    "7) What is a kanjis onyomi\n"
    "8) What is a kanjis meaning\n"
    "9) How many strokes a kanji has\n"
    "10) What parts or radicals a kanji is made up of\n"
    "11) What is an example of the kanji in a sentence\n"
    "-> ");

    scanf("%d", &ans);
    // Exhaust input buffer
    int flush;
    while (((flush = getchar())) != '\n' && flush != EOF);
    return ans;
}

void kanjiByMeaning(sqlite3 * db){
    char * errMsg = 0;

    char meaning[100];

    printf("Enter the kanji's meaning: ");
    scanf("%s", meaning);

    char sql[] = "SELECT Character " \
        "FROM Kanji " \
        "WHERE Unicode = (SELECT KanjiId " \
        "FROM KanjiMeaning " \
        "WHERE KanjiMeaning.MeaningId = (SELECT Id " \
        "FROM Meaning " \
        "WHERE Meaning.Means = '%s') " \
        ");";

    char query[200];
    sprintf(query, sql, meaning);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void kanjiByKunyomi(sqlite3 * db){
    char * errMsg = 0;

    char kunyomi[100];

    printf("Enter the kanji's kunyomi: ");
    scanf("%s", kunyomi);

    char sql[] = "SELECT Character " \
            "FROM Kanji " \
            "WHERE Unicode = (SELECT KanjiId " \
            "FROM KanjiKunyomi " \
            "WHERE KanjiKunyomi.KunyomiId = (SELECT Id " \
            "FROM Kunyomi " \
            "WHERE Kunyomi.Romaji = '%s' OR " \
            "Kunyomi.Hiragana = '%s' OR Kunyomi.Katakana = '%s') " \
            ");";

    char query[250];
    sprintf(query, sql, kunyomi, kunyomi, kunyomi);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void kanjiByOnyomi(sqlite3 * db){
    char * errMsg = 0;

    char onyomi[100];

    printf("Enter the kanji's onyomi: ");
    scanf("%s", onyomi);

    char sql[] = "SELECT Character " \
                "FROM Kanji " \
                "WHERE Unicode = (SELECT KanjiId " \
                "FROM KanjiOnyomi " \
                "WHERE KanjiOnyomi.OnyomiId = (SELECT Id " \
                "FROM Onyomi " \
                "WHERE Onyomi.Romaji = '%s' OR " \
                "Onyomi.Hiragana = '%s' OR Onyomi.Katakana = '%s') " \
                ");";

    char query[250];
    sprintf(query, sql, onyomi, onyomi, onyomi);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void kanjiByStrokes(sqlite3 * db){
    char * errMsg = 0;

    int stroke;

    printf("Enter the kanji's stroke number: ");
    scanf("%d", &stroke);

    char sql[] = "SELECT Character " \
                "FROM Kanji " \
                "WHERE StrokeId = (SELECT Id " \
                "FROM Stroke " \
                "WHERE Stroke.Number = %d " \
                ");";
    
    char query[200];
    sprintf(query, sql, stroke);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void kanjiByLevel(sqlite3 * db){
    char * errMsg = 0;

    char level[5];

    printf("Enter the kanji's JLPT level: ");
    scanf("%s", level);

    char sql[] = "SELECT Character " \
                "FROM Kanji " \
                "WHERE JlptLevel = '%s';";

    char query[100];
    sprintf(query, sql, level);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void kunyomiOfKanji(sqlite3 * db){
    char * errMsg = 0;

    char kanji[5];

    printf("Enter a kanji: ");
    scanf("%s", kanji);

    char sql[] = "SELECT Romaji " \
                "FROM Kunyomi " \
                "WHERE Kunyomi.Id = (SELECT KunyomiId " \
                "From KanjiKunyomi " \
                "WHERE KanjiKunyomi.KanjiId = (SELECT Unicode " \
                "FROM Kanji " \
                "WHERE Kanji.Character = '%s') " \
                ");";

    char query[250];
    sprintf(query, sql, kanji);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void onyomiOfKanji(sqlite3 * db){
    char * errMsg = 0;

    char kanji[5];

    printf("Enter a kanji: ");
    scanf("%s", kanji);

    char sql[] = "SELECT Romaji " \
                "FROM Onyomi " \
                "WHERE Onyomi.Id = (SELECT OnyomiId " \
                "From KanjiOnyomi " \
                "WHERE KanjiOnyomi.KanjiId = (SELECT Unicode " \
                "FROM Kanji " \
                "WHERE Kanji.Character = '%s') " \
                ");";

    char query[250];
    sprintf(query, sql, kanji);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void meaningOfKanji(sqlite3 * db){
    char * errMsg = 0;

    char kanji[5];

    printf("Enter a kanji: ");
    scanf("%s", kanji);

    char sql[] = "SELECT Means " \
                "FROM Meaning " \
                "WHERE Meaning.Id = (SELECT MeaningId " \
                "FROM KanjiMeaning " \
                "WHERE KanjiMeaning.KanjiId = (SELECT Unicode " \
                "FROM Kanji " \
                "WHERE Kanji.Character = '%s') " \
                ");";
    
    char query[250];
    sprintf(query, sql, kanji);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void strokeOfKanji(sqlite3 * db){
    char * errMsg = 0;

    char kanji[5];

    printf("Enter a kanji: ");
    scanf("%s", kanji);

    char sql[] = "SELECT Number " \
                "FROM Stroke " \
                "WHERE Stroke.Id = (SELECT StrokeId " \
                "From Kanji " \
                "WHERE Kanji.Character = '%s' " \
                ");";

    char query[250];
    sprintf(query, sql, kanji);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void radicalsOfKanji(sqlite3 * db){
    char * errMsg = 0;

    char kanji[5];

    printf("Enter a kanji: ");
    scanf("%s", kanji);

    char sql[] = "SELECT RadicalKanji " \
                "FROM AreMadeOfKanji " \
                "WHERE AreMadeOfKanji.LargeKanji = (SELECT Unicode " \
                "FROM Kanji " \
                "WHERE Kanji.Character = '%s' " \
                ");";

    char query[250];
    sprintf(query, sql, kanji);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void kanjiExampleSentence(sqlite3 * db){
    char * errMsg = 0;

    char kanji[5];

    printf("Enter a kanji: ");
    scanf("%s", kanji);

    char sql[] = "SELECT Sentence " \
                "FROM Examples " \
                "WHERE Examples.Id = (SELECT ExampleId " \
                "FROM KanjiExamples " \
                "WHERE KanjiExamples.KanjiId = (SELECT Unicode " \
                "From Kanji " \
                "WHERE Kanji.Character = '%s') " \
                ");";

    char query[250];
    sprintf(query, sql, kanji);

    int r = sqlite3_exec(db, query, callback, 0, &errMsg);

    if(r != SQLITE_OK){
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

static int callback(void* data, int argc, char** argv, char** ColName){

    for(int i = 0; i < argc; i++){
        printf("%s = %s\n", ColName[i], argv[i]);
    }

    return 0;
}