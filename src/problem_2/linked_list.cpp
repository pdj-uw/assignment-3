#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value)
{
	ListNode<T> *node;

	node = head->next;
	head->next = new ListNode<T>(value);
	head->next->next = node;
	num_of_element++;

}

template<class T>
void LinkedList<T>::push_back(const T &value)
{
	ListNode<T> *node;

	for (node = head; node->next; node = node->next);
	node->next = new ListNode<T>(value);
	num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back()
{
	ListNode<T> *node;

	if (!head->next)
		return;

	for (node = head; node->next->next; node = node->next);
	delete node->next;
	node->next = NULL;
	num_of_element--;
}

template<class T>
void LinkedList<T>::pop_front()
{
	ListNode<T> *node;

	if (!head->next)
		return;

	node = head->next->next;
	delete head->next;
	head->next = node;
	num_of_element--;
}

template<class T>
void LinkedList<T>::remove(T &val)
{
	ListNode<T> *parent, *child;

	for (parent = head; (child = parent->next);) {
		if (child->val == val) {
			parent->next = child->next;
			delete child;
			num_of_element--;
		} else {
			parent = parent->next;
		}
	}
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot)
{
	const LinkedList<T> &o = dynamic_cast<const LinkedList<T> &>(ot);
	ListNode<T> *n1 = o.head->next, *n2 = head, *tmp;

	for (; n1; n1 = n1->next) {
		for (; n2->next && n2->next->val < n1->val; n2 = n2->next);
		tmp = n2->next;
		n2->next = new ListNode<T>(n1->val);
		n2->next->next = tmp;
		num_of_element++;
	}
}

template<class T>
void LinkedList<T>::reverse_iterative()
{
	ListNode<T> *node, *tmp;

	node = head->next;
	head->next = NULL;

	while (node) {
		tmp = node->next;
		node->next = head->next;
		head->next = node;
		node = tmp;
	}
}
