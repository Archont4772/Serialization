#pragma once
#include <vector>
#include <memory>
#include <string>

#include <boost/variant.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/variant.hpp>

using namespace std;

class Node
{
public:
	Node();
	Node( boost::variant< int32_t, double, string >, int _p_id, int _level );
	~Node();
	void Print();
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize( Archive & ar, const unsigned int version )
	{
		ar & m_data;
		ar & m_parent_id;
		ar & m_tree_level;
	}

	boost::variant< int32_t, double, string > m_data;
	int32_t m_parent_id; // used for linking to the parent node
	int32_t m_tree_level; // used for printing tree
};

