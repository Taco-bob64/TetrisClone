#include "piece.h"

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
std::uniform_int_distribution die{ 0, 6 };
struct grave
{
	std::vector<glm::vec2>placedBlocks;
	std::vector<glm::mat4> placedBlocksTrans;
	std::vector<glm::vec3>blockColor;
	bool findloc(glm::vec2 x)
	{
		for (auto& e : placedBlocks)
		{
			if (x == e)
				return true;
		}
		return false;
	}
	
	void destroyLine(float y)
	{
		std::cout << "searching for y values of " << y << '\n';
		for (auto e : placedBlocks)
		{
			std::cout << e.x << " , " << e.y << '\n';
		}
		std::cout << "destroyLine initiated!" << '\n';
		std::vector <int> destroyedInd;
		std::cout << placedBlocks.size() << '\n';
		int target = static_cast <int>(placedBlocks.size());
		std::cout << target << '\n';
		//std::vector <glm::vec2> copy = placedBlocks;
		int uh = static_cast <int>(placedBlocks.size());
		for (int i = 0; i < placedBlocks.size(); i++)
		{
			
			if (placedBlocks[i].y == y)
			{
				std::cout << placedBlocks[i].x << " , " << placedBlocks[i].y << '\n';
				placedBlocks.erase(placedBlocks.begin() + (i));
				destroyedInd.push_back(i);
				i = -1;

			}
			
		}
		for (auto e : destroyedInd)
		{
			placedBlocksTrans.erase(placedBlocksTrans.begin() + (e));
			blockColor.erase(blockColor.begin() + (e));
		}
		//move base less blocks down
	
		
	}
};

grave pB;

Piece::Piece(pieces p)
{
	type = p;
	changeBlock(die(mersenne));
	next.push_back(type);
	changeBlock(die(mersenne));
	next.push_back(type);
	changeBlock(die(mersenne));
	next.push_back(type);
	resetBlock(NONE);
}

glm::mat4 Piece::setBlock()
{
	glm::mat4 squm = glm::mat4(1.0f);
	squm = glm::scale(squm, glm::vec3(0.56f, 1.0f, 1.0f));
	squm = glm::scale(squm, glm::vec3(0.097f, 0.097f, 1.0f));
	squm = glm::translate(squm, glm::vec3(1.615f, 2.15f, 0.0f));
	squm = glm::translate(squm, glm::vec3(-1 * (0.932f), 9 * (0.9648f), 0.0f));
	return squm;
}

void Piece::draw(Render obj)
{
	
	obj.draw(b1, color);
	obj.draw(b2, color);
	obj.draw(b3, color);
	obj.draw(b4, color);
	for (int i = 0; i< pB.placedBlocksTrans.size(); i++)
	{

		obj.draw(pB.placedBlocksTrans[i], pB.blockColor[i]);
	}



	// held and next items
	savetype = type;
	colorSave = color;
	b1Save = b1;
	b1LocSave = b1Loc;
	b2Save = b2;
	b2LocSave = b2Loc;
	b3Save = b3;
	b3LocSave = b3Loc;
	b4Save = b4;
	b4LocSave = b4Loc;
	fourWayRotSave = fourWayRot;
	twoWayRotSave = twoWayRot;
	savenext = next;

	
		

		resetBlock(held);

		setUpExtra();


		if (isheld)
		{
		obj.draw(b1, color);
		obj.draw(b2, color);
		obj.draw(b3, color);
		obj.draw(b4, color);
		}

		//do next items

		
		
		next = savenext;
		
		type = next[0];
		b1 = setBlock();
		b2 = setBlock();
		b3 = setBlock();
		b4 = setBlock();
		spec();
		setUpExtra();
		b1 = glm::translate(b1, bright * 17.0f);
		b2 = glm::translate(b2, bright * 17.0f);
		b3 = glm::translate(b3, bright * 17.0f);
		b4 = glm::translate(b4, bright * 17.0f);
		
	

				obj.draw(b1, color);
				obj.draw(b2, color);
				obj.draw(b3, color);
				obj.draw(b4, color);
				
				
				
				 
				type = next[1];
				b1 = setBlock();
				b2 = setBlock();
				b3 = setBlock();
				b4 = setBlock();
				spec();
				setUpExtra();
				b1 = glm::translate(b1, bdown * 5.0f);
				b2 = glm::translate(b2, bdown * 5.0f);
				b3 = glm::translate(b3, bdown * 5.0f);
				b4 = glm::translate(b4, bdown * 5.0f);
				b1 = glm::translate(b1, bright * 17.0f);
				b2 = glm::translate(b2, bright * 17.0f);
				b3 = glm::translate(b3, bright * 17.0f);
				b4 = glm::translate(b4, bright * 17.0f);
				
			

				obj.draw(b1, color);
				obj.draw(b2, color);
				obj.draw(b3, color);
				obj.draw(b4, color);

		
				type = next[2];
				
				b1 = setBlock();
				b2 = setBlock();
				b3 = setBlock();
				b4 = setBlock();
				spec();
				setUpExtra();
				b1 = glm::translate(b1, bdown * 10.0f);
				b2 = glm::translate(b2, bdown * 10.0f);
				b3 = glm::translate(b3, bdown * 10.0f);
				b4 = glm::translate(b4, bdown * 10.0f);
				b1 = glm::translate(b1, bright * 17.0f);
				b2 = glm::translate(b2, bright * 17.0f);
				b3 = glm::translate(b3, bright * 17.0f);
				b4 = glm::translate(b4, bright * 17.0f);

				obj.draw(b1, color);
				obj.draw(b2, color);
				obj.draw(b3, color);
				obj.draw(b4, color);
			
		type = savetype;
		 color = colorSave;
		 b1 = b1Save;
		 b1Loc = b1LocSave;
		b2 = b2Save;
		 b2Loc = b2LocSave;
		b3 = b3Save;
		 b3Loc = b3LocSave;
		 b4 = b4Save;
		  b4Loc = b4LocSave;
		fourWayRot = fourWayRotSave;
		twoWayRot = twoWayRotSave;
	
}
void Piece::Proj(Render proj)
{
	test1 = b1Loc;
	test2 = b2Loc;
	test3 = b3Loc;
	test4 = b4Loc;
	float downTimes = 0;

	while (noCollide())
	{
		test1.y -= 1;
		test2.y -= 1;
		test3.y -= 1;
		test4.y -= 1;
		downTimes += 1;
	}

	test1.y += 1;
	test2.y += 1;
	test3.y += 1;
	test4.y += 1;
	downTimes -= 1;

	b1Save = b1;
	b2Save = b2;
	b3Save = b3;
	b4Save = b4;
	b1 = glm::translate(b1, bdown * downTimes);
	b2 = glm::translate(b2, bdown * downTimes);
	b3 = glm::translate(b3, bdown * downTimes);
	b4 = glm::translate(b4, bdown * downTimes);

	proj.draw(b1, color);
	proj.draw(b2, color);
	proj.draw(b3, color);
	proj.draw(b4, color);

	b1 = b1Save;
	b2 = b2Save;
	b3 = b3Save; 
	b4 = b4Save;
}

void Piece::setUpExtra()
{
	b1 = glm::translate(b1, bleft * 9.0f);
	b2 = glm::translate(b2, bleft * 9.0f);
	b3 = glm::translate(b3, bleft * 9.0f);
	b4 = glm::translate(b4, bleft * 9.0f);

	b1 = glm::translate(b1, bdown * 5.0f);
	b2 = glm::translate(b2, bdown * 5.0f);
	b3 = glm::translate(b3, bdown * 5.0f);
	b4 = glm::translate(b4, bdown * 5.0f);

	if (type == BLOCK)
	{

		b1 = glm::translate(b1, bleft * 0.5f);
		b2 = glm::translate(b2, bleft * 0.5f);
		b3 = glm::translate(b3, bleft * 0.5f);
		b4 = glm::translate(b4, bleft * 0.5f);

	}
	else if (type == LL || type == L)
	{
		b1 = glm::translate(b1, bup);
		b2 = glm::translate(b2, bup);
		b3 = glm::translate(b3, bup);
		b4 = glm::translate(b4, bup);
	}
	else if (type == STICK)
	{
		b1 = glm::translate(b1, bup * 2.0f);
		b2 = glm::translate(b2, bup * 2.0f);
		b3 = glm::translate(b3, bup * 2.0f);
		b4 = glm::translate(b4, bup * 2.0f);
	}
	checkLoss();
	if (lines >= 20)
	{
		speedMultiplier += 0.75f;
		lines = 0;
	}
}

void Piece::down()
{
	
		test1 = b1Loc;
		test1[1] -= 1;
		test2 = b2Loc;
		test2[1] -= 1;
		test3 = b3Loc;
		test3[1] -= 1;
		test4 = b4Loc;
		test4[1] -= 1;

		if (noCollide())
		{
			b1 = glm::translate(b1, bdown);
			b1Loc[1] -= 1;
			b2 = glm::translate(b2, bdown);
			b2Loc[1] -= 1;
			b3 = glm::translate(b3, bdown);
			b3Loc[1] -= 1;
			b4 = glm::translate(b4, bdown);
			b4Loc[1] -= 1;
			return;
		}
	

	
	pB.placedBlocks.push_back(b1Loc);
	pB.placedBlocks.push_back(b2Loc);
	pB.placedBlocks.push_back(b3Loc);
	pB.placedBlocks.push_back(b4Loc);

	pB.placedBlocksTrans.push_back(b1);
	pB.placedBlocksTrans.push_back(b2);
	pB.placedBlocksTrans.push_back(b3);
	pB.placedBlocksTrans.push_back(b4);

	pB.blockColor.push_back(color);
	pB.blockColor.push_back(color);
	pB.blockColor.push_back(color);
	pB.blockColor.push_back(color);


	//destroy lines
	int line1 = 0;
	std::vector <float> Ys;
	
	
	float linesDest = 0.0f;
	for (int i = -20; i < 5; i++)
	{

		for (auto& e : pB.placedBlocks)
		{
			if (e.y == i)
			{
				//std::cout << "found 1 at " << e.y << '\n';
				line1 += 1;
			}


		}
		//std::cout << "line1 is " << line1 << '\n';
		if (line1 == 10)
		{
			//destroy all blocks
			
			Ys.push_back(i);
		

			pB.destroyLine(static_cast<float>(i));
			linesDest += 1.0f;
			line1 = 0;
		}
		else
			line1 = 0;
	}
	

	if (linesDest > 0.0f)
	{
		lines += linesDest;
		totalLines += linesDest;
		for (int k = linesDest-1; k > -1; k--)
		{
			for (int ii = 0; ii < pB.placedBlocks.size(); ii++)
			{
				//make fall to floor

				for (int h = 0; h < 19; h++)
				{

					moveGrave(Ys[k] + h, ii, linesDest);
				}

			}
		}
	}
	
	resetBlock(NONE);
	h = false;
	doFastDrop = false;

}

void Piece::left()
{
		test1 = b1Loc;
		test1[0] -= 1;
		test2 = b2Loc;
		test2[0] -= 1;
		test3 = b3Loc;
		test3[0] -= 1;
		test4 = b4Loc;
		test4[0] -= 1;

		if (noCollide())
		{
			b1 = glm::translate(b1, bleft);
			b1Loc[0] -= 1;
			b2 = glm::translate(b2, bleft);
			b2Loc[0] -= 1;
			b3 = glm::translate(b3, bleft);
			b3Loc[0] -= 1;
			b4 = glm::translate(b4, bleft);
			b4Loc[0] -= 1;
			return;
		}
}

void Piece::right()
{
			test1 = b1Loc;
			test1[0] += 1;
			test2 = b2Loc;
			test2[0] += 1;
			test3 = b3Loc;
			test3[0] += 1;
			test4 = b4Loc;
			test4[0] += 1;

			if (noCollide())
			{
				b1 = glm::translate(b1, bright);
				b1Loc[0] += 1;
				b2 = glm::translate(b2, bright);
				b2Loc[0] += 1;
				b3 = glm::translate(b3, bright);
				b3Loc[0] += 1;
				b4 = glm::translate(b4, bright);
				b4Loc[0] += 1;
			}
}

void Piece::fastDrop()
{
	while (doFastDrop)
	{
		down();
	}
	doFastDrop = true;
}

void Piece::sayCords()
{
	std::cout << "B1 = " << b1Loc[0] << ", " << b1Loc[1] << '\n';
	std::cout << "B2 = " << b2Loc[0] << ", " << b2Loc[1] << '\n';
	std::cout << "B3 = " << b3Loc[0] << ", " << b3Loc[1] << '\n';
	std::cout << "B4 = " << b4Loc[0] << ", " << b4Loc[1] << '\n';
}

void Piece::resetBlock(pieces TYPE)
{
	b1 = setBlock();
	b1Loc = { 6, 3 };
	b2 = setBlock();
	b2Loc = { 6, 3 };
	b3 = setBlock();
	b3Loc = { 6, 3 };
	b4 = setBlock();
	b4Loc = { 6, 3 };
	twoWayRot = 0;
	fourWayRot = 0;

	if (TYPE == NONE)
	{
		changeBlock(die(mersenne));
		next.push_back(type);
		type = next[0];
		next.erase(next.begin() + 0);
	}
	else
		type = TYPE;

	typeSpec();

	

}

void Piece::typeSpec()
{
	switch (type)
	{
	case BLOCK:
	{
		b2 = glm::translate(b2, bdown);
		b2Loc[1] -= 1;
		b3 = glm::translate(b3, bright);
		b3Loc[0] += 1;
		b4 = glm::translate(b4, bright);
		b4Loc[0] += 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		color = yellow;
		break;
	}
	case STICK:
	{
		b2 = glm::translate(b2, bdown);
		b2Loc[1] -= 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		color = lightBlue;
		break;
	}
	case L:
	{
		b2 = glm::translate(b2, bdown);
		b2Loc[1] -= 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bright);
		b4Loc[0] += 1;
		color = orange;
		break;
	}
	case LL:
	{
		b2 = glm::translate(b2, bdown);
		b2Loc[1] -= 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bleft);
		b4Loc[0] -= 1;
		color = blue;
		break;
	}
	case ZIGR:
	{
		b2 = glm::translate(b2, bright);
		b2Loc[0] += 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bleft);
		b4Loc[0] -= 1;
		color = green;
		break;
	}
	case ZIGL:
	{
		b2 = glm::translate(b2, bleft);
		b2Loc[0] -= 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bright);
		b4Loc[0] += 1;
		color = red;
		break;
	}
	case T:
	{
		b2 = glm::translate(b2, bdown);
		b2Loc[1] -= 1;
		b3 = glm::translate(b3, bdown);
		b3Loc[1] -= 1;
		b3 = glm::translate(b3, bright);
		b3Loc[0] += 1;
		b4 = glm::translate(b4, bdown);
		b4Loc[1] -= 1;
		b4 = glm::translate(b4, bleft);
		b4Loc[0] -= 1;
		color = purple;
		break;
	}
	}
}

void Piece::spec()
{
	switch (type)
	{
	case BLOCK:
	{
		b2 = glm::translate(b2, bdown);
		b3 = glm::translate(b3, bright);
		b4 = glm::translate(b4, bright);
		b4 = glm::translate(b4, bdown);
		color = yellow;
		break;
	}
	case STICK:
	{
		b2 = glm::translate(b2, bdown);
		b3 = glm::translate(b3, bdown);
		b3 = glm::translate(b3, bdown);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bdown);
		color = lightBlue;
		break;
	}
	case L:
	{
		b2 = glm::translate(b2, bdown);
		b3 = glm::translate(b3, bdown);
		b3 = glm::translate(b3, bdown);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bright);
		color = orange;
		break;
	}
	case LL:
	{
		b2 = glm::translate(b2, bdown);
		b3 = glm::translate(b3, bdown);
		b3 = glm::translate(b3, bdown);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bleft);
		color = blue;
		break;
	}
	case ZIGR:
	{
		b2 = glm::translate(b2, bright);
		b3 = glm::translate(b3, bdown);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bleft);
		color = green;
		break;
	}
	case ZIGL:
	{
		b2 = glm::translate(b2, bleft);
		b3 = glm::translate(b3, bdown);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bright);
		color = red;
		break;
	}
	case T:
	{
		b2 = glm::translate(b2, bdown);
		b3 = glm::translate(b3, bdown);
		b3 = glm::translate(b3, bright);
		b4 = glm::translate(b4, bdown);
		b4 = glm::translate(b4, bleft);
		color = purple;
		break;
	}
	}
}


void Piece::changeBlock(int t)
{

	switch (t)
	{
	case 0:
	{
		type = BLOCK;
		break;
	}
	case 1:
	{
		type = STICK;
		break;
	}
	case 2:
	{
		type = L;
		break;
	}
	case 3:
	{
		type = LL;
		break;
	}
	case 4:
	{
		type = ZIGR;
		break;
	}
	case 5:
	{
		type = ZIGL;
		break;
	}
	case 6:
	{
		type = T;
		break;
	}
	}
}

bool Piece::noCollide()
{
	if (test1[0] != 0 && test2[0] != 0 && test3[0] != 0 && test4[0] != 0 && test1[0] != 11 && test2[0] != 11 && test3[0] != 11 && test4[0] != 11 && test1[1] != -19 && test2[1] != -19 && test3[1] != -19 && test4[1] != -19 && !pB.findloc(test1) && !pB.findloc(test2) && !pB.findloc(test3) && !pB.findloc(test4))
		return true;

	return false;
}

void Piece::moveGrave(int y, int ii, float linesDest)
{
	if (pB.placedBlocks[ii].y == y)
	{
		test1 = pB.placedBlocks[ii];
		test1[1] -= 1;
		pB.placedBlocks[ii].y = test1.y;
		pB.placedBlocksTrans[ii] = glm::translate(pB.placedBlocksTrans[ii], bdown);
		
	}	
}

void Piece::increaseTest(int x, int y) 
{
	test1 = b1Loc;
	test1.x += x;
	test1.y += y;

	test2 = b2Loc;
	test2.x += x;
	test2.y += y;

	test3 = b3Loc;
	test3.x += x;
	test3.y += y;

	test4 = b4Loc;
	test4.x += x;
	test4.y += y;
}

void Piece::checkLoss()
{
	for (auto e : pB.placedBlocks)
	{
		if (e.y >= 1)
		{
			//reset everything, and bring to loss menue
			reset();
			std::cout << "loss" << '\n';
			loss = true;	
			break;
		}
	}
}

void Piece::reset()
{
	pB.blockColor.clear();
	pB.placedBlocks.clear();
	pB.placedBlocksTrans.clear();
	next.clear();
	type = NONE;
	held = NONE;
	isheld = false;
	lines = 0;
	totalLines = 0;
	speedMultiplier = 1.0f;
	changeBlock(die(mersenne));
	next.push_back(type);
	changeBlock(die(mersenne));
	next.push_back(type);
	changeBlock(die(mersenne));
	next.push_back(type);
	resetBlock(NONE);
}
void Piece::hold()
{
	isheld = true;
	if (held == NONE)
	{
		held = type;
		resetBlock(NONE);
	}
	else
	{
		pieces save = type;
		resetBlock(held);
		held = save;

	}
}



void Piece::rotate()
{
	switch (type)
	{
	case BLOCK:
	{
		break;
	}
	case STICK:
	{
		if (twoWayRot == 0)
		{
			test1 = b1Loc;
			test1[1] -= 3;
			test2 = b2Loc;
			test2[1] -= 2;
			test2[0] -= 1;
			test3 = b3Loc;
			test3[1] -= 1;
			test3[0] -= 2;
			test4 = b4Loc;
			test4[0] += 1;


			if (noCollide())
			{
				b1 = glm::translate(b1, bdown);
				b1 = glm::translate(b1, bdown);
				b1 = glm::translate(b1, bdown);

				b2 = glm::translate(b2, bdown);
				b2 = glm::translate(b2, bdown);
				b2 = glm::translate(b2, bleft);

				b3 = glm::translate(b3, bdown);
				b3 = glm::translate(b3, bleft);
				b3 = glm::translate(b3, bleft);

				b4 = glm::translate(b4, bright);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;

				twoWayRot = 1;
			}
			else {

				test1[0] -= 1;
				test2[0] -= 1;
				test3[0] -= 1;
				test4[0] -= 1;
				if (noCollide())
				{
					b1 = glm::translate(b1, bdown);
					b1 = glm::translate(b1, bdown);
					b1 = glm::translate(b1, bdown);
					b1 = glm::translate(b1, bleft);

					b2 = glm::translate(b2, bdown);
					b2 = glm::translate(b2, bdown);
					b2 = glm::translate(b2, bleft);
					b2 = glm::translate(b2, bleft);

					b3 = glm::translate(b3, bdown);
					b3 = glm::translate(b3, bleft);
					b3 = glm::translate(b3, bleft);
					b3 = glm::translate(b3, bleft);

					b4 = glm::translate(b4, bright);
					b4 = glm::translate(b4, bleft);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					twoWayRot = 1;

				}
				else {
					test1[0] += 2;
					test2[0] += 2;
					test3[0] += 2;
					test4[0] += 2;
					if (noCollide())
					{
						b1 = glm::translate(b1, bdown);
						b1 = glm::translate(b1, bdown);
						b1 = glm::translate(b1, bdown);
						b1 = glm::translate(b1, bright);

						b2 = glm::translate(b2, bdown);
						b2 = glm::translate(b2, bdown);
						b2 = glm::translate(b2, bleft);
						b2 = glm::translate(b2, bright);

						b3 = glm::translate(b3, bdown);
						b3 = glm::translate(b3, bleft);
						b3 = glm::translate(b3, bleft);
						b3 = glm::translate(b3, bright);

						b4 = glm::translate(b4, bright);
						b4 = glm::translate(b4, bright);

						b1Loc = test1;
						b2Loc = test2;
						b3Loc = test3;
						b4Loc = test4;
						twoWayRot = 1;
					}
					else
					{
						test1[0] += 1;
						test2[0] += 1;
						test3[0] += 1;
						test4[0] += 1;
						if (noCollide())
						{
							b1 = glm::translate(b1, bdown);
							b1 = glm::translate(b1, bdown);
							b1 = glm::translate(b1, bdown);
							b1 = glm::translate(b1, bright);
							b1 = glm::translate(b1, bright);

							b2 = glm::translate(b2, bdown);
							b2 = glm::translate(b2, bdown);
							b2 = glm::translate(b2, bleft);
							b2 = glm::translate(b2, bright);
							b2 = glm::translate(b2, bright);

							b3 = glm::translate(b3, bdown);
							b3 = glm::translate(b3, bleft);
							b3 = glm::translate(b3, bleft);
							b3 = glm::translate(b3, bright);
							b3 = glm::translate(b3, bright);

							b4 = glm::translate(b4, bright);
							b4 = glm::translate(b4, bright);
							b4 = glm::translate(b4, bright);

							b1Loc = test1;
							b2Loc = test2;
							b3Loc = test3;
							b4Loc = test4;
							twoWayRot = 1;
						}
					}


				}

			}
		}
		else if (twoWayRot == 1)
		{
			test1 = b1Loc;
			test1[1] += 3;
			test2 = b2Loc;
			test2[1] += 2;
			test2[0] += 1;
			test3 = b3Loc;
			test3[1] += 1;
			test3[0] += 2;
			test4 = b4Loc;
			test4[0] -= 1;

			if (noCollide())
			{
				b1 = glm::translate(b1, bup);
				b1 = glm::translate(b1, bup);
				b1 = glm::translate(b1, bup);
				b2 = glm::translate(b2, bup);
				b2 = glm::translate(b2, bup);
				b2 = glm::translate(b2, bright);
				b3 = glm::translate(b3, bup);
				b3 = glm::translate(b3, bright);
				b3 = glm::translate(b3, bright);
				b4 = glm::translate(b4, bleft);
				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				twoWayRot = 0;
			}
		}
		break;


	}
	case L:
	{
		if (fourWayRot == 0)
		{
			test1 = b1Loc;
			test1[1] -= 1;
			test1[0] -= 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[0] -= 1;
			test4 = b4Loc;
			test4[1] += 1;

			if (noCollide())
			{
				b1 = glm::translate(b1, bdown);
				b1 = glm::translate(b1, bleft);
				b3 = glm::translate(b3, bleft);
				b4 = glm::translate(b4, bup);
				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 1;
			}
			else
			{
				test1[0] += 1;
				test2[0] += 1;
				test3[0] += 1;
				test4[0] += 1;

				if (noCollide())
				{
					b1 = glm::translate(b1, bdown);
					b1 = glm::translate(b1, bleft);
					b1 = glm::translate(b1, bright);

					b2 = glm::translate(b2, bright);

					b3 = glm::translate(b3, bleft);
					b3 = glm::translate(b3, bright);

					b4 = glm::translate(b4, bup);
					b4 = glm::translate(b4, bright);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					fourWayRot = 1;
				}
			}
		}
		else if (fourWayRot == 1)
		{
			test1 = b1Loc;
			test1[1] += 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[0] += 1;
			test4 = b4Loc;
			test4[1] += 1;
			test4[0] -= 1;


			if (noCollide())
			{
				b1 = glm::translate(b1, bup);

				b3 = glm::translate(b3, bright);

				b4 = glm::translate(b4, bup);
				b4 = glm::translate(b4, bleft);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 2;
			}

		}
		else if (fourWayRot == 2)
		{
			test1 = b1Loc;
			test1[1] -= 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[0] += 1;
			test3[1] += 1;
			test4 = b4Loc;
			test4[0] += 1;

			if (noCollide())
			{
				b1 = glm::translate(b1, bdown);

				b3 = glm::translate(b3, bright);

				b3 = glm::translate(b3, bup);

				b4 = glm::translate(b4, bright);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 3;
			}
			else
			{
				test1[0] -= 1;
				test2[0] -= 1;
				test3[0] -= 1;
				test4[0] -= 1;

				if (noCollide())
				{
					b1 = glm::translate(b1, bdown);
					b1 = glm::translate(b1, bleft);

					b2 = glm::translate(b2, bleft);

					b3 = glm::translate(b3, bright);
					b3 = glm::translate(b3, bup);
					b3 = glm::translate(b3, bleft);

					b4 = glm::translate(b4, bright);
					b4 = glm::translate(b4, bleft);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					fourWayRot = 3;
				}


			}
		}
		else if (fourWayRot == 3)
		{
			test1 = b1Loc;
			test1[1] += 1;
			test1[0] += 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[0] -= 1;
			test3[1] -= 1;
			test4 = b4Loc;
			test4[1] -= 2;

			if (noCollide())
			{
				b1 = glm::translate(b1, bup);
				b1 = glm::translate(b1, bright);

				b3 = glm::translate(b3, bdown);
				b3 = glm::translate(b3, bleft);

				b4 = glm::translate(b4, bdown);
				b4 = glm::translate(b4, bdown);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 0;
			}
		}

		break;
	}
	case LL:
	{
		if (fourWayRot == 0)
		{
			test1 = b1Loc;
			test1[0] -= 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[0] += 1;
			test3[1] += 1;
			test4 = b4Loc;
			test4[1] += 1;

			if (noCollide())
			{
				b1 = glm::translate(b1, bleft);

				b3 = glm::translate(b3, bup);
				b3 = glm::translate(b3, bright);

				b4 = glm::translate(b4, bup);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 1;
			}
			else
			{
				test1[0] -= 1;
				test2[0] -= 1;
				test3[0] -= 1;
				test4[0] -= 1;

				if (noCollide())
				{
					b1 = glm::translate(b1, bleft);
					b1 = glm::translate(b1, bleft);

					b2 = glm::translate(b2, bleft);

					b3 = glm::translate(b3, bright);
					b3 = glm::translate(b3, bup);
					b3 = glm::translate(b3, bleft);

					b4 = glm::translate(b4, bup);
					b4 = glm::translate(b4, bleft);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					fourWayRot = 1;
				}
			}
		}
		else if (fourWayRot == 1)
		{
			test1 = b1Loc;
			test1[0] += 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[1] += 1;
			test4 = b4Loc;
			test4[1] -= 1;
			test4[0] += 1;


			if (noCollide())
			{
				b1 = glm::translate(b1, bright);

				b3 = glm::translate(b3, bup);

				b4 = glm::translate(b4, bdown);
				b4 = glm::translate(b4, bright);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 2;
			}

		}
		else if (fourWayRot == 2)
		{
			test1 = b1Loc;
			test1[1] -= 1;
			test1[0] -= 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[1] -= 1;
			test4 = b4Loc;
			test4[0] += 1;

			if (noCollide())
			{
				b1 = glm::translate(b1, bdown);
				b1 = glm::translate(b1, bleft);

				b3 = glm::translate(b3, bdown);

				b4 = glm::translate(b4, bright);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 3;
			}
			else
			{
				test1[0] += 1;
				test2[0] += 1;
				test3[0] += 1;
				test4[0] += 1;

				if (noCollide())
				{
					b1 = glm::translate(b1, bdown);
					b1 = glm::translate(b1, bleft);
					b1 = glm::translate(b1, bright);

					b2 = glm::translate(b2, bright);

					b3 = glm::translate(b3, bdown);
					b3 = glm::translate(b3, bright);

					b4 = glm::translate(b4, bright);
					b4 = glm::translate(b4, bright);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					fourWayRot = 3;
				}


			}
		}
		else if (fourWayRot == 3)
		{
			test1 = b1Loc;
			test1[1] += 1;
			test1[0] += 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[0] -= 1;
			test3[1] -= 1;
			test4 = b4Loc;
			test4[0] -= 2;

			if (noCollide())
			{
				b1 = glm::translate(b1, bup);
				b1 = glm::translate(b1, bright);

				b3 = glm::translate(b3, bdown);
				b3 = glm::translate(b3, bleft);

				b4 = glm::translate(b4, bleft);
				b4 = glm::translate(b4, bleft);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 0;
			}
		}
		break;
	}
	case ZIGR:
	{


		if (twoWayRot == 0)
		{
			test1 = b1Loc;
			test2 = b2Loc;
			test2[0] -= 2;
			test3 = b3Loc;
			test4 = b4Loc;
			test4[1] += 2;

			if (noCollide())
			{

				b2 = glm::translate(b2, bleft);
				b2 = glm::translate(b2, bleft);

				b4 = glm::translate(b4, bup);
				b4 = glm::translate(b4, bup);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				twoWayRot = 1;
			}
		}
		else if (twoWayRot == 1)
		{
			test1 = b1Loc;
			test2 = b2Loc;
			test2[0] += 2;
			test3 = b3Loc;
			test4 = b4Loc;
			test4[1] -= 2;

			if (noCollide())
			{
				b2 = glm::translate(b2, bright);
				b2 = glm::translate(b2, bright);

				b4 = glm::translate(b4, bdown);
				b4 = glm::translate(b4, bdown);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				twoWayRot = 0;
			}
			else
			{
				test1[0] -= 1;
				test2[0] -= 1;
				test3[0] -= 1;
				test4[0] -= 1;

				if (noCollide())
				{
					b1 = glm::translate(b1, bleft);

					b2 = glm::translate(b2, bright);
					b2 = glm::translate(b2, bright);
					b2 = glm::translate(b2, bleft);

					b3 = glm::translate(b3, bleft);

					b4 = glm::translate(b4, bdown);
					b4 = glm::translate(b4, bdown);
					b4 = glm::translate(b4, bleft);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					twoWayRot = 0;
				}
			}

		}

		break;
	}
	case ZIGL:
	{
		if (twoWayRot == 0)
		{
			test1 = b1Loc;
			test2 = b2Loc;
			test2[0] += 2;
			test3 = b3Loc;
			test4 = b4Loc;
			test4[1] += 2;

			if (noCollide())
			{

				b2 = glm::translate(b2, bright);
				b2 = glm::translate(b2, bright);

				b4 = glm::translate(b4, bup);
				b4 = glm::translate(b4, bup);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				twoWayRot = 1;
			}
		}
		else if (twoWayRot == 1)
		{
			test1 = b1Loc;
			test2 = b2Loc;
			test2[0] -= 2;
			test3 = b3Loc;
			test4 = b4Loc;
			test4[1] -= 2;

			if (noCollide())
			{
				b2 = glm::translate(b2, bleft);
				b2 = glm::translate(b2, bleft);

				b4 = glm::translate(b4, bdown);
				b4 = glm::translate(b4, bdown);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				twoWayRot = 0;
			}
			else
			{
				test1[0] += 1;
				test2[0] += 1;
				test3[0] += 1;
				test4[0] += 1;

				if (noCollide())
				{
					b1 = glm::translate(b1, bright);

					b2 = glm::translate(b2, bleft);
					b2 = glm::translate(b2, bleft);
					b2 = glm::translate(b2, bright);

					b3 = glm::translate(b3, bright);

					b4 = glm::translate(b4, bdown);
					b4 = glm::translate(b4, bdown);
					b4 = glm::translate(b4, bright);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					twoWayRot = 0;
				}
			}

		}
		break;
	}
	case T:
	{
		if (fourWayRot == 0)
		{
			test1 = b1Loc;
			test2 = b2Loc;
			test3 = b3Loc;
			test4 = b4Loc;
			test4[1] -= 1;
			test4[0] += 1;

			if (noCollide())
			{
				b4 = glm::translate(b4, bdown);
				b4 = glm::translate(b4, bright);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 1;
			}
			else
			{
				test1[1] += 1;
				test2[1] += 1;
				test3[1] += 1;
				test4[1] += 1;
				if (noCollide())
				{
					b1 = glm::translate(b1, bup);

					b2 = glm::translate(b2, bup);

					b3 = glm::translate(b3, bup);

					b4 = glm::translate(b4, bdown);
					b4 = glm::translate(b4, bright);
					b4 = glm::translate(b4, bup);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					fourWayRot = 1;
				}
			}
		}
		else if (fourWayRot == 1)
		{
			test1 = b1Loc;
			test1[1] -= 1;
			test1[0] -= 1;
			test2 = b2Loc;
			test3 = b3Loc;
			test4 = b4Loc;


			if (noCollide())
			{
				b1 = glm::translate(b1, bdown);
				b1 = glm::translate(b1, bleft);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 2;
			}
			else
			{
				test1[0] += 1;
				test2[0] += 1;
				test3[0] += 1;
				test4[0] += 1;
				if (noCollide())
				{

					b1 = glm::translate(b1, bdown);
					b1 = glm::translate(b1, bleft);
					b1 = glm::translate(b1, bright);

					b2 = glm::translate(b2, bright);

					b3 = glm::translate(b3, bright);

					b4 = glm::translate(b4, bright);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					fourWayRot = 2;
				}
			}



		}
		else if (fourWayRot == 2)
		{
			test1 = b1Loc;
			test2 = b2Loc;
			test3 = b3Loc;
			test3[1] += 1;
			test3[0] -= 1;
			test4 = b4Loc;


			if (noCollide())
			{
				b3 = glm::translate(b3, bup);
				b3 = glm::translate(b3, bleft);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 3;
			}

		}
		else if (fourWayRot == 3)
		{
			test1 = b1Loc;
			test1[1] += 1;
			test1[0] += 1;

			test2 = b2Loc;

			test3 = b3Loc;
			test3[1] -= 1;
			test3[0] += 1;

			test4 = b4Loc;
			test4[1] += 1;
			test4[0] -= 1;

			if (noCollide())
			{
				b1 = glm::translate(b1, bup);
				b1 = glm::translate(b1, bright);

				b3 = glm::translate(b3, bdown);
				b3 = glm::translate(b3, bright);

				b4 = glm::translate(b4, bup);
				b4 = glm::translate(b4, bleft);

				b1Loc = test1;
				b2Loc = test2;
				b3Loc = test3;
				b4Loc = test4;
				fourWayRot = 0;
			}
			else
			{
				test1[0] -= 1;
				test2[0] -= 1;
				test3[0] -= 1;
				test4[0] -= 1;
				if (noCollide())
				{
					b1 = glm::translate(b1, bup);
					b1 = glm::translate(b1, bright);
					b1 = glm::translate(b1, bleft);

					b2 = glm::translate(b2, bleft);

					b3 = glm::translate(b3, bdown);
					b3 = glm::translate(b3, bright);
					b3 = glm::translate(b3, bleft);

					b4 = glm::translate(b4, bup);
					b4 = glm::translate(b4, bleft);
					b4 = glm::translate(b4, bleft);

					b1Loc = test1;
					b2Loc = test2;
					b3Loc = test3;
					b4Loc = test4;
					fourWayRot = 0;
				}
			}
		}
		break;
	}
	}
}