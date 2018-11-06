#include "control.h"
Object pControl_char(Object p, int size, vector<vector<string>> Board) {

	ControlKey controlKey;

	int press = 0;
	while (press == 0)
	{
		press = 0;
		char key = _getch();
		if (key == 'A' || key == 'a')
		{
			if (p.x == 0) 
			{
				p.x = p.x;
			}
			else
			{
				p.x -= 2;
			}
		}
		if (key == 'D' || key == 'd')
		{
			if (p.x / 2 == size-1)
			{
				p.x = p.x;
			}
			else
			{
				p.x += 2;
			}
		}
		if (key == 'W' || key == 'w')
		{
			if (p.y == 0)
			{
				p.y = p.y;
			}
			else
			{
				p.y -= 1;
			}
		}
		if (key == 'S' || key == 's')
		{
			if (p.y == size - 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y += 1;
			}
		}
		gotoXY(p.x, p.y);
		if (key == 'H' || key == 'h')
		{
			if (Board[p.x/2][p.y] == "_")
			{
				cout << p.icon;
				press = 1;

			}
			else
			{
				press = 0;
			}

		}
		if (key == controlKey.save || key == controlKey.save + 32)
		{
			p.save = 1;
			break;
		}

		if (key == controlKey.undo || key == controlKey.undo + 32)
		{
			p.undo = 1;
			break;
		}
		if (key == controlKey.back || key == controlKey.back + 32)
		{
			p.quit = 1;
			break;
		}


	}
	return p;
}
Object pControl_num(Object p, int size, vector<vector<string>> Board) {

	ControlKey controlKey;

	int press = 0;
	while (press == 0)
	{
		press = 0;
		char key = _getch();
		if (key == 75)
		{
			if (p.x == 0)
			{
				p.x = p.x;
			}
			else
			{
				p.x -= 2;
			}
		}
		if (key == 77)
		{
			if (p.x / 2 == size - 1)
			{
				p.x = p.x;
			}
			else
			{
				p.x += 2;
			}
		}
		if (key == 72)
		{
			if (p.y == 0)
			{
				p.y = p.y;
			}
			else
			{
				p.y -= 1;
			}
		}
		if (key == 80)
		{
			if (p.y == size - 1)
			{
				p.y = p.y;
			}
			else
			{
				p.y += 1;
			}
		}
		gotoXY(p.x, p.y);
		if (key == '1' || key == '1')
		{
			if (Board[p.x / 2][p.y] == "_")
			{
				cout << p.icon;
				press = 1;
			}
			else
			{
				press = 0;
			}
		}

		if (key == controlKey.save || key == controlKey.save + 32)
		{
			p.save = 1;
			break;
		}

		if (key == controlKey.undo || key == controlKey.undo + 32)
		{
			p.undo = 1;
			break;
		}
		if (key == controlKey.back || key == controlKey.back + 32)
		{
			p.quit = 1;
			break;
		}
	}
	return p;

	
}