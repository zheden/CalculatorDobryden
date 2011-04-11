#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>


using std::cout;
using std::endl;
using namespace boost;

class Node
{
public:
	Node(function<double(double,double)> func):_f(func){}

	shared_ptr<Node>& next()//head-left-rigth
	{
		if (_left!=0) 
			return _left;
		if (_right!=0) 
			return _right;
		if (this!=_father.lock()->_right.get()) 
			return _father.lock()->_right;
		if (this->_father.lock()!=_father.lock()->_father.lock()->_right) 
			return _father.lock()->_father.lock()->_right;
		return shared_ptr<Node>(this);
	}
	bool hasNoChild()
	{
		return ((_left==0)&&(_right==0));
	}
	function<double (double, double)>& f() {return _f;}
	shared_ptr<Node>& left(){return _left;}
	shared_ptr<Node>& right(){return _right;}
	weak_ptr<Node>& father(){return _father;}

private:
	function<double (double, double)> _f;
	shared_ptr<Node> _left,_right;
	weak_ptr<Node> _father;
};

class Tree
{
public:
	Tree(shared_ptr<Node>& n): _treeNode(n){}
	Tree& operator++()
	{
		_treeNode=_treeNode->next();//_treeNode=shared_ptr<Node>(&(_treeNode->next()));   ///?????? before Node& next()   ->error deleting pointers
  		return *this;
	}
	double operator()(double x, double y)
	{
		return _treeNode->f()(x, y);
	}
	bool hasNoChild()
	{
		return _treeNode->hasNoChild();
	}

private:
	shared_ptr<Node> _treeNode;
};


struct Fake 
{
	int fake(double, double){return _x;}
	Fake(double x):_x(x){}

	double _x;
};

double count(Tree& tr)
{
	if (tr.hasNoChild())
		return tr(0,0);

	Tree trcopy=tr;//because head first
	double l=count(++tr);///???? inside-> different result
	return trcopy(l, count(++tr));
}

int main()
{
	//============making nodes================
	Fake x3(3);
	Fake x5(5);
	Fake x10(10);

	shared_ptr<Node> n1(new Node(std::minus<double>()));
	shared_ptr<Node> n2(new Node(bind(&Fake::fake, ref(x3), _1, _2)));
	shared_ptr<Node> n3(new Node(std::divides<double>()));
	shared_ptr<Node> n4(new Node(bind(&Fake::fake, ref(x5), _1, _2)));
	shared_ptr<Node> n5(new Node(bind(&Fake::fake, ref(x10), _1, _2)));

	//connecting tree
	n1->left()=n2;
	n1->right()=n3;
	n3->left()=n4;
	n3->right()=n5;

	n2->father()=n1;
	n3->father()=n1;
	n4->father()=n3;
	n5->father()=n3;   //   3-5/10

	//===Tree==
	cout<<"==Tree=="<<endl;
	Tree tr(n1);
	
	cout<<"Result is "<<count(tr)<<endl;


	return 0;
}