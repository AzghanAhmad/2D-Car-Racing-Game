//Azghan_Ahmad_22i2667
//Arslan_Shabbir_21i1739
 
#include <iostream>
#include <string>
#include <Windows.h> 
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <conio.h>    //for _getch() function
//header files
#include"Graph.h"
#include"Stack.h"
#include"Obstacle.h"
#include"Leaderboard.h"
#pragma comment(lib,"winmm.lib")     //for music

using namespace std;

const int INFINITY_INT = 1e9;

void move_car(int start_x, int start_y, int final_x, int final_y, graph game_graph, obstacle& obstacs, Stack& scoreStack)
{
    char input;
    char prev = game_graph.display[start_x][start_y];
    game_graph.display[start_x][start_y] = 'C';
    game_graph.display[final_x][final_y] = 'F';


    for (int i = 0; i < 4; i++) 
    {

        if (obstacs.Is_stone_quey_empty() == false)
        {
            nod* temp = obstacs.deque_stone();
            game_graph.display[temp->x][temp->y] = 'S';
        }
    }
    while (1)
    {

        if (obstacs.Is_stick_quey_empty() == false)
        {
            break;
        }
        nod* temp = obstacs.deque_stick();

        if (game_graph.display[temp->x][temp->y] == ' ') 
        {
            game_graph.display[temp->x][temp->y] = 'S';
            break;
        }
    }
    game_graph.print();
    int x, y;

//here is the movement of car through Keys 
    while (true) 
    {
        input = _getch();  // Get the character for the car moment

        bool action = false;

        int x = start_x;
        int y = start_y;

        if (input == 'a' && (start_y - 1 > 0) && (game_graph.display[start_x][start_y - 1] == 'S' || game_graph.display[start_x][start_y - 1] == ' ' || game_graph.display[start_x][start_y - 1] == 'F')) 
        {


            for (int h = 1; h <= speed && start_y > 0; h++) 
            {
                if (game_graph.display[start_x][start_y - 1] == ' ' || game_graph.display[start_x][start_y - 1] == 'F' || game_graph.display[start_x][start_y - 1] == 'S')
                {

                    if (game_graph.display[start_x][start_y - 1] == 'S' || game_graph.display[start_x][start_y - 1] == 'F')
                    {
                        start_y--;
                        action = true;
                        break;
                    }
                    else
                        start_y--;
                }
            }
            action = true;
        }
        else if (input == 'd' && (start_y + 1 < 120) && (game_graph.display[start_x][start_y + 1] == ' ' || game_graph.display[start_x][start_y + 1] == 'F' || game_graph.display[start_x][start_y + 1] == 'S'))
        {

            for (int h = 1; h <= speed && start_y < 120; h++)
            {
                if (game_graph.display[start_x][start_y + 1] == ' ' || game_graph.display[start_x][start_y + 1] == 'F' || game_graph.display[start_x][start_y + 1] == 'S') 
                {

                    if (game_graph.display[start_x][start_y + 1] == 'S' || game_graph.display[start_x][start_y + 1] == 'F')
                    {
                        start_y++;
                        action = true;
                        break;
                    }
                    else
                        start_y++;
                }
            }
            action = true;
        }
        else if (input == 'w' && (start_x - 1 >= 1) && (game_graph.display[start_x - 1][start_y] == ' ' || game_graph.display[start_x - 1][start_y] == 'F' || game_graph.display[start_x - 1][start_y] == 'S')) {

            for (int h = 1; h <= speed && start_x > 0; h++) {
                if (game_graph.display[start_x - 1][start_y] == ' ' || game_graph.display[start_x - 1][start_y] == 'F' || game_graph.display[start_x - 1][start_y] == 'S') {

                    if (game_graph.display[start_x - 1][start_y] == 'S' || game_graph.display[start_x - 1][start_y] == 'F') {
                        start_x--;
                        action = true;
                        break;
                    }
                    else
                        start_x--;
                }
            }
            action = true;
        }
        else if (input == 's' && (start_x + 1 < 25) && (game_graph.display[start_x + 1][start_y] == ' ' || game_graph.display[start_x + 1][start_y] == 'F' || game_graph.display[start_x + 1][start_y] == 'S')) {

            for (int h = 1; h <= speed && start_x < 25; h++) {
                if (game_graph.display[start_x + 1][start_y] == ' ' || game_graph.display[start_x + 1][start_y] == 'F' || game_graph.display[start_x + 1][start_y] == 'S') {

                    if (game_graph.display[start_x + 1][start_y] == 'S' || game_graph.display[start_x + 1][start_y] == 'F') {
                        start_x++;;
                        action = true;
                        break;
                    }
                    else
                        start_x++;
                }
            }
            action = true;
        }
        if (input == 'a' || input == 'w'|| input == 's' || input == 'd')  // If not speed control, check for hitting walls
        {
            if (!action)
            {


                  // Car hits the wall, decrease the score by 1
                score -= 1;
                
                if (input == 'a' && (start_y - 1 > 0))
                    game_graph.display[start_x][start_y - 1] = ' ';
                else if (input == 'd' && (start_y + 1 < 120))
                    game_graph.display[start_x][start_y + 1] = ' ';
                else if (input == 'w' && (start_x - 1 >= 1))
                    game_graph.display[start_x - 1][start_y] = ' ';
                else if (input == 's' && (start_x + 1 < 25))
                    game_graph.display[start_x + 1][start_y] = ' ';

                
                game_graph.print();
            }
        }
        if (input == 'v')   // speed up
            if (speed < 4)   // apply limit
                speed++;


        if (input == 'b') // speed low
            if (speed > 1)  // apply limit
                speed--;

        if (action) 
        {

            system("cls");

//Here calculating the score 
//if car eats S it collect 5 score
            if (game_graph.display[start_x][start_y] == 'S') 
            {
               // score += 5;

                while (!obstacs.Is_stick_quey_empty()) 
                {
                    nod* temp = obstacs.deque_stick();

                    if (game_graph.display[temp->x][temp->y] == ' ') 
                    {
                        game_graph.display[temp->x][temp->y] = 'S';
                        break;
                    }
                }
                score += 5;
                scoreStack.push(5);
            }
            game_graph.display[x][y] = ' ';

            game_graph.display[start_x][start_y] = 'C';
            game_graph.print();

            if (start_x == final_x && start_y == final_y)   //car arries at finishing point
            {
                cout << "_____________________________________________" << endl;
                cout << "  _____                    ____              " << endl;
                cout << " / ___/__ ___ _  ___      / __ \\_  _____ ____" << endl;
                cout << "/ (_ / _ `/  ' \\/ -_)    / /_/ / |/ / -_) __/" << endl;
                cout << "\\___/\\_,_/_/_/_/\\__/     \\____/|___/\\__/_/   " << endl;
                cout << "_____________________________________________" << endl;

                int totalScore = 0;
                while (!scoreStack.isEmpty())
                {
                    totalScore += scoreStack.peek();
                    scoreStack.pop();
                }
               //it will store the score with palyer name in the txt file 
                cout <<"Player Name: " << player_name << " " << "Score: " << totalScore << endl;
                ofstream scoreFile("score.txt", ios::app);

                if (scoreFile.is_open()) 
                {
                    scoreFile << player_name << "," << score << endl;
                    scoreFile.close();
                }
                break;
            }
        }
    }
}

//used to implement the automatic movement of car using dijkstra algorithm
bool check_vertical_point(int x, int y, char** display, char coin)
{
    if (y < 0 || y >= boundary_y)
        return false;

    else if (x < 0 || x >= boundary_x)
        return false;

    else if (display[x][y] == ' ' || display[x][y] == coin || display[x][y] == 'C' || display[x][y] == 'F')
        return true;

    else return false;

}

bool check_horizantal_point(int x, int y, char** display, char coin)
{


    if (y < 0 || y >= boundary_y)
        return false;

    else if (x < 0 || x >= boundary_x)
        return false;

    else if (display[x][y] == ' ' || display[x][y] == coin || display[x][y] == 'C' || display[x][y] == 'F')
        return true;

    else return false;

}

int** make_Adjancy_List(char** display) 
{
    char coin = 'S';
    int nodes = boundary_x * boundary_y;

    // Allocate memory for adjacency list
    int** adj_list = new int* [nodes];
    for (int i = 0; i < nodes; ++i)
        adj_list[i] = new int[nodes]();

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            adj_list[i][j] = 0;


    for (int k = 0; k < nodes; k++)
    {
        int i = k / boundary_x;
        int j = k % boundary_x;

        if (check_vertical_point(i - 1, j, display, coin)) 
        {
            adj_list[k][(i - 1) * boundary_x + j] = 1;
        }

        if (check_vertical_point(i + 1, j, display, coin)) 
        {
            adj_list[k][(i + 1) * boundary_x + j] = 1;
        }


        if (check_horizantal_point(i, j - 1, display, coin))
        {
            adj_list[k][(i * boundary_x) + j - 1] = 1;
        }

        if (check_horizantal_point(i, j + 1, display, coin)) 
        {
            adj_list[k][(i * boundary_x) + j + 1] = 1;
        }
    }

    return adj_list;
}



void print_adjancyList(int** list, int x, int y)
{
    int i = x * boundary_x + y;
    int node = boundary_x * boundary_y;


    for (int j = 0; j < node; j++)
    {
        if (list[i][j] != 0) {
            cout << j / boundary_x << " , " << j % boundary_x << "    ";
        }
    }

    cout << endl;
}

int minDistance(const int* distance, const bool* visited, int V)
{
    int minDist = INFINITY_INT;
    int minIndex = -1;

    for (int v = 0; v < V; ++v) 
    {
        if (!visited[v] && distance[v] < minDist) 
        {
            minDist = distance[v];
            minIndex = v;
        }
    }

    return minIndex;
}

//using dijkstra algorithm to find the shortest path
void DijkstraAlgorithm(int** adjMatrix, int* D, int* P, bool visited[], int V, int s)
{

    for (int i = 0; i < V; i++) 
    {

        D[i] = 99999;
        P[i] = -1;
    }

    D[s] = 0;

    for (int i = 0; i < V - 1; i++)
    {

        int u = minDistance(D, visited, V);

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {

            if (!visited[v] && adjMatrix[u][v] != 0 && D[u] + adjMatrix[u][v] < D[v])
            {

                D[v] = D[u] + adjMatrix[u][v];
                P[v] = u;
            }
        }
    }
};


void printPath(int* P, int destination, char** display)
{
    Stack s;
    
    int current = destination;
    while (current != -1) 
    {
        s.push(current);
        current = P[current];
    }

    cout << "Shortest path to destination:\n";
    while (!s.isEmpty()) 
    {
        int val = s.gettop();

        int displayRow = val / boundary_x;
        int displayCol = val % boundary_x;


        display[displayRow][displayCol] = 'y';
        // 

        s.pop();

        if (!s.isEmpty())
        {

        }
    }

}


void automode(int** list, int start_x, int start_y, int end_x, int end_y, char** display)
{
    int V = boundary_x * boundary_y;  // Number of vertices
    int* D = new int[V];
    int* P = new int[V];
    bool* visited = new bool[V]();

    int startVertex = start_x * boundary_x + start_y;
    int destinationVertex = end_x * boundary_x + end_y;

    DijkstraAlgorithm(list, D, P, visited, V, startVertex);

    // Check if a path exists
    if (P[destinationVertex] == -1)
    {
        cout << "No path to the destination.\n";
    }
    else {
        // Mark the path on the display
        printPath(P, destinationVertex, display);
    }

    
}

void create_menu()  //menu of game
{
    HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(w, 10);
    PlaySound(TEXT("welcom.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    
    cout << "________________________________________________________________" << endl;
    cout << "     ___  ___       _____              ___           _          " << endl;
    cout << "    |_  |/ _ \\     / ___/__ _____     / _ \\___ _____(_)__  ___ _" << endl;
    cout << "   / __// // /    / /__/ _ `/ __/    / , _/ _ `/ __/ / _ \\/ _ `/" << endl;
    cout << "  /____/____/     \\___/\\_,_/_/      /_/|_|\\_,_/\\__/_/_//_/\\_, / " << endl;
    cout << "                                                         /___/  " << endl;
    cout << "________________________________________________________________" << endl;

    system("PAUSE");
    cin.get();
    PlaySound(NULL, 0, 0);
    system("cls");
    SetConsoleTextAttribute(w, 7);
}
void instructin()  //instruction of game
{
    HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(w, 10);
    cout << "------------------------------------------------" << endl;
    cout << "|                                               |" << endl;
    cout << "| ->It is a game, based on control keys.        |" << endl;
    cout << "| ->Press A to move Left.                       |" << endl;
    cout << "| ->Press D to move Right.                      |" << endl;
    cout << "| ->Press W to move Up.                         |" << endl;
    cout << "| ->Press S to move Down.                       |" << endl;
    cout << "| ->Press V to power up the speed of car.       |" << endl;
    cout << "| ->Press B to decrease the speed of car.       |" << endl;
    cout << "|                                               |" << endl;
    cout << "------------------------------------------------" << endl;
    system("PAUSE");
    system("cls");
    SetConsoleTextAttribute(w, 7);

}
void ending() 
{
    //system("PAUSE");
    HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(w, 10);
    PlaySound(TEXT("gameover.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    cout << "\t\t\t\t\t\tLoading" << endl;
    char x = 219;
    for (int i = 0; i <= 27; i++) {
        Sleep(70);
        cout << x;
    }
    system("cls");

    cout << "_____________________________________________" << endl;  
    cout << "  _____                    ____              " << endl;
    cout << " / ___/__ ___ _  ___      / __ \\_  _____ ____" << endl;
    cout << "/ (_ / _ `/  ' \\/ -_)    / /_/ / |/ / -_) __/" << endl;
    cout << "\\___/\\_,_/_/_/_/\\__/     \\____/|___/\\__/_/   " << endl;
    cout << "_____________________________________________" << endl;
    SetConsoleTextAttribute(w, 7);

}
void Lyrics()
{
   PlaySound(TEXT("Relaxing-thinking-music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void Punjabi()
{
   PlaySound(TEXT("PunjabiSong.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void Background1()
{
   PlaySound(TEXT("Travel.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void Background2()
{
	PlaySound(TEXT("Dreamy.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

int main()
{
    create_menu();
    BTree* root = nullptr;
    int total_node = 24;
    int option;
    int current_level = 0;
    Stack scoreStack;

    obstacle easy_obstacs;
    obstacle medium_obstacs;
    obstacle hard_obstacs;

    easy_obstacs.stone_insertion();
    medium_obstacs.stone_insertion();
    hard_obstacs.stone_insertion();

    easy_obstacs.stick_insertion();
    medium_obstacs.stick_insertion();
    hard_obstacs.stick_insertion();

    graph easy_game_graph(total_node);
    graph medium_game_graph(total_node);
    graph hard_game_graph(total_node);

    easy_game_graph.create_display_easy();
    medium_game_graph.create_display_medium();
    hard_game_graph.create_display_hard();

   int** list = make_Adjancy_List(easy_game_graph.display);

    easy_game_graph.set_random_node();
    medium_game_graph.set_random_node();
    hard_game_graph.set_random_node();

    easy_game_graph.mark_node_axis();
    medium_game_graph.mark_node_axis();
    hard_game_graph.mark_node_axis();

    easy_game_graph.make_graph_display_easy();
    medium_game_graph.make_graph_display_medium();
    hard_game_graph.make_graph_display_hard();

    easy_game_graph.check_node_Axis();
    medium_game_graph.check_node_Axis();
    hard_game_graph.check_node_Axis();

    system("cls");
    easy_game_graph.mark_edges_connectin();

   
    // menu
    while (1) 
    {
        HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(w, 10);
        cout << "-----------------------------------" << endl;
        cout << "|       ------------------         |" << endl;
        cout << "|      | 1.Manual mode    |        |" << endl;
        cout << "|       ------------------         |" << endl;
        cout << "|      | 2.Automated mode |        |" << endl;
        cout << "|       ------------------         |" << endl;
        cout << "|      | 3.Leader Board   |        |" << endl;
        cout << "|       ------------------         |" << endl;
        cout << "|      | 4.Instruction    |        |" << endl;
        cout << "|       ------------------         |" << endl;
        cout << "|      | 5.Resume Game    |        |" << endl;
        cout << "|       ------------------         |" << endl;
        cout << "|      | 6.End Game       |        |" << endl;
        cout << "|       ------------------         |" << endl;
        cout << "-----------------------------------" << endl;
        cout << "  >>  ";
        cin >> option;

        switch (option)
        {

        case 1:
        {
            string music;
            int songtype, level;
            cout << "    Enter Player Name:   ";
            cin >> player_name;
            cout << "    Do you want to play with music? (y or n)    " << endl;
            cin >> music;
            if (music == "y")
            {
                cout << "    Please Choose a Song:    " << endl;
                cout << "    1. Background Music 1" << endl;
                cout << "    2. Background Music 2" << endl;
                cout << "    3. Background Music 3" << endl;
                cout << "    4. Punjabi" << endl;
                cout << "    5. No Music" << endl;
                cin >> songtype;

                if (songtype == 1)
                {
                    Lyrics();
                }
                else if (songtype == 2)
                {
					Background1();
				}
                else if (songtype == 3)
                {
					Background2();
				}
                else if (songtype == 4)
                {
                    Punjabi();
                }
            }
            else if (music == "n")
            {
                cout << "No Music" << endl;
            }

            HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(w, 10);
            cout << "\t\t\t\t\t\tLOADING" << endl;
            char x = 219;
            for (int i = 0; i <= 27; i++)
            {
                Sleep(5);
                cout << x;

            }
            system("cls");
        l:
            cout << "    Enter Level to Play:    " << endl;
            cout << "    1. Easy" << endl;
            cout << "    2. Hard" << endl;
            cin >> level;

            if (level == 1)
            {
                move_car(car_x, car_y, final_x, final_y, easy_game_graph, easy_obstacs, scoreStack);
                current_level = 1;
            }
            else if (level == 2)
            {
                move_car(car_x, car_y, final_x, final_y, hard_game_graph, hard_obstacs, scoreStack);
                current_level = 2;
            }
            else
            {
                cout << "     Enter Correct Option" << endl;
                goto l;
            }
            break;
		}
        case 2:
        {
            car_x = 13;
            car_y = 30;
            easy_game_graph.display[car_x][car_y] = 'C';

            easy_game_graph.display[10][70] = 'F';

            easy_game_graph.print();
            automode(list, car_x, car_y, final_x, final_y, easy_game_graph.display);



            easy_game_graph.print();
        }
        case 3:
        {
            ifstream scoreFile("score.txt");
            if (scoreFile.is_open())
            {
                string line;
                while (getline(scoreFile, line))
                {

                    size_t commaPos = line.find(',');
                    if (commaPos != string::npos)
                    {
                        string player_name = line.substr(0, commaPos);
                        int score = stoi(line.substr(commaPos + 1));
                        root = insert(root, player_name, score);
                    }
                }
                scoreFile.close();
            }
            else
            {
                cout << "Unable to open score.txt" << endl;
                return 1;
            }
            displayLeaderBoard(root);
            system("PAUSE");
            system("cls");
            break; 
        }
        case 4:
        {
            instructin();
            break;
        }
        case 5:
        {
            system("cls");
            if (current_level == 0)
            {
                cout << "No game to resume. Please start a new game first." << endl;
            }
            else if (current_level == 1)
            {
				move_car(car_x, car_y, final_x, final_y, easy_game_graph, easy_obstacs, scoreStack);
			}
			
            else if (current_level == 2)
            {
				move_car(car_x, car_y, final_x, final_y, hard_game_graph, hard_obstacs, scoreStack);
			}
            else
            {
				cout << "Enter Correct Option" << endl;
                break;
			}
            
            break;
        }
        case 6:
        {
            //cout << "Exit the Game" << endl;
            ending();
            return 0;
        }
        break;
        default:
        {
            cout << "Enter Correct Option" << endl;
            break;
        }
        }
    }
    return 0;
}
