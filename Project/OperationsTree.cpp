#include <string>
#include <vector>
#include <sstream>
using namespace std;

#include "TreeNode.h"

void makeConnectedTree(vector <TreeNode*>& io_tree)//sets left and rigtht values ofTreeNodes
{
	int i;
	for (i=1; i<io_tree.size()-2; ++i)
	{
		io_tree[i]->setLeft(io_tree[i-1]);
		io_tree[i]->setRight(io_tree[i+2]);
	}
	io_tree[i]->setLeft(io_tree[i-1]);
	io_tree[i]->setRight(io_tree[i+1]);
}
double calculateTree(const vector <TreeNode*>& i_tree)//returns the result of arithmetic operations in our task
{
	return i_tree[1]->getRes(double(i_tree[1]->getLeftVal()));
}
int intFromString(const string& i_str)//string into int
{
	int resValue;
	istringstream stream(i_str);
	stream >> resValue;
	return resValue;
}
TreeNode* strGetNum(const string& i_str, size_t& i_numPos, bool& io_nextislast)//returns number from numPos position
{
	size_t numPos = i_str.find_first_of("1234567890", i_numPos);
	size_t endPos;
	if (!io_nextislast) 
	{
		endPos = i_str.find_first_of("+-/*", numPos);//*
		size_t checkEndPos = i_str.find_last_of("+-/*");
		if (endPos==checkEndPos) 
			io_nextislast=true;
	}
	else //if this number is last in our string (the * would be incorrect):
		endPos = i_str.length();
	i_numPos=endPos;

	string value=i_str.substr(numPos, endPos - numPos);	
	int resValue=intFromString(value);

	return new NumberTreeNode(resValue);
}
TreeNode* strGetPos(const string& i_str, size_t& i_numPos)// the same for operator
{
	string value=i_str.substr(i_numPos, 1);
	++i_numPos;
	return new OperTreeNode(value[0]);	
}
void makeNodesVector(const string& i_str, vector<TreeNode*>& io_vect)//building vector of treeNodes from our string
{
	bool islast(false);
	size_t numPos(0);
	while (!islast)
	{
		io_vect.push_back(strGetNum(i_str, numPos,islast));
		io_vect.push_back(strGetPos(i_str, numPos));
	}
	io_vect.push_back(strGetNum(i_str, numPos,islast));
	return;	
}