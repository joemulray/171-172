#include <iostream>
#include <string>
#include <vector>
using namespace std;


Node::Node(int d, Node * N)
{
    Data(d);
    Next(N);
}

int Node::Data() const
{
    return Data_;
}

void Node::Data(int d)
{
    Data_ = d;
}

Node * Node::Next() const
{
    return Next_;
}

void Next(Node * N)
{
    Next_ = N;
}