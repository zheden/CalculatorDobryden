//#pragma once

#include <iostream>
#include <vector>
using namespace std;


#include "TreeNode.h"
#include "OperationsTree.h"

//Dobryden Zhenya
int main()
{
	try
	{
		cout<<"==1=="<<endl;
		vector <TreeNode*> vectExample;
		makeNodesVector("6+2*5", vectExample);
		makeConnectedTree(vectExample);
		cout<<"Result is "<<calculateTree(vectExample)<<endl;
		cout<<"Correct is "<<6+2*5<<endl<<endl;

		cout<<"==2=="<<endl;
		vectExample.clear();
		makeNodesVector("60+2*5-6/3", vectExample);
		makeConnectedTree(vectExample);
		cout<<"Result is "<<calculateTree(vectExample)<<endl;
		cout<<"Correct is "<<60+2*5-6/3<<endl<<endl;

		cout<<"==3=="<<endl;
		vectExample.clear();
		makeNodesVector("100-2*3*100+1", vectExample);
		makeConnectedTree(vectExample);
		cout<<"Result is "<<calculateTree(vectExample)<<endl;
		cout<<"Correct is "<<100-2*3*100+1<<endl<<endl;

		cout<<"==4=="<<endl;
		vectExample.clear();
		makeNodesVector("3+7/2", vectExample);
		makeConnectedTree(vectExample);
		cout<<"Result is "<<calculateTree(vectExample)<<endl;
		cout<<"Correct is "<<3+7*0.5<<endl<<endl;

		cout<<"==5=="<<endl;
		vectExample.clear();
		makeNodesVector("6+2*5*10/0", vectExample);
		makeConnectedTree(vectExample);
		cout<<"Result is "<<calculateTree(vectExample)<<endl;

	}
	catch (char* error)
	{
		cout<<error<<endl;
	}

	return 0;
}