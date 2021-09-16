#ifndef FIREN_H_INCLUDED
#define FIREN_H_INCLUDED

# include "hero.h"
# include <string.h>
# include "loadedPictures.h"
# include "allScore.h"

//state description
//0 = stand 
//1 = walk
//2 = punch
//3 = power

void firen_initialize();
void firen_arrow_initialize();
void firen_walk_and_punch();
void firen_walk_and_punch_render();
void firen_power();
void firen_power_render();
void firen_arrow();
void firen_arrow_render();
void hero_firen_collision();
void firen();


/*
the firen_arrow structure is used to hold values for each of firens arrow.
it holds the charactaristics for each of the arrow.
for example the arrows location , index and if the arow is active
*/

struct firen_arrow
{
	int x;
	int y;
	int index;
	int active;


}arrow[20];

int firen_x = 1000;                    //firens initial standing location is initialized at first
int firen_y = 128;

int firen_dx = 5;                      // the value at which firen will move in the X-axis or in the Y-axis
int firen_dy = 4;

int firen_walk_index = 0;              //the index values for each of firens actions
int firen_punch_index = 0;
int firen_power_index= 0;


int firen_life = 500;                 //this variable holds the life for firen
int firen_dead = 0;                   // variable that holds if firen is dead or not... 0 is not dead... 1 is dead
int firen_dir = 0;                    // ths variable holds the direction firen faces... 1 is left ... 2 is right

int firen_state = 1;                  // this corresponds to the state firen is in


int firen_power_timer = 0;            //variable that decides the amount of time firen will be in the power mode

int firen_power_on = 0;               // variable that decides if the power of firen is on or not... 0 is power off....any other value means the power is on


/*
firn_initialize() function initializes the firen character with it's initial values that are required 
to move the character
*/

void firen_initialize()
{

	firen_x = 1000;
	firen_y = 128;

	firen_walk_index = 0;
	firen_punch_index = 0;
	firen_power_index= 0;


	firen_life = 200;
	firen_dead = 0;
	firen_dir = 0;

	firen_state = 1;


	firen_power_timer = 0;

	firen_power_on = 0;



}


/*
firen_arrow_iitialize() function initizes the arrows outside the screen .
This is called after each power call from the firen character
*/


void firen_arrow_initialize()
{
	for(int i = 0 ; i <=15 ; i++)
	{
		arrow[i].x = rand() % 300 + 850 ;
		arrow[i].y = rand() % 200;
		arrow[i].active = 1;
		arrow[i].index = 0;
		

	
	}
}

/*
This function is used to change the values that is required for firen to walk ..
firen follows the hero whereever the hero goes...this logic can be found here..

*/
void firen_walk_and_punch()
{

	if(firen_life <=0)                 //this logic is for if the health of firen is null firen will be declared as dead through firen_dead = 1
		{
			firen_dead = 1;
			

			firen_x = 1000 ;
			firen_y = 1000 ;
		}



	if(firen_x <= hero_walk_x + 35 && firen_x >= hero_walk_x - 35  && firen_y >= hero_walk_y && firen_y <= hero_walk_y + 5 && hero_state != 2 && hero_state != 3 && firen_dead == 0)  
	{

			firen_state = 2;                              //this is the punch logic...when firen comes near the hero the firen_state will change to 2 that is the punching mode..also causing the hero to loose life
			                                              //punch will not happen if the hero is punching or kicking or firen is dead
			firen_punch_index++ ;

			if(firen_punch_index >= 3)
				firen_punch_index = 0 ;
			
			if(hero_life > 0)
				hero_life--; 

			if(hero_life <= 0)
			{
				PlaySound("music//gameover", NULL, SND_ASYNC);
				mode = 7;												//if hero has no life then game over mode will occure that is mode = 7
			}
	}



	else if(firen_dead == 0)                              //walk logic for firen ...if firen is not dead...he will go to the crrent value of the hero ..also change direction according to his movement

	{
		firen_state = 1; 
		firen_walk_index++;

		if(firen_walk_index >= 3)
			firen_walk_index=0;



		if(firen_x > hero_walk_x)
		{
			firen_dir = 1;
			firen_x = firen_x - firen_dx;  
		}



		if(firen_x < hero_walk_x)
		{
			firen_dir = 2;
			firen_x = firen_x + firen_dx;
		}



		if(firen_y > hero_walk_y)
		{
	
			firen_y = firen_y - firen_dy; 
		}



		if(firen_y < hero_walk_y)
		{	

			firen_y = firen_y + firen_dy;
		}


	}



}

/*
this function is used to render the walk and punch movements of firen
*/

void firen_walk_and_punch_render()
{

	if( firen_dir == 2 && firen_state == 1 && firen_dead == 0 )
			iShowBMPAlternativeSkipBlack( firen_x , firen_y , Firen_walk[firen_walk_index]);

	if( firen_dir == 1 && firen_state == 1 && firen_dead == 0 )
			iShowBMPAlternativeSkipBlack( firen_x , firen_y , Firen_walk_mirror[firen_walk_index]);

	if( firen_dir == 2 && firen_state == 2 && firen_dead == 0 )
			iShowBMPAlternativeSkipBlack( firen_x , firen_y , Firen_punch[firen_punch_index]);

	if( firen_dir == 1 && firen_state == 2 && firen_dead == 0  )
			iShowBMPAlternativeSkipBlack( firen_x , firen_y , Firen_punch_mirror[firen_punch_index]);
}


/*
firen_power() function changes all the values that is required foe firen to go in power mode and show it
*/
void firen_power()
{
	firen_power_index++;

	firen_power_timer++;

	if(firen_power_timer == 9)
		{
			firen_power_on = 1 ;

			firen_power_index =  0;
			firen_power_timer = 0;
			firen_state = 1;
		}

	

}

/*
firen_power_render() function renders the firen power mode pictures
*/

void firen_power_render()
{
	if(firen_power_index<3)
	iShowBMPAlternativeSkipBlack( firen_x , firen_y , Firen_power[firen_power_index] );

	else
		iShowBMPAlternativeSkipBlack( firen_x - 32, firen_y , Firen_power[firen_power_index] );
}

/*
firen_arrow() function will onlt work if the the firen_power_on value is not 0...
at that moment all the arrows will start to come from the right ..after a certain time the power will be turned of through 
the firen_power_on variable
*/

void firen_arrow()
{
	if(firen_power_on != 0 )
	{
		firen_power_on++;

		for(int i = 0 ; i <=15 ; i++)
		{
			arrow[i].x = arrow[i].x - 20;
		}
	}


	if(firen_power_on>63)
	{
		            
		//void firen_arrow_initializer()

		for(int i = 0 ; i <= 15 ; i++)
		{
			arrow[i].x = rand() % 300 + 850 ;
			arrow[i].y = rand() % 200;
			arrow[i].index = 0;
			arrow[i].active = 1;

			
		
		}

		firen_power_on = 0;
	}
}

/*
firen_arrow_render() function is used to render the the arrows...it is always rendering outside the screen...
and renders inside the screen when it is called
*/

void firen_arrow_render()
{
	for(int i = 0 ; i<= 15; i++)
	{
		if(arrow[i].active == 1)
			iShowBMPAlternativeSkipBlack( arrow[i].x , arrow[i].y , Firen_arrow[arrow[i].index]);
	}
}


/*
this function holds the logic for hero and firen collision..
if the hero is near firen then firen will go to punching mode that is firen_state=2 and hero life will decrease
*/

void hero_firen_collision()
{
	
	/*
	This if condition holds the logic for firens arrow and the heroes collision that will cause the hero to loose life
	*/
	if(firen_power_on !=0 )
	{
		for(int i = 0 ; i<= 15; i++)
		{

			if( arrow[i].x >= hero_walk_x && arrow[i].x <= hero_walk_x + 64 && arrow[i].y >= hero_walk_y - 20 && arrow[i].y <= hero_walk_y + 40 && arrow[i].active == 1)     //arrow[i].active == 1)
			{

				hero_life = hero_life - 10;
				arrow[i].active = 0 ;
				
				if(hero_life <= 0)
				{
					PlaySound("music//gameover", NULL, SND_ASYNC);
					mode = 7;
				}
			}
		}

	}

	/*
	This if condition holds the logic for hero's laser and firens collision...this will cause firen to loose health
	*/


	if(laser_on != 0)                                 //laser and firen collision logic , when true, decreases firens health
		{
		
			for(int i = 0 ; i <=15 ; i++ )

				
				{
					if(laser_loc[i].x + 100 >= firen_x &&  laser_loc[i].x +100 <= firen_x + 64 &&  laser_loc[i].y >= firen_y - 20 &&  laser_loc[i].y <= firen_y + 40 && laser_loc[i].active ==1 && temp_dir == 2 )
					{
						firen_life = firen_life - 10 ;                                          //right side facing laser collision
						score = score + 100 ;
						laser_loc[i].active = 0;
					
						
					}

					if(laser_loc[i].x - 150 >= firen_x  &&  laser_loc[i].x - 150 <= firen_x + 64 &&  laser_loc[i].y >= firen_y - 20 &&  laser_loc[i].y <= firen_y + 40 && laser_loc[i].active ==1  && temp_dir ==1 )
					{
						firen_life = firen_life - 10 ;                                          //left side facing laser collision
						score = score + 100 ;
						laser_loc[i].active = 0;
					}

				}

		}

	/*
	this if contains the logic for collision between the hero's laser and firen's arrow
	*/

	if(firen_power_on !=0 &&  laser_on != 0)
	{
		for(int i = 0 ; i <= 15 ; i++)
			for(int j = 0 ; j <= 15 ; j++)
			{
				if(laser_loc[i].x + 100 >= arrow[j].x  && laser_loc[i].x + 100 <= arrow[j].x + 64 && laser_loc[i].y >= arrow[j].y - 15 && laser_loc[i].y <= arrow[j].y + 15 && laser_loc[i].active ==1 && arrow[j].active == 1)
				{
					laser_loc[i].active = 0;
					arrow[j].active = 0 ;
				}
			}

	}



	/*
	this is the logic while hero punches firen..will cause firen to loose life...but it will be very low
	*/
	
	if(hero_dir == 2)  //when the hero is facing right
		{

				if(firen_x <= hero_walk_x + 35 && firen_x >= hero_walk_x  && firen_y >= hero_walk_y && firen_y <= hero_walk_y + 5 && ( hero_state == 2 || hero_state == 3) && firen_dead == 0)
					{
						firen_life = firen_life - 1 ; 
						score = score + 100 ;
					}
		}


	if(hero_dir == 1)       //when the hero is facing left
		{

				if(firen_x <= hero_walk_x && firen_x >= hero_walk_x -35 && firen_y >= hero_walk_y && firen_y <= hero_walk_y + 5 && ( hero_state == 2 || hero_state == 3) && firen_dead == 0)
					{
						firen_life = firen_life - 1 ; 
						score = score + 100 ;
					}
		}
}

/*
this function holds all function that is required to render depending on each firen_state
but collision will always render as it can happen anytime..same goes for arrows
*/

void firen()
{

	hero_firen_collision();

	firen_arrow_render();

	if(hero_state == 5)
	{
		
		if(firen_dir == 2)
			iShowBMPAlternativeSkipBlack( firen_x , firen_y ,  Firen_stand[0] );

		else if(firen_dir == 1)         
			iShowBMPAlternativeSkipBlack( firen_x , firen_y ,  Firen_stand_mirror[0] );
		
	}

	else if(firen_state==3)
		firen_power_render();

	else

	firen_walk_and_punch_render();

	
}


#endif // FIREN_H_INCLUDED
