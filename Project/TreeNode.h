class TreeNode
{
public:
	TreeNode();
	virtual TreeNode* setLeft(TreeNode* i_node);
	virtual TreeNode* setRight(TreeNode* i_node);

	virtual double getRes(double i_prev)=0;
	virtual double getLeftVal()=0;

protected:
	TreeNode* m_left;
	TreeNode* m_right;
};

class OperTreeNode : public TreeNode
{
public:
	OperTreeNode(char i_val);
	OperTreeNode(const OperTreeNode& i_node);
	OperTreeNode& operator=(const OperTreeNode& i_node);
	
	virtual char getVal() const;
	virtual double getRes(double i_prev);
	virtual double getLeftVal();

private:
	char m_val;
};

class NumberTreeNode : public TreeNode
{
public:
	NumberTreeNode(int i_val);
	NumberTreeNode(const NumberTreeNode& i_node);
	NumberTreeNode& operator=(const NumberTreeNode& i_node);

	virtual int getVal() const;
	virtual double getRes(double i_prev);
	virtual double getLeftVal();

private:
	int m_val;
};
