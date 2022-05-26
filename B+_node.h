#ifndef BPLUS_NODE
#define BPLUS_NODE

enum NODE_TYPE
{
	INTERNAL,
	LEAF
}; 
enum SIBLING_DIRECTION
{
	LEFT,
	RIGHT
}; 
const int ORDER = 10;					 	
const int MINNUM_KEY = ORDER - 1;		 	
const int MAXNUM_KEY = 2 * ORDER - 1;	 	
const int MINNUM_CHILD = MINNUM_KEY + 1; 	
const int MAXNUM_CHILD = MAXNUM_KEY + 1; 	
const int MINNUM_LEAF = MINNUM_KEY;		 	
const int MAXNUM_LEAF = MAXNUM_KEY;		 	

// 结点基类
template <typename KT, typename DT>
class CNode
{
public:
	CNode();
	virtual ~CNode();

	NODE_TYPE getType() const;
	void setType(NODE_TYPE type);
	int getKeyNum() const;
	void setKeyNum(int n);
	KT getKeyValue(int i) const;
	void setKeyValue(int i, KT key);

	int getKeyIndex(KT key) const; 
	
	virtual void removeKey(int keyIndex, int childIndex) = 0;																				  
	
	virtual void split(CNode *parentNode, int childIndex) = 0;																				
	virtual void mergeChild(CNode<KT, DT> *parentNode, CNode<KT, DT> *childNode, int keyIndex) = 0;					  
	virtual void clear() = 0;																												 
	virtual void borrowFrom(CNode<KT, DT> *destNode, CNode<KT, DT> *parentNode, int keyIndex, SIBLING_DIRECTION d) = 0; 
	virtual int getChildIndex(KT key, int keyIndex) = 0;																			  

protected:
	NODE_TYPE m_Type;
	int m_KeyNum;
	KT m_KeyValues[MAXNUM_KEY];
};


template <typename KT, typename DT>
class CInternalNode : public CNode<KT, DT>
{
public:
	CInternalNode();
	virtual ~CInternalNode();

	CNode<KT, DT> *getChild(int i) const;
	void setChild(int i, CNode<KT, DT> *child);

	void insert(int keyIndex, int childIndex, KT key, CNode<KT, DT> *childNode);
	virtual void split(CNode<KT, DT> *parentNode, int childIndex);
	virtual void mergeChild(CNode<KT, DT> *parentNode, CNode<KT, DT> *childNode, int keyIndex);
	virtual void removeKey(int keyIndex, int childIndex);
	virtual void clear();
	virtual void borrowFrom(CNode<KT, DT> *destNode, CNode<KT, DT> *parentNode, int keyIndex, SIBLING_DIRECTION d);
	virtual int getChildIndex(KT key, int keyIndex);

private:
	CNode<KT, DT> *m_Childs[MAXNUM_CHILD];
};

// 叶子结点
template <typename KT, typename DT>
class CLeafNode : public CNode<KT, DT>
{


public:
	CLeafNode();
	virtual ~CLeafNode();

	CLeafNode<KT, DT> *getLeftSibling() const;
	void setLeftSibling(CLeafNode<KT, DT> *node);
	CLeafNode<KT, DT> *getRightSibling() const;
	void setRightSibling(CLeafNode<KT, DT> *node);
	DT getData(int i);
	void setData(int i, const DT &data);

	DT *getDataAddr(int i);

	void mainInsert(KT key, const DT data);
	void insert(KT key, const DT data);
	virtual void split(CNode<KT, DT> *parentNode, int childIndex);
	virtual void mergeChild(CNode<KT, DT> *parentNode, CNode<KT, DT> *childNode, int keyIndex);
	virtual void removeKey(int keyIndex, int childIndex);
	virtual void clear();
	virtual void borrowFrom(CNode<KT, DT> *destNode, CNode<KT, DT> *parentNode, int keyIndex, SIBLING_DIRECTION d);
	virtual int getChildIndex(KT key, int keyIndex);

	//below is about the overflow
	void pour();
	void sortOverflow();
	void overflowInsert(KT key, const DT data);

private:
	CLeafNode<KT, DT> *m_LeftSibling;
	CLeafNode<KT, DT> *m_RightSibling;
	DT m_Data[MAXNUM_LEAF];

	
	KT m_keys_overflow[ORDER/2];
	DT m_data_overflow[ORDER/2];
	int m_overflow_size;
};

#endif