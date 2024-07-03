#include <iostream>
#include <array>
using namespace std;

void printRings();
void moveRings(string fromPeg[], string toPeg[]);
void moveRing(int ringNumber, string direction);
void UserInput();
void solve();
bool CanMoveRing();

#pragma region VARIABLES
//ascii of the rings, base and pole
string pole  = "\x1B[38;5;214m         |         ";
string ring1 = "\x1B[38;5;160m       (_1_)       ";
string ring2 = "\x1B[38;5;208m      (__2__)      ";
string ring3 = "\x1B[38;5;220m     (___3___)     ";
string ring4 = "\x1B[38;5;148m    (____4____)    ";
string ring5 = "\x1B[38;5;123m   (_____5_____)   ";
string ring6 =  "\x1B[38;5;20m  (______6______)  ";
string ring7 = "\x1B[38;5;129m (_______7_______) ";
string ring8 = "\x1B[38;5;201m(________8________)";
string base  = "\x1B[38;5;214m-=-=-=-=-|-=-=-=-=-";

//available spots, go in descending order
string peg1[8] = { ring1, ring2, ring3, ring4, ring5, ring6, ring7, ring8 };
string peg2[8] = { pole, pole, pole, pole, pole, pole, pole, pole };
string peg3[8] = { pole, pole, pole, pole, pole, pole, pole, pole };

//user input values
int ringToMove = 0;
string direction = "";

#pragma endregion

int main()
{
    printRings();
    cout << "\x1B[38;5;255mTime to solve the Tower of Hanoi!" << endl;
    solve();
    return 0;
}

void printRings()
{
    //print the exact pattern currently represented

    string line1 = pole + pole + pole;
    string line2 = peg1[0] + peg2[0] + peg3[0];
    string line3 = peg1[1] + peg2[1] + peg3[1];
    string line4 = peg1[2] + peg2[2] + peg3[2];
    string line5 = peg1[3] + peg2[3] + peg3[3];
    string line6 = peg1[4] + peg2[4] + peg3[4];
    string line7 = peg1[5] + peg2[5] + peg3[5];
    string line8 = peg1[6] + peg2[6] + peg3[6];
    string line9 = peg1[7] + peg2[7] + peg3[7];
    string line10 = base + base + base;

    cout << line1 << endl;
    cout << line2 << endl;
    cout << line3 << endl;
    cout << line4 << endl;
    cout << line5 << endl;
    cout << line6 << endl;
    cout << line7 << endl;
    cout << line8 << endl;
    cout << line9 << endl;
    cout << line10 << endl;
}
#pragma region AUTO SOLVE

void solve()
{
    moveRings(peg1, peg2);
    moveRings(peg2, peg3);
}

void moveRings(string fromPeg[], string toPeg[])
{
    int toPegMaxSize = (int)sizeof(toPeg);
    int currentToPeg = (int)sizeof(toPeg) - 1;

    for (int i = 0; i < toPegMaxSize; i++)
    {
        toPeg[currentToPeg] = fromPeg[i];
        currentToPeg--;
        fromPeg[i] = pole;
        printRings();
    }
}

#pragma endregion
#pragma region USER SOLVE

void UserInput()
{
    cout << "What ring do you wish to move?";
    cin >> ringToMove;
    cout << "Which peg do you wish to move ring " << ringToMove << " to?";
    cin >> direction;
    moveRing(ringToMove, direction);
    printRings();
}

void moveRing(int ringNumber, string direction)
{
    //make direction lowercase
    //see where the ring currently is
    // - if the ring is underneath a RING we cannot move it
    // - if the ring is on the left peg it can't move left, vice versa on the right peg
    switch (ringNumber)
    {
        case 1:
            if (CanMoveRing())
            {
                cout << "MOVING RING " << ringNumber << endl;
            }
            break;
        case 2:
            if (CanMoveRing())
            {
                cout << "MOVING RING " << ringNumber << endl;
            }
            break;
        case 3:
            if (CanMoveRing())
            {
                cout << "MOVING RING " << ringNumber << endl;
            }
            break;
        case 4:
            if (CanMoveRing())
            {
                cout << "MOVING RING " << ringNumber << endl;
            }
            break;
        case 5:
            if (CanMoveRing())
            {
                cout << "MOVING RING " << ringNumber << endl;
            }
            break;
        case 6:
            if (CanMoveRing())
            {
                cout << "MOVING RING " << ringNumber << endl;
            }
            break;
        case 7:
            if (CanMoveRing())
            {
                cout << "MOVING RING " << ringNumber << endl;
            }
            break;
        case 8:
            if (CanMoveRing())
            {
                cout << "MOVING RING " << ringNumber << endl;
            }
            break;
        default:
            cout << "Not a valid ring, please choose another ring" << endl;
            UserInput();
    }
}

bool CanMoveRing()
{
    //return a true or false value if the ring can move
    return false;
}

#pragma endregion