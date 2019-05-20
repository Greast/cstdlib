#include "tree.h"
#include "list.h"
__attribute__((nonnull(1,2)))
int tree_add(struct tree ** tree, int(*cmp)(const void*, const void*), const void* key, void* value){
  if(!*tree) {
      struct tree new_tree = {
        .node = {
          .key = key,
          .value = value,
        }
      };
      *tree = HEAPIFY(new_tree);
      return 0;
  }
  const int ret = cmp((*tree)->node.key, key);
  if(!ret) return -1;
  struct tree ** child = 0 < ret ? &(*tree)->rhs : &(*tree)->lhs;
  return tree_add(child, cmp, key, value);
}

__attribute__((nonnull(1,2)))
void ** tree_get(struct tree ** tree, int(*cmp)(const void*, const void*), const void* key){
  if(!*tree) return NULL;
  const int ret = cmp((*tree)->node.key, key);
  if(!ret) {
    return &(*tree)->node.value;
  };
  struct tree ** child = 0 < ret ? &(*tree)->rhs : &(*tree)->lhs;
  return tree_get(child, cmp, key);
}

__attribute__((nonnull(2,3,4)))
int tree_join(struct tree* tree, int(*print)(FILE* stream, const void* lhs, const void* rhs), FILE* stream, const char* seperator){
  int sum = 0;
  if(!tree) return sum;
  int ret;
  if((ret = tree_join(tree->lhs, print, stream, seperator))){
    sum += ret + fprintf(stream, "%s", seperator);
  }
  sum += print(stream, tree->node.key, tree->node.value);

  if((ret = tree_join(tree->rhs, print, stream, seperator))){
    sum += ret + fprintf(stream, "%s", seperator);
  }
  return sum;
}

void tree_values_recursiv(struct list ** list,  struct tree* tree){
  if(!tree) return;
  tree_values_recursiv(list, tree->lhs);
  list_add(list, tree->node.value);
  tree_values_recursiv(list, tree->rhs);
}

struct list * tree_values(struct tree* tree){
  struct list * list = NULL;
  tree_values_recursiv(&list, tree);
  return list;
}
