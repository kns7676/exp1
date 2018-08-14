// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {

  cursor = nullptr;
  head = nullptr;
  tail = nullptr;
  current = nullptr;
  nodesize = 0;

  if (head == nullptr)
	  head = new Node('H');

  if (tail == nullptr)
  {
	  tail = head->InsertNextNode('T');
	  cursor = tail;
  }

  return;
}

void TypingMachine::HomeKey() {

	cursor = head->GetNextNode();
  return;
}

void TypingMachine::EndKey() {
	cursor = tail;
  return;
}

void TypingMachine::LeftKey() {
	if (cursor->GetPreviousNode() != head)
		cursor = cursor->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
	if (cursor != tail)
		cursor = cursor->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
	if ((32 <= key && key <= 126) && nodesize<100) {
		cursor->InsertPreviousNode(key);
		nodesize++;
		return true;
	}

  return false;
}

bool TypingMachine::EraseKey() {
	Node* previous_node;

	previous_node = cursor->GetPreviousNode();
	if (nodesize > 0 && previous_node !=head)
	{
		cursor->ErasePreviousNode();
		nodesize--;
		return true;
	}
	
  return false;
}

std::string TypingMachine::Print(char separator) {

	std::string str;
	char data;
	Node* current;
		


	current = head->GetNextNode();

	for (int i = 0; i <= nodesize; i++)
	{
		if (cursor == current)
		{
			if (separator!=0)
				str.push_back(separator);
		}
			
		if (current == tail)
			break;

		data = current->GetData();
		str.push_back(data);	
		current = current->GetNextNode();
	}

	return str;
}
