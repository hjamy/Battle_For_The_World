#ifndef BANDIT_H_INCLUDED
#define BANDIT_H_INCLUDED


# include "hero.h"
# include <string.h>
# include "loadedPictures.h"
# include "allScore.h"


typedef struct bandit_group bd_grp ;


void bandit_initialize();
void bandit_walk_and_punch();
void bandit_walk__and_punch_render();
void hero_bandit_collision();
void bandit();



int bandit_counter = -1;         //counts the number of bandits that are in the screen..
								 //also used to manuulate the number of bandits that are in the screen

int bandit_dx = 5 ;              //bandits movement spped across X-axis and Y-axis
int bandit_dy = 4 ;


//state description
//0 = stand 
//1 = walk
//2 = punch


/*
structure to store the information of multilpe bandite units ..it stores their charactaristics also.
each element of the bandits will change throughtout the game..each bandits condition will not have effect n any other bandits in the screen
*/

struct bandit_group
{
	int x ;
	int y ;

	int walk_index ;
	int punch_index ;

	int dir ;

	int state ;

	int life;

	int dead;

	int active;

}band[25];


/*
bandit_initialize() function is used to initialize the starting values for all the bandits.
it initializes their priliminary charactristics
*/

void bandit_initialize()
{
	for(int i = 0 ; i < 25 ; i++)
	{
		if(i % 2 ==0)
			band[i].x = -50 ;
		else if(i % 2 != 0)
			band[i].x = 850 ;
		
			
		band[i].y = rand() % 250 ;

		band[i].walk_index = 0 ;
		band[i].punch_index = 0 ;

		band[i].dir = 1 ;

		band[i].state = 1 ;

		band[i].life = 50 ;

		band[i].dead = 0 ;

		band[i].active = 0 ;

		bandit_counter = -1;
	
	}
}

/*
bandit_walk_and_punch() is used to control the variables while the bandit is in walk and punch mode.
it is fully automated and the change occurs according to the position and the change of satte of the hero
*/

void bandit_walk_and_punch()
{
	for(int i = 0 ; i < bandit_counter ; i++ )    //code for bandit walking and punching
	{

		if(band[i].life <=0)
		{
			band[i].dead = 1;
			band[i].x = 1000 ;
			band[i].y = 1000 ;
		}


		
		if(band[i].x <= hero_walk_x + 35 && band[i].x >= hero_walk_x - 35  && band[i].y >= hero_walk_y && band[i].y <= hero_walk_y + 5 && hero_state != 2 && hero_state != 3 && band[i].dead == 0 ) 

		{
			band[i].state = 2;                             // code for bandit punching..will punch when firzen is in the area of a bandit

			band[i].punch_index++ ;

			if(band[i].punch_index >= 3)
				band[i].punch_index = 0 ;
			
			if(hero_life > 0)
			hero_life--; 

			if(hero_life <= 0)
			{
				PlaySound("music//gameover", NULL, SND_ASYNC);
				mode = 7;
			}
		}


		else if(band[i].dead == 0)                    // code for bandit walking depending on the current location of the the hero
		{
			band[i].state = 1;

			band[i].walk_index++ ;

			if(band[i].walk_index >= 3)

				band[i].walk_index = 0;
		
		
			if(band[i].x > hero_walk_x)
			{
				band[i].dir = 1;
				band[i].x = band[i].x - bandit_dx ; 
			}

			if(band[i].x < hero_walk_x)
			{
				band[i].dir = 2;
				band[i].x = band[i].x + bandit_dx ;
			}

			if(band[i].y > hero_walk_y)
			{
	
				band[i].y = band[i].y - bandit_dy ; 
			}

			if(band[i].y < hero_walk_y)
			{	

				band[i].y = band[i].y + bandit_dy ;
			}

		}

	}
}

/*
bandit_walk_and_punch_render() is used to render the images while the bandit is in walk and punch mode
*/

void bandit_walk__and_punch_render()
{
	
	for(int i = 0; i < bandit_counter ; i++)
	{
		if( band[i].dir == 2 && band[i].state == 1 && band[i].dead == 0 )
			iShowBMPAlternativeSkipBlack( band[i].x , band[i].y , Bandit_walk[band[i].walk_index]);

		if( band[i].dir == 1 && band[i].state == 1 && band[i].dead == 0 )
			iShowBMPAlternativeSkipBlack( band[i].x , band[i].y , Bandit_walk_mirror[band[i].walk_index]);

		if( band[i].dir == 2 && band[i].state == 2 && band[i].dead == 0 )
			iShowBMPAlternativeSkipBlack( band[i].x , band[i].y , Bandit_punch[band[i].punch_index]);

		if( band[i].dir == 1 && band[i].state == 2 && band[i].dead == 0  )
			iShowBMPAlternativeSkipBlack( band[i].x , band[i].y , Bandit_punch_mirror[band[i].punch_index]);
	}
	
}

/*
hero_bandit_collision() holds the logic for hero ad bandit collision and all the outcome may occure because of it.
if hero laser has a bandit in its area..the laser will deactivate after dealing a damage to the bandit
*/
void hero_bandit_collision()
{
	
	
		if(laser_on != 0)                                 //laser bandit collision 
		{
		
			for(int i = 0 ; i <=15 ; i++ )

				for(int j = 0 ; j<bandit_counter ; j++)
				{
					if(laser_loc[i].x + 100 >= band[j].x &&  laser_loc[i].x +100 <= band[j].x + 64 &&  laser_loc[i].y >= band[j].y-20 &&  laser_loc[i].y <= band[j].y +40 && laser_loc[i].active ==1 && temp_dir ==2 )
					{
						band[j].life = band[j].life - 220 ;                                          //right side collision
						score = score + 100 ;
						laser_loc[i].active = 0;
					
					}

					if(laser_loc[i].x - 150 >= band[j].x  &&  laser_loc[i].x - 150 <= band[j].x + 64 &&  laser_loc[i].y >= band[j].y-20 &&  laser_loc[i].y <= band[j].y +40 && laser_loc[i].active ==1  && temp_dir ==1 )
					{
						band[j].life = band[j].life - 220 ;                                          //left side collision
						score = score + 100 ;
						laser_loc[i].active = 0;
					}

				}

		}

	



	if(hero_dir == 2)                       //code for hero punch or kick collision with the bandits           

		{
			for(int i = 0 ; i < bandit_counter ; i++ )

				if(band[i].x <= hero_walk_x + 35 && band[i].x >= hero_walk_x  && band[i].y >= hero_walk_y && band[i].y <= hero_walk_y + 5 && ( hero_state == 2 || hero_state == 3) && band[i].dead == 0)
					{
						band[i].life = band[i].life - 55 ; 
						score = score + 100 ;
					}
		}


	if(hero_dir == 1)
		{
			for(int i = 0 ; i < bandit_counter ; i++ )

				if(band[i].x <= hero_walk_x && band[i].x >= hero_walk_x -35 && band[i].y >= hero_walk_y && band[i].y <= hero_walk_y + 5 && ( hero_state == 2 || hero_state == 3) && band[i].dead == 0)
					{
						band[i].life = band[i].life - 55 ; 
						score = score + 100 ;
					}
		}
		
}




/*
bandit() function is used for determining the bandit state depending on the hero_state

*/

void bandit()
{

	hero_bandit_collision();

	if(hero_state == 5)
	{
		for(int i = 0 ; i <= bandit_counter ; i++ )
		{
		if(band[i].dir == 2)
			iShowBMPAlternativeSkipBlack( band[i].x , band[i].y ,  Bandit_stand[0] );

		else if(band[i].dir == 1)         
			iShowBMPAlternativeSkipBlack( band[i].x , band[i].y ,  Bandit_stand_mirror[0] );
		}
	}

	
	else 
		
		bandit_walk__and_punch_render();

	
		
}







#endif // BANDIT_H_INCLUDED
