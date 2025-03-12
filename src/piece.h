#pragma once
#include "render.h"
#include <vector>
#include <ctime>
#include <random>
enum pieces
{
	BLOCK,
	STICK,
	L,
	LL,
	ZIGR,
	ZIGL,
	T,
	NONE,
};
class Piece
{
private:
	pieces type;
	pieces savetype;

	glm::vec3 bdown{ 0.0f, -0.9648f, 0.0f };
	glm::vec3 bup{ 0.0f, 0.9648f, 0.0f };
	glm::vec3 bright{ 0.932f, 0.0f, 0.0f };
	glm::vec3 bleft{-0.932f, 0.0f, 0.0f};
	int fourWayRot{ 0 };
	int twoWayRot{ 0 };
	bool doFastDrop = true;
	
	
	pieces held = NONE;
	bool isheld = false;

	int lines = 0;
	const glm::vec3 red{ 1.0f, 0.2f, 0.0f };
	const glm::vec3 lightBlue{ 0.0f, 1.0f, 1.0f };
	const glm::vec3 blue{ 0.0f, 0.0f, 0.8f };
	const glm::vec3 orange{ 1.0f, 0.4f, 0.0f };
	const glm::vec3 yellow{ 1.0f, 1.0f, 0.2f };
	const glm::vec3 green{ 0.0f, 1.0f, 0.0f };
	const glm::vec3 purple{ 0.7f, 0.0f, 0.6f };

	glm::vec3 color;
	glm::mat4 b1;
	glm::vec2 b1Loc;
	glm::mat4 b2;
	glm::vec2 b2Loc;
	glm::mat4 b3;
	glm::vec2 b3Loc;
	glm::mat4 b4;
	glm::vec2 b4Loc;
	glm::vec2 test1;
	glm::vec2 test2;
	glm::vec2 test3;
	glm::vec2 test4;


	glm::vec3 colorSave;
	glm::mat4 b1Save;
	glm::vec2 b1LocSave;
	glm::mat4 b2Save;
	glm::vec2 b2LocSave;
	glm::mat4 b3Save;
	glm::vec2 b3LocSave;
	glm::mat4 b4Save;
	glm::vec2 b4LocSave;
	int fourWayRotSave;
	int twoWayRotSave;
	std::vector <pieces> next;
	std::vector <pieces> savenext;

	glm::mat4 b1Save2;
	glm::mat4 b2Save2;
	glm::mat4 b3Save2;
	glm::mat4 b4Save2;
	
public:
	Piece(pieces p);
	glm::mat4 setBlock();
	void draw(Render obj);
	void rotate();
	void down();
	void left();
	void right();
	void fastDrop();
	void sayCords();
	void resetBlock(pieces TYPE);
	void changeBlock(int t);
	bool noCollide();
	void moveGrave(int y, int ii, float linesDest);
	void increaseTest(int x, int y);
	void hold();
	void typeSpec();
	void spec();
	void setUpExtra();
	void Proj(Render proj);
	void checkLoss();
	void reset();
	bool h = false;
	bool loss = false;
	int totalLines = 0;
	float speedMultiplier = 1.0f;
};