#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED


# include <string.h>
# include "loadedPictures.h"


typedef struct hero_power_loc hero_power_loc;


void hero_power();
void hero_power_render();
void hero_laser_initialize();
void hero_laser();
void hero_laser_render();
void hero_walk();
void hero_walk_render();
void hero_punch();
void hero_punch_render();
void hero_kick();
void hero_kick_render();
void hero_jump();
void hero_jump_render();
void hero();


/*
The structure hero_power_loc holds the hero lasers each part's value .
There are total 15 parts ..so we used 15 variables of this structures type though 25 were declared.
Each variable here contains the characteristics of each of the laser part
for example the laser loaction,if the laser is active after collision and the index of that laser that 
is to be printed on the screen
*/

struct hero_power_loc
{
	int x;
	int y;
	int laser_index;
	int active;

}laser_loc[25];

int hero_dead = 0;                          // variable to determine if the hro is dead or not... 0 is not dead... 1 is dead

int hero_life = 200 ;                       // variable indicating hero life..also the lentgh of the hero life bar 

int hero_mana = 200 ;                       // variable indicating hero mana..also the length of the hero mana bar

int hero_walk_index = 0;                    //these are the index for all the pictures that is to be rendered when the hero is in a specific
int hero_punch_index = 0;                   // hero_state completeing a specific action
int hero_kick_index = 0;
int hero_jump_index = 0;

 
int hero_dir = 2;                           //this variable is to indicate which direction the hero is facing... 1 is left .. 2 is rght

int temp_dir ;                              /*
											hero laser direction depends on the direction hero is facing ..
											if the hero changes direction while the laser is still on the screen then the laser also changes direction ..
											In order to hold the initial direction the hero was facing when the laser was first called this varibale 
											is used which temporarily holds the hero's initial laser throughing direction
											*/


int hero_dx = 5;                            // varibale to change hero's direction in the X-axis through button press
int hero_dy = 4;                            // variable to change hero's direction in the Y-axis through button press

int hero_jump_dy = 10;                      // variable to determine the speed at which the hero will jump and drop
 
int hero_jump_time_count = 0;               /* 
											variable to count the time the hero will sit before jump , the time hero will go up,
											the time hero will go down and the time hero will sit after landing on the ground
											*/
                                              

int hero_power_index = 0;                   // the changes in heros's body and the pictures that are needed to be renderes to show that are called through this index variable

int hero_laser_throw_timer = -3 ;           /* 
											hero will get ready before the laser will be thrwn.that time is given by initializing this variable
											with -3 ..when the value reacher 0 the hero will b ready and at the same time laser will start
											*/

int laser_on = 0;                           //variable to determine if the laser is on or not and also after how much time the laser will stop


int hero_walk_x = 100;                      //initial values for hero...hero will stand at this co-ordinate when the game starts or the stage changes
int hero_walk_y = 100;


int hero_state=0;                           // variable that holds the state the heroes in and calls other functions according to ir..it changes through iKeyborad

//0=stealth
//1=walk
//2=punch
//3=kick
//4=power
//5=jump

/*
The hero_initialize() function is used for initializing all the values of the hero in different parts of the 
game...Foe example after finishing the game, after game over due to dying or after completeing a stage
*/
void hero_initialize()
{
		hero_state=0;
		hero_life = 200;
		hero_mana = 200;
		hero_walk_x = 100;
		hero_walk_y = 100;
		hero_dead = 0;
		hero_walk_index = 0;
		hero_punch_index = 0;
		hero_kick_index = 0;
		hero_jump_index = 0;
		hero_dir = 2;
		hero_jump_time_count = 0;
		hero_power_index = 0; 
		hero_laser_throw_timer = -3 ;   
		laser_on = 0;

}



/*
hero_laser_initialize() is used to initialize all the laser with a value before using it in game..
this values are all reinitialized after each call by the player
*/
void hero_laser_initialize()

{
	laser_loc[0].laser_index = 0;   

	for(int i = 1 ; i <= 15 ; i++)
		{
			laser_loc[i].laser_index = 1;      
		}

	for(int i=0 ; i<=15 ;i++)
		{
			laser_loc[i].x = -100;
			laser_loc[i].y = -100;
			laser_loc[i].active = 1 ;
			
		}
}


/*
The hero_poweer() function is called when the hero_state= 4..
it changes the values for heroes in power mode movement and changes the heroes power index values.
This value helps to render the hero power mode..
In this function the laser_on variable is set to value 1 which turns the laser on.
After the laser_throw_timer variable reaches a certain limit this functionmstops working as the hero_state changes to 0
*/

void hero_power()
{


	hero_power_index++;

	if(hero_power_index >=5)
		hero_power_index = 3;
		
	hero_laser_throw_timer++;

	if(hero_laser_throw_timer ==0)
	{
		laser_on =1;
		laser_loc[0].x = hero_walk_x + 40;
		
		if(hero_selector==1)
		laser_loc[0].y = hero_walk_y -3; 

		if(hero_selector==2)
		laser_loc[0].y = hero_walk_y +5;          //bat requares the value +5 to make laser parallel..the value for firzen is -3
	}



	if(hero_laser_throw_timer >=15 )              // after the hero_laser_timer reaches 15 the state changes to 0
	{
		
		hero_power_index =  0;
		hero_laser_throw_timer = -3;
		hero_state = 0;

	}

}

/*
hero_power_render() calls the pictures that are required to show the hero is in power mode..
this uses the direction the hero is in to call ifferent picures and also adjust hero location 
*/

void hero_power_render()
{
	if(hero_dir == 2)
	{
		
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_power[hero_power_index]);
	}

	else if(hero_dir == 1)
	{
		if(hero_power_index < 3)
			iShowBMPAlternativeSkipBlack( hero_walk_x  , hero_walk_y , Hero_power_mirror[hero_power_index]);
		else
		iShowBMPAlternativeSkipBlack( hero_walk_x -64  , hero_walk_y , Hero_power_mirror[hero_power_index]);
	}


}



/*
hero_laser() is used to control the variable that are required for the laser to move.
This function only works when the laser_on value is not 0 which means laser is turned on.
laser_on variable's value increases with each call ..after the value reaches a certain point the laser values reinitialze.
*/


void hero_laser()
{

	if(laser_on != 0 )                   
	{
		
		laser_on++;


		for(int i = 15; i >= 1 ; i--)         
		{

			laser_loc[i].x = laser_loc[i - 1].x ;
			laser_loc[i].y = laser_loc[i - 1].y ;
		}

		if(temp_dir == 2)
			laser_loc[0].x =  laser_loc[0].x + 32 ;
		if(temp_dir == 1)
			laser_loc[0].x =  laser_loc[0].x - 32 ;


		if(laser_on>=40)            
		{
			

			for(int i=0 ; i<=15 ;i++)
			{
				laser_loc[i].x = -100;
				laser_loc[i].y = -100;
				laser_loc[i].active = 1;
			}

			laser_on =0;
		}


	}

	
}

/*
hero_laser_render() is used render the laser images when the laser is in motion.it uses the temp_dir to hold
and use the initial direction
*/

void hero_laser_render()
{
	
		for( int i=0 ; i <= 15 ; i++ )
			{
				if(temp_dir == 2 && laser_loc[i].active == 1)
					iShowBMPAlternativeSkipBlack( laser_loc[i].x , laser_loc[i].y , Hero_laser[laser_loc[i].laser_index]);

				if(temp_dir == 1 && laser_loc[i].active == 1)
					iShowBMPAlternativeSkipBlack( laser_loc[i].x -192 , laser_loc[i].y , Hero_laser_mirror[laser_loc[i].laser_index]);
		}
			
			
}




/*
hero_walk() is used to control the index and other state variables that are required for the hero to walk.
it also changes the variables according to which the render is done
*/

void hero_walk()
{
	hero_walk_index++;
	if(hero_walk_index >= 3)
	{
		hero_walk_index = 0;
		hero_state =0;
	}
}

/*
hero_walk_render() is used to render the images when the hero is in walking mode 
*/

void hero_walk_render()
{
	if(hero_dir == 2)
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_walk[hero_walk_index]);

	else if(hero_dir == 1)
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_walk_mirror[hero_walk_index]);
}

/*
hero_punch() is used to control the variables while the hero is in punch mode
*/


void hero_punch()
{

	hero_punch_index++;
	if(hero_punch_index >= 4)
		{
			hero_punch_index=0;
			hero_state =0;
		}
}


/*
hero_punch_render() is used render the images when the hero is in punching mode
*/

void hero_punch_render()
{
	if(hero_dir == 2)
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_punch[hero_punch_index]);

	else if(hero_dir == 1)
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_punch_mirror[hero_punch_index]);
}

/*
hero_kick() is used to control the variables while the hero is in kick mode
*/


void hero_kick()
{
	hero_kick_index++;
	if(hero_kick_index >= 4)
		{
			hero_kick_index=0;
			hero_state =0;
		}
}

/*
hero_kick_render() is used render the images when the hero is in kicking mode
*/

void hero_kick_render()
{
	if(hero_dir == 2)
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_kick[hero_kick_index]);

	else if(hero_dir == 1)
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_kick_mirror[hero_kick_index]);
}

/*
hero_jump() is used to control the variables while the hero is in jump mode
the hero_jump_time_count 
*/


void hero_jump()
{

	if( hero_jump_time_count < 2 && hero_jump_time_count >= 0)
		hero_jump_index=0;


	if( hero_jump_time_count >= 2 && hero_jump_time_count <=7)
		{
			hero_jump_index=1;
			hero_walk_y = hero_walk_y + hero_jump_dy;

		}

	if( hero_jump_time_count >= 8 && hero_jump_time_count <=13)
		{
			hero_jump_index=1;
			hero_walk_y = hero_walk_y - hero_jump_dy;

		}


	if( hero_jump_time_count >=14 &&  hero_jump_time_count < 16)
		hero_jump_index=0;

	if(hero_jump_time_count >= 16)
	{
		hero_jump_time_count = 0;
		hero_jump_index = 0;
			hero_state = 0;
	}

	hero_jump_time_count++ ;
	
}

/*
hero_jump_render() is used render the images when the hero is in jump mode
*/

void hero_jump_render()
{
	if(hero_dir == 2)
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_jump[hero_jump_index]);

	else if(hero_dir == 1)
		iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y , Hero_jump_mirror[hero_jump_index]);
}


/*
hero() function is used to determine which pictures are to rennder according
to the hero_state variable 

*/
 
void hero()
{

	iShowBMP(35 , 525 , Hero_thumb[0] );      // these are the codes for showing hero life and mana ..also hero thumbnail picture...also contains other designing code lines

	iSetColor(100,100,255);
	iFilledRectangle (140 , 525 , 220 ,60);

	iSetColor(17, 21 , 176);
	iFilledRectangle(150 ,560, 200 , 15);
	iFilledRectangle(150 ,535, 200 , 15);

	iSetColor(255,0,0);
	iFilledRectangle(150 ,560, hero_life , 15);

	iSetColor(0,0,255);
	iFilledRectangle(150 ,535, hero_mana , 15);


	

	hero_laser_render(); //always renders outsisde the scree...when laser values are changes then it is called in front of the players

	if(hero_state==0)
	{
		if(hero_dir == 2)
			iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y ,  Hero_stand[0]);

		else if(hero_dir == 1)         
			iShowBMPAlternativeSkipBlack( hero_walk_x , hero_walk_y ,  Hero_stand_mirror[0]);
	}

	if(hero_state==1)
		hero_walk_render();

	if(hero_state==2)
		hero_punch_render();

	if(hero_state==3)
		hero_kick_render();

	if(hero_state==4)
		hero_power_render();

	if(hero_state==5)
		hero_jump_render();
}

#endif // HERO_H_INCLUDED
