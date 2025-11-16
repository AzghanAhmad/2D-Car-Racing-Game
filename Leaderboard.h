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


//Making Binaary Tree for finding maximum score from file
//As instructed by Maam
struct BTree
{
    string player_name;
    int score;
    BTree* left;
    BTree* right;

    BTree(string name, int s)
    {
        player_name = name;
        score = s;
        left = nullptr;
        right = nullptr;
    }
};
// Function to insert a new node into the binary tree as we instructed by maam
BTree* insert(BTree* root, string player_name, int score)
{
    if (root == nullptr)
    {
        return new BTree(player_name, score);
    }

    if (score < root->score)
    {
        root->left = insert(root->left, player_name, score);
    }
    else if (score > root->score)
    {
        root->right = insert(root->right, player_name, score);
    }

    return root;
}
void printLeaderboard(BTree* root)  //to display all the players with their scores in leaderboard
{
    if (root != nullptr)
    {
        printLeaderboard(root->right);

        cout << "| " << root->player_name << "              " << root->score << endl;

        printLeaderboard(root->left);
    }
}
void displayLeaderBoard(BTree* root)
{

    HANDLE w = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(w, 10);
    cout << "\tLeaderboard" << endl;
    char x = 219;
    for (int i = 0; i <= 27; i++)
    {
        Sleep(60);
        cout << x;
    }
    //SetConsoleTextAttribute(w, 7);
    if (root != nullptr)
    {
        cout << "                          " << endl;
        cout << "| Name            Score   " << endl;
        cout << "|                         " << endl;
        printLeaderboard(root);
        cout << "|                         " << endl;
        cout << "--------------------------" << endl;
    }
    else
    {
        cout << "No players in the list." << endl;
    }
    SetConsoleTextAttribute(w, 7);
}

