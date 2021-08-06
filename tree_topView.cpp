unordered_map<Node *, int> levelofNode;

void dfs(Node * root, int level){
    if(!root) return;
    levelofNode[root] = level;
    dfs(root->left, level -1);
    dfs(root->right, level +1);
    
    
}


   void topView( Node * root){
       dfs(root, 0);
//        for(auto it: levelofNode){
//     cout<<it.first->data <<" "<<it.second<<endl;
// }

       map<int, int> visitedLevel;
       visitedLevel[0] = root->data;
       queue<Node *> q;
       q.push(root);
       while(!q.empty()){
           Node * curr = q.front();
           q.pop();
           if(curr->left){
               if(visitedLevel.count(levelofNode[curr->left]) == 0)
                    visitedLevel[levelofNode[curr->left]] = curr->left->data;
                q.push(curr->left);
           } 
           if(curr->right){
               if(visitedLevel.count(levelofNode[curr->right]) == 0)
                    visitedLevel[levelofNode[curr->right]] = curr->right->data;
                q.push(curr->right);
           } 
           
       }
       
       for(auto i: visitedLevel){
           cout<<i.second<<" ";
       }
       
   }
