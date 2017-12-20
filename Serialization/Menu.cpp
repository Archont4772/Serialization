#include "stdafx.h"
#include "Menu.h"

using namespace std;

Menu::Menu( ifstream& _in_file, ofstream& _out_file ) : in_file( _in_file ), out_file( _out_file )
{
}


Menu::~Menu()
{
}

void Menu::Show()
{
	char key;
	bool IsTried = false;
	do
	{
		system( "CLS" );
		cout << "Welcome to the Matrix" << endl << endl;
		cout << "1. Load test data to the tree" << endl;
		cout << "2. Serialize tree to a file" << endl;
		cout << "3. Print tree" << endl;
		cout << "4. Deserialize tree" << endl;
		
		cout << "Press ESC to Disconnect" << endl << endl;
		key = _getch();

		switch (key)
		{
		case '1':
		{
			marple.FillWithTestValues();
			cout << "Data loading was successful" << endl << endl;
			cout << "Press any key to continue..." << endl;
			_getch();
			break;
		}
		case '2':
		{
			boost::archive::text_oarchive oa( out_file );
			oa << marple;
			cout << "Serialization was successful" << endl << endl;
			cout << "Press any key to continue..." << endl;
			_getch();
			break;
		}
		case '3':
		{
			marple.Print();
			break;
		}
		case '4':
		{
			if ( IsTried ) break; // Workaround of unhandled exception inside Archive
			// while trying to deserialize file second time
			boost::archive::text_iarchive ia( in_file );
			ia >> marple;
			cout << "Deserialization was successful" << endl << endl;
			cout << "Press any key to continue..." << endl;
			_getch();
			IsTried = true;
			break;
		}
		case ESC:
			exit( 0 );
		default:
			break;
		}
	} while (key != ESC);
}
