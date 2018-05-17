#include <iostream> //for cin and cout
#include <cstdlib> // for rand()
#include <ctime> // access to computer clock
#include <fstream> // for file output
using namespace std;

int otherDoorFrom(int, int);

int main(){srand (time(0));
    ofstream fout;
    fout.open("gameShowStats.txt");
    int num1, num2;
    int winChange = 0;
    int winStay = 0;
    int games = 0;
    int lose = 0;
    int hint;
    char YesNo;
    
    cout << "Welcome to the Monty Hall Game!!" << endl << endl;
    
    do {
        int ans = rand()%3 + 1;
        cout << "In one of these doors, there is a grand prize of $10,000!" << endl;
        cout << "The other two will hold dish soap." << endl;
        cout <<" _______  _______  _______" << endl;
        cout <<"|       ||       ||       |" << endl;
        cout <<"|   1   ||   2   ||   3   |" << endl;
        cout <<"|O      ||O      ||O      |" << endl;
        cout <<"|       ||       ||       |" << endl;
        cout <<"|       ||       ||       |" << endl;
        cout <<"|_______||_______||_______|" << endl;
        cout <<"The choices are 1-3. Choose wisely... ";
        cin >> num1;

        if (!cin){// the user inputs an invalid selection
            cout << endl << endl;
            cerr << "Invalid Selection!! Please enter a valid number this time." << endl << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (num1 <1 || num1 > 3 ) {
            cout << endl << endl;
            cout << "Invalid Selection!! Please enter a valid number this time." << endl << endl;
            continue;
        }
        hint = otherDoorFrom(num1, ans);
        cout <<"Before the door is revealed, you'll have a" <<endl;
        cout<< "chance to change your mind" << endl;
        cout <<"and you will be given a hint." << endl;
        cout <<"The door that does not have the grand prize is Door #" << hint << "." << endl;
        cout << "What is your choice now? Will you change or stay?: ";
        cin >> num2;
        cout << endl;
        
        if (num2 <1 || num2 > 3 ) {
            cout << endl << endl << "Invalid Selection!! Please enter a valid number this time." << endl << endl;
            continue;
        }
        
        if (!cin){// the user inputs an invalid selection
            cout << endl << endl;
            cerr << "Invalid Selection!! Please enter a valid number this time." << endl << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        
        if (num2 == ans) {
            if (num1 == num2){
                games++;
                winStay++;// adds a score to wins where the player does not change
                cout << "        Door#" << num2 << endl;
                cout << "       _______ /|      " << endl;
                cout << "      |       | |      " << endl;
                cout << "      |       | |      " << endl;
                cout << "      |  $$$  |O|O     " << endl;
                cout << "      |       | |      " << endl;
                cout << "      |       | |      " << endl;
                cout << "      |_______|/       " << endl;
                cout << "$$Congratulations!!$$" << endl;
                cout << "You just won $10,000!!"<< endl;
            }
            if (num1 != num2){
                games++;
                winChange++;// adds a score to wins where the player changes
                cout << "        Door#" << num2 << endl;
                cout << "       _______ /|      " << endl;
                cout << "      |       | |      " << endl;
                cout << "      |       | |      " << endl;
                cout << "      |  $$$  |O|O     " << endl;
                cout << "      |       | |      " << endl;
                cout << "      |       | |      " << endl;
                cout << "      |_______|/       " << endl;
                cout << "$$Congratulations!!$$" << endl;
                cout<< "You just won $10,000!!"<< endl;
            }
        }
        else {
            lose++;// adds a score to the lose counter
            games++;
            cout << "     Door#" << num2 << "      Door#" << ans << endl;
            cout << "    _______ /|  _______ /|" << endl;
            cout << "   |       | | |       | |" << endl;
            cout << "   |       | | |       | |" << endl;
            cout << "   |  :'(  |O|O|  $$$  |O|O" << endl;
            cout << "   |       | | |       | |" << endl;
            cout << "   |       | | |       | |" << endl;
            cout << "   |_______|/  |_______|/" << endl;
            if (num2 == hint) { // if player picks the revealed door
                cout << "You just kind of given up, haven't you?" << endl;
            }
            else {
                cout << "Awwww, that's to bad..." << endl;
            }
            cout << "Turns out, Door#" << ans << " had the grand prize" << endl;
            cout << "But hey! Look on the bright side" << endl;
            cout << "Your dishes will be much cleaner now." << endl;
        }
        
        cout << "Would you like to try again? (Y/N): ";
        cin >> YesNo;
        cout << endl << endl << endl << endl << endl << endl << endl;
        if (!cin) {
            cout << endl;
            cerr << "Invalid Selection! Select 'Y' or 'N'" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        // user wants to start over
        else if (YesNo == 'Y' || YesNo == 'y') {
            cout <<"Alrighty then!" << endl;
        }
        // user wants to end and is given final stats
        else if (YesNo == 'N' || YesNo == 'n') {
            clog << "You have won " << winChange + winStay << " out of " << games;
            if (games == 1 && (winChange + winStay) == 1) {
                clog << " game"<< endl;
            }
            else {
                clog << " games"<< endl;
            }
            clog << "Number of successful switches: " << winChange << endl;
            clog << "Number of successful stays: " << winStay << endl;
            clog << "Number of losses: " << lose << endl;
            fout << "You have won " << winChange + winStay << " out of " << games;
            if (games == 1 && (winChange + winStay) == 1) {
                fout << " game"<< endl;
            }
            else {
                fout << " games"<< endl;
            }
            fout << "Number of successful switches: " << winChange << endl;
            fout << "Number of successful stays: " << winStay << endl;
            fout << "Number of losses: " << lose << endl;
        }
        else {
            cout << endl << endl <<"Ummm ... I'll take that as a yes" << endl 
            << "(next time if you want to quit, press 'N')"<< endl << endl;
        }
    } while(YesNo !='N' && YesNo != 'n');
 
    return 0;
}

//this function calculates hints
int otherDoorFrom(int n1, int ans) {
    if (n1 == 1){
        if (ans == 1){
            return (rand()%1 + 2);
        }
        if (ans == 2){
            return 3;
        }
        if (ans == 3){
            return 2;
        }
    }
    if (n1 == 2){
        if (ans == 2){
            return 1;
        }
        if (ans == 3){
            return 1;
        }
        if (ans == 1){
            return 3;
        }
    }
    if (n1 == 3){
        if (ans == 3){
            return (rand()%2 + 1);
        }
        if (ans == 2){
            return 1;
        }
        if (ans == 1){
            return 2;
        }
    }
}

/* -The door number is the same for the entire game
-still need to properly implement hint system
-line 130 needs to change because it gives incorrect numbers
*/