#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 200
#define MAX_RESPONSES 50

void tellJoke();
void tellFunFact();
void triviaQuiz();
void casualTalk(char* response);
void dynamicTalk(char* response);
void personalizedChat(char* response);
void provideGeneralInfo(char* query);
void enhancedCasualTalk(char* response);
void giveFunnyCompliment();
void aboutAuthor();

const char* jokes[] = {
    "Why don't scientists trust atoms? Because they make up everything!",
    "Why did the scarecrow win an award? Because he was outstanding in his field!",
    "Why don't programmers like nature? It has too many bugs.",
    "What do you call fake spaghetti? An impasta!",
    "Why did the math book look sad? Because it had too many problems.",
    "How does a penguin build its house? Igloos it together!",
    "What do you call cheese that isn't yours? Nacho cheese!",
    "Why don’t skeletons fight each other? They don’t have the guts!",
    "What do you call a factory that makes good products? A satisfactory!",
    "Why did the bicycle fall over? It was two-tired!"
};

const char* facts[] = {
    "Did you know? Honey never spoils.",
    "A group of flamingos is called a 'flamboyance'.",
    "Octopuses have three hearts.",
    "Bananas are berries, but strawberries aren't.",
    "The Eiffel Tower can be 15 cm taller during the summer.",
    "Wombat poop is cube-shaped.",
    "A jiffy is an actual unit of time. It’s 1/100th of a second.",
    "The shortest war in history was between Britain and Zanzibar on August 27, 1896. Zanzibar surrendered after 38 minutes.",
    "An ostrich's eye is bigger than its brain.",
    "The longest time between two twins being born is 87 days."
};

const char* casualTalkResponses[] = {
    "How's your day going so far?",
    "What did you have for breakfast today?",
    "Have you read any good books lately?",
    "Do you prefer coffee or tea?",
    "What’s the best movie you’ve watched recently?",
    "What’s something you’re looking forward to?",
    "Any exciting plans for the weekend?",
    "What’s your go-to way to relax?",
    "Have you tried any new hobbies recently?",
    "What’s the most interesting place you’ve visited?"
};

const char* dynamicResponses[] = {
    "I love talking about that! What else do you want to discuss?",
    "That’s a great topic! What’s your take on it?",
    "Interesting! What other things do you like related to that?",
    "That’s cool! Can you share more about your thoughts on it?",
    "Wow, that’s a unique perspective! How did you come to that conclusion?",
    "That’s fascinating! What are some related topics you enjoy?",
    "I’d love to hear more about that! What’s your opinion on it?",
    "That’s a great subject! How do you feel about it?",
    "So interesting! What other ideas do you have on this?",
    "You’ve got my attention! What more can you tell me?"
};

const char* generalInfoResponses[] = {
    "I’m here to chat and provide information. Feel free to ask me anything!",
    "I can tell you jokes, fun facts, or even provide some trivia. What would you like to know?",
    "Whether it’s general knowledge, fun facts, or just casual talk, I’ve got you covered!",
    "Need information on a specific topic? Just ask and I’ll do my best to provide it.",
    "I’m happy to help with a range of topics. What interests you today?",
    "From science to history, I'm full of knowledge. What do you want to learn about?",
    "Curious about anything? I'm here to answer your questions!",
    "Got questions? I’ve got answers. Ask me anything about general knowledge!",
    "Whether it's about space, animals, or anything in between, I'm here to provide information.",
    "Looking for interesting facts or explanations? Just let me know!"
};

const char* personalizedResponses[] = {
    "It’s nice to get to know you! What do you enjoy doing in your free time?",
    "Tell me more about yourself. What’s something you’re passionate about?",
    "Everyone has unique interests. What’s yours?",
    "I’d love to hear about your favorite hobbies or activities!",
    "What makes you tick? Share something you’re really into!"
};

const char* funnyCompliments[] = {
    "You're like a cloud. When you disappear, it's a beautiful day!",
    "If you were a vegetable, you’d be a cute-cumber!",
    "You must be made of copper and tellurium because you're Cu-Te.",
    "Do you have a map? Because I just got lost in your eyes!",
    "If you were a fruit, you’d be a fine-apple.",
    "Are you a magician? Because whenever I look at you, everyone else disappears.",
    "If you were a cat, you’d purr-fect.",
    "You’re like a software update. Whenever I see you, I’m excited for the new features!",
    "Are you a parking ticket? Because you’ve got ‘FINE’ written all over you!",
    "Do you have a name, or can I call you mine?"
};

const char* getRandomResponse(const char* responses[], int size) {
    srand(time(NULL));
    int index = rand() % size;
    return responses[index];
}

void tellJoke() {
    printf("Here's a joke for you: %s\n", getRandomResponse(jokes, sizeof(jokes) / sizeof(jokes[0])));
}

void tellFunFact() {
    printf("Here's a fun fact: %s\n", getRandomResponse(facts, sizeof(facts) / sizeof(facts[0])));
}

void triviaQuiz() {
    int answer;
    printf("Welcome to the trivia quiz! Answer the following questions:\n");

    printf("1. What is the capital of France?\n");
    printf("1) Berlin\n2) Madrid\n3) Paris\n4) Rome\nYour choice: ");
    scanf("%d", &answer);
    if (answer == 3) {
        printf("Correct! Paris is the capital of France.\n");
    } else {
        printf("Incorrect. The right answer is Paris.\n");
    }

    printf("2. What is the chemical symbol for water?\n");
    printf("1) O2\n2) CO2\n3) H2O\n4) H2SO4\nYour choice: ");
    scanf("%d", &answer);
    if (answer == 3) {
        printf("Correct! The chemical symbol for water is H2O.\n");
    } else {
        printf("Incorrect. The right answer is H2O.\n");
    }

    printf("3. Who wrote 'To Kill a Mockingbird'?\n");
    printf("1) J.K. Rowling\n2) Harper Lee\n3) Mark Twain\n4) Ernest Hemingway\nYour choice: ");
    scanf("%d", &answer);
    if (answer == 2) {
        printf("Correct! Harper Lee wrote 'To Kill a Mockingbird'.\n");
    } else {
        printf("Incorrect. The right answer is Harper Lee.\n");
    }
}

void casualTalk(char* response) {
    if (strstr(response, "weather") != NULL) {
        printf("The weather is always great when you're chatting with me! But seriously, I hope it's nice where you are.\n");
    } else if (strstr(response, "food") != NULL) {
        printf("Food is always a good topic! Do you have a favorite dish or cuisine?\n");
    } else if (strstr(response, "movies") != NULL) {
        printf("Movies are fantastic! What's the last movie you watched?\n");
    } else if (strstr(response, "hobbies") != NULL) {
        printf("Hobbies are a great way to unwind! What’s your favorite hobby?\n");
    } else if (strstr(response, "sports") != NULL) {
        printf("Sports are exciting! Do you follow any particular sport or team?\n");
    } else {
        printf("%s\n", getRandomResponse(casualTalkResponses, sizeof(casualTalkResponses) / sizeof(casualTalkResponses[0])));
    }
}

void dynamicTalk(char* response) {
    if (strstr(response, "technology") != NULL) {
        printf("Technology is evolving so fast! What’s the most exciting tech trend you’ve heard of recently?\n");
    } else if (strstr(response, "travel") != NULL) {
        printf("Traveling can be such an adventure! What’s your dream travel destination?\n");
    } else if (strstr(response, "music") != NULL) {
        printf("Music is a universal language! What’s your favorite genre or artist?\n");
    } else if (strstr(response, "gaming") != NULL) {
        printf("Gaming is so much fun! What’s your favorite game or gaming console?\n");
    } else if (strstr(response, "books") != NULL) {
        printf("Books open up new worlds! What’s a book you’ve enjoyed recently?\n");
    } else {
        printf("%s\n", getRandomResponse(dynamicResponses, sizeof(dynamicResponses) / sizeof(dynamicResponses[0])));
    }
}

void personalizedChat(char* response) {
    if (strstr(response, "hobbies") != NULL) {
        printf("It’s great to hear about your hobbies! What’s one that you’re particularly passionate about?\n");
    } else if (strstr(response, "career") != NULL) {
        printf("Careers can be very fulfilling. What field are you interested in or working in?\n");
    } else if (strstr(response, "family") != NULL) {
        printf("Family is important. What’s something special about your family?\n");
    } else if (strstr(response, "dreams") != NULL) {
        printf("Dreams are inspiring! What’s a big dream or goal you’re working towards?\n");
    } else {
        printf("%s\n", getRandomResponse(personalizedResponses, sizeof(personalizedResponses) / sizeof(personalizedResponses[0])));
    }
}

void provideGeneralInfo(char* query) {
    if (strstr(query, "weather") != NULL) {
        printf("I can't check the weather for you, but I hope it's nice where you are!\n");
    } else if (strstr(query, "time") != NULL) {
        time_t now;
        struct tm *tm_info;
        char buffer[26];

        time(&now);
        tm_info = localtime(&now);

        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        printf("The current local time is: %s\n", buffer);
    } else if (strstr(query, "news") != NULL) {
        printf("I don’t have access to live news updates, but you can check out the latest news on your favorite news website.\n");
    } else if (strstr(query, "history") != NULL) {
        printf("History is full of fascinating events! Is there a particular historical period or event you're interested in?\n");
    } else if (strstr(query, "science") != NULL) {
        printf("Science is amazing! What branch of science interests you the most?\n");
    } else if (strstr(query, "technology") != NULL) {
        printf("Technology is constantly advancing! Are there any tech developments you’re excited about?\n");
    } else if (strstr(query, "space") != NULL) {
        printf("Space is so intriguing! Are you interested in planets, stars, or space exploration?\n");
    } else if (strstr(query, "animals") != NULL) {
        printf("Animals are wonderful creatures! Do you have a favorite animal or a fun animal fact?\n");
    } else {
        printf("%s\n", getRandomResponse(generalInfoResponses, sizeof(generalInfoResponses) / sizeof(generalInfoResponses[0])));
    }
}

void giveFunnyCompliment() {
    printf("%s\n", getRandomResponse(funnyCompliments, sizeof(funnyCompliments) / sizeof(funnyCompliments[0])));
}

void aboutAuthor() {
    printf("This chatbot is created by Quicksilver, a skilled hacker and founder of Quicksilver-lab.\n");
    printf("Quicksilver-lab is where Quicksilver performs experiments and develops various projects.\n");
    printf("GitHub Username: Quicksilver-lab\n");
    printf("You can find Quicksilver's GitHub profile here: https://github.com/Quicksilver-lab\n");
}

int main() {
    char response[MAX_LENGTH];
    int choice;

    printf("Hello! I'm your Quickly chatbot. How can I assist you today?\n");
    printf("1. Tell me a joke\n");
    printf("2. Share a fun fact\n");
    printf("3. Take a trivia quiz\n");
    printf("4. Casual talk\n");
    printf("5. Dynamic talk\n");
    printf("6. Personalized chat\n");
    printf("7. Provide general information\n");
    printf("8. Give a funny compliment\n");
    printf("9. About the author\n");
    printf("10. Exit\n");

    while (1) {
        printf("Enter your choice (1-10): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                tellJoke();
                break;
            case 2:
                tellFunFact();
                break;
            case 3:
                triviaQuiz();
                break;
            case 4:
                printf("What would you like to talk about? ");
                fgets(response, sizeof(response), stdin);
                response[strcspn(response, "\n")] = '\0';
                casualTalk(response);
                break;
            case 5:
                printf("What topic are you interested in? ");
                fgets(response, sizeof(response), stdin);
                response[strcspn(response, "\n")] = '\0';
                dynamicTalk(response);
                break;
            case 6:
                printf("Tell me something about yourself: ");
                fgets(response, sizeof(response), stdin);
                response[strcspn(response, "\n")] = '\0';
                personalizedChat(response);
                break;
            case 7:
                printf("Ask me for general information: ");
                fgets(response, sizeof(response), stdin);
                response[strcspn(response, "\n")] = '\0';
                provideGeneralInfo(response);
                break;
            case 8:
                giveFunnyCompliment();
                break;
            case 9:
                aboutAuthor();
                break;
            case 10:
                printf("Goodbye! Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a number between 1 and 10.\n");
        }
    }

    return 0;
}
