#include<iostream>
#include <random>
#include <iomanip>
using namespace std;
int count=1;
//now i am defining the board of the snake and ladder
void board(int (&matrix)[10][10] ){     //here i have inisalize a matrix of the 10*10 matrix
for(int i=9;i>=0;i--){;
    if((i%2)==1){
        for(int j=9;j>=0;j--){
            matrix[i][j]=count++;}}     //i am trying to take the value of the board in the matrix;
            else for(int j=0;j<=9;j++){
                matrix[i][j]=count++;}cout<<endl;}}
                void printboard(int (&matrix)[10][10]){
                    for(int i=0;i<10;i++){
                        for(int j=0;j<10;j++){
                            cout<<matrix[i][j]<<"\t";}cout<<endl;}}
int diceroll(void){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 6);      // THIS defines your range [1, 100]

    return distrib(gen);}                 //this is the frame of the program of the snake and laddar 
void swap(int &currentplayer){     //for the swapping of the two players
    if(currentplayer==1){
        currentplayer=0;}
    else
    currentplayer=1;}
// this is the function for the snake and the ladder 
void movePlayer(int &position, int start[], int end[]) {
    for(int i = 0; i < 4; i++){
        if(start[i] == position){
            position = end[i];
            if(start[i]<end[i]){cout<<"yay: ladder from"<<start[i]<<"to"<<end[i]<<endl;}else cout<<"ooh snake from"<<start[i]<<"to"<<end[i]<<endl;break;
        }}}
//this is the whole function which check the winner of the game made
bool iswinner(int score){if (score==100){return true;}else return false;}
//now i will code to add the marker in the code of snake and ladder
void printBoardWithMarkers(int player1, int player2, int matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Check if player positions match the current cell value
            if (matrix[i][j] == player1 && matrix[i][j] == player2) {
                cout << "OX\t"; // Both on one spot
            } else if (matrix[i][j] == player1) {
                cout << "O\t"; // Player 1
            } else if (matrix[i][j] == player2) {
                cout << "X\t"; // Player 2
            } else {
                cout << matrix[i][j] << "\t"; // Empty spot
            }
        }
        cout << endl;
    }
}
int main() {
    int player1 = 0; // Position of player 1
    int player2 = 0; // Position of player 2
    int dice;
    char input;
    int matrix[10][10];
    int turn = 1; // 1 for Player 1, 2 for Player 2
    //now i am defining the snakea and the ladder in the code
    int snakeStart[] = {99, 90, 54, 19};
    int snakeEnd[] = {7, 48, 34, 5};
    int ladderStart[] = {4, 9, 20, 28};
    int ladderEnd[] = {14, 31, 38, 84};
    int numSnakes = 4;
    int numLadders = 4;
    
    board(matrix);

    do {
        cout << "Player " << turn << " press any key to roll the dice: ";
        cin >> input;
        dice = diceroll();
        cout << "Rolled a: " << dice << endl;

        if (turn == 1) {
            player1 += dice;
            if (player1 > 100) player1 -= dice; // Don't move if > 100
            // Optional: movePlayer(player1, ...); // Call your snakes/ladders here
        } else {
            player2 += dice;
            if (player2 > 100) player2 -= dice;
            // Optional: movePlayer(player2, ...); // Call your snakes/ladders here
        }
        if (turn==1){movePlayer(player1,ladderStart,ladderEnd);}
        if(turn==2){movePlayer(player2,ladderStart,ladderEnd);}
        if (turn==1){movePlayer(player1,snakeStart,snakeEnd);}
        if(turn==2){movePlayer(player2,snakeStart,snakeEnd);}
       //only one time printing the board
        printBoardWithMarkers(player1, player2, matrix);

        // Check winner based on position, not turn
        if (player1 >= 100) {
            cout << "Player 1 wins!" << endl;
            break;
        }
        if (player2 >= 100) {
            cout << "Player 2 wins!" << endl;
            break;
        }

        // Swap turn
       if (turn == 1) {
    turn = 2;
} else {
    turn = 1;
}

    } while (true);

    return 0;
}