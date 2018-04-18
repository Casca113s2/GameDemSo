#include "SLL.h"

void NodeData::set_data(const unsigned int data)
{
	__data.set_data(data);
}

void NodeData::set_next_node(NodeData * p)
{
	__next = p;
}

unsigned int NodeData::get_data()
{
	return __data.get_data();
}

NodeData * NodeData::get_next_node()
{
	return __next;
}

SLL::SLL()
{
	__head = NULL;
	__tail = NULL;
	__count = 0;
}

SLL::~SLL()
{
	NodeData * p = __head;
	NodeData * temp;
	while (p != NULL)
	{
		temp = p;
		p = p->get_next_node();
		delete temp;
	}
}

void SLL::set_head(NodeData * p)
{
	__head = p;
}

void SLL::set_tail(NodeData * p)
{
	__tail = p;
}

void SLL::set_count(const unsigned int input_count)
{
	__count += input_count;
}

NodeData * SLL::get_head()
{
	return __head;
}

NodeData * SLL::get_tail()
{
	return __tail;
}

unsigned int SLL::get_count()
{
	return __count;
}

NodeData * SLL::createNote(unsigned int data)
{
	NodeData *p = new NodeData;
	if (p == NULL)
	{
		cout << "Can't allocate memory for the node" << "\n";
		return NULL;
	}
	p->set_data(data);
	p->set_next_node(NULL);

	return p;
}

void SLL::addTail(unsigned int data)
{
	NodeData *p = createNote(data);
	if (__head == NULL)
	{
		__head = __tail = p;
	}
	else
	{
		__tail->set_next_node(p);
		__tail = p;
	}
}

void SLL::sorting()
{
	NodeData * temp_ptr = __head;
	unsigned int temp_data = 0;
	for (int i = 0; i < (__count); i++)
	{
		for (int j = 0; j < ((__count) - i -1); j++)
		{
			if (temp_ptr->get_data() > temp_ptr->get_next_node()->get_data())
			{
				temp_data = temp_ptr->get_data();
				temp_ptr->set_data(temp_ptr->get_next_node()->get_data());
				temp_ptr->get_next_node()->set_data(temp_data);
			}
			temp_ptr = temp_ptr->get_next_node();
		}
		temp_ptr = __head;
	}
}

void SLL::Print()
{
	for (NodeData *p = __head; p != NULL; p = p->get_next_node())
	{
		cout << p->get_data() << "\n";
	}
}
