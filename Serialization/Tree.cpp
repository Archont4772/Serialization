#include "stdafx.h"
#include "Tree.h"

using namespace std;

Tree::Tree() : IsLoaded( false )
{
}


Tree::~Tree() 
{
}

void Tree::Print()
{
	if (node_list.size() == 0)
	{
		cout << "The tree is empty" << endl;
		cout << endl << "Press any key to continue..." << endl;
		_getch();
		return;
	}

	for (size_t i = 0; i < node_list.size(); i++)
	{
		node_list[i]->Print();
	}
	cout << endl << "Press any key to continue..." << endl;
	_getch();
}

void Tree::FillWithTestValues()
{
	if ( IsLoaded ) return;

	// Just test values to be serialized into a file
	shared_ptr< Node > n0 = make_shared<Node>( 1, 0, 0 );
	node_list.push_back( n0 );

	shared_ptr< Node > n1 = make_shared<Node>( 2.3, 0, 1 );
	node_list.push_back( n1 );

	shared_ptr< Node > n2 = make_shared<Node>( "tt", 1, 2 );
	node_list.push_back( n2 );

	shared_ptr< Node > n3 = make_shared<Node>( "param", 0, 1 );
	node_list.push_back( n3 );

	shared_ptr< Node > n4 = make_shared<Node>( 2, 3, 2 );
	node_list.push_back( n4 );

	shared_ptr< Node > n5 = make_shared<Node>( 3.5, 4, 3 );
	node_list.push_back( n5 );

	IsLoaded = true;
}
