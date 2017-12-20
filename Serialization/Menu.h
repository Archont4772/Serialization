#pragma once
#include "Tree.h"

#define ESC 27

class Menu
{
public:
	Menu( ifstream& _in_file,  ofstream& _out_file );
	~Menu();
	void Show();
private:
	ifstream& in_file;
	ofstream& out_file;
	Tree marple; // marple = клён
};
