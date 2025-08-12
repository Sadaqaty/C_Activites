#include <stdio.h>
#include <string.h>

int analyze_sentiment(const char *text) {
    // Simple keywords-based sentiment analysis
    const char *positive_keywords[] = {"good", "happy", "joy", "love"};
    const char *negative_keywords[] = {"bad", "sad", "angry", "hate"};
    int positive_count = 0, negative_count = 0;
    
    for (int i = 0; i < 4; i++) {
        if (strstr(text, positive_keywords[i])) positive_count++;
        if (strstr(text, negative_keywords[i])) negative_count++;
    }

    if (positive_count > negative_count) return 1;
    if (negative_count > positive_count) return -1;
    return 0;
}

int main() {
    const char *text = "I am so happy and joyful today!";
    int result = analyze_sentiment(text);
    if (result == 1) printf("Positive sentiment\n");
    else if (result == -1) printf("Negative sentiment\n");
    else printf("Neutral sentiment\n");
    return 0;
}
