// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {

	previous = nullptr;
	next = nullptr;
	nodedata = data;

  return;
}

char Node::GetData() {
	return nodedata;
}

Node* Node::GetPreviousNode() {
  return previous;
}

Node* Node::GetNextNode() {
  return next;
}

Node* Node::InsertPreviousNode(char data) {
	Node* newNode = new Node(data);
	Node* prev = this->previous;

	newNode->next = this;
	this->previous = newNode;

	if (prev == nullptr)
		return newNode;

	prev->next = newNode;
	newNode->previous = prev;

	return newNode;
}

Node* Node::InsertNextNode(char data) {
	Node* newNode = new Node(data);
	Node* next = this->next;

	this->next = newNode;
	newNode->previous = this;

	if (next == nullptr)
		return newNode;

	newNode->next = next;
	next->previous = newNode;

	return newNode;
}

bool Node::ErasePreviousNode() {
	Node* delNode = this->previous;

	if (delNode == nullptr)
		return false;

	Node* prevNode = delNode->previous;

	if (prevNode != nullptr)
		prevNode->next = this;
	
	this->previous = prevNode;

	delete delNode;

  return true;
}

bool Node::EraseNextNode() {
	Node* delNode = this->next;

	if (delNode == nullptr)
		return false;

	Node* nextNode = delNode->next;

	this->next = nextNode;
	if (nextNode != nullptr)
		nextNode->previous = this;

	delete delNode;

	return true;
}
