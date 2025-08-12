#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 100

typedef struct {
    char *keyword;
    int spam_count;
    int not_spam_count;
} Keyword;

Keyword keywords[MAX_KEYWORDS];
int keyword_count = 0;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
}

void add_keyword(const char *keyword, int spam_count, int not_spam_count) {
    if (keyword_count >= MAX_KEYWORDS) return;
    keywords[keyword_count].keyword = strdup(keyword);
    keywords[keyword_count].spam_count = spam_count;
    keywords[keyword_count].not_spam_count = not_spam_count;
    keyword_count++;
}

int classify_text(const char *text) {
    char temp_text[1024];
    strcpy(temp_text, text);
    to_lowercase(temp_text);

    int spam_score = 0, not_spam_score = 0;
    char *word = strtok(temp_text, " ");

    while (word != NULL) {
        for (int i = 0; i < keyword_count; i++) {
            if (strcmp(word, keywords[i].keyword) == 0) {
                spam_score += keywords[i].spam_count;
                not_spam_score += keywords[i].not_spam_count;
            }
        }
        word = strtok(NULL, " ");
    }

    return spam_score > not_spam_score ? 1 : 0;
}

int main() {
    add_keyword("free", 5, 1);
    add_keyword("winner", 6, 2);
    add_keyword("prize", 4, 3);

    const char *text = "Congratulations! You are a winner of a free prize.";
    int result = classify_text(text);
    printf(result ? "Spam\n" : "Not Spam\n");
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 100

typedef struct {
    char *keyword;
    int spam_count;
    int not_spam_count;
} Keyword;

Keyword keywords[MAX_KEYWORDS];
int keyword_count = 0;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
}

void add_keyword(const char *keyword, int spam_count, int not_spam_count) {
    if (keyword_count >= MAX_KEYWORDS) return;
    keywords[keyword_count].keyword = strdup(keyword);
    keywords[keyword_count].spam_count = spam_count;
    keywords[keyword_count].not_spam_count = not_spam_count;
    keyword_count++;
}

int classify_text(const char *text) {
    char temp_text[1024];
    strcpy(temp_text, text);
    to_lowercase(temp_text);

    int spam_score = 0, not_spam_score = 0;
    char *word = strtok(temp_text, " ");

    while (word != NULL) {
        for (int i = 0; i < keyword_count; i++) {
            if (strcmp(word, keywords[i].keyword) == 0) {
                spam_score += keywords[i].spam_count;
                not_spam_score += keywords[i].not_spam_count;
            }
        }
        word = strtok(NULL, " ");
    }

    return spam_score > not_spam_score ? 1 : 0;
}

int main() {
    add_keyword("free", 5, 1);
    add_keyword("winner", 6, 2);
    add_keyword("prize", 4, 3);

    const char *text = "Congratulations! You are a winner of a free prize.";
    int result = classify_text(text);
    printf(result ? "Spam\n" : "Not Spam\n");
    return 0;
}
