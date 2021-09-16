

# include <string.h>
# include "iGraphics.h"
# include "bitmap_loader.h"
# include "menu.h"
# include "inGame.h"
# include "hero.h"
# include "loadedPictures.h"
# include "bandit.h"
# include "allScore.h"
# include "julien.h"
# include "firen.h"

int mposx,  mposy;  // this variables are used to hold the mouse pointer location in iPassiveMouse function

//mode descripption
//1 = menu
//2 = Ingame 
//3 = loadGame
//4 = instruction
//5 = highscore
//6 = heroSelection
//7 = gameover
//8 = gameFinished
//9 = nextStage window
//10 = save game window
//11 = enter name window
//12 = intro screen


/*
this function is called when mode=1 .this holds the interface for the menu..clicking inside a parameter 
will cause the mode to change according to the players desire
*/

void menu_interface()
{
	iShowBMP(0,0,"menu images\\menu items\\menu background.bmp");

	//iSetColor(255,0,0);
	//iFilledRectangle(300,295,180,30);
	if(mposx >= 300 && mposx <= 480 && mposy >= 295 && mposy <= 325)
		iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\start game selected.bmp");
	else
	iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\start game.bmp");

	//iSetColor(255,0,0);
	//iFilledRectangle(300,245,180,30);
	if(mposx >= 300 && mposx <= 480 && mposy >= 245 && mposy <= 275)
		iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\load game selected.bmp");
	else
	iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\load game.bmp");

	//iSetColor(255,0,0);
	//iFilledRectangle(290,195,205,30);	
	if(mposx >= 290 && mposx <= 495 && mposy >= 195 && mposy <= 225)
		iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\instructions selected.bmp");
	else
	iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\instructions.bmp");

	//iSetColor(255,0,0);
	//iFilledRectangle(300,145,180,30);
	if(mposx >= 300 && mposx <= 480 && mposy >= 145 && mposy <= 175)
		iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\high score selected.bmp");
	else
	iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\high score.bmp");

	//iSetColor(255,0,0);
	//iFilledRectangle(350,105,70,30);
	if(mposx >= 350 && mposx <= 420 && mposy >= 105 && mposy <= 135)
		iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\exit selected.bmp");
	else
	iShowBMPAlternativeSkipBlack(0,0,"menu images\\menu items\\exit.bmp");

	
}

/*
this function is called when mode = 6 ...allows the player to click a picture to select the hero to his or er desire
*/


void hero_selection()
{
	if(mposx >= 0 && mposx <= 400 && mposy >= 175 && mposy <= 425 && mode==6)

		iShowBMP(0,0,"menu images\\hero_selection\\firzen_on.bmp");

	else if(mposx >= 400 && mposx <= 800 && mposy >= 175 && mposy <= 425 && mode==6)

		iShowBMP(0,0,"menu images\\hero_selection\\bat_on.bmp");

	else 
		iShowBMP(0,0,"menu images\\hero_selection\\hero_selection.bmp");

	iSetColor(255,255,255);
	iLine(0,175,800,175);
	iLine(0,425,800,425);
	iLine(400,175,400,425);

}



void iDraw()
{
	
	iClear();
	
	//different modes are used for different parts of the game
	if(mode==1)
		menu_interface();

	else if(mode == 2)
		gameStart();

	else if(mode == 3)
		loadGame();

	else if(mode == 4)
		instructions();

	else if(mode == 5)
		highScore();

	else if(mode == 6)
		hero_selection();

	else if(mode == 7)
		gameOver();

	else if(mode == 8)
		gameFinished();

	else if(mode == 9)
		nextStage();

	else if(mode == 10)
		saveGame();

	else if(mode == 11)
		takePlayerName();

	else if(mode == 12)
		intro();
		

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

	//used to control main menu through mouse and control modes

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx >= 300 && mx <= 480 && my >= 295 && my <= 325 && mode == 1)
		{
			PlaySound("music//click", NULL, SND_ASYNC);
			mode = 11; //start game 300,295,180,30
		}

		if(mx >= 300 && mx <= 480 && my >= 245 && my <= 275 && mode == 1)
		{
			PlaySound("music//click", NULL, SND_ASYNC);
			mode = 3; //load game 300,245,180,30
		}

		if(mx >= 290 && mx <= 495 && my >= 195 && my <= 225 && mode == 1)
		{
			PlaySound("music//click", NULL, SND_ASYNC);
			mode = 4; //instruction  290,195,205,30
		}

		if(mx >= 300 && mx <= 480 && my >= 145 && my <= 175 && mode == 1)
		{
			PlaySound("music//click", NULL, SND_ASYNC);
			mode = 5; //highscore 300,145,180,30
		}

		if(mx >= 350 && mx <= 420 && my >= 105 && my <= 135 && mode == 1)
		{
			PlaySound("music//click", NULL, SND_ASYNC);
			exit(0); //end game 350,105,70,30
		}

		if(mx >= 0 && mx <= 400 && my >= 175 && my <= 425 && mode==6)  //eita hero selection screen er jonno
		{
			PlaySound("music//click", NULL, SND_ASYNC);
			hero_selector = 1;
			hero_selector_func();
			mode = 2;
		}

		if(mx >= 400 && mx <= 800 && my >= 175 && my <= 425 && mode==6)  //eita hero selection screen er jonno
		{
			PlaySound("music//click", NULL, SND_ASYNC);
			hero_selector = 2;
			hero_selector_func();
			mode = 2;
		}
			
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;


// if(mx== 2){}        /*Something to do with mx*/
 //else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{

	if(key == 'q' )
	{
		score++;
		
	}

	//used for going to the main menu



	if(key == 27 && (mode ==4 || mode == 5 || mode== 3 || mode == 12) )
	{
		PlaySound("music//enter", NULL, SND_ASYNC);
		mode = 1;
		PlaySound("music//intro", NULL, SND_LOOP | SND_ASYNC);
	}

	if(key == 27 && (mode ==10) )
	{
		PlaySound("music//enter", NULL, SND_ASYNC);
		mode = 9;
	}

	if(key == 'l')
	{
		level ++;
		if(level==4)
			level=1;
	}

	if(key == 'a' && hero_state != 5 && hero_state != 4 && mode ==2)
	{
		hero_state = 2;
		PlaySound("music//punch", NULL, SND_ASYNC);

	}

	if(key == 's' && hero_state != 5 && hero_state != 4 && mode ==2)
	{
		hero_state = 3;
		PlaySound("music//kick", NULL, SND_ASYNC);

	}

	if(key == 'd' && hero_state != 5 && hero_state != 4 && mode ==2 && laser_on == 0)
	{

		if(hero_mana >= 40)
		{
			temp_dir = hero_dir;
			hero_mana = hero_mana - 40;
			hero_state = 4;
		}
		PlaySound("music//power", NULL, SND_ASYNC);
		
	}

	if(key == 'w' && hero_state != 4 && mode ==2)
	{
		
		hero_state = 5;
		PlaySound("music//jump", NULL, SND_ASYNC);

	}

	if(mode == 3)
	{
		if(key == '\r' && move_save == 1)
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			loadFromFile();
			hero_selector_func();
			level = temp_level;
			mode=2;

		}

		if(key == '\r' && move_save == 2)
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			loadFromFile();
			hero_selector_func();
			level = temp_level;
			mode=2;
		}


		if(key == '\r' && move_save == 3)
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			loadFromFile();
			hero_selector_func();
			level = temp_level;
			mode=2;
		}

	}



	if(key == '\r' && mode == 7)              //here all the values are given there initial values after the game over
	{
		PlaySound("music//intro", NULL, SND_ASYNC);
		mode = 1 ;

		strcpy(ssf[10].playerName,name );
		ssf[10].playerScore = score;

		for(int i = 0 ; i < nameL ; i++)
				name[i] = 0;

		score=0;
		nameL=0;
	
		

		level = 1;                     
		level_1_land_x = 0 ;         
		mountain1_x = 0 ;
		mountain2_x = 0 ;
		cliff_x = 0 ;                
		level_2_land_x = 0; 
		volcano_x = 0;               
		level_3_land_x = 0 ;

		dead_bandit=0;               
		level_2_bandit_dead = 0 ;    
		level_3_bandit_dead = 0 ;

		bandit_initialize();
		julien_initialize();
		julien_skull_initialize();
		firen_initialize();
		firen_arrow_initialize();

		hero_initialize();

		hero_laser_initialize();

		


		saveScore();
		
	}

	if(key == '\r' && mode == 8)              //here all the values are given there initial values after the game finished
	{
		PlaySound("music//intro", NULL, SND_ASYNC);
		mode = 1 ;

		strcpy(ssf[10].playerName,name );
		ssf[10].playerScore = score;

		for(int i = 0 ; i < nameL ; i++)
				name[i] = 0;

		score=0;
		nameL=0;
	
		

		level = 1;                     
		level_1_land_x = 0 ;         
		mountain1_x = 0 ;
		mountain2_x = 0 ;
		cliff_x = 0 ;                
		level_2_land_x = 0; 
		volcano_x = 0;               
		level_3_land_x = 0 ;

		dead_bandit=0;               
		level_2_bandit_dead = 0 ;    
		level_3_bandit_dead = 0 ;

		bandit_initialize();
		julien_initialize();
		julien_skull_initialize();
		firen_initialize();
		firen_arrow_initialize();

		hero_initialize();

		hero_laser_initialize();

		


		saveScore();
		
	}

	if(key == 's' && mode == 9)
	{
		PlaySound("music//enter", NULL, SND_ASYNC);
		mode = 10;
	}


	if(key == '\r' && mode == 9)
	{
		
		if(level==1 || level==2)
			{


				PlaySound("music//levelup", NULL, SND_ASYNC);
				level++;

				mode=2;

				dead_bandit=0;               
				level_2_bandit_dead = 0 ;    
				level_3_bandit_dead = 0 ;

				bandit_initialize();
				julien_initialize();
				julien_skull_initialize();
				firen_initialize();
				firen_arrow_initialize();


				hero_initialize();
				hero_laser_initialize();

				

			}
		
	}

	if(mode == 10)
	{
		if(key == '\r' && move_save == 1)
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			temp_level = level + 1;
			saveInFile();
			mode = 9;
		}

		if(key == '\r' && move_save == 2)
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			temp_level = level + 1;
			saveInFile();
			mode = 9;
		}


		if(key == '\r' && move_save == 3)
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			temp_level = level + 1;
			saveInFile();
			mode = 9;
		}

	}

	

	if(mode == 11)                           //this is the condition for taking in player name which is stored in "name" and later
	{                                        //shown in the player name taking menu and later in the game
		  
		if(key == '\r')
		{
			PlaySound("music//enter", NULL, SND_ASYNC);
			mode=6;

		}

		else if(key == '\b')
		{
			
			if(nameL>0)
			{
				PlaySound("music//backspace", NULL, SND_ASYNC);
				nameL--;
				name[nameL] = '\0';               
			}
			if(nameL == 0)
				PlaySound("music//error", NULL, SND_ASYNC);
		}

		else 
		{
			PlaySound("music//button", NULL, SND_ASYNC);
			name[nameL] = key;           
			nameL++;
		}

	}

	if(key  == ' ' &&  mode==12)
	{
		intro_page++;
		if(intro_page==4)
			{
				mode = 1;
				intro_page = 1;
			}
	}


	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	
	

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	if(key == GLUT_KEY_UP && mode ==2  && hero_state != 5 && hero_state != 4)
	{
		
		if(hero_walk_y >=250)
			hero_walk_y = hero_walk_y;

		else
			hero_walk_y = hero_walk_y + hero_dy ;     //border logic

		
		hero_state=1;
		
	}

	if(key == GLUT_KEY_DOWN && mode ==2 && hero_state != 5 && hero_state != 4)
	{
		
		if(hero_walk_y <= 10)
			hero_walk_y = hero_walk_y;
		else
			hero_walk_y = hero_walk_y - hero_dy ;      //border logic

		
		hero_state=1;
		
	}
	


	if(key == GLUT_KEY_RIGHT && mode ==2 && hero_state != 4)
	{

		hero_dir = 2;

		if(hero_walk_x < 750)
		{	                 //border logic
	
			hero_walk_x = hero_walk_x + hero_dx ;

			level_move_function();
		
			
			if(hero_state !=5) //jump er moddhe direction change korar jonno
				hero_state=1;

		}

		
		
	}

	if(key == GLUT_KEY_LEFT && mode==2 && hero_state != 4)
	{
		
		hero_dir = 1;

		if(hero_walk_x > -10)
		{
			hero_walk_x = hero_walk_x - hero_dx ;    //border logic

			level_move_function();
		
			if(hero_state !=5)  //jump er moddhe direction change korar jonno
				hero_state=1;


		}

		
		
	}

	if(key == GLUT_KEY_UP && (mode ==10 || mode == 3) )
	{
		PlaySound("music//toggle", NULL, SND_ASYNC);
		move_save--;
		if(move_save < 1)
			move_save=3;
	}

	if(key == GLUT_KEY_DOWN && (mode ==10 || mode == 3) )
	{
		PlaySound("music//toggle", NULL, SND_ASYNC);
		move_save++;
		if(move_save > 3)
			move_save = 1;
	}


	//place your codes for other keys here
}

/*
 hero_change() is called through iSetTimer() to
monitor any change in hero movement throughout the game

*/

void hero_change()
{
	hero_laser();

	if(mode == 2 && hero_state == 1)
		hero_walk();

	if(mode == 2 && hero_state == 2)
		hero_punch();

	if(mode == 2 && hero_state == 3)
		hero_kick();

	if(mode == 2 && hero_state == 4)
		hero_power();

	if(mode == 2 && hero_state == 5)
		hero_jump();

}

/*

julien_change() is called through iSetTimer() to
monitor any change in bandit movement throughout the game

*/

void julien_change()
{

	if(level==3 && level_3_bandit_dead==1)
	{
		julien_skull();


		if (mode == 2  && hero_state != 5 && ( julien_state == 1 || julien_state == 2) )
			julien_walk_and_punch();

		if(mode == 2  && hero_state != 5 && julien_state == 3 ){
			julien_power();
			PlaySound("music//laugh", NULL, SND_ASYNC);}
			
	}

}

/*

firen_change() is called through iSetTimer() to
monitor any change in bandit movement throughout the game

*/

void firen_change()
{

	if(level==2 && level_2_bandit_dead==1)
	{
		firen_arrow();


		if (mode == 2  && hero_state != 5 && ( firen_state == 1 || firen_state == 2) )
			firen_walk_and_punch();

		if(mode == 2  && hero_state != 5 && firen_state == 3 ){
			firen_power();
			PlaySound("music//laser", NULL, SND_ASYNC);}
	}

}

/*

bandit_change() is called through iSetTimer() to
monitor any change in bandit movement throughout the game

*/

void bandit_change()
{
	if (mode == 2  && hero_state != 5)
		bandit_walk_and_punch();
}

/*

bandit_coming() is called through iSetTimer and is used to control the number 
of bandits that will enter the screen at a given time

*/

void bandit_coming()
{
	if(mode == 2)
		if(bandit_counter < 20)
			{
				bandit_counter++;
				band[bandit_counter].active =  1;
			}

}


/*
this function determines after how much time julien will through power with the help of iSetTimer()
*/

void julien_throws_power()
{
	if(julien_power_on == 0 && julien_dead ==0)
		julien_state=3;
}

/*
this function determines after how much time firen will through power with the help of iSetTimer()
*/

void firen_throws_power()
{
	if(firen_power_on == 0 && firen_dead ==0)
		firen_state=3;
}

/*
this function is use to put all character changing function in under one function and then call that function in a iSetTimer
*/
void character_change()
{

	bandit_change();
	julien_change();
	firen_change();
	hero_change();
}

/*
this function is used to put the enemy laser throw timer functions under one function and then call them under a iSetTimer
*/

void boss_power()
{
	julien_throws_power();
	firen_throws_power();
}




int main()
{
	//place your own initialization codes here.


	/*
	bandit_initialize() and hero_laser_initialize() are used to initialize the variables to control 
	hero laser and the bandits
	
	*/


	bandit_initialize();
	hero_laser_initialize();
	julien_skull_initialize();
	firen_arrow_initialize();
	
	PlaySound("music//intro", NULL, SND_LOOP | SND_ASYNC);

	iSetTimer(90 , character_change);

	iSetTimer(1000,bandit_coming);

	iSetTimer(500 , boss_power);



	

	

	iInitialize(800, 600, "Batlle For The World");
	return 0;
}
