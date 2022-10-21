void check(TreeNode* root ,long long int *sum ,  int *count , int target){
       if(root==NULL){
           return;
       }
        *sum = *sum + root->val;
        if(*sum == target){
            *count = *count +1 ;
            
        }
        check(root->left, sum , count , target);
            check(root->right, sum , count , target);
            
        *sum = *sum - root->val;        
          
    }
    void path(TreeNode* root , long long int *sum ,int *count , int target){
        if(root==NULL){
            return ;
        }
       check(root ,sum ,  count , target);
        *sum =0;
        path(root->left ,sum ,  count , target);
        *sum =0;
        path(root->right ,sum ,  count , target);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long sum =0;
        int count =0;
        path(root ,&sum ,  &count , targetSum);
        return count ;
    }
