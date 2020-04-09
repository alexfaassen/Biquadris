#include "dropcmd.h"

void DropCmd::run(Player &player, const int times) const override { player.drop(1); }
