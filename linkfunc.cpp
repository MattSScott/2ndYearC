#include <iostream>
#include <fstream>

typedef int list_t;

struct listnode{
  list_t val;
  listnode* link;
};

typedef listnode* mlist;

void consref(list_t el, mlist& l);
mlist consret(list_t el, mlist l);
void printlist(mlist l);
void deallocate_c(mlist l);
void deallocate_r(mlist& l);
int listlength(mlist l);
int finditem(mlist l, list_t el);
void deleteitem(mlist& l, int input);
mlist concatenate(mlist a, mlist b);
mlist copylist(const mlist& input);

int main(){
  mlist la = NULL;
  mlist lb = NULL;
  mlist lc = NULL;

  int n, el, num_to_find, delnum;

  std::ifstream numberfile;
  std::string filename;

  std::cout << "Enter file name:" << std::endl;
  std::cin >> filename;

  numberfile.open(filename.c_str());

  if(!numberfile.is_open()){
    std::cout << "shit didn't work" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << "Choose num to find:" << std::endl;
  std::cin >> num_to_find;

  std::cout << "Choose num to delete:" << std::endl;
  std::cin >> delnum;


  while(numberfile >> el){
    consref(el, la);
    lb = consret(el, lb);
  }

  std::cout << std::endl;
  printlist(la);
  int lena = listlength(la);

  std::cout << std::endl;
  printlist(lb);
  int lenb = listlength(lb);

  int positiona = finditem(la, num_to_find);
  int positionb = finditem(lb, num_to_find);

  lc = concatenate(la, lb);
  std::cout << std::endl;
  int lenc = listlength(lc);
  printlist(lc);

  std::cout << std::endl;

  deleteitem(la, delnum);
  printlist(la);

  mlist copy = copylist(la);

  deallocate_c(la);
  deallocate_r(lb);
  deallocate_c(lc);

  std::cout << std::endl;

  std::cout << "length of a: " << lena << std::endl;
  std::cout << "length of b: " << lenb << std::endl;
  std::cout << "length of concatenated list: " << lenc << std::endl;

  std::cout << std::endl;

  if(positiona != -1){
  std::cout << "position of " << num_to_find << " in a: " << positiona << std::endl;
  std::cout << "position of " << num_to_find << " in b: " << positionb << std::endl;
  }
  else{
    std::cout << "element not found in a" << std::endl;
    std::cout << "element not found in b" << std::endl;
  }

  std::cout << std::endl;

  printlist(copy);

  return 0;
}


void consref(list_t el, mlist& l){
  mlist tmp = new listnode;
  tmp->val = el;
  tmp->link = l;
  l = tmp;
}

mlist consret(list_t el, mlist l){
  mlist tmp = new listnode;
  tmp->val = el;
  tmp->link = l;
  return tmp;
}

void printlist(mlist l){
  while(l!=NULL){
    std::cout << l->val << std::endl;
    l = l->link;
  }
}

void deallocate_c(mlist l){
  while(l!=NULL){
    delete l;
    l = l->link;
  }
}

void deallocate_r(mlist& l){
  while(l!=NULL){
    delete l;
    l = l->link;
  }
}

int listlength(mlist l){
  int length = 0;
  while(l != NULL){
    l = l->link;
    length++;
  }
  return length;
}

int finditem(mlist l, list_t el){
  int length = 0;
  int position = 0;
  while(l != NULL){
    if(el == l->val){
      position = length;
    }
    l = l->link;
    length++;
  }
  if(position == 0 && l == NULL){
    position = -1;
  }
  else{
    position++;
  }
  return position;
}

void deleteitem(mlist& l, int input){
int delposition = 0;
int reposition = 0;
mlist tmp = l;
mlist tmp1 = l;

  while(tmp->val != input){
    tmp = tmp->link;
    delposition++;
}
  tmp = l;

  while(tmp != NULL){
    if(reposition == delposition - 1){
      l = l->link;
      tmp->link = l->link;
      delete l;
      l = tmp;
    }
    else if(delposition == 0){
      l = l->link;
      tmp1 = l;
      delete tmp;
      tmp = l;
      return;
    }
    else{
      l = l->link;
      tmp = tmp->link;
    }
    reposition++;
  }
  l = tmp1;
}

mlist concatenate(mlist a, mlist b){
  mlist c = NULL;
  while(a != NULL){
    mlist tmp = new listnode;
    tmp->val = a->val;
    tmp->link = c;
    c = tmp;
    a = a->link;
  }
  while(b != NULL){
    mlist tmp = new listnode;
    tmp->val = b->val;
    tmp->link = c;
    c = tmp;
    b = b->link;
  }
  mlist d = NULL;
  mlist del = c;
  while(c != NULL){
    mlist tmp = new listnode;
    tmp->val = c->val;
    tmp->link = d;
    d = tmp;
    c = c->link;
  }
  return d;
}

mlist copylist(const mlist& input){
  mlist tmp = input;
  mlist tmp1;
  int i = 0;
  int array[listlength(input)];
  while(tmp != NULL){
    array[i] = tmp->val;
    tmp = tmp->link;
    i++;
  }
  for(int i=listlength(input)-1; i>-1; i--){
    mlist tmp1 = new listnode;
    tmp1->val = array[i];
    tmp1->link = tmp;
    tmp = tmp1;
  }
  //delete array; Debug?
  return tmp;
}
