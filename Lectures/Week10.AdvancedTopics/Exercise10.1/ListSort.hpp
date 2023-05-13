#ifndef LIST_SORT_HPP_
#define LIST_SORT_HPP_

#include "List.hpp"

void sort(List& list);
Node_ptr merge_sort(Node_ptr head);
Node_ptr merge(Node_ptr firstNode, Node_ptr secondNode);
Node_ptr findMiddle(Node_ptr head);

#endif