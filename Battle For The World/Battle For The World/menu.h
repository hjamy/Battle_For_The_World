#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


# include <string.h>
# include "loadedPictures.h"
# include "hero.h"
# include "loadedPictures.h"
# include "allScore.h"

void highScore();
void instructions();
void saveGame();
void saveInFile();
void loadGame();
void loadFromFile();
void intro();


/*
this structure creates 3 slots...
but only 1 is used to initially store the data before the data 
is saved in a file

*/
struct gameSaveFile                   
{
	int hero;
	char playerName[100];
	int score;
	int level;
	int nameL;

}slot[3];

/* 

the three file pointer type variables that corresponds to the three files
where the game can be saved....giving the game 3 slots to use altogether
 
*/

FILE *s1 , *s2 , *s3;              

int mode = 12;                     //mode variable indicates which game-state the game is currently in             
char holdHighScore[100];		   //this variable is used to hold highscore while converting it to char from int value with itoa() function

int move_save = 0;                 //this variable is used to move the save score cursor up and down in the save score menu  and the load game menu
                                   //this is controlled through iKeyborad(up and down button)

int temp_level;                    //as the 'level' variable cannot be directly accesseed ...the 'temp_level' was used
                                   //which holds the 'level' variables value from iMain.cpp

int intro_page = 1;                // this is used to change page while in mode=12 (intro)..value chanes through SPACE in iKeyboard




/*
The highScore() function is accessed when user clicks and changes mode value to mode =5.
Here , a image will load..
After that top 10 previous highscores will load and be saved in the 'saveScoreFile' structure.
Then on top of the image loaded previously the values and names will be printed on the screen.
The highscores will already be saved in descending order in the file.
So the values will be printed accordingly.
Special designing codes were also used to make it more aesthetic

*/


void highScore()
{
	iShowBMP(0,0,"menu images\\High Scores\\highscores.bmp");

	iSetColor(251,160,38);

	iText(435,520, "Name ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(650,520, "Score ",GLUT_BITMAP_TIMES_ROMAN_24);

	accessSaveFile = fopen("High Score.txt","r");

	for(int i = 0 ; i < 10 ; i ++)
	{
		fscanf(accessSaveFile , "%s %d" , &ssf[i].playerName  , &ssf[i].playerScore);
	}


	fclose(accessSaveFile);

	iSetColor(225,220,30);

	iText( 440 , 450  , "1. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 410  , "2. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 370  , "3. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 330  , "4. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 290  , "5. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 250  , "6. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 210  , "7. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 170  , "8. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 440 , 130  , "9. " , GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 430 , 90  , "10. " , GLUT_BITMAP_TIMES_ROMAN_24 );

	iSetColor(53,204,236);

	for(int i = 0 ; i < 10 ; i++)
	{
		
		

		iText( 470 , 450 - i *40 , ssf[i].playerName , GLUT_BITMAP_TIMES_ROMAN_24 );

		itoa(ssf[i].playerScore , holdHighScore , 10);
		iText( 650 , 450 - i *40 , holdHighScore , GLUT_BITMAP_TIMES_ROMAN_24 );

	}
	
}

/*
The instruction() function is called when mode value is changed through click to mode=4.
this function just shows the instruction holding image file.
pressing Esc will take back to mode= 1(main menu)
*/

void instructions()
{
	iShowBMP(0,0,"menu images\\Instructions\\Instructions.bmp");
	
}

/*
the saveGame() function is called when the next stage window(mode=9) appears ans 's' is pressed.
this function shows a window which holds three slots to save the game in.The slots can be accessed through 
the up and down arrow key and then ENTER.
pressing ENTER while any slot is selected will save the game values in that slot file
for example selecting 'slot 1' will save the game in 'slot 1.txt.'

*/
void saveGame()
{
	iSetColor(0,0,0);
	iFilledRectangle(0,0,800,600);
	iShowBMP(0,0,"SL screen\\1.bmp");

	iSetColor(57 , 129 , 206);
	iFilledRectangle(200,375,400,50);
	iFilledRectangle(200,275,400,50);
	iFilledRectangle(200,175,400,50);

	if(move_save==1)
		iSetColor(236,173,28);
	else
		iSetColor(28,205,236);
	iFilledRectangle(210,385,380,30);


	if(move_save==2)
		iSetColor(236,173,28);
	else
		iSetColor(28,205,236);
	iFilledRectangle(210,285,380,30);


	if(move_save==3)
		iSetColor(236,173,28);
	else
		iSetColor(28,205,236);
	iFilledRectangle(210,185,380,30);

	iSetColor(0,0,0);
	iText(350,390, " SLOT 1 ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350,290, " SLOT 2 ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350,190, " SLOT 3 ",GLUT_BITMAP_TIMES_ROMAN_24);


}

/*
The SaveInFile() is called when ENTER is pressed in any slot in mode=10(save game window).
This function takes the in game values that is required to be saved and stores them in 
a structure called 'slot'.
Then these values are saved in a file (slot 1.txt , slot 2.txt , slot 3.txt )
according to the file that was selected through the 'move_save' variable

*/

void saveInFile()
{

	slot[0].hero = hero_selector;
	strcpy(slot[0].playerName , name);
	slot[0].score = score ; 
	slot[0].level = temp_level ;
	slot[0].nameL = nameL ;

	if(move_save==1)
	{

		s1 = fopen("slot 1.txt", "w");

		fprintf(s1 , "%s\t%d\t%d\t%d\t%d" , slot[0].playerName  , slot[0].hero , slot[0].score , slot[0].level , slot[0].nameL );
		
	
		fclose(s1);

	}

	if(move_save==2)
	{
		s2 = fopen("slot 2.txt", "w");

		fprintf(s2 , "%s\t%d\t%d\t%d\t%d" , slot[0].playerName  , slot[0].hero , slot[0].score , slot[0].level , slot[0].nameL );
		
	
		fclose(s2);
	}

	if(move_save==3)
	{
		s3 = fopen("slot 3.txt", "w");

		fprintf(s3 , "%s\t%d\t%d\t%d\t%d" , slot[0].playerName  , slot[0].hero , slot[0].score , slot[0].level , slot[0].nameL );
		
	
		fclose(s3);
	}
}


/*
The loadGame() function is called when the user is in mode=1(main menu) and presses to enter mode=3(load game).
here three slots are shows indicating the three save game files.These can be selected with the up and down arrow keys and accessed
by pressing ENTER.When ENTER is pressed the loadFromFile() function will be called
*/

void loadGame()
{
	iSetColor(0,0,0);
	iFilledRectangle(0,0,800,600);
	iShowBMP(0,0,"SL screen\\2.bmp");

	iSetColor(57 , 129 , 206);
	iFilledRectangle(200,375,400,50);
	iFilledRectangle(200,275,400,50);
	iFilledRectangle(200,175,400,50);

	if(move_save==1)
		iSetColor(236,173,28);
	else
		iSetColor(28,205,236);
	iFilledRectangle(210,385,380,30);


	if(move_save==2)
		iSetColor(236,173,28);
	else
		iSetColor(28,205,236);
	iFilledRectangle(210,285,380,30);


	if(move_save==3)
		iSetColor(236,173,28);
	else
		iSetColor(28,205,236);
	iFilledRectangle(210,185,380,30);

	iSetColor(0,0,0);
	iText(350,390, " SLOT 1 ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350,290, " SLOT 2 ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350,190, " SLOT 3 ",GLUT_BITMAP_TIMES_ROMAN_24);
}

/*
In loadFromFile() function the function reads from the file that is directed and 
stores the data in structure called 'slot'.
Then the values are restored to the in game values which allows theplayer to resume from their saved position with their previous achievments.
*/

void loadFromFile()
{

	if(move_save==1)
	{

		s1 = fopen("slot 1.txt", "r");

		fscanf(s1 , "%s %d %d %d %d" , &slot[0].playerName  , &slot[0].hero , &slot[0].score , &slot[0].level , &slot[0].nameL );
		
	
		fclose(s1);

	}

	if(move_save==2)
	{
		s2 = fopen("slot 2.txt", "r");

		fscanf(s2 , "%s %d %d %d %d" , &slot[0].playerName  , &slot[0].hero , &slot[0].score , &slot[0].level , &slot[0].nameL );
		
	
		fclose(s2);
	}

	if(move_save==3)
	{
		s3 = fopen("slot 3.txt", "r");

		fscanf(s3 , "%s %d %d %d %d" , &slot[0].playerName  , &slot[0].hero , &slot[0].score , &slot[0].level , &slot[0].nameL );
		
	
		fclose(s3);
	}


	hero_selector = slot[0].hero;
	strcpy(name , slot[0].playerName);
	score = slot[0].score;
	temp_level = slot[0].level;
	nameL = slot[0].nameL;

}

/*

The intro() function responds when mode value is mode=12.
It holds three pages that is accessed by changing the 'intro_page' variable through SPACE.
When intro_page value becomes greater than 3 then it changes mode to mode=1 and shows the main menu

*/

void intro()
{
	if(intro_page==1)
		iShowBMP(0,0,"Intro\\1.bmp");

	if(intro_page==2)
		iShowBMP(0,0,"Intro\\2.bmp");

	if(intro_page==3)
		iShowBMP(0,0,"Intro\\3.bmp");

}


#endif // MENU_H_INCLUDED
