#ifndef JULIEN_H_INCLUDED
#define JULIEN_H_INCLUDED

# include "hero.h"
# include <string.h>
# include "loadedPictures.h"
# include "allScore.h"

//state description
//0 = stand 
//1 = walk
//2 = punch
//3 = power

void julien_initialize();
void julien_skull_initialize();
void julien_walk_and_punch();
void julien_walk_and_punch_render();
void julien_power();
void julien_power_render();
void julien_skull();
void julien_skull_render();
void hero_julien_collision();
void julien();


/*
the julien_skull structure is used to hold values for each of julien skull.
it holds the charactaristics for each of the skull.
for example the skull location , index and if the arow is active
*/

struct julien_skull
{
	int x;
	int y;
	int index;
	int active;


}skull[15];

int julien_x = 1000;             //juliens initial standing location is initialized at first
int julien_y = 128;

int julien_dx = 5;               // the value at which julien will move in the  X-axis or the Y-axis
int julien_dy = 4;

int julien_walk_index = 0;       // the index value for each of juliens actions
int julien_punch_index = 0;
int julien_power_index= 0;


int julien_life = 700;           //the variable holds life for julien
int julien_dead = 0;             //variable that holds if firen is dead or not .. 0 is not dead .. 1 is dead
int julien_dir = 0;              //variable holds the direction julien faces ..1 is left...2 is right

int julien_state = 1;            // this corresponds to the state julien is in


int julien_power_timer = 0;     //variable that decides the amount of time julien will be in the power mode

int julien_power_on = 0;        //variable that decides if the power of julien is on or not

/*
julien_initialize() function initializes the julien character with it's initial values that are required 
to move the character
*/

void julien_initialize()
{
	julien_x = 1000;
	julien_y = 128;

	julien_walk_index = 0;
	julien_punch_index = 0;
	julien_power_index= 0;


	julien_life = 200;
	julien_dead = 0;
	julien_dir = 0;

	julien_state = 1;


	julien_power_timer = 0;
	julien_power_on = 0;


}

/*
julien_arrow_initialize() function initizes the skulls outside the screen .
This is called after each power call from the julien character
*/

void julien_skull_initialize()
{
	for(int i = 0 ; i < 15 ; i++)
	{
		skull[i].x = rand() % 300 + 850 ;
		skull[i].y = rand() % 200;
		skull[i].active = 1;
		skull[i].index = 0;
		

	
	}
}

/*
This function is used to change the values that is required for julien to walk ..
julien follows the hero whereever the hero goes...this logic can be found here..

*/

void julien_walk_and_punch()
{

	if(julien_life <=0)                 //this logic is for if the health of julien is null julien will be declared as dead through julien_dead = 1
		{
			julien_dead = 1;
			

			julien_x = 1000 ;
			julien_y = 1000 ;
		}



	if(julien_x <= hero_walk_x + 35 && julien_x >= hero_walk_x - 35  && julien_y >= hero_walk_y && julien_y <= hero_walk_y + 5 && hero_state != 2 && hero_state != 3 && julien_dead == 0)  //punch logic
	{

			julien_state = 2;                                        //this is the punch logic...when julien comes near the hero the julien_state will change to 2 that is the punching mode..also causing the hero to loose life
			                                                         //punch will not happen if the hero is punching or kicking or julien is dead
			julien_punch_index++ ;

			if(julien_punch_index >= 3)
				julien_punch_index = 0 ;
			
			if(hero_life > 0)
				hero_life--; 

			if(hero_life <= 0)  
			{
				PlaySound("music//gameover", NULL, SND_ASYNC);
				mode = 7;												//if hero has no life then game over mode will occure that is mode = 7
			}
	}



	else if(julien_dead == 0)              //walk logic for firen ...if firen is not dead...he will go to the crrent value of the hero ..also change direction according to his movement

	{
		julien_state = 1; 
		julien_walk_index++;

		if(julien_walk_index >= 3)
			julien_walk_index=0;



		if(julien_x > hero_walk_x)
		{
			julien_dir = 1;
			julien_x = julien_x - julien_dx;  
		}



		if(julien_x < hero_walk_x)
		{
			julien_dir = 2;
			julien_x = julien_x + julien_dx;
		}



		if(julien_y > hero_walk_y)
		{
	
			julien_y = julien_y - julien_dy; 
		}



		if(julien_y < hero_walk_y)
		{	

			julien_y = julien_y + julien_dy;
		}


	}



}

/*
this function is used to render the walk and punch movements of julien
*/

void julien_walk_and_punch_render()
{

	if( julien_dir == 2 && julien_state == 1 && julien_dead == 0 )
			iShowBMPAlternativeSkipBlack( julien_x , julien_y , Julien_walk[julien_walk_index]);

	if( julien_dir == 1 && julien_state == 1 && julien_dead == 0 )
			iShowBMPAlternativeSkipBlack( julien_x , julien_y , Julien_walk_mirror[julien_walk_index]);

	if( julien_dir == 2 && julien_state == 2 && julien_dead == 0 )
			iShowBMPAlternativeSkipBlack( julien_x , julien_y , Julien_punch[julien_punch_index]);

	if( julien_dir == 1 && julien_state == 2 && julien_dead == 0  )
			iShowBMPAlternativeSkipBlack( julien_x , julien_y , Julien_punch_mirror[julien_punch_index]);
}

/*
julien_power() function changes all the values that is required for julien to go in power mode and show it
*/

void julien_power()
{
	julien_power_index++;

	julien_power_timer++;

	if(julien_power_timer == 9)
		{
			julien_power_on = 1 ;

			julien_power_index =  0;
			julien_power_timer = 0;
			julien_state = 1;
		}

	

}

/*
julien_power_render() function renders the julien power mode pictures
*/

void julien_power_render()
{
	if(julien_power_index<3)
		iShowBMPAlternativeSkipBlack( julien_x , julien_y , Julien_power[julien_power_index] );
	else
		iShowBMPAlternativeSkipBlack( julien_x - 32 , julien_y , Julien_power[julien_power_index] );
}

/*
julien_skull() function will onlt work if the the julien_power_on value is not 0...
at that moment all the skulls will start to come from the right ..after a certain time the power will be turned of through 
the julien_power_on variable
*/

void julien_skull()
{
	if(julien_power_on != 0 )
	{
		julien_power_on++;

		for(int i = 0 ; i <15 ; i++)
		{
			skull[i].x = skull[i].x - 20;
		}
	}


	if(julien_power_on>63)
	{
		            
		//void julien_skull_initializer()

		for(int i = 0 ; i < 15 ; i++)
		{
			skull[i].x = rand() % 300 + 850 ;
			skull[i].y = rand() % 200;
			skull[i].index = 0;
			skull[i].active = 1;

			
		
		}

		julien_power_on = 0;
	}
}

/*
julien_skull_render() function is used to render the the skulls...it is always rendering outside the screen...
and renders inside the screen when it is called
*/

void julien_skull_render()
{
	for(int i = 0 ; i< 15; i++)
	{
		if(skull[i].active == 1)
			iShowBMPAlternativeSkipBlack( skull[i].x , skull[i].y , Julien_skull[skull[i].index]);
	}
}

/*
this function holds the logic for hero and julien collision..
if the hero is near julien then julien will go to punching mode that is julien_state=2 and hero life will decrease
*/


void hero_julien_collision()
{

	/*
	This if condition holds the logic for juliens skull and the heroes collision that will cause the hero to loose life
	*/
	
	if(julien_power_on !=0 )
	{
		for(int i = 0 ; i< 15; i++)
		{

			if( skull[i].x >= hero_walk_x && skull[i].x <= hero_walk_x + 64 && skull[i].y >= hero_walk_y - 20 && skull[i].y <= hero_walk_y + 40 && skull[i].active == 1)     //skull[i].active == 1)
			{

				hero_life = hero_life - 10;
				skull[i].active = 0 ;

				if(hero_life <= 0)
				{
					PlaySound("music//gameover", NULL, SND_ASYNC);
					mode = 7;
				}
			}
		}

	}


	/*
	This if condition holds the logic for hero's laser and JULIENS collision...this will cause julien to loose health
	*/



	if(laser_on != 0)                                 //laser and julien collision logic , when true, decreases juliens health 
		{
		
			for(int i = 0 ; i <=15 ; i++ )

				
				{
					if(laser_loc[i].x + 100 >= julien_x &&  laser_loc[i].x +100 <= julien_x + 64 &&  laser_loc[i].y >= julien_y - 20 &&  laser_loc[i].y <= julien_y + 40 && laser_loc[i].active ==1 && temp_dir == 2 )
					{
						julien_life = julien_life - 10 ;                                          //right side facing lasercollision
						score = score + 100 ;
						laser_loc[i].active = 0;
					
						
					}

					if(laser_loc[i].x - 150 >= julien_x  &&  laser_loc[i].x - 150 <= julien_x + 64 &&  laser_loc[i].y >= julien_y - 20 &&  laser_loc[i].y <= julien_y + 40 && laser_loc[i].active ==1  && temp_dir ==1 )
					{
						julien_life = julien_life - 10 ;                                          //left side facing laser collision
						score = score + 100 ;
						laser_loc[i].active = 0;
					}

				}

		}


	/*
	this if contains the logic for collision between the hero's laser and julien's skull
	*/

	if(julien_power_on !=0 &&  laser_on != 0)
	{
		for(int i = 0 ; i <= 15 ; i++)
			for(int j = 0 ; j <= 15 ; j++)
			{
				if(laser_loc[i].x + 100 >= skull[j].x  && laser_loc[i].x + 100 <= skull[j].x + 64 && laser_loc[i].y >= skull[j].y - 15 && laser_loc[i].y <= skull[j].y + 15 && laser_loc[i].active ==1 && skull[j].active == 1)
				{
					laser_loc[i].active = 0;
					skull[j].active = 0 ;
				}
			}

	}




	/*
	this is the logic while hero punches julien..will cause julien to loose life...but it will be very low
	*/

	
	if(hero_dir == 2) //when the hero is facing right
		{

				if(julien_x <= hero_walk_x + 35 && julien_x >= hero_walk_x  && julien_y >= hero_walk_y && julien_y <= hero_walk_y + 5 && ( hero_state == 2 || hero_state == 3) && julien_dead == 0)
					{
						julien_life = julien_life - 1 ; 
						score = score + 100 ;
					}
		}


	if(hero_dir == 1) //when the hero is facing left
		{

				if(julien_x <= hero_walk_x && julien_x >= hero_walk_x -35 && julien_y >= hero_walk_y && julien_y <= hero_walk_y + 5 && ( hero_state == 2 || hero_state == 3) && julien_dead == 0)
					{
						julien_life = julien_life - 1 ; 
						score = score + 100 ;
					}
		}
}

/*
this function holds all function that is required to render depending on each julien_state
but collision will always render as it can happen anytime..same goes for skulls
*/

void julien()
{

	hero_julien_collision();

	julien_skull_render();

	if(hero_state == 5)
	{
		
		if(julien_dir == 2)
			iShowBMPAlternativeSkipBlack( julien_x , julien_y ,  Julien_stand[0] );

		else if(julien_dir == 1)         
			iShowBMPAlternativeSkipBlack( julien_x , julien_y ,  Julien_stand_mirror[0] );
		
	}

	else if(julien_state==3)
		julien_power_render();

	else

	julien_walk_and_punch_render();

	
}


#endif // JULIEN_H_INCLUDED
