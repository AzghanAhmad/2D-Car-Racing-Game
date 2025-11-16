#pragma once

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

using namespace std;

int boundary_x = 25;        //nummber of rows of graph
int boundary_y = 120;      //number of colums in graph
int car_x = 1;
int car_y = 1;
int final_x = 23;
int final_y = 117;
int score = 0;        //startig score
string player_name;
int speed = 1;      //Basic speed

//Here is the implementaion of Graph in which
//Each fuction is in followings like Display,
//car movements,car controls,adjustment of obstacles, e.t.c
//node for obstcles
struct node
{
    int x;
    int y;
    node()
    {
        x = 0;
        y = 0;
    }
};
class graph
{
public:
    node* point;
    char** display;
    int total_node;
    bool* rand_node_display;
    bool** node_connection;

    graph(int total_node_)
    {

        total_node = total_node_;
        point = new node[total_node];

        rand_node_display = new bool[total_node];

        node_connection = new bool* [total_node];

        for (int i = 0; i < total_node; i++)
            node_connection[i] = new bool[4];

        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < total_node; i++)
            for (int j = 0; j < 4; j++)
                node_connection[i][j] = rand() % 2;
    }
    void check_node_Axis()
    {
        for (int i = 0; i < total_node; i++)
            cout << i + 1 << "  " << point[i].x << "   " << point[i].y << endl;
    }
    void make_graph_display_easy()      //for easy level
    {

        for (int i = 0; i < total_node; i++)
        {

            if (rand_node_display[i] == true)
                display[point[i].y][point[i].x] = '*';
        }

    }
    void make_graph_display_medium()   //for medium level
    {
        for (int i = 0; i < boundary_x; i++)
        {
            for (int j = 0; j < boundary_y; j++)
            {
                if (display[i][j] == 'C' || display[i][j] == 'F')
                    continue;                   // Skip car and finish point positions

                for (int i = 0; i < total_node; i++)
                {

                    if (rand_node_display[i] == true)
                        display[point[i].y][point[i].x] = '*';
                }


                if (j % 4 == 0)    //boundries
                    display[i][j] = '|';

                else if (j == 0 || j == boundary_y - 1)           // Left and right boundaries
                    display[i][j] = '|';
                else if (i == 0 || i == boundary_x - 1)            // Top and bottom boundaries
                    display[i][j] = '-';
            }
        }
    }
    void make_graph_display_hard()     //for hard level
    {
        for (int i = 0; i < boundary_x; i++)
        {
            for (int j = 0; j < boundary_y; j++)
            {
                if (display[i][j] == 'C' || display[i][j] == 'F')
                    continue;                   // Skip car and finish point positions

                for (int i = 0; i < total_node; i++)
                {

                    if (rand_node_display[i] == true)
                        display[point[i].y][point[i].x] = '*';
                }


                if (j % 2 == 0)    //boundries
                    display[i][j] = '|';

                else if (j == 0 || j == boundary_y - 1)           // Left and right boundaries
                    display[i][j] = '|';
                else if (i == 0 || i == boundary_x - 1)            // Top and bottom boundaries
                    display[i][j] = '-';
                if (j == 2)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 4)
                {
                    if (i % 3 == 0)
                        display[i][j] = ' ';
                }
                if (j == 6)
                {
                    if (i % 6 == 0)
                        display[i][j] = ' ';
                }
                if (j == 8)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 10)
                {
                    if (i % 13 == 0)
                        display[i][j] = ' ';
                }
                if (j == 12)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 14)
                {
                    if (i % 8 == 0)
                        display[i][j] = ' ';
                }
                if (j == 16)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 18)
                {
                    if (i % 9 == 0)
                        display[i][j] = ' ';
                }
                if (j == 20)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 22)
                {
                    if (i % 8 == 0)
                        display[i][j] = ' ';
                }
                if (j == 24)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 26)
                {
                    if (i % 4 == 0)
                        display[i][j] = ' ';
                }
                if (j == 28)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 30)
                {
                    if (i % 2 == 0)
                        display[i][j] = ' ';
                }
                if (j == 32)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 34)
                {
                    if (i % 8 == 0)
                        display[i][j] = ' ';
                }
                if (j == 36)
                {
                    if (i % 10 == 0)
                        display[i][j] = ' ';
                }
                if (j == 38)
                {
                    if (i % 6 == 0)
                        display[i][j] = ' ';
                }
                if (j == 40)
                {
                    if (i % 4 == 0)
                        display[i][j] = ' ';
                }
                if (j == 42)
                {
                    if (i % 12 == 0)
                        display[i][j] = ' ';
                }
                if (j == 44)
                {
                    if (i % 3 == 0)
                        display[i][j] = ' ';
                }
                if (j == 46)
                {
                    if (i % 10 == 0)
                        display[i][j] = ' ';
                }
                if (j == 48)
                {
                    if (i % 12 == 0)
                        display[i][j] = ' ';
                }
                if (j == 50)
                {
                    if (i % 16 == 0)
                        display[i][j] = ' ';
                }
                if (j == 52)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 54)
                {
                    if (i % 3 == 0)
                        display[i][j] = ' ';
                }
                if (j == 56)
                {
                    if (i % 6 == 0)
                        display[i][j] = ' ';
                }
                if (j == 58)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 60)
                {
                    if (i % 13 == 0)
                        display[i][j] = ' ';
                }
                if (j == 62)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 64)
                {
                    if (i % 8 == 0)
                        display[i][j] = ' ';
                }
                if (j == 66)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 68)
                {
                    if (i % 9 == 0)
                        display[i][j] = ' ';
                }
                if (j == 70)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 72)
                {
                    if (i % 8 == 0)
                        display[i][j] = ' ';
                }
                if (j == 74)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 76)
                {
                    if (i % 4 == 0)
                        display[i][j] = ' ';
                }
                if (j == 78)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 80)
                {
                    if (i % 2 == 0)
                        display[i][j] = ' ';
                }
                if (j == 82)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 84)
                {
                    if (i % 8 == 0)
                        display[i][j] = ' ';
                }
                if (j == 86)
                {
                    if (i % 10 == 0)
                        display[i][j] = ' ';
                }
                if (j == 88)
                {
                    if (i % 6 == 0)
                        display[i][j] = ' ';
                }
                if (j == 90)
                {
                    if (i % 4 == 0)
                        display[i][j] = ' ';
                }
                if (j == 92)
                {
                    if (i % 12 == 0)
                        display[i][j] = ' ';
                }
                if (j == 94)
                {
                    if (i % 3 == 0)
                        display[i][j] = ' ';
                }
                if (j == 96)
                {
                    if (i % 10 == 0)
                        display[i][j] = ' ';
                }
                if (j == 98)
                {
                    if (i % 12 == 0)
                        display[i][j] = ' ';
                }
                if (j == 100)
                {
                    if (i % 16 == 0)
                        display[i][j] = ' ';
                }
                if (j == 102)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 104)
                {
                    if (i % 3 == 0)
                        display[i][j] = ' ';
                }
                if (j == 106)
                {
                    if (i % 6 == 0)
                        display[i][j] = ' ';
                }
                if (j == 108)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 110)
                {
                    if (i % 13 == 0)
                        display[i][j] = ' ';
                }
                if (j == 112)
                {
                    if (i % 11 == 0)
                        display[i][j] = ' ';
                }
                if (j == 114)
                {
                    if (i % 8 == 0)
                        display[i][j] = ' ';
                }
                if (j == 116)
                {
                    if (i % 7 == 0)
                        display[i][j] = ' ';
                }
                if (j == 118)
                {
                    if (i % 9 == 0)
                        display[i][j] = ' ';
                }
            }
        }
    }
    //This will print the Player name and score on top of Grid Boundaries
    void print()
    {

        cout << endl << endl;

        cout << "   ->  Press V to speed up" << endl;
        cout << "   ->  Press B to speed down" << endl;
        cout << "   Player Name :   " << player_name << "       Score  :  " << score << endl;
        for (int i = 0; i < boundary_x; i++)
        {

            for (int j = 0; j < boundary_y; j++)
                cout << display[i][j];
            cout << endl;
        }

    }
    //THis will create the boundries 
    void create_display_easy()
    {

        display = new char* [boundary_x];

        for (int i = 0; i < boundary_x; i++)
            display[i] = new char[boundary_y];

        for (int i = 0; i < boundary_x; i++)
            for (int j = 0; j < boundary_y; j++)
                display[i][j] = ' ';

        for (int i = 0; i < boundary_x; i++)  // mark left bounday
            display[i][0] = '|';

        for (int i = 0; i < boundary_x; i++)  // mark right bounday
            display[i][boundary_y - 1] = '|';

        for (int i = 0; i < boundary_y; i++)  // mark  top bounday
            display[0][i] = '-';

        for (int i = 0; i < boundary_y; i++)  // mark bottom bounday
            display[boundary_x - 1][i] = '-';

    }
    void create_display_medium()
    {
        display = new char* [boundary_x];

        for (int i = 0; i < boundary_x; i++)
            display[i] = new char[boundary_y];

        for (int i = 0; i < boundary_x; i++)
            for (int j = 0; j < boundary_y; j++)
                display[i][j] = ' ';


    }
    void create_display_hard()
    {
        display = new char* [boundary_x];

        for (int i = 0; i < boundary_x; i++)
            display[i] = new char[boundary_y];

        for (int i = 0; i < boundary_x; i++)
            for (int j = 0; j < boundary_y; j++)
                display[i][j] = ' ';

        for (int i = 0; i < boundary_x; i++)
            for (int j = 0; j < boundary_y; j++)
            {
                if (i == car_x && j == car_y)
                    display[i][j] = 'C'; // Place the car at the initial position
                else if (i == 23 && j == 117)
                    display[i][j] = 'F'; // Place the finish point at a specific position
            }
    }
    void mark_node_axis()
    {
        int x, y;
        x = 10; y = 4;
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < total_node / 4; j++)
            {
                point[j + count].x = x;
                point[j + count].y = y;
                x += 15;
            }
            x = 10; y += 4;
            count += total_node / 4;
        }
    }
    //set random node 
    void set_random_node()
    {

        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < total_node; i++)
            rand_node_display[i] = rand() % 2;
    }

    //This will show connection between obstacles,horizontal and verticaly. 
    void mark_edges_connectin()
    {

        for (int i = 0; i < boundary_x; i++)     // mark random horizantal nodes connection
        {

            for (int j = 0; j < boundary_y; j++)
            {

                if (display[i][j] == '*' and (node_connection[i][0] || node_connection[i][1])) {

                    for (int k = j + 1; k < boundary_y; k++)
                    {
                        if (display[i][k] == '*')
                        {
                            for (int h = j + 1; h < k - 1; h++)
                                display[i][h] = '-';
                        }
                    }
                }
            }
        }


        for (int i = 0; i < boundary_y; i++)          // mark random vertical nodes connection
        {

            for (int j = 0; j < boundary_x; j++)
            {

                if (display[j][i] == '*')
                {

                    for (int k = j + 1; k < boundary_x; k++)
                    {
                        if (display[k][i] == '*')
                        {
                            for (int h = j + 1; h < k; h++)
                                display[h][i] = '|';
                        }
                    }
                }
            }
        }
    }



};