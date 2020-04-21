#include "observer.h"
#include "player.h"

Observer::~Observer() {}

bool Observer::isAlive() const { return alive; }

void Observer::kill() { alive = false; }

void Observer::attach(Player* const newPlayer) { player = newPlayer; }

void Observer::notify(const Event currEvent, const int i) {}

void Observer::notify(const Event currEvent, const Move currMove) {}

void Observer::notify(const Event currEvent, const char c) {}

void Observer::notify(const Event currEvent, std::vector<std::vector<char>> &boardPrint) {}

void Observer::notify(const Event currEvent, PlayerWindow&) {};
