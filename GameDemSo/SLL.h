//
// @Author: Van Cong Le Ca
//
#include "common.h"

struct NodeData
{
private:
	Data __data;
	NodeData * __next;
public:
	void set_data(const unsigned int data);
	void set_next_node(NodeData * p);

	unsigned int get_data();
	NodeData * get_next_node();
};

struct SLL
{
private:
	NodeData * __head;
	NodeData * __tail;
	unsigned int  __count;
public:
	SLL();
	~SLL();

	void set_head(NodeData * p);
	void set_tail(NodeData * p);
	void set_count(const unsigned int input_count);

	NodeData * get_head();
	NodeData * get_tail();
	unsigned int get_count();

	NodeData *createNote(unsigned int data);
	void addTail(unsigned int data);
	void sorting();
	void Print();

};