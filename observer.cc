#include "observer.h"
#include "player.h"

Observer::~Observer() {}

bool Observer::isAlive() const { return alive; }

void Observer::kill() { delete this; }

void Observer::attach(Player* const newPlayer) { player = newPlayer; }

void Observer::notify(const Event currEvent, const int linesCleared) {}

void Observer::notify(const Event currEvent, std::vector<std::vector<char>> &boardPrint) {}
