#include "control.h"
Object mainControl(Object p, int size, vector<vector<string>> board) {

	PlayerKey mainPlayer;
	PlayerKey secondPlayer;
	ControlGame controlGame;
	getKey(mainPlayer, secondPlayer, controlGame);

	int press = 0;
	while (press == 0)
	{
		press = 0;
		char key = _getch();

		if (mainPlayer.up == 'w')
		{
			mainPlayer.up = 72;
		}
		if (mainPlayer.left == 'a')
		{
			mainPlayer.left = 75;
		}
		if (mainPlayer.right == 'd')
		{
			mainPlayer.right = 77;
		}
		if (mainPlayer.down == 's')
		{
			mainPlayer.down = 80;
		}



		if (key == mainPlayer.left || key == mainPlayer.left + 32)
		{
			if (p.x == 2) 
			{
				p.x = p.x;
			}
			else
			{
				p.x -= 4;
			}
		}
		if (key == mainPlayer.right || key == mainPlayer.right + 32)
		{
			if (p.x == size*4-2)
			{
				p.x = p.x;
			}
			else
			{
				p.x += 4;
			}
		}
		if (key == mainPlayer.up || key == mainPlayer.up + 32)
		{
			if (p.y == 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y -= 2;
			}
		}
		if (key == mainPlayer.down || key == mainPlayer.down + 32)
		{
			if (p.y == size*2 -1)
			{
				p.y = p.y;
			}
			else
			{
				p.y += 2;
			}
		}
		gotoXY(p.x, p.y);
		if (key == mainPlayer.attack || key == mainPlayer.attack + 32)
		{
			if (board[(p.x - 2)/ 4][(p.y - 1) / 2] == "_" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "B" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "C")
			{
				cout << p.icon;
				press = 1;

			}
			else
			{
				press = 0;
			}

		}
		if (key == controlGame.save || key == controlGame.save + 32)
		{
			p.save = 1;
			break;
		}

		if (key == controlGame.undo || key == controlGame.undo + 32)
		{
			p.undo = 1;
			break;
		}
		if (key == controlGame.back || key == controlGame.back + 32)
		{
			p.quit = 1;
			break;
		}


	}
	return p;
}

Object secondControl(Object p, int size, vector<vector<string>> board) {

	PlayerKey mainPlayer;
	PlayerKey secondPlayer;
	ControlGame controlGame;
	getKey(mainPlayer, secondPlayer, controlGame);


	int press = 0;
	while (press == 0)
	{
		press = 0;
		char key = _getch();

		if (secondPlayer.up == 'w')
		{
			secondPlayer.up = 72;
		}
		if (secondPlayer.left == 'a')
		{
			secondPlayer.left = 75;
		}
		if (secondPlayer.right == 'd')
		{
			secondPlayer.right = 77;
		}
		if (secondPlayer.down == 's')
		{
			secondPlayer.down = 80;
		}



		if (key == secondPlayer.left || key == secondPlayer.left + 32)
		{
			if (p.x == 2)
			{
				p.x = p.x;
			}
			else
			{
				p.x -= 4;
			}
		}
		if (key == secondPlayer.right || key == secondPlayer.right + 32)
		{
			if (p.x == size*4 - 2)
			{
				p.x = p.x;
			}
			else
			{
				p.x += 4;
			}
		}
		if (key == secondPlayer.up || key == secondPlayer.up + 32)
		{
			if (p.y == 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y -= 2;
			}
		}
		if (key == secondPlayer.down || key == secondPlayer.down + 32)
		{
			if (p.y == size*2 - 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y += 2;
			}
		}
		gotoXY(p.x, p.y);
		if (key == secondPlayer.attack || key == secondPlayer.attack + 32)
		{
			if (board[(p.x - 2) / 4][(p.y - 1) / 2] == "_" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "B" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "C")
			{
				cout << p.icon;
				press = 1;
			}
			else
			{
				press = 0;
			}
		}

		if (key == controlGame.save || key == controlGame.save + 32)
		{
			p.save = 1;
			break;
		}

		if (key == controlGame.undo || key == controlGame.undo + 32)
		{
			p.undo = 1;
			break;
		}
		if (key == controlGame.back || key == controlGame.back + 32)
		{
			p.quit = 1;
			break;
		}
	}
	return p;

}

Object mainControlRule6(Object p, int size, vector<vector<string>> board, int numMove, int maxMove) {

	PlayerKey mainPlayer;
	PlayerKey secondPlayer;
	ControlGame controlGame;
	getKey(mainPlayer, secondPlayer, controlGame);

	int press = 0;
	while (press == 0)
	{
		press = 0;
		char key = _getch();

		if (mainPlayer.up == 'w')
		{
			mainPlayer.up = 72;
		}
		if (mainPlayer.left == 'a')
		{
			mainPlayer.left = 75;
		}
		if (mainPlayer.right == 'd')
		{
			mainPlayer.right = 77;
		}
		if (mainPlayer.down == 's')
		{
			mainPlayer.down = 80;
		}


		if (key == mainPlayer.left || key == mainPlayer.left + 32)
		{
			if (p.x == 2)
			{
				p.x = p.x;
			}
			else
			{
				p.x -= 4;
			}
			numMove++;
		}
		if (key == mainPlayer.right || key == mainPlayer.right + 32)
		{
			if (p.x == size*4 - 2)
			{
				p.x = p.x;
			}
			else
			{
				p.x += 4;
			}
			numMove++;
		}
		if (key == mainPlayer.up || key == mainPlayer.up + 32)
		{
			if (p.y == 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y -= 2;
			}
			numMove++;
		}
		if (key == mainPlayer.down || key == mainPlayer.down + 32)
		{
			if (p.y == size*2 - 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y += 2;
			}
			numMove++;
		}
		gotoXY(p.x, p.y);
		if (key == mainPlayer.attack || key == mainPlayer.attack + 32)
		{
			if (board[(p.x - 2) / 4][(p.y - 1) / 2] == "_" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "B" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "C")
			{
				cout << p.icon;
				press = 1;

			}
			else
			{
				press = 0;
			}

		}
		if (key == controlGame.save || key == controlGame.save + 32)
		{
			p.save = 1;
			break;
		}

		if (key == controlGame.undo || key == controlGame.undo + 32)
		{
			p.undo = 1;
			break;
		}
		if (key == controlGame.back || key == controlGame.back + 32)
		{
			p.quit = 1;
			break;
		}

		if (numMove == maxMove)
		{
			if (board[(p.x - 2) / 4][(p.y - 1) / 2] != "_")
			{
				numMove--;
			}
			else
			{
				cout << p.icon;
				numMove = 0;
				return p;
			}
		}


	}
	return p;
}

Object secondControlRule6(Object p, int size, vector<vector<string>> board, int numMove, int maxMove) {

	PlayerKey mainPlayer;
	PlayerKey secondPlayer;
	ControlGame controlGame;
	getKey(mainPlayer, secondPlayer, controlGame);


	int press = 0;
	while (press == 0)
	{
		press = 0;
		char key = _getch();

		if (secondPlayer.up == 'w')
		{
			secondPlayer.up = 72;
		}
		if (secondPlayer.left == 'a')
		{
			secondPlayer.left = 75;
		}
		if (secondPlayer.right == 'd')
		{
			secondPlayer.right = 77;
		}
		if (secondPlayer.down == 's')
		{
			secondPlayer.down = 80;
		}



		if (key == secondPlayer.left || key == secondPlayer.left + 32)
		{
			if (p.x == 2)
			{
				p.x = p.x;
			}
			else
			{
				p.x -= 4;
			}
			numMove++;
		}
		if (key == secondPlayer.right || key == secondPlayer.right + 32)
		{
			if (p.x == size*4 - 2)
			{
				p.x = p.x;
			}
			else
			{
				p.x += 4;
			}
			numMove++;
		}
		if (key == secondPlayer.up || key == secondPlayer.up + 32)
		{
			if (p.y == 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y -= 2;
			}
			numMove++;
		}
		if (key == secondPlayer.down || key == secondPlayer.down + 32)
		{
			if (p.y == size*2 - 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y += 2;
			}
			numMove++;
		}
		gotoXY(p.x, p.y);
		if (key == secondPlayer.attack || key == secondPlayer.attack + 32)
		{
			if (board[(p.x - 2) / 4][(p.y - 1) / 2] == "_" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "B" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "C")
			{
				cout << p.icon;
				press = 1;
			}
			else
			{
				press = 0;
			}
		}

		if (key == controlGame.save || key == controlGame.save + 32)
		{
			p.save = 1;
			break;
		}

		if (key == controlGame.undo || key == controlGame.undo + 32)
		{
			p.undo = 1;
			break;
		}
		if (key == controlGame.back || key == controlGame.back + 32)
		{
			p.quit = 1;
			break;
		}

		if (numMove == maxMove)
		{
			if (board[(p.x - 2) / 4][(p.y - 1) / 2] != "_")
			{
				numMove--;
			}
			else
			{
				cout << p.icon;
				numMove = 0;
				return p;
			}
		}
	}
	return p;

}

Object mainControlRule7(Object p, int size, vector<vector<string>> board, int lastXPos, int lastYPos, int range) {

	PlayerKey mainPlayer;
	PlayerKey secondPlayer;
	ControlGame controlGame;
	getKey(mainPlayer, secondPlayer, controlGame);

	int press = 0;
	while (press == 0)
	{
		press = 0;
		char key = _getch();

		if (mainPlayer.up == 'w')
		{
			mainPlayer.up = 72;
		}
		if (mainPlayer.left == 'a')
		{
			mainPlayer.left = 75;
		}
		if (mainPlayer.right == 'd')
		{
			mainPlayer.right = 77;
		}
		if (mainPlayer.down == 's')
		{
			mainPlayer.down = 80;
		}


		if (key == mainPlayer.left || key == mainPlayer.left + 32)
		{
			if (p.x == 2 || (p.x - 2) / 4 == lastXPos - range)
			{
				p.x = p.x;
			}
			else
			{
				p.x -= 4;
			}
		}
		if (key == mainPlayer.right || key == mainPlayer.right + 32)
		{
			if (p.x == size*4 - 2 || (p.x - 2) / 4 == lastXPos + range)
			{
				p.x = p.x;
			}
			else
			{
				p.x += 4;
			}
		}
		if (key == mainPlayer.up || key == mainPlayer.up + 32)
		{
			if (p.y == 1 || (p.y - 1) / 2 == lastYPos - range)
			{
				p.y = p.y;
			}
			else
			{
				p.y -= 2;
			}
		}
		if (key == mainPlayer.down || key == mainPlayer.down + 32)
		{
			if (p.y == size*2 - 1 || (p.y - 1) / 2 == lastYPos + range)
			{
				p.y = p.y;
			}
			else
			{
				p.y += 2;
			}
		}
		gotoXY(p.x, p.y);
		if (key == mainPlayer.attack || key == mainPlayer.attack + 32)
		{
			if (board[(p.x - 2) / 4][(p.y - 1) / 2] == "_" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "B")
			{
				cout << p.icon;
				press = 1;

			}
			else
			{
				press = 0;
			}

		}
		if (key == controlGame.save || key == controlGame.save + 32)
		{
			p.save = 1;
			break;
		}

		if (key == controlGame.undo || key == controlGame.undo + 32)
		{
			p.undo = 1;
			break;
		}
		if (key == controlGame.back || key == controlGame.back + 32)
		{
			p.quit = 1;
			break;
		}

	}
	return p;
}

Object secondControlRule7(Object p, int size, vector<vector<string>> board, int lastXPos, int lastYPos, int range) {

	PlayerKey mainPlayer;
	PlayerKey secondPlayer;
	ControlGame controlGame;
	getKey(mainPlayer, secondPlayer, controlGame);


	int press = 0;
	while (press == 0)
	{
		press = 0;
		char key = _getch();

		if (secondPlayer.up == 'w')
		{
			secondPlayer.up = 72;
		}
		if (secondPlayer.left == 'a')
		{
			secondPlayer.left = 75;
		}
		if (secondPlayer.right == 'd')
		{
			secondPlayer.right = 77;
		}
		if (secondPlayer.down == 's')
		{
			secondPlayer.down = 80;
		}



		if (key == secondPlayer.left || key == secondPlayer.left + 32)
		{
			if (p.x == 2 || (p.x - 2) / 4 == lastXPos - range)
			{
				p.x = p.x;
			}
			else
			{
				p.x -= 4;
			}
		}
		if (key == secondPlayer.right || key == secondPlayer.right + 32)
		{
			if (p.x == size*4 - 2 || (p.x - 2) / 4 == lastXPos + range)
			{
				p.x = p.x;
			}
			else
			{
				p.x += 4;
			}
		}
		if (key == secondPlayer.up || key == secondPlayer.up + 32)
		{
			if (p.y == 1 || (p.y - 1) / 2 == lastYPos - range)
			{
				p.y = p.y;
			}
			else
			{
				p.y -= 2;
			}
		}
		if (key == secondPlayer.down || key == secondPlayer.down + 32)
		{
			if (p.y == size*2 - 1 || (p.y - 1) / 2 == lastYPos + range)
			{
				p.y = p.y;
			}
			else
			{
				p.y += 2;
			}
		}
		gotoXY(p.x, p.y);
		if (key == secondPlayer.attack || key == secondPlayer.attack + 32)
		{
			if (board[(p.x - 2) / 4][(p.y - 1) / 2] == "_" || board[(p.x - 2) / 4][(p.y - 1) / 2] == "B")
			{
				cout << p.icon;
				press = 1;
			}
			else
			{
				press = 0;
			}
		}

		if (key == controlGame.save || key == controlGame.save + 32)
		{
			p.save = 1;
			break;
		}

		if (key == controlGame.undo || key == controlGame.undo + 32)
		{
			p.undo = 1;
			break;
		}
		if (key == controlGame.back || key == controlGame.back + 32)
		{
			p.quit = 1;
			break;
		}
	}
	return p;

}