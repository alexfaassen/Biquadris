#ifndef LEVEL4_H
#define LEVEL4_H

class Level4 : public Level {
	public:
	Level4(bool customSeed = 0, int seed = 0, int identifier = 0, std::ifstream *file = NULL, const int playerID, Effect *heavy, Effect *centreDrop);

	void generateEffects(); //TODO

	Block *CreateBlock() override;
};

#endif
