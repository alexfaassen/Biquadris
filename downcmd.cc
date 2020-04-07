#include "downcmd.h"

void DownCmd::run(Player *player, const int times) const override { player->moveBlock(Down, times, 1); }
