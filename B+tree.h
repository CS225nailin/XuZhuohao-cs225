#ifndef BPLUS_TREE_H
#define BPLUS_TREE_H

#include "B+_node.cpp"
#include <vector>
using namespace std;

enum COMPARE_OPERATOR
{
	LT,
	LE,
	EQ,
	BE,
	BT,
	BETWEEN
}; // 比较操作符：<、<=、=、>=、>、<>
const int INVALID_INDEX = -1;

template <typename KT, typename DT>
struct SelectResult
{
	int keyIndex;
	CLeafNode<KT, DT> *targetNode;
};

template <typename KT, typename DT>
class CBPlusTree
{
public:
	
	CBPlusTree();
	~CBPlusTree();

	
	bool insert(KT key, const DT data);
	bool remove(KT key);
	bool update(KT oldKey, KT newKey);


	vector<DT> oneSideSelect(KT compareKey, int compareOpeartor) const;

	
	vector<DT> twoSideSelect(KT smallKey, KT largeKey) const;


	bool search(KT key) const;


	DT *getDataHandle(KT key) const;

	
	void clear();
	DT *report();

	void print() const;


	void printData() const;
	int getnum();
	int num;
private:
	void recursive_insert(CNode<KT, DT> *parentNode, KT key, const DT data);
	void recursive_remove(CNode<KT, DT> *parentNode, KT key);
	void printInConcavo(CNode<KT, DT> *pNode, int count) const;
	bool recursive_search(CNode<KT, DT> *pNode, KT key) const;
	void recursive_search(CNode<KT, DT> *pNode, KT key, SelectResult<KT, DT> &result);
	DT *recursive_getDataHandle(CNode<KT, DT> *pNode, KT key) const;
	void changeKey(CNode<KT, DT> *pNode, KT oldKey, KT newKey);
	void search(KT key, SelectResult<KT, DT> &result);
	void remove(KT key, DT &dataValue);
	void recursive_remove(CNode<KT, DT> *parentNode, KT key, DT &dataValue);

private:
	CNode<KT, DT> *m_Root;
	CLeafNode<KT, DT> *m_DataHead;
	KT m_MaxKey; // B+树中的最大键
	DT* rep;

};

#endif
