bool GetNodePath(TreeNode *pRoot, TreeNode *pNode, list<TreeNode*> &path)
{
	if(pRoot == pNode) return true;
	path.push_back(pRoot)
	bool found = false;

	vector<TreeNode*>::iterator it = pRoot -> m_children.begin();
	while(!found && it < pRoot -> m_children.end())
	{
		found = GetNodePath(*it, pNode, path);
		++it;
	}

	if(!found) path.pop_back();
	return found;
}

TreeNode *GetLastCommonNode(const list<TreeNode*> &path1, const list<TreeNode*> path2)
{
	list<TreeNode*>::const_iterator it1 = path1.begin();
	list<TreeNode*>::const_iterator it2 = path2.begin();

	TreeNode *pLast = nullptr;

	while(it1 != path1.end() && it2 != path2.end())
	{
		if(*it1 == *it2)
			pLast = *it1;
		++it1, ++it2;
	}

	return pLast;
}

TreeNode *GetLastCommonParent(TreeNode *pRoot, TreeNode *pNode1, TreeNode *pNode2)
{
	if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL) return NULL;

	list<TreeNode*> path1, path2;
	GetLastCommonNode(pRoot, pNode1, path1);
	GetLastCommonNode(pRoot, pNode2, path2);

	return GetLastCommonParent(path1, path2);
}