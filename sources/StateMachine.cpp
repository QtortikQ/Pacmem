#include "StateMachine.hpp"

StateMachine::StateMachine() {
}

StateMachine::~StateMachine() {
}

void StateMachine::moveState() {
	ghost_.move();
}

void StateMachine::disbandState() {
	ghost_.disband();
}

void StateMachine::setState(Ghost ghost) {
	ghost_ = ghost;
}