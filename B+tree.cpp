#pragma once
#include "B+tree.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <typename KT, typename DT>
CBPlusTree<KT, DT>::CBPlusTree()
{
	m_Root = NULL;
	m_DataHead = NULL;
<<<<<<< HEAD
	rep=new DataType[10000];
	num = 0;
=======
	rep=new DT[10000];
>>>>>>> f6c7b2acae6db10d88aed77a03f11c1be1bc7019

}

template <typename KT, typename DT>
CBPlusTree<KT, DT>::~CBPlusTree()
{
	clear();
}

template <typename KT, typename DT>
bool CBPlusTree<KT, DT>::insert(KT key, const DT data)
{
	
	if (search(key))
	{
	
		return false;
	}

	if (m_Root == NULL)
	{
		
		m_Root = new CLeafNode<KT, DT>;
		m_DataHead = (CLeafNode<KT, DT> *)m_Root;
		m_MaxKey = key;
	}
	if (m_Root->getKeyNum() >= MAXNUM_KEY) 
	{
		
		CInternalNode<KT, DT> *newNode = new CInternalNode<KT, DT>; 
		newNode->setChild(0, m_Root);
		m_Root->split(newNode, 0);
		m_Root = newNode;		  
	}
	if (key > m_MaxKey) 
	{
		
		m_MaxKey = key;
	}
	recursive_insert(m_Root, key, data);
	return true;
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::recursive_insert(CNode<KT, DT> *parentNode, KT key, const DT data)
{
	if (parentNode->getType() == LEAF) 
	{
		
		((CLeafNode<KT, DT> *)parentNode)->insert(key, data);
	}
	else
	{
		
		int keyIndex = parentNode->getKeyIndex(key);
		int childIndex = parentNode->getChildIndex(key, keyIndex); 
		CNode<KT, DT> *childNode = ((CInternalNode<KT, DT> *)parentNode)->getChild(childIndex);
		if (childNode->getKeyNum() >= MAXNUM_LEAF) 
		{
			childNode->split(parentNode, childIndex);
			if (parentNode->getKeyValue(childIndex) <= key) 
			{
				childNode = ((CInternalNode<KT, DT> *)parentNode)->getChild(childIndex + 1);
			}
		}
		recursive_insert(childNode, key, data);
	}
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::clear()
{
	if (m_Root != NULL)
	{
		m_Root->clear();
		delete m_Root;
		m_Root = NULL;
		m_DataHead = NULL;
	}
}

template <typename KT, typename DT>
bool CBPlusTree<KT, DT>::search(KT key) const
{
	return recursive_search(m_Root, key);
}

template <typename KT, typename DT>
bool CBPlusTree<KT, DT>::recursive_search(CNode<KT, DT> *pNode, KT key) const
{
	if (pNode == NULL) 
	{
		return false;
	}
	else
	{
		int keyIndex = pNode->getKeyIndex(key);
		int childIndex = pNode->getChildIndex(key, keyIndex); 
		if (keyIndex < pNode->getKeyNum() && key == pNode->getKeyValue(keyIndex))
		{
			return true;
		}
		else
		{
			if (pNode->getType() == LEAF) 
			{
				return false;
			}
			else
			{
				return recursive_search(((CInternalNode<KT, DT> *)pNode)->getChild(childIndex), key);
			}
		}
	}
}

template <typename KT, typename DT>
DT *CBPlusTree<KT, DT>::getDataHandle(KT key) const
{
	return recursive_getDataHandle(m_Root, key);
}

template <typename KT, typename DT>
DT *CBPlusTree<KT, DT>::recursive_getDataHandle(CNode<KT, DT> *pNode, KT key) const
{
	
	if (pNode == NULL) 
	{
		return nullptr;
	}

	int keyIndex = pNode->getKeyIndex(key);
	int childIndex = pNode->getChildIndex(key, keyIndex); 

	
	if (pNode->getType() == LEAF)
	{
		

		if (keyIndex < pNode->getKeyNum() && key == pNode->getKeyValue(keyIndex))
		{
			
			return ((CLeafNode<KT, DT> *)pNode)->getDataAddr(childIndex);
		}
		else
		{
			
			return nullptr;
		}
	}
	else
		

	return recursive_getDataHandle(((CInternalNode<KT, DT> *)pNode)->getChild(childIndex), key);
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::print() const
{
	cout << endl;
	cout << endl;
	cout << "Now print the keys in tree form:" << endl
		 << endl;
	printInConcavo(m_Root, 10);
	cout << endl;
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::printInConcavo(CNode<KT, DT> *pNode, int count) const
{
	if (pNode->getType() == LEAF)
		((CLeafNode<KT, DT> *)pNode)->pour();
	if (pNode != NULL)
	{
		int i, j;
		for (i = 0; i < pNode->getKeyNum(); ++i)
		{
			if (pNode->getType() != LEAF)
			{
				printInConcavo(((CInternalNode<KT, DT> *)pNode)->getChild(i), count - 2);
			}
			for (j = count; j >= 0; --j)
			{
				cout << "---";
			}
			cout << pNode->getKeyValue(i) << endl;
		}
		if (pNode->getType() != LEAF)
		{
			printInConcavo(((CInternalNode<KT, DT> *)pNode)->getChild(i), count - 2);
		}
	}
}
template <typename KT, typename DT>
int CBPlusTree<KT, DT>::getnum() 
{
	return num;	
}
template <typename KT, typename DT>
DT* CBPlusTree<KT, DT>::report() 
{
	CLeafNode<KT, DT> *itr = m_DataHead;
	itr->pour();
	int n = -1;
	while (itr != NULL)
	{
<<<<<<< HEAD
		for (int i = 0; i < itr->getKeyNum(); ++i)
		{	
=======
		
		for (int i = 0; i < itr->getKeyNum(); ++i)
		{
>>>>>>> f6c7b2acae6db10d88aed77a03f11c1be1bc7019
			n+=1;
			rep[n]= itr->getData(i);
		}
		itr = itr->getRightSibling();
	}
	this->num=n+1;
	return rep;
}
template <typename KT, typename DT>
void CBPlusTree<KT, DT>::printData() const
{
	cout << endl;
	cout << "Now print all the data stored in B+ tree:" << endl
		 << endl;
	CLeafNode<KT, DT> *itr = m_DataHead;
	itr->pour();
	while (itr != NULL)
	{
		cout << "block size: " << itr->getKeyNum() << endl;
		cout << "[ ";
		for (int i = 0; i < itr->getKeyNum(); ++i)
		{
			cout << itr->getData(i) << " , ";
		}
		cout << " ]" << endl;
		itr = itr->getRightSibling();
	}
	cout << endl;
}

template <typename KT, typename DT>
bool CBPlusTree<KT, DT>::remove(KT key)
{
	if (!search(key)) 
	{
		return false;
	}
	if (m_Root->getKeyNum() == 1) 
	{
		if (m_Root->getType() == LEAF)
		{
			clear();
			return true;
		}
		else
		{
			CNode<KT, DT> *pChild1 = ((CInternalNode<KT, DT> *)m_Root)->getChild(0);
			CNode<KT, DT> *pChild2 = ((CInternalNode<KT, DT> *)m_Root)->getChild(1);
			if (pChild1->getKeyNum() == MINNUM_KEY && pChild2->getKeyNum() == MINNUM_KEY)
			{
				pChild1->mergeChild(m_Root, pChild2, 0);
				delete m_Root;
				m_Root = pChild1;
			}
		}
	}
	recursive_remove(m_Root, key);
	return true;
}


template <typename KT, typename DT>
void CBPlusTree<KT, DT>::recursive_remove(CNode<KT, DT> *parentNode, KT key)
{
	int keyIndex = parentNode->getKeyIndex(key);
	int childIndex = parentNode->getChildIndex(key, keyIndex);
	if (parentNode->getType() == LEAF)						  
	{
		if (key == m_MaxKey && keyIndex > 0)
		{
			m_MaxKey = parentNode->getKeyValue(keyIndex - 1);
		}
		parentNode->removeKey(keyIndex, childIndex); 
		
		if (childIndex == 0 && m_Root->getType() != LEAF && parentNode != m_DataHead)
		{
			changeKey(m_Root, key, parentNode->getKeyValue(0));
		}
	}
	else 
	{
		cout << "call" << endl;
		CNode<KT, DT> *pChildNode = ((CInternalNode<KT, DT> *)parentNode)->getChild(childIndex); 
		if (pChildNode->getKeyNum() == MINNUM_KEY)																	   
		{
			CNode<KT, DT> *pLeft = childIndex > 0 ? ((CInternalNode<KT, DT> *)parentNode)->getChild(childIndex - 1) : NULL;						
			CNode<KT, DT> *pRight = childIndex < parentNode->getKeyNum() ? ((CInternalNode<KT, DT> *)parentNode)->getChild(childIndex + 1) : NULL; 
		
			if (pLeft && pLeft->getKeyNum() > MINNUM_KEY) 
			{
				pChildNode->borrowFrom(pLeft, parentNode, childIndex - 1, LEFT);
			}
			else if (pRight && pRight->getKeyNum() > MINNUM_KEY) 
			{
				pChildNode->borrowFrom(pRight, parentNode, childIndex, RIGHT);
			}
			
			else if (pLeft) 
			{
				pLeft->mergeChild(parentNode, pChildNode, childIndex - 1);
				pChildNode = pLeft;
			}
			else if (pRight) 
			{
				pChildNode->mergeChild(parentNode, pRight, childIndex);
			}
		}
		recursive_remove(pChildNode, key);
	}
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::changeKey(CNode<KT, DT> *pNode, KT oldKey, KT newKey)
{
	if (pNode != NULL && pNode->getType() != LEAF)
	{
		int keyIndex = pNode->getKeyIndex(oldKey);
		if (keyIndex < pNode->getKeyNum() && oldKey == pNode->getKeyValue(keyIndex)) 
		{
			pNode->setKeyValue(keyIndex, newKey);
		}
		else 
		{
			changeKey(((CInternalNode<KT, DT> *)pNode)->getChild(keyIndex), oldKey, newKey);
		}
	}
}

template <typename KT, typename DT>
bool CBPlusTree<KT, DT>::update(KT oldKey, KT newKey)
{
	if (search(newKey)) 
	{
		return false;
	}
	else
	{
		int dataValue;
		remove(oldKey, dataValue);
		if (dataValue == INVALID_INDEX)
		{
			return false;
		}
		else
		{
			return insert(newKey, dataValue);
		}
	}
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::remove(KT key, DT &dataValue)
{
	if (!search(key)) 
	{
		dataValue = INVALID_INDEX;
		return;
	}
	if (m_Root->getKeyNum() == 1) 
	{
		if (m_Root->getType() == LEAF)
		{
			dataValue = ((CLeafNode<KT, DT> *)m_Root)->getData(0);
			clear();
			return;
		}
		else
		{
			CNode<KT, DT> *pChild1 = ((CInternalNode<KT, DT> *)m_Root)->getChild(0);
			CNode<KT, DT> *pChild2 = ((CInternalNode<KT, DT> *)m_Root)->getChild(1);
			if (pChild1->getKeyNum() == MINNUM_KEY && pChild2->getKeyNum() == MINNUM_KEY)
			{
				pChild1->mergeChild(m_Root, pChild2, 0);
				delete m_Root;
				m_Root = pChild1;
			}
		}
	}
	recursive_remove(m_Root, key, dataValue);
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::recursive_remove(CNode<KT, DT> *parentNode, KT key, DT &dataValue)
{
	int keyIndex = parentNode->getKeyIndex(key);
	int childIndex = parentNode->getChildIndex(key, keyIndex);
	if (parentNode->getType() == LEAF)						   
	{
		if (key == m_MaxKey && keyIndex > 0)
		{
			m_MaxKey = parentNode->getKeyValue(keyIndex - 1);
		}
		dataValue = ((CLeafNode<KT, DT> *)parentNode)->getData(keyIndex);
		parentNode->removeKey(keyIndex, childIndex); 
		
		if (childIndex == 0 && m_Root->getType() != LEAF && parentNode != m_DataHead)
		{
			changeKey(m_Root, key, parentNode->getKeyValue(0));
		}
	}
	else 
	{
		CNode<KT, DT> *pChildNode = ((CInternalNode<KT, DT> *)parentNode)->getChild(childIndex); 
		if (pChildNode->getKeyNum() == MINNUM_KEY)																	   
		{
			CNode<KT, DT> *pLeft = childIndex > 0 ? ((CInternalNode<KT, DT> *)parentNode)->getChild(childIndex - 1) : NULL;						 
			CNode<KT, DT> *pRight = childIndex < parentNode->getKeyNum() ? ((CInternalNode<KT, DT> *)parentNode)->getChild(childIndex + 1) : NULL; 
			
			if (pLeft && pLeft->getKeyNum() > MINNUM_KEY) 
			{
				pChildNode->borrowFrom(pLeft, parentNode, childIndex - 1, LEFT);
			}
			else if (pRight && pRight->getKeyNum() > MINNUM_KEY) 
			{
				pChildNode->borrowFrom(pRight, parentNode, childIndex, RIGHT);
			}
			
			else if (pLeft) 
			{
				pLeft->mergeChild(parentNode, pChildNode, childIndex - 1);
				pChildNode = pLeft;
			}
			else if (pRight) 
			{
				pChildNode->mergeChild(parentNode, pRight, childIndex);
			}
		}
		recursive_remove(pChildNode, key, dataValue);
	}
}

template <typename KT, typename DT>
vector<DT> CBPlusTree<KT, DT>::oneSideSelect(KT compareKey, int compareOpeartor) const
{
	vector<DT> results;
	if (m_Root != NULL)
	{
		if (compareKey > m_MaxKey)
		{
			if (compareOpeartor == LE || compareOpeartor == LT)
			{
				for (CLeafNode<KT, DT> *itr = m_DataHead; itr != NULL; itr = itr->getRightSibling())
				{
					for (int i = 0; i < itr->getKeyNum(); ++i)
					{
						results.push_back(itr->getData(i));
					}
				}
			}
		}
		else if (compareKey < m_DataHead->getKeyValue(0)) 
		{
			if (compareOpeartor == BE || compareOpeartor == BT)
			{
				for (CLeafNode<KT, DT> *itr = m_DataHead; itr != NULL; itr = itr->getRightSibling())
				{
					for (int i = 0; i < itr->getKeyNum(); ++i)
					{
						results.push_back(itr->getData(i));
					}
				}
			}
		}
		else 
		{
			SelectResult<KT, DT> result;
			search(compareKey, result);
			switch (compareOpeartor)
			{
			case LT:
			case LE:
			{
				CLeafNode<KT, DT> *itr = m_DataHead;
				int i;
				while (itr != result.targetNode)
				{
					for (i = 0; i < itr->getKeyNum(); ++i)
					{
						results.push_back(itr->getData(i));
					}
					itr = itr->getRightSibling();
				}
				for (i = 0; i < result.keyIndex; ++i)
				{
					results.push_back(itr->getData(i));
				}
				if (itr->getKeyValue(i) < compareKey ||
					(compareOpeartor == LE && compareKey == itr->getKeyValue(i)))
				{
					results.push_back(itr->getData(i));
				}
			}
			break;
			case EQ:
			{
				if (result.targetNode->getKeyValue(result.keyIndex) == compareKey)
				{
					results.push_back(result.targetNode->getData(result.keyIndex));
				}
			}
			break;
			case BE:
			case BT:
			{
				CLeafNode<KT, DT> *itr = result.targetNode;
				if (compareKey < itr->getKeyValue(result.keyIndex) ||
					(compareOpeartor == BE && compareKey == itr->getKeyValue(result.keyIndex)))
				{
					results.push_back(itr->getData(result.keyIndex));
				}
				int i;
				for (i = result.keyIndex + 1; i < itr->getKeyNum(); ++i)
				{
					results.push_back(itr->getData(i));
				}
				itr = itr->getRightSibling();
				while (itr != NULL)
				{
					for (i = 0; i < itr->getKeyNum(); ++i)
					{
						results.push_back(itr->getData(i));
					}
					itr = itr->getRightSibling();
				}
			}
			break;
			default: 
				break;
			}
		}
	}
	sort<vector<DT>::iterator>(results.begin(), results.end());
	return results;
}

template <typename KT, typename DT>
vector<DT> CBPlusTree<KT, DT>::twoSideSelect(KT smallKey, KT largeKey) const
{
	vector<DT> results;
	if (smallKey <= largeKey)
	{
		SelectResult<KT, DT> start, end;
		search(smallKey, start);
		search(largeKey, end);
		CLeafNode<KT, DT> *itr = start.targetNode;
		int i = start.keyIndex;
		if (itr->getKeyValue(i) < smallKey)
		{
			++i;
		}
		if (end.targetNode->getKeyValue(end.keyIndex) > largeKey)
		{
			--end.keyIndex;
		}
		while (itr != end.targetNode)
		{
			for (; i < itr->getKeyNum(); ++i)
			{
				results.push_back(itr->getData(i));
			}
			itr = itr->getRightSibling();
			i = 0;
		}
		for (; i <= end.keyIndex; ++i)
		{
			results.push_back(itr->getData(i));
		}
	}
	sort<vector<DT>::iterator>(results.begin(), results.end());
	return results;
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::search(KT key, SelectResult<KT, DT> &result)
{
	recursive_search(m_Root, key, result);
}

template <typename KT, typename DT>
void CBPlusTree<KT, DT>::recursive_search(CNode<KT, DT> *pNode, KT key, SelectResult<KT, DT> &result)
{
	
	int keyIndex = pNode->getKeyIndex(key);
	int childIndex = pNode->getChildIndex(key, keyIndex); 
	if (pNode->getType() == LEAF)
	{
		result.keyIndex = keyIndex;
		result.targetNode = (CLeafNode<KT, DT> *)pNode;
		return;
	}
	else
	{
		recursive_search(((CInternalNode<KT, DT> *)pNode)->getChild(childIndex), key, result);
	}
}
