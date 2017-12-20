#pragma once
#include <vector>
#include <memory>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include "Node.h"

using namespace std;
class Tree
{
public:
	enum Types
	{
		INT,
		DOUBLE,
		STRING,
	};

	Tree();
	~Tree();
	void Print();
	void FillWithTestValues();
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize( Archive & ar, const unsigned int version )
	{
		ar & node_list;
	}
	vector< shared_ptr< Node > > node_list;
	bool IsLoaded;
};

