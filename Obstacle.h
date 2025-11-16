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



//node for obstacles
struct nod
{
    int x;
    int y;
    string type;
    nod* next;

    nod()
    {
        x = 0;
        y = 0;
        type = "";
        next = NULL;
    }
};
//Here the obstacles are implemented
//Also queue implemented for the scoring
//obstacles are genrating Randomly
//Also Coins with name of stone are in queue
//That are also Randomly generated
class obstacle
{
public:
    nod* stone_head;
    nod* stone_tail;
    int count_stone;
    nod* stick_head;
    nod* stick_tail;
    int count_stick;

    obstacle()
    {
        count_stone = rand() % 10;
        count_stick = rand() % 10;
        stone_head = NULL;
        stone_tail = NULL;
        stick_head = NULL;
        stick_tail = NULL;
    }
    void stone_insertion()
    {
        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < count_stone; i++)
        {
            nod* stone = new nod();
            stone->x = rand() % 14 + 3;
            stone->y = rand() % 100 + 10;

            if (stone_head == NULL)
            {
                stone_head = stone;
                stone_tail = stone;
            }
            else
            {
                stone_tail->next = stone;
                stone_tail = stone_tail->next;
            }
        }
    }
    void stick_insertion()
    {
        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < count_stick; i++)
        {
            nod* stick = new nod();
            stick->x = rand() % 20 + 5;
            stick->y = rand() % 100 + 10;

            if (stick_head == NULL) {
                stick_head = stick;
                stick_tail = stick;
            }
            else
            {
                stick_tail->next = stick;
                stick_tail = stick_tail->next;
            }
        }
    }
    bool Is_stone_quey_empty()
    {

        if (stone_head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Is_stick_quey_empty()
    {

        if (stick_head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    nod* deque_stone()
    {

        nod* temp = stone_head;
        stone_head = stone_head->next;
        return temp;
    }
    nod* deque_stick()
    {

        nod* temp = stick_head;
        stick_head = stick_head->next;
        return temp;
    }

};
