#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NUM_GUESSES 10

int word_is_complete(char *correct, char *running);
int check_letter(char *correct, char *running, char guess, int num_guesses);

int word_is_complete(char *correct, char *running){
    int possible = 1;
    while(*correct && possible){
        if(*correct != *running){
            possible = 0;
        }
        correct++;
        running++;
    }
    return possible;
}

int check_letter(char *correct, char *running, char guess, int num_guesses){
    int invalid = 1;

    guess = tolower(guess);

    while(*correct){
        if(tolower(*correct) == guess){
            *running = *correct;
            invalid = 0;
        }
        correct++;
        running++;
    }
    if(invalid){
        num_guesses++;
    }
    return num_guesses;
}

int game_over(char *correct, char *running, int num_guesses){
    int done = 0;
    if(num_guesses >= NUM_GUESSES) {
        done = 1;
    } else if(word_is_complete(correct, running)){
        done = 1;
    }
    return done;
}

void print_board(char *running, int num_guesses){
    printf("You've guessed %d times.\n", num_guesses);
    printf("You have %d more tries.\n", NUM_GUESSES - num_guesses);
    printf("Currently, the word is '");
    while(*running){
        printf("%c ", *running);
        running++;
    }
    printf("'\n");
}

void init_word(char *correct, char *running){
    while(*correct){
        *running = '_';
        correct++;
        running++;
    }
}

char get_guess(){
    char guess;

    printf("Please enter a guess:\n>");
    guess = getchar();
    fflush(stdin);

    return guess;
}

void end_game(char *correct, char *running, int num_guesses){
    if(word_is_complete(correct, running)){
        printf("You won the game!\n");
    } else {
        printf("Sorry, better luck next time!\n");
    }
    printf("The word was '");
    while(*correct){
        printf("%c", *correct);
        correct++;
    }
    printf("'\n");
}

int main(int argc, const char *argv[]){
    char *word = "Truck";
    char *running = malloc(sizeof(*word));
    char guess;
    int num_guesses = 0;

    init_word(word, running);

    while(!game_over(word, running, num_guesses)){
        print_board(running, num_guesses);
        guess = get_guess();
        num_guesses = check_letter(word, running, guess, num_guesses);
    }
    end_game(word, running, num_guesses);

    return 0;
}
