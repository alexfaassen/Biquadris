#ifndef LEVEL4_H
#define LEVEL4_H

class Level4 : public Level {
	public:
	Level4(bool customSeed, int seed, int identifier = 4, std::ifstream *file, const int playerID, Effect *heavy, Effect *centreDrop);

	void generateEffects(); //TODO

	Block *CreateBlock() override;
};

#endif
