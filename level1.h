#ifndef LEVEL1_H
#define LEVEL1_H

class Level1 : public Level {
	public:
	Level1(int seed = 0, int identifier = 0, std::ifstream *file = NULL, const int playerID);

	Block *CreateBlock() override;
};

#endif
