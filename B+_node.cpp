#pragma once
#include "B+_node.h"
#include <iostream>
using namespace std;

template <typename KT, typename DT>
CNode<KT, DT>::CNode()
{
	setType(LEAF);
	setKeyNum(0);
}

template <typename KT, typename DT>
CNode<KT, DT>::~CNode()
{
	setKeyNum(0);
}

template <typename KT, typename DT>
NODE_TYPE CNode<KT, DT>::getType() const { return m_Type; }

template <typename KT, typename DT>
void CNode<KT, DT>::setType(NODE_TYPE type) { this->m_Type = type; }

template <typename KT, typename DT>
int CNode<KT, DT>::getKeyNum() const
{
	return m_KeyNum;
}

template <typename KT, typename DT>
void CNode<KT, DT>::setKeyNum(int n)
{
	m_KeyNum = n;
}

template <typename KT, typename DT>
KT CNode<KT, DT>::getKeyValue(int i) const
{
	return m_KeyValues[i];
}

template <typename KT, typename DT>
void CNode<KT, DT>::setKeyValue(int i, KT key)
{
	m_KeyValues[i] = key;
}

template <typename KT, typename DT>
int CNode<KT, DT>::getKeyIndex(KT key) const
{
	
	if (getKeyNum() == 0)
		return 0;
	
	int ret = this->getKeyNum() - 1;
	for (int i=0;i<this->getKeyNum();i++)
	{
		if (this->m_KeyValues[i] >= key)
		{
			ret = i;
			/
			break;
		}
	}
	return ret;
}


template <typename KT, typename DT>
CInternalNode<KT, DT>::CInternalNode()
{
	this->setType(INTERNAL);
}

template <typename KT, typename DT>
CInternalNode<KT, DT>::~CInternalNode()
{
}

template <typename KT, typename DT>
CNode<KT, DT> *CInternalNode<KT, DT>::getChild(int i) const { return m_Childs[i]; }

template <typename KT, typename DT>
void CInternalNode<KT, DT>::setChild(int i, CNode<KT, DT> *child) { m_Childs[i] = child; }

template <typename KT, typename DT>
void CInternalNode<KT, DT>::clear()
{
	for (int i = 0; i <= this->m_KeyNum; ++i)
	{
		if (!m_Childs[i])
		{
			m_Childs[i]->clear();
			delete m_Childs[i];
			m_Childs[i] = NULL;
		}
	}
}

template <typename KT, typename DT>
void CInternalNode<KT, DT>::split(CNode<KT, DT> *parentNode, int childIndex)
{
	CInternalNode<KT, DT> *newNode = new CInternalNode<KT, DT>; 
	newNode->setKeyNum(MINNUM_KEY);
	int i;
	for (i = 0; i < MINNUM_KEY; ++i) // COPY THE value of key
	{
		newNode->setKeyValue(i, this->m_KeyValues[i + MINNUM_CHILD]);
	}
	for (i = 0; i < MINNUM_CHILD; ++i) // Copy the child node pointer
	{
		newNode->setChild(i, m_Childs[i + MINNUM_CHILD]);
	}
	this->setKeyNum(MINNUM_KEY); 
	((CInternalNode<KT, DT> *)parentNode)->insert(childIndex, childIndex + 1, this->m_KeyValues[MINNUM_KEY], newNode);
}

template <typename KT, typename DT>
void CInternalNode<KT, DT>::insert(int keyIndex, int childIndex, KT key, CNode<KT, DT> *childNode)
{
	int i;
	for (i = this->getKeyNum(); i > keyIndex; --i) 
	{
		setChild(i + 1, m_Childs[i]);
		this->setKeyValue(i, this->m_KeyValues[i - 1]);
	}
	if (i == childIndex)
	{
		setChild(i + 1, m_Childs[i]);
	}
	setChild(childIndex, childNode);
	this->setKeyValue(keyIndex, key);
	this->setKeyNum(this->m_KeyNum + 1);
}

template <typename KT, typename DT>
void CInternalNode<KT, DT>::mergeChild(CNode<KT, DT> *parentNode, CNode<KT, DT> *childNode, int keyIndex)
{
	// 合并数据
	insert(MINNUM_KEY, MINNUM_KEY + 1, parentNode->getKeyValue(keyIndex), ((CInternalNode<KT, DT> *)childNode)->getChild(0));
	int i;
	for (i = 1; i <= childNode->getKeyNum(); ++i)
	{
		insert(MINNUM_KEY + i, MINNUM_KEY + i + 1, childNode->getKeyValue(i - 1), ((CInternalNode<KT, DT> *)childNode)->getChild(i));
	}
	//父节点删除index的key
	parentNode->removeKey(keyIndex, keyIndex + 1);
	delete ((CInternalNode<KT, DT> *)parentNode)->getChild(keyIndex + 1);
}

template <typename KT, typename DT>
void CInternalNode<KT, DT>::removeKey(int keyIndex, int childIndex)
{
	for (int i = 0; i < this->getKeyNum() - keyIndex - 1; ++i)
	{
		this->setKeyValue(keyIndex + i, this->getKeyValue(keyIndex + i + 1));
		setChild(childIndex + i, getChild(childIndex + i + 1));
	}
	this->setKeyNum(this->getKeyNum() - 1);
}

template <typename KT, typename DT>
void CInternalNode<KT, DT>::borrowFrom(CNode<KT, DT> *siblingNode, CNode<KT, DT> *parentNode, int keyIndex, SIBLING_DIRECTION d)
{
	switch (d)
	{
	case LEFT: 
	{
		insert(0, 0, parentNode->getKeyValue(keyIndex), ((CInternalNode<KT, DT> *)siblingNode)->getChild(siblingNode->getKeyNum()));
		parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(siblingNode->getKeyNum() - 1));
		siblingNode->removeKey(siblingNode->getKeyNum() - 1, siblingNode->getKeyNum());
	}
	break;
	case RIGHT: 
	{
		insert(this->getKeyNum(), this->getKeyNum() + 1, parentNode->getKeyValue(keyIndex), ((CInternalNode<KT, DT> *)siblingNode)->getChild(0));
		parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(0));
		siblingNode->removeKey(0, 0);
	}
	break;
	default:
		break;
	}
}

template <typename KT, typename DT>
int CInternalNode<KT, DT>::getChildIndex(KT key, int keyIndex)
{
	if (key >= this->getKeyValue(keyIndex))
	{
		return keyIndex + 1;
	}
	else
	{
		return keyIndex;
	}
}

// CLeafNode
template <typename KT, typename DT>
CLeafNode<KT, DT>::CLeafNode()
{
	this->setType(LEAF);
	setLeftSibling(NULL);
	setRightSibling(NULL);

	m_overflow_size = 0;
}

template <typename KT, typename DT>
CLeafNode<KT, DT>::~CLeafNode()
{
}

template <typename KT, typename DT>
CLeafNode<KT, DT> *CLeafNode<KT, DT>::getLeftSibling() const { return m_LeftSibling; }

template <typename KT, typename DT>
void CLeafNode<KT, DT>::setLeftSibling(CLeafNode<KT, DT> *node) { m_LeftSibling = node; }

template <typename KT, typename DT>
CLeafNode<KT, DT> *CLeafNode<KT, DT>::getRightSibling() const { return m_RightSibling; }

template <typename KT, typename DT>
void CLeafNode<KT, DT>::setRightSibling(CLeafNode<KT, DT> *node) { m_RightSibling = node; }

template <typename KT, typename DT>
DT CLeafNode<KT, DT>::getData(int i)
{
	this->pour();
	return m_Data[i];
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::setData(int i, const DT &data)
{
	m_Data[i] = data;
}

template <typename KT, typename DT>
DT *CLeafNode<KT, DT>::getDataAddr(int i)
{
	this->pour();
	return &(m_Data[i]);
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::clear()
{
	for (int i = 0; i < this->m_KeyNum; ++i)
	{
		
	}
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::mainInsert(KT key, const DT data)
{
	int i;
	for (i = this->m_KeyNum; i >= 1 && this->m_KeyValues[i - 1] > key; --i)
	{
		this->setKeyValue(i, this->m_KeyValues[i - 1]);
		setData(i, m_Data[i - 1]);
	}
	this->setKeyValue(i, key);
	setData(i, data);
	this->setKeyNum(this->m_KeyNum + 1);
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::insert(KT key, const DT data)
{


	if (this->m_KeyNum + ORDER / 2 > MAXNUM_LEAF)
	{
		mainInsert(key, data);
	}
	else
	{
		overflowInsert(key, data);
	}
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::split(CNode<KT, DT> *parentNode, int childIndex)
{
	this->pour();
	CLeafNode<KT, DT> *newNode = new CLeafNode<KT, DT>; 
	this->setKeyNum(MINNUM_LEAF);
	newNode->setKeyNum(MINNUM_LEAF + 1);
	newNode->setRightSibling(getRightSibling());
	setRightSibling(newNode);
	newNode->setLeftSibling(this);
	int i;
	for (i = 0; i < MINNUM_LEAF + 1; ++i) 
	{
		newNode->setKeyValue(i, this->m_KeyValues[i + MINNUM_LEAF]);
	}
	for (i = 0; i < MINNUM_LEAF + 1; ++i) 
	{
		newNode->setData(i, m_Data[i + MINNUM_LEAF]);
	}
	((CInternalNode<KT, DT> *)parentNode)->insert(childIndex, childIndex + 1, this->m_KeyValues[MINNUM_LEAF], newNode);
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::mergeChild(CNode<KT, DT> *parentNode, CNode<KT, DT> *childNode, int keyIndex)
{
	this->pour();
	
	for (int i = 0; i < childNode->getKeyNum(); ++i)
	{
		insert(childNode->getKeyValue(i), ((CLeafNode *)childNode)->getData(i));
	}
	setRightSibling(((CLeafNode *)childNode)->getRightSibling());
	
	parentNode->removeKey(keyIndex, keyIndex + 1);
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::removeKey(int keyIndex, int childIndex)
{
	this->pour();
	for (int i = keyIndex; i < this->getKeyNum() - 1; ++i)
	{
		this->setKeyValue(i, this->getKeyValue(i + 1));
		setData(i, getData(i + 1));
	}
	this->setKeyNum(this->getKeyNum() - 1);
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::borrowFrom(CNode<KT, DT> *siblingNode, CNode<KT, DT> *parentNode, int keyIndex, SIBLING_DIRECTION d)
{
	this->pour();
	switch (d)
	{
	case LEFT: 
	{
		insert(siblingNode->getKeyValue(siblingNode->getKeyNum() - 1), ((CLeafNode *)siblingNode)->getData(siblingNode->getKeyNum() - 1));
		siblingNode->removeKey(siblingNode->getKeyNum() - 1, siblingNode->getKeyNum() - 1);
		parentNode->setKeyValue(keyIndex, this->getKeyValue(0));
	}
	break;
	case RIGHT: 
	{
		insert(siblingNode->getKeyValue(0), ((CLeafNode *)siblingNode)->getData(0));
		siblingNode->removeKey(0, 0);
		parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(0));
	}
	break;
	default:
		break;
	}
}

template <typename KT, typename DT>
int CLeafNode<KT, DT>::getChildIndex(KT key, int keyIndex)
{
	this->pour();
	return keyIndex;
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::pour()
{
	if (m_overflow_size == 0)
		return;
	
	sortOverflow();
	
	for (int k = 0; k < m_overflow_size; k++)
	{
		KT key = m_keys_overflow[k];
		DT data = m_data_overflow[k];

		mainInsert(key, data);
	}
	m_overflow_size = 0;
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::sortOverflow()
{
	int end_of_sorted = 0;

	while (end_of_sorted < m_overflow_size - 1)
	{
		int start = 0;

		while (m_keys_overflow[start] < m_keys_overflow[end_of_sorted + 1])
		{
			start++;
		}

		int temp = m_keys_overflow[end_of_sorted + 1];

		for (int i = end_of_sorted; i >= start; i--)
		{
			m_keys_overflow[i + 1] = m_keys_overflow[i];
			m_data_overflow[i + 1] = m_data_overflow[i];
		}

		m_keys_overflow[start] = temp;
		end_of_sorted++;
	}
}

template <typename KT, typename DT>
void CLeafNode<KT, DT>::overflowInsert(KT key, const DT data)
{
	if (m_overflow_size >= ORDER / 2)
		pour();
	m_keys_overflow[m_overflow_size] = key;
	m_data_overflow[m_overflow_size] = data;
	m_overflow_size++;
}
