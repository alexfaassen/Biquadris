#ifndef LEVEL3_H
#define LEVEL3_H

class Level3 : public Level {
	public:
	Level3(bool customSeed = 0, int seed = 0, int identifier = 0, std::ifstream *file = NULL, const int playerID, Effect *heavy);

	void generateEffects(); //TODO

	Block *CreateBlock() override;
};

#endif
