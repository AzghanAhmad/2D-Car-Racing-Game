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

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }
    int gettop()
    {
		return top->data;
	}

    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};
