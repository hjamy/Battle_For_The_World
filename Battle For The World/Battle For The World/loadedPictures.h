
#ifndef LOADEDPICTURES_H_INCLUDED
#define LOADEDPICTURES_H_INCLUDED


# include <string.h>

int hero_selector = 0 ;  //this variable determins which hero is selected and calls all the pictures required to run that hero


//Hero_variable_declarations

char Hero_thumb[6][50] ; 

char Hero_stand[6][50] ;

char Hero_stand_mirror[6][50] ;

char Hero_walk[6][50] ;

char Hero_walk_mirror[6][50] ;

char Hero_punch[6][50];

char Hero_punch_mirror[6][50] ;

char Hero_kick[6][50] ;

char Hero_kick_mirror[6][50] ;

char Hero_jump[6][50] ;

char Hero_jump_mirror[6][50] ;

char Hero_power[6][50] ;

char Hero_power_mirror[6][50] ;

char Hero_laser[6][50] ;

char Hero_laser_mirror[6][50] ;


//all firzen images

char Firzen_thumb[6][50] = { "Firzen\\firzen_thumb.bmp" } ;

char Firzen_stand[6][50] = {"Firzen\\Firzen_stand\\1.bmp"};

char Firzen_stand_mirror[6][50] = { "Firzen\\mirror\\Firzen_stand\\1.bmp" } ;

char Firzen_walk[6][50] = {"Firzen\\Firzen_walk\\1.bmp", "Firzen\\Firzen_walk\\2.bmp", "Firzen\\Firzen_walk\\3.bmp", "Firzen\\Firzen_walk\\4.bmp"};

char Firzen_walk_mirror[6][50] = {"Firzen\\mirror\\Firzen_walk\\1.bmp", "Firzen\\mirror\\Firzen_walk\\2.bmp", "Firzen\\mirror\\Firzen_walk\\3.bmp", "Firzen\\mirror\\Firzen_walk\\4.bmp"};

char Firzen_punch[6][50] = { "Firzen\\Firzen_punch\\1.bmp", "Firzen\\Firzen_punch\\2.bmp", "Firzen\\Firzen_punch\\3.bmp", "Firzen\\Firzen_punch\\4.bmp" };

char Firzen_punch_mirror[6][50] = { "Firzen\\mirror\\Firzen_punch\\1.bmp", "Firzen\\mirror\\Firzen_punch\\2.bmp", "Firzen\\mirror\\Firzen_punch\\3.bmp", "Firzen\\mirror\\Firzen_punch\\4.bmp" };

char Firzen_kick[6][50] = { "Firzen\\Firzen_kick\\1.bmp", "Firzen\\Firzen_kick\\2.bmp", "Firzen\\Firzen_kick\\3.bmp", "Firzen\\Firzen_kick\\4.bmp" };

char Firzen_kick_mirror[6][50] = { "Firzen\\mirror\\Firzen_kick\\1.bmp", "Firzen\\mirror\\Firzen_kick\\2.bmp", "Firzen\\mirror\\Firzen_kick\\3.bmp", "Firzen\\mirror\\Firzen_kick\\4.bmp" };

char Firzen_jump[6][50] = { "Firzen\\Firzen_jump\\1.bmp" ,"Firzen\\Firzen_jump\\2.bmp" };

char Firzen_jump_mirror[6][50] = { "Firzen\\mirror\\Firzen_jump\\1.bmp" ,"Firzen\\mirror\\Firzen_jump\\2.bmp" };

char Firzen_power[6][50] = { "Firzen\\Firzen_power\\1.bmp" , "Firzen\\Firzen_power\\2.bmp" ,"Firzen\\Firzen_power\\3.bmp" ,"Firzen\\Firzen_power\\4.bmp" ,"Firzen\\Firzen_power\\5.bmp" ,"Firzen\\Firzen_power\\6.bmp"  };

char Firzen_power_mirror[6][50] = { "Firzen\\mirror\\Firzen_power\\1.bmp" , "Firzen\\mirror\\Firzen_power\\2.bmp" ,"Firzen\\mirror\\Firzen_power\\3.bmp" ,"Firzen\\mirror\\Firzen_power\\4.bmp" ,"Firzen\\mirror\\Firzen_power\\5.bmp" ,"Firzen\\mirror\\Firzen_power\\6.bmp"  };

char Firzen_laser[6][50] = { "Firzen\\Firzen_laser\\1.bmp" , "Firzen\\Firzen_laser\\2.bmp" ,"Firzen\\Firzen_laser\\3.bmp" ,"Firzen\\Firzen_laser\\4.bmp" ,"Firzen\\Firzen_laser\\5.bmp" } ;

char Firzen_laser_mirror[6][50] = { "Firzen\\mirror\\Firzen_laser\\1.bmp" , "Firzen\\mirror\\Firzen_laser\\2.bmp" ,"Firzen\\mirror\\Firzen_laser\\3.bmp" ,"Firzen\\mirror\\Firzen_laser\\4.bmp" ,"Firzen\\mirror\\Firzen_laser\\5.bmp" } ;   


//all bat images
 
char Bat_thumb[6][50] = { "Bat\\bat_thumb.bmp" } ;

char Bat_stand[6][50] = { "Bat\\Bat_stand\\1.bmp" } ;

char Bat_stand_mirror[6][50] = { "Bat\\mirror\\Bat_stand\\1.bmp" } ;

char Bat_walk[6][50] = {"Bat\\Bat_walk\\1.bmp", "Bat\\Bat_walk\\2.bmp", "Bat\\Bat_walk\\3.bmp", "Bat\\Bat_walk\\4.bmp"};

char Bat_walk_mirror[6][50] = {"Bat\\mirror\\Bat_walk\\1.bmp", "Bat\\mirror\\Bat_walk\\2.bmp", "Bat\\mirror\\Bat_walk\\3.bmp", "Bat\\mirror\\Bat_walk\\4.bmp"};

char Bat_punch[6][50] = { "Bat\\Bat_punch\\1.bmp", "Bat\\Bat_punch\\2.bmp", "Bat\\Bat_punch\\3.bmp", "Bat\\Bat_punch\\4.bmp" };

char Bat_punch_mirror[6][50] = { "Bat\\mirror\\Bat_punch\\1.bmp", "Bat\\mirror\\Bat_punch\\2.bmp", "Bat\\mirror\\Bat_punch\\3.bmp", "Bat\\mirror\\Bat_punch\\4.bmp" };

char Bat_kick[6][50] = { "Bat\\Bat_kick\\1.bmp", "Bat\\Bat_kick\\2.bmp", "Bat\\Bat_kick\\3.bmp", "Bat\\Bat_kick\\4.bmp" };

char Bat_kick_mirror[6][50] = { "Bat\\mirror\\Bat_kick\\1.bmp", "Bat\\mirror\\Bat_kick\\2.bmp", "Bat\\mirror\\Bat_kick\\3.bmp", "Bat\\mirror\\Bat_kick\\4.bmp" };

char Bat_jump[6][50] = { "Bat\\Bat_jump\\1.bmp" ,"Bat\\Bat_jump\\2.bmp" };

char Bat_jump_mirror[6][50] = { "Bat\\mirror\\Bat_jump\\1.bmp" ,"Bat\\mirror\\Bat_jump\\2.bmp" };

char Bat_power[6][50] = { "Bat\\Bat_power\\1.bmp" , "Bat\\Bat_power\\2.bmp" ,"Bat\\Bat_power\\3.bmp" ,"Bat\\Bat_power\\4.bmp" ,"Bat\\Bat_power\\5.bmp" ,"Bat\\Bat_power\\6.bmp"  };

char Bat_power_mirror[6][50] = { "Bat\\mirror\\Bat_power\\1.bmp" , "Bat\\mirror\\Bat_power\\2.bmp" ,"Bat\\mirror\\Bat_power\\3.bmp" ,"Bat\\mirror\\Bat_power\\4.bmp" ,"Bat\\mirror\\Bat_power\\5.bmp" ,"Bat\\mirror\\Bat_power\\6.bmp"  };

char Bat_laser[6][50] = { "Bat\\Bat_laser\\1.bmp" , "Bat\\Bat_laser\\2.bmp" ,"Bat\\Bat_laser\\3.bmp" ,"Bat\\Bat_laser\\4.bmp" ,"Bat\\Bat_laser\\5.bmp" } ;

char Bat_laser_mirror[6][50] = { "Bat\\mirror\\Bat_laser\\1.bmp" , "Bat\\mirror\\Bat_laser\\2.bmp" ,"Bat\\mirror\\Bat_laser\\3.bmp" ,"Bat\\mirror\\Bat_laser\\4.bmp" ,"Bat\\mirror\\Bat_laser\\5.bmp" } ; 


//function to load pictures according to the selected hero in the hero selection window

void hero_selector_func()

{
	if(hero_selector==1)

		for(int i =0 ; i<6 ;i++)
		{
			strcpy( Hero_thumb[i] , Firzen_thumb[i]);

			strcpy( Hero_stand[i] , Firzen_stand[i]);

			strcpy( Hero_stand_mirror[i] , Firzen_stand_mirror[i]);

			strcpy( Hero_walk[i] , Firzen_walk[i]);

			strcpy( Hero_walk_mirror[i] , Firzen_walk_mirror[i]);

			strcpy( Hero_punch[i] , Firzen_punch[i]);

			strcpy( Hero_punch_mirror[i] , Firzen_punch_mirror[i]);

			strcpy( Hero_kick[i] , Firzen_kick[i]);

			strcpy( Hero_kick_mirror[i] , Firzen_kick_mirror[i]);

			strcpy( Hero_jump[i] ,  Firzen_jump[i]);

			strcpy( Hero_jump_mirror[i] , Firzen_jump_mirror[i]);

			strcpy( Hero_power[i] , Firzen_power[i]);

			strcpy( Hero_power_mirror[i] , Firzen_power_mirror[i]);

			strcpy( Hero_laser[i] , Firzen_laser[i]);

			strcpy( Hero_laser_mirror[i] , Firzen_laser_mirror[i]);
		}

	if(hero_selector==2)

		for(int i =0 ; i<6 ;i++)
		{
			strcpy( Hero_thumb[i] , Bat_thumb[i]);

			strcpy( Hero_stand[i] , Bat_stand[i]);

			strcpy( Hero_stand_mirror[i] , Bat_stand_mirror[i]);

			strcpy( Hero_walk[i] , Bat_walk[i]);

			strcpy( Hero_walk_mirror[i] , Bat_walk_mirror[i]);

			strcpy( Hero_punch[i] , Bat_punch[i]);

			strcpy( Hero_punch_mirror[i] , Bat_punch_mirror[i]);

			strcpy( Hero_kick[i] , Bat_kick[i]);

			strcpy( Hero_kick_mirror[i] , Bat_kick_mirror[i]);

			strcpy( Hero_jump[i] ,  Bat_jump[i]);

			strcpy( Hero_jump_mirror[i] , Bat_jump_mirror[i]);

			strcpy( Hero_power[i] , Bat_power[i]);

			strcpy( Hero_power_mirror[i] , Bat_power_mirror[i]);

			strcpy( Hero_laser[i] , Bat_laser[i]);

			strcpy( Hero_laser_mirror[i] , Bat_laser_mirror[i]);
		}

}


//load all bandit images

char Bandit_stand[1][50] = { "Bandit\\Bandit_stand\\1.bmp" };

char Bandit_stand_mirror[1][50] = { "Bandit\\mirror\\Bandit_stand\\1.bmp" };

char Bandit_walk[4][50] = {"Bandit\\Bandit_walk\\1.bmp", "Bandit\\Bandit_walk\\2.bmp", "Bandit\\Bandit_walk\\3.bmp", "Bandit\\Bandit_walk\\4.bmp"};

char Bandit_walk_mirror[4][50] = {"Bandit\\mirror\\Bandit_walk\\1.bmp", "Bandit\\mirror\\Bandit_walk\\2.bmp", "Bandit\\mirror\\Bandit_walk\\3.bmp", "Bandit\\mirror\\Bandit_walk\\4.bmp"};

char Bandit_punch[4][50] = {"Bandit\\Bandit_punch\\1.bmp", "Bandit\\Bandit_punch\\2.bmp", "Bandit\\Bandit_punch\\3.bmp", "Bandit\\Bandit_punch\\4.bmp"};

char Bandit_punch_mirror[4][50] = {"Bandit\\mirror\\Bandit_punch\\1.bmp", "Bandit\\mirror\\Bandit_punch\\2.bmp", "Bandit\\mirror\\Bandit_punch\\3.bmp", "Bandit\\mirror\\Bandit_punch\\4.bmp"};


//load all julien images

char Julien_stand[1][50] = { "Julien\\Julien_stand\\1.bmp" };

char Julien_stand_mirror[1][50] = { "Julien\\mirror\\Julien_stand\\1.bmp" };

char Julien_walk[4][50] = { "Julien\\Julien_walk\\1.bmp" , "Julien\\Julien_walk\\2.bmp" , "Julien\\Julien_walk\\3.bmp" , "Julien\\Julien_walk\\4.bmp" } ;

char Julien_walk_mirror[4][50] = { "Julien\\mirror\\Julien_walk\\1.bmp" , "Julien\\mirror\\Julien_walk\\2.bmp" , "Julien\\mirror\\Julien_walk\\3.bmp" , "Julien\\mirror\\Julien_walk\\4.bmp" };

char Julien_punch[4][50] = { "Julien\\Julien_punch\\1.bmp" , "Julien\\Julien_punch\\2.bmp" , "Julien\\Julien_punch\\3.bmp" , "Julien\\Julien_punch\\4.bmp" };

char Julien_punch_mirror[4][50] =  { "Julien\\mirror\\Julien_punch\\1.bmp" , "Julien\\mirror\\Julien_punch\\2.bmp" , "Julien\\mirror\\Julien_punch\\3.bmp" , "Julien\\mirror\\Julien_punch\\4.bmp" };

char Julien_power[10][50] = { "Julien\\Julien_power\\1.bmp" , "Julien\\Julien_power\\2.bmp" , "Julien\\Julien_power\\3.bmp" , "Julien\\Julien_power\\4.bmp" , "Julien\\Julien_power\\5.bmp" , "Julien\\Julien_power\\6.bmp" , "Julien\\Julien_power\\7.bmp" , "Julien\\Julien_power\\8.bmp" , "Julien\\Julien_power\\9.bmp" , "Julien\\Julien_power\\10.bmp" };

char Julien_skull[1][50] = { "Julien\\Julien_skull\\1.bmp" };



//load all firen images

char Firen_stand[1][50] = { "Firen\\Firen_stand\\1.bmp"} ;

char Firen_stand_mirror[1][50] = { "Firen\\mirror\\Firen_stand\\1.bmp"} ;

char Firen_walk[4][50] = { "Firen\\Firen_walk\\1.bmp" , "Firen\\Firen_walk\\2.bmp" , "Firen\\Firen_walk\\3.bmp" , "Firen\\Firen_walk\\4.bmp" } ;

char Firen_walk_mirror[4][50] = { "Firen\\mirror\\Firen_walk\\1.bmp" , "Firen\\mirror\\Firen_walk\\2.bmp" , "Firen\\mirror\\Firen_walk\\3.bmp" , "Firen\\mirror\\Firen_walk\\4.bmp" };

char Firen_punch[4][50] = { "Firen\\Firen_punch\\1.bmp" , "Firen\\Firen_punch\\2.bmp" , "Firen\\Firen_punch\\3.bmp" , "Firen\\Firen_punch\\4.bmp" };

char Firen_punch_mirror[4][50] =  { "Firen\\mirror\\Firen_punch\\1.bmp" , "Firen\\mirror\\Firen_punch\\2.bmp" , "Firen\\mirror\\Firen_punch\\3.bmp" , "Firen\\mirror\\Firen_punch\\4.bmp" };

char Firen_power[10][50] = { "Firen\\Firen_power\\1.bmp" , "Firen\\Firen_power\\2.bmp" , "Firen\\Firen_power\\3.bmp" , "Firen\\Firen_power\\4.bmp" , "Firen\\Firen_power\\5.bmp" , "Firen\\Firen_power\\6.bmp" , "Firen\\Firen_power\\7.bmp" , "Firen\\Firen_power\\8.bmp" , "Firen\\Firen_power\\9.bmp" , "Firen\\Firen_power\\10.bmp" };

char Firen_arrow[1][50] = { "Firen\\Firen_arrow\\1.bmp" };



#endif  LOADEDPICTURES_H_INCLUDED
