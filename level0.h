#ifndef LEVEL0_H
#define LEVEL0_H

class Level0 : public Level {
	public:
	Level0(bool customSeed; int seed, int identifier = 0, std::ifstream *file, const int playerID);

	Block *CreateBlock() override;
};

#endif
