#include "stdafx.h"
#include "Menu.h"

using namespace std;

int main( int argc, const char* argv[] )
{
	if (argc < 2)
	{
		cout << "Wrong argument count. Expected 2." << endl << endl;
		exit( 1 );
	}
	ifstream in_file( argv[1], ios::in | ios::binary );
	ofstream out_file( argv[2], ios::out | ios::binary );

	if (!out_file.good())
	{
		cout << "Output file is corrupted or missing..." << endl;
		_getch();
		exit( 1 );
	}

	if (!in_file.good())
	{
		cout << "Input file is corrupted or missing..." << endl;
		_getch();
		exit( 1 );
	}

	Menu menu( in_file, out_file );
	menu.Show();

    return 0;
}

