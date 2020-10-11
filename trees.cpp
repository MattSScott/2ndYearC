#include <iostream>
#include <fstream>
#include <vector>

struct treenode {
  int val;
  treenode* left;
  treenode* right;
};

typedef treenode* mtree;

mtree constree(int el, mtree l, mtree r);
mtree instree(int el, mtree t);
void instree_ref(int l, mtree& t);
void print_root(const mtree& t);
void print_tree(const mtree& t);
mtree deletefromtree_nmr(int el, mtree t);
int minvalnode(mtree t);
void delete_tree(mtree t);
int nodecount(mtree t);
int treeheight(mtree t);
bool has_element(mtree t, const int& el);
int num_less_than(mtree t, const int& el);

int main(){
  int n;
  mtree t1 = NULL;
  mtree t2 = NULL;
  int del;

  std::ifstream numberfile;
  std::string filename;

  std::cout << "enter file name:" << std::endl;
  std::cin >> filename;

  numberfile.open(filename.c_str());

  if(!numberfile.is_open()){
    std::cout << "file didn't open" << std::endl;
    exit(EXIT_FAILURE);
  }

  while(numberfile >> n){
    t1 = instree(n, t1);
    instree_ref(n, t2);
  }

  std::cout << std::endl;
  print_tree(t1);
  std::cout << std::endl;
  print_tree(t2);

  std::cout << "choose element to delete" << std::endl;
  std::cin >> del;

  deletefromtree_nmr(del, t1);
  deletefromtree_nmr(del, t2);

  std::cout << std::endl;
  print_tree(t1);
  std::cout << std::endl;
  print_tree(t2);

  std::cout << std::endl;


  std::cout << nodecount(t1) << std::endl;
  std::cout << treeheight(t1) << std::endl;
  std::cout << has_element(t1, 7) << std::endl;
  std::cout << num_less_than(t1, 7) << std::endl;

  delete_tree(t1);
  t1 = NULL;
  delete_tree(t2);
  t2 = NULL;

  return 0;
}

mtree constree(int el, mtree l, mtree r){
  mtree tmp = new treenode;
  tmp->val = el;
  tmp->left = l;
  tmp->right = r;
  return tmp;
}

mtree instree(int el, mtree t){
  if(t == NULL){
    return constree(el, NULL, NULL);
  }
  else if(el < t->val){
    t->left = instree(el, t->left);
    return t;
  }
  else{
    t->right = instree(el, t->right);
    return t;
  }
}

void instree_ref(int el, mtree& t){
  if(t == NULL){
    mtree tmp = new treenode;
    tmp->val = el;
    tmp->left = NULL;
    tmp->right = NULL;
    t = tmp;
  }
  else if(el < t->val){
    instree_ref(el, t->left);
  }
  else{
    instree_ref(el, t->right);
  }
}

void print_root(const mtree& t){
  std::cout << t->val << std::endl;
}

void print_tree(const mtree& t){
  if(t != NULL){
    print_tree(t->left);
    print_root(t);
    print_tree(t->right);
  }
}

mtree deletefromtree_nmr(int el, mtree t){
  if(t == NULL){
    return t;
  }
  else if(el == t->val){
    if(t->left == NULL && t->right == NULL){
      delete t;
      return NULL;
    }
    else if(t->left == NULL){
      mtree tmp = t->right;
      delete t;
      return tmp;
    }
    else if(t->right == NULL){
      mtree tmp = t->left;
      delete t;
      return tmp;
    }
    else{
      t->val = minvalnode(t->right);
      t->right = deletefromtree_nmr(t->val, t->right);
      return t;
    }
  }
  else if(el < t->val){
    t->left = deletefromtree_nmr(el, t->left);
    return t;
  }
  else{
    t->right = deletefromtree_nmr(el, t->right);
    return t;
  }
}


int minvalnode(mtree t){
  if(t->left != NULL){
    return minvalnode(t->left);
  }
  return t->val;
}

void delete_tree(mtree t){
  if(t != NULL){
    delete_tree(t->left);
    delete_tree(t->right);
    delete t;
  }
}

int nodecount(mtree t){
  if(t == NULL){
    return 0;
  }
  else{
    return (nodecount(t->left) + nodecount(t->right) + 1);
  }
}

int treeheight(mtree t){
  if(t == NULL){
    return 0;
  }
  else{
    int ldepth = treeheight(t->left);
    int rdepth = treeheight(t->right);

    if(ldepth > rdepth){
      return(ldepth+1);
    }
    else{
      return(rdepth+1);
    }
  }
}

bool has_element(mtree t, const int& el){
  if(el > t->val && t->right != NULL){
    return has_element(t->right, el);
  }
  else if(el < t->val && t->left != NULL){
    return has_element(t->left, el);
  }
  else if(t->val != el){
    return 0;
  }
  else{
    return 1;
  }
}

int num_less_than(mtree t, const int& el){
  if(t == NULL){
    return 0;
  }
  else if(t->val < el){
    return (num_less_than(t->left, el) + num_less_than(t->right, el) + 1);
  }
  else{
    return (num_less_than(t->left, el) + num_less_than(t->right, el));
  }
}
