#ifndef INGAME_H_INCLUDED
#define INGAME_H_INCLUDED


# include <string.h>
# include "hero.h"
# include "loadedPictures.h"
# include "bandit.h"
# include "julien.h"
# include "firen.h"
# include "allScore.h"


void gameFinished();
void StageChangeLogic();
void nextStage();
void levelSelect();
void level_1_move();
void level_2_move();
void level_3_move();
void level_move_function();
void gameStart();
void gameOver();
void gameFinished();
	




int level = 1;                   //variable to go from one level to another  

int level_1_land_x = 0 ;         //variables to control level 1 background
int mountain1_x = 0 ;
int mountain2_x = 0 ;

int cliff_x = 0 ;                //variables to control level 2 background
int level_2_land_x = 0; 

int volcano_x = 0;               //variables to control level 3 background
int level_3_land_x = 0 ;

int dead_bandit=0;               //dead bandit conuting variable which is required to go to next stage

int level_2_bandit_dead = 0 ;    //to know if all the bandits in level 2 or 3 are dead in order to call firen or julien
int level_3_bandit_dead = 0 ;

/*
the levelSelect() function is used to determine which stage backgroung will now play
depending on the variable "level"
after level 1 & 2 the variables will re-initialize using the StageChangeLogic() function
which sets all the values to their initial state
after finishing level 3 the game finish window will come through mode =8..
if player dies in any stage ..game over will occur and take the player to the game over window

*/


void levelSelect()
{
	iSetColor(50,77,154);                      //the road of each stage takes 256 pixel... the background also takes 256 pixel           
	iFilledRectangle(0,0,800,600);             //the blue portion on the uper part of the screen takes 88 pixel .... so 256+256+88 =600                     
	


	if(level ==1)
	{

		for(int i = -1 ; i <=1 ; i++ )               //total number of mountains called and printed is controlled through this loop
		{
			iShowBMPAlternativeSkipBlack(mountain1_x + ( 1024 * i ) , 384 , "Background\\Forest\\Mountain.bmp");

			iShowBMPAlternativeSkipBlack(mountain2_x + ( 1024 * i ) , 320 , "Background\\Forest\\Mountain2.bmp");

		}


		for(int i = -1 ; i <= 2 ; i++)              //total number of forests called and printed is controlled through this loop
		{
			iShowBMPAlternativeSkipBlack(level_1_land_x + ( 1024 * i ) , 0 ,"Background\\Forest\\level_1_land.bmp");
		}

		
		StageChangeLogic();

           
			
	}

	if(level==2)
	{
		

		iShowBMPAlternativeSkipBlack(cliff_x - 800 , 256 , "Background\\Mountain\\cliff.bmp");

		for(int i = -1 ; i <=2 ; i++ )            //total number of mountains called and printed is controlled through this loop
		{
			iShowBMPAlternativeSkipBlack( level_2_land_x + ( 1024 * i ) , 0 , "Background\\Mountain\\level_2_land.bmp");

		}

		
		dead_bandit = 0 ;

		for(int i =0 ;i < bandit_counter ; i++)
		{
			if(band[i].dead == 1)
				dead_bandit++;
		}

		if(dead_bandit==20)
			level_2_bandit_dead=1;


		StageChangeLogic();

	
		
	}



	if(level ==3)
	{

			
	

		iShowBMPAlternativeSkipBlack( volcano_x - 800 , 256 , "Background\\Volcano\\volcano.bmp");


		for(int i = -1 ; i <=2 ; i++ )
		{
			iShowBMPAlternativeSkipBlack( level_3_land_x + ( 1024 * i ) , 0 , "Background\\Volcano\\level_3_land.bmp");

		}

		dead_bandit = 0 ;

		for(int i =0 ;i < bandit_counter ; i++)
		{
			if(band[i].dead == 1)
				dead_bandit++;
		}

		if(dead_bandit==20)
			level_3_bandit_dead=1;

		StageChangeLogic();


	}


}


/*

this function will be called after killing 20 bandits in
either level 1 or level 2....this will prompt to activate mode = 9
thus activating the NEXT STAGE window

in level 3 ..if all the bandits are dead...this will activate mode = 8
thus activating the game finished window
*/


void StageChangeLogic()
{
	if(level==1)
	{
		
		dead_bandit = 0 ;

		for(int i =0 ;i < bandit_counter ; i++)
		{
			if(band[i].dead == 1)
				dead_bandit++;
		}

		if(dead_bandit==20)
			mode = 9;

	}

	else if(level==2)
	{
		if(firen_dead==1)
			mode = 9;
	}

	else if(level==3)
	{
		if(julien_dead==1)
		{
			PlaySound("music//gamefinished", NULL, SND_ASYNC);
			mode=8;
		}
	}

	
}


/*
this will activate when mode =9
this function will prompt to save the game or move on to the next stage
the input logic can be found in the iKeyboard function...
also ..if pressed ENTER  on this window...all the values except score will re-initialize for the next level..
so it also works as a initializer for each level
only the picture for next stage window is shown here

*/
void nextStage()
{
	iClear();

	iShowBMP(0 , 0 ,"NextStage\\1.bmp");

}




/*
this function holds all the logic to change the values for level=1 backgroung
rendaring according to the movement of the hero 

*/

void level_1_move()
{
	if(hero_dir == 1)
	{

		level_1_land_x = level_1_land_x + 15 ;

		mountain1_x = mountain1_x + 2 ;

		mountain2_x = mountain2_x + 4 ;


	}

	if(hero_dir == 2)
	{

		level_1_land_x = level_1_land_x - 15 ;

		mountain1_x = mountain1_x - 2 ;

		mountain2_x = mountain2_x - 4 ;
	}


}

/*
this function holds all the logic to change the values for level=2 backgroung
rendaring according to the movement of the hero 

*/


void level_2_move()
{
	if(hero_dir == 1)
	{
		cliff_x = cliff_x + 1 ;

		level_2_land_x = level_2_land_x + 15;

	}

	if(hero_dir == 2)
	{
		cliff_x = cliff_x - 1 ;

		level_2_land_x = level_2_land_x - 15;

	}

}

/*
this function holds all the logic to change the values for level=3 backgroung
rendaring according to the movement of the hero 

*/

void level_3_move()
{

	if(hero_dir == 1)
	{
		volcano_x = volcano_x + 1; 
		level_3_land_x = level_3_land_x + 15 ;

	}

	if(hero_dir == 2)
	{
		volcano_x = volcano_x - 1; 
		level_3_land_x = level_3_land_x - 15 ;

	}
}

/*
this function determines which level is to be moved 
having the value for the "level" variable
also it doesn't allow the background to move when the hero is inn jump state(hero_state = 5)

*/

void level_move_function()
{
	if(level==1 && mode==2  && hero_state !=5 )
			{
		
				level_1_move();
			}

	if(level==2 && mode==2  && hero_state !=5 )
			{
		
				level_2_move();
			}

	if(level==3 && mode==2  && hero_state !=5 )
			{
		
				level_3_move();
			}
}


/*
gameStart() function holds all the functions that needs to be worked together to 
run the the...for example...we need level....on screen score....hero..enemy...boss...
so all the functions controllinf these elements are called in this one function...
gameStart() function is then called in IDraw() to render

*/

void gameStart()
{
	
	levelSelect();

	onScreen_score_and_name();


	hero();


	bandit();

	if(level==2 && level_2_bandit_dead==1)   //firen will come if all the bandit in level 2 are dead
		firen();
	
	if(level==3 && level_3_bandit_dead==1)   //julien will come if all the bandit in level 2 are dead
		julien();

	

	//iShowBMPAlternativeSkipBlack(100,100,Julien_stand_mirror[0]);
	
}


/*
gameover() function will activate through mode = 7 when the hero lif is <=0 
this function only shows the picture..but the input given here can be found in the 
iKeyborad function which will only work while in mode = 7 (game over state)
pressing enter will take the player to mode =1(main menu)
and re-initialize all the values to start a new game later

*/
void gameOver()

{
	
	iShowBMP(0,0,"GameOver\\1.bmp");

}

/*
gameFinished() function will activate through mode = 8 when 20 bandits(for now) are
dead in level=3...
this function only shows the picture..but the input given here can be found in the 
iKeyborad function which will only work while in mode = 8 (game finish state)

pressing enter will take the player to mode =1(main menu)
and re-initialize all the values to start a new game later
*/

void gameFinished()
{
	iShowBMP(0,0,"Game finished\\1.bmp");
}

#endif // INGAME_H_INCLUDED
