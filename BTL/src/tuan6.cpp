#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
};

struct Stack {
	Node *arr;
	int max;
	int count;
	int top;
};

Node* createArr() {
	Node *head = new Node;
	head->data = 0;
	head->next = head;
	head->pre = head;
	return head;
}

Stack createStack(int max) {
	Stack stack;
	stack.arr = createArr();
	stack.count = 0;
	stack.top = 0;
	stack.max = max;
	return stack;
}
bool isEmpty(Stack s) {
	if(s.top == 0) {
		printf("\nNGAN XEP RONG!");
		return true;
	}
	return false;
}
bool isFull(Stack s) {
	if(s.count == s.max) {
		printf("\nNGAN XEP DAY!");
		return true;
	}
	return false;
}
void push(Stack& stack, int x) {

	if(isFull(stack)) return;

	//tao mot node
	Node *n = new Node;
	n->data = x;
	n->next = stack.arr; // next = NULL , chua co con tro tiep theo
	stack.arr->pre = n;

	if (stack.top == 0) {
		n->pre = stack.arr; // moc noi vao con tro truoc do
		stack.arr->next = n; // moc nguoc lai
	} else {
		Node *tim = stack.arr;
		while (tim->next != stack.arr) {
			tim = tim->next;
		}
		n->pre = tim;
		tim->next = n;

	}

	stack.top++;
	stack.count++;
}
int pop(Stack& s) {
	int back = -9999999;

	if(isEmpty(s))
		return back;

	Node* temp = s.arr->next;
	//chay tu 1 vi du lieu chua tu khi top = 1
	int i = 1;
	while (i < s.top) {
		temp = temp->next;
		i++;
	}

	//moc noi duoi vao dau arr
	temp->pre->next = s.arr;
	//moc nguoc arr vao cuoi
	s.arr->pre = temp->pre;

	s.top--;
	s.count--;

	//gan du lieu
	back = temp->data;

	//giai bien sau pop
	delete temp;

	return back;
}
void printStack(Stack s) {
	Node *t = s.arr->next;
	int i = 0;
	while (i < s.top) {
		printf("Gia tri: %d\n", t->data);
		t = t->next;
		i++;
	}
	if (s.top == 0)
		printf("STACK EMPTY\n");
}
void printRevertStack(Stack s) {
	Node *t = s.arr->pre;
	int i = 0;
	while (i < s.top) {
		printf("Gia tri: %d\n", t->data);
		t = t->pre;
		i++;
	}
	if (s.top == 0)
		printf("STACK EMPTY\n");
}
int main() {
	Stack s = createStack(10);

	for(int i = 0; i<4; i++)
		push(s, i*100+1);

	printRevertStack(s);

	printStack(s);

	for(int i = 0; i<20; i++)
		printf("\nPOP: %d , TOP %d",pop(s),s.top);

	return 0;
}

