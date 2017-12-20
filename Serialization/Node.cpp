#include "stdafx.h"
#include "Node.h"

Node::Node( boost::variant< int32_t, double, string > _data, int _p_id, int _level )
	: m_data( _data ), m_parent_id( _p_id ), m_tree_level( _level )
{
}

Node::Node()
{

}

Node::~Node()
{
}

void Node::Print()
{
	for ( size_t i = 0; i < (size_t)m_tree_level; i++ )
	{
		cout << "    "; // 4 spaces
	}

	cout << m_data << endl;
}
