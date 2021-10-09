#define NUM_KEYS 10
// NUM_KEYS should be set to make each tree node as large as 4KB.
// But for this assignment, we will set the degree of node small to make debugging and $
// Please do not change this number.
// In practice, DBMS employs 'slotted page structure' to store variable-length records $
// But the purpose of this assignment is to make students familiar with B-tree itself.

enum NodeType {
        ROOT,
        INTERNAL,
        LEAF
};

class BTreeNode{
   protected:
        NodeType type;
        long long keys[NUM_KEYS];
        int level; 
   public:
        BTreeNode();
        virtual ~BTreeNode() {}
        NodeType getNodeType();
        void keysetter(long long outtervalue, int i)
        {
             this->keys[i]=outtervalue;
        }
        long long keygetter(int i)
        {
             return keys[i];
        }
        long long* keysgetter()
        {
             return keys; 
        }
        int getlevel()
        {
             return level;
        }
};

class BTreeInternalNode:public BTreeNode{
   private:
        BTreeNode* child[NUM_KEYS+1];
   public:
        BTreeInternalNode();
        ~BTreeInternalNode();
        void childsetter(BTreeNode* ptr, int j)
        {
             this->child[j]=ptr;
        }
        BTreeNode* childgetter(int j)
        {
             return child[j];
        }
};

class BTreeLeafNode:public BTreeNode{
   private:
        long long keys[NUM_KEYS];
        BTreeLeafNode* right_sibling;
   public:
        BTreeLeafNode();
        ~BTreeLeafNode();
        void printLeafNode(); // print all keys in the current leaf node, separated by $
        void siblingsetter(BTreeLeafNode* ptr)
        {
             right_sibling=ptr;
        }
        BTreeLeafNode* siblinggetter()
        {
             return right_sibling;
        }
};

void sort(long long*p, int n)
{
     int i,j,temp;
     for(i=0;i<n;i++)
     {
          for(j=i;i<=n;j++)
          {
               if(p[i]>p[j])
               {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
               }
          }
     }
}

class BTree{
    private:
        BTreeNode *root;
    public:
        // You are not allowed to change the interfaces of these public methods.
        BTree();
        ~BTree();
        void insert(long long value);
//      void remove(long long value);
        void printLeafNode(long long value);
        // find the leaf node that contains 'value' and print all values in the leaf no$
        void pointQuery(long long value);
        // print the found value or "NOT FOUND" if there is no value in the index
        void rangeQuery(long long low, long long high);
        // print all found keys (low <= keys < high), separated by comma (e.g., 10, 11,$
};

