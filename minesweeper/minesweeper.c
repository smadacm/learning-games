#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

const int CELL_EMPTY_REVEALED = 0;
const int CELL_BOMB_REVEALED = 1;

const int CELL_EMPTY_HIDDEN = 2;
const int CELL_BOMB_HIDDEN = 3;

const int CELL_EMPTY_FLAGGED = 4;
const int CELL_BOMB_FLAGGED = 5;

struct Row {
    int cells[WIDTH];
};

void flag_cell(struct Row *board[], int x, int y){
    if(board[y]->cells[x] == CELL_EMPTY_HIDDEN){
        board[y]->cells[x] = CELL_EMPTY_FLAGGED;
    } else if(board[y]->cells[x] == CELL_BOMB_HIDDEN){
        board[y]->cells[x] = CELL_BOMB_FLAGGED;
    } else if(board[y]->cells[x] == CELL_EMPTY_REVEALED){
    } else if(board[y]->cells[x] == CELL_BOMB_REVEALED){
    } else if(board[y]->cells[x] == CELL_BOMB_FLAGGED){
        board[y]->cells[x] = CELL_BOMB_HIDDEN;
    } else if(board[y]->cells[x] == CELL_EMPTY_FLAGGED){
        board[y]->cells[x] = CELL_EMPTY_HIDDEN;
    }
}

int reveal_cell(struct Row *board[], struct Row *under_board[], int x, int y){
    if(board[y]->cells[x] == CELL_EMPTY_REVEALED || board[y]->cells[x] == CELL_EMPTY_HIDDEN){
        board[y]->cells[x] = CELL_EMPTY_REVEALED;
        if(under_board[y]->cells[x] == (int) ' '){
            if(x > 0 && board[y]->cells[x-1] == CELL_EMPTY_HIDDEN){
                reveal_cell(board, under_board, x-1, y);
            }
            if(y > 0 && board[y-1]->cells[x] == CELL_EMPTY_HIDDEN){
                reveal_cell(board, under_board, x, y-1);
            }
            if(y < (HEIGHT - 1) && board[y+1]->cells[x] == CELL_EMPTY_HIDDEN){
                reveal_cell(board, under_board, x, y+1);
            }
            if(x < (WIDTH - 1) && board[y]->cells[x+1] == CELL_EMPTY_HIDDEN){
                reveal_cell(board, under_board, x+1, y);
            }
        }
    } else if(board[y]->cells[x] == CELL_BOMB_FLAGGED || board[y]->cells[x] == CELL_EMPTY_FLAGGED) {
        printf("That cell is flagged!\n");
    } else if(board[y]->cells[x] == CELL_BOMB_HIDDEN) {
        board[y]->cells[x] = CELL_BOMB_REVEALED;
        printf("You hit a bomb!\n");
        return 1;
    }
    return 0;
}

int game_is_lost(struct Row *board[]){
    int ret = 0;
    int y=0, x=0;

    for(y=0; y<HEIGHT && ret==0; y++){
        for(x=0; x<WIDTH && ret==0; x++){
            if(board[y]->cells[x] == CELL_BOMB_REVEALED){
                ret = 1;
            }
        }
    }

    return ret;
}
int game_is_won(struct Row *board[]){
    int ret = 1;
    int y=0, x=0;

    for(y=0; y<HEIGHT && ret==1; y++){
        for(x=0; x<WIDTH && ret==1; x++){
            if(board[y]->cells[x] == CELL_EMPTY_HIDDEN || board[y]->cells[x] == CELL_BOMB_REVEALED){
                ret = 0;
            }
        }
    }

    return ret;
}

void prep_under_board(struct Row *board[], struct Row *under_board[]){
    int x=0, y=0, count=0;

    for(y=0; y<HEIGHT; y++){
        for(x=0; x<WIDTH; x++){
            count = 0;

            if(board[y]->cells[x] == CELL_BOMB_HIDDEN){
                under_board[y]->cells[x] = (int) 'X';
            } else {


                if(y > 0 && x > 0 && board[y-1]->cells[x-1] == CELL_BOMB_HIDDEN)
                    count++;
                if(y > 0 && board[y-1]->cells[x] == CELL_BOMB_HIDDEN)
                    count++;
                if(y > 0 && x < (WIDTH - 1) && board[y-1]->cells[x+1] == CELL_BOMB_HIDDEN)
                    count++;

                if(x > 0 && board[y]->cells[x-1] == CELL_BOMB_HIDDEN)
                    count++;
                if(x < (WIDTH - 1) && board[y]->cells[x+1] == CELL_BOMB_HIDDEN)
                    count++;

                if(y < (HEIGHT - 1) && x > 0 && board[y+1]->cells[x-1] == CELL_BOMB_HIDDEN)
                    count++;
                if(y < (HEIGHT - 1) && board[y+1]->cells[x] == CELL_BOMB_HIDDEN)
                    count++;
                if(y < (HEIGHT - 1) && x < (WIDTH - 1) && board[y+1]->cells[x+1] == CELL_BOMB_HIDDEN)
                    count++;

                if(count == 0)
                    under_board[y]->cells[x] = (int) ' ';
                else
                    under_board[y]->cells[x] = ((int) '0') + count;
            }
        }
    }
}

//const int CELL_EMPTY_REVEALED = 0;
//const int CELL_BOMB_REVEALED = 1;
//
//const int CELL_EMPTY_HIDDEN = 2;
//const int CELL_BOMB_HIDDEN = 3;
//
//const int CELL_EMPTY_FLAGGED = 4;
//const int CELL_BOMB_FLAGGED = 5;

void display_board(struct Row *board[], struct Row *under_board[], int showall){
    int x=0, y=0;

    printf("  ");
    for(x=0; x<WIDTH; x++){
        printf("%c", x+((int) 'A'));
    }
    printf("\n");

    for(y=0; y<HEIGHT; y++){
        printf("%d ", y);
        for(x=0; x<WIDTH; x++){
            if(!showall && (board[y]->cells[x] == CELL_EMPTY_HIDDEN || board[y]->cells[x] == CELL_BOMB_HIDDEN)){
                printf("#");
            } else if(!showall && (board[y]->cells[x] == CELL_EMPTY_FLAGGED || board[y]->cells[x] == CELL_BOMB_FLAGGED)){
                printf("F");
            } else {
                printf("%c", under_board[y]->cells[x]);
            }
        }
        printf("\n");
    }
}

int handle_turn(struct Row *board[], struct Row *under_board[]){
    char x=0, y=0, c=0;
    char xs=0, ys=0, cs=0;
    int xi=0, yi=0;

    printf("Please enter a command:\n");
    printf("F -- Flag a cell\n");
    printf("R -- Reveal a cell\n");
    printf(">");

    while( (cs = tolower(getchar())) != '\n' ){
        c = cs;
    }
    if(c == 'q'){
        return 0;
    }

    printf("Please enter a column letter:\n>");
    while( (xs = tolower(getchar())) != '\n' ){
        x = xs;
    }

    printf("Please enter a row number:\n>");
    while( (ys = tolower(getchar())) != '\n' ){
        y = ys;
    }
    
    xi = (int) (x - 'a');
    yi = (int) (y - '0');

    printf("You entered '%c' for X: %c and Y: %c\n", c, x, y);
    printf("This translates to '%c' for X: %d and Y: %d\n", c, xi, yi);
    if(c == 'f') {
        flag_cell(board, xi, yi);
    } else if(c == 'r') {
        reveal_cell(board, under_board, xi, yi);
    }
    return 1;
}

int main(int argc, const char *argv[]){
    struct Row *board[HEIGHT];
    struct Row *under_board[HEIGHT];
    int x=0, y=0;
    int keep_going=1;

    for(y=0; y<HEIGHT; y++){
        board[y] = malloc(sizeof(struct Row));
        under_board[y] = malloc(sizeof(struct Row));
        for(x=0; x<WIDTH; x++){
            board[y]->cells[x] = CELL_EMPTY_HIDDEN;
            under_board[y]->cells[x] = 0;
        }
    }

    srand((unsigned)time(NULL));
    while(rand()%17) //random number of seeds
        srand(rand());

    for(x=0; x<10; x++){
        board[rand()%10]->cells[rand()%10] = CELL_BOMB_HIDDEN;
    }


    prep_under_board(board, under_board);

    while(keep_going && !(game_is_won(board)) && !(game_is_lost(board))){
        display_board(board, under_board, 0);
        keep_going = handle_turn(board, under_board);
    }

    display_board(board, under_board, 1);
    if(game_is_won(board)){
        printf("Congratulations!\n");
    } else if(game_is_lost(board)) {
        printf("Sorry!\n");
    }

    return 0;
}
