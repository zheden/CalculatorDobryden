#ifndef __TreeNode_h__//comment
#include "TreeNode.h"
//#define __TreeNode_h__
#endif


//#include "TreeNode.h"

TreeNode::TreeNode(): m_left(0), m_right(0){}
TreeNode* TreeNode::setLeft(TreeNode* i_node)//left son
{
	m_left=i_node;
	return this;
}
TreeNode* TreeNode::setRight(TreeNode* i_node)//right son
{
	m_right=i_node;
	return this;
}

OperTreeNode::OperTreeNode(char i_val):TreeNode(), m_val(i_val){}
OperTreeNode::OperTreeNode(const OperTreeNode& i_node): m_val(i_node.getVal()){}	
OperTreeNode& OperTreeNode::operator=(const OperTreeNode& i_node)
{
	m_val=i_node.getVal(); 
	return *this;
}
char OperTreeNode::getVal() const
{
	return m_val;
}
double OperTreeNode::getRes(double i_prev)// i_prev is counted previous result 
{
	double curres;
	switch (m_val){
	case '-':
		curres=-1*(m_right->getLeftVal());//take the value of left son if right son and give as i_prec to right son
		return i_prev+m_right->getRes(curres);//we go go down until our treenode will be number
	case '+':
		curres=m_right->getLeftVal();
		return i_prev+m_right->getRes(curres);
	case '*':
		curres=i_prev*m_right->getLeftVal();
		return m_right->getRes(curres);
	case '/':
		if (m_right->getLeftVal()==0) throw "Division by zero!";
		curres=i_prev/m_right->getLeftVal();
		return m_right->getRes(curres);
	}
	throw "Unknown operator";
}
double OperTreeNode::getLeftVal()//value of left son
{
	return m_left->getLeftVal();
}

NumberTreeNode::NumberTreeNode(int i_val):TreeNode(), m_val(i_val){}
NumberTreeNode::NumberTreeNode(const NumberTreeNode& i_node): m_val(i_node.getVal()){}
NumberTreeNode& NumberTreeNode::operator=(const NumberTreeNode& i_node)
{
	m_val=i_node.getVal(); 
	return *this;
}
int NumberTreeNode::getVal() const
{
	return m_val;
}
double NumberTreeNode::getRes(double i_prev)
{
	return i_prev;
}
double NumberTreeNode::getLeftVal()// if node is number we return its value
{
	return this->m_val;
}