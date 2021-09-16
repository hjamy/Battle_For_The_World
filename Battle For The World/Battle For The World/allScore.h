#ifndef ALLSCORE_H_INCLUDED
#define ALLSCORE_H_INCLUDED


void takePlayerName();
void onScreen_score_and_name();
void saveScore();

int score = 0 ;               //this variable changes when hero hits enemy...
				              //usage can be found in hero_bandit_collision()

char score_string[20];        //variable that holds the score's string value to print on the sceen in game

char name[100];               //used to store player name
int nameL;                    //used to store name character in each array cell

/*
used to store the all the player name and score including hthe latest score..
*/

struct saveScoreFile         
{
	char playerName[100];
	int playerScore;
}ssf[11];

FILE *accessSaveFile;
char tempName[100];
int tempScore;





/*
this function just shows the content of the mode 11.
only the picture showing system is shown here..the rest is
fully dependant on input..so it can be found in the iKeyboard method in iMain.cpp
 
*/
void takePlayerName()
{
	iClear();
	iShowBMP( 0 , 0 ,"Name Enter\\1.bmp");
	iSetColor(255,255,255);

	iRectangle(105,290,500,75);

	iText(115,320, name ,GLUT_BITMAP_TIMES_ROMAN_24);
}


/*
funtion to show the player score while the player is in game
*/

void onScreen_score_and_name()
{
	iSetColor(255 , 255 , 255);
	iText(610, 560, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);

	itoa(score , score_string , 10);
	iText(610, 530, score_string, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(400 , 560 , "Name:", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(400 , 530 , name , GLUT_BITMAP_TIMES_ROMAN_24);


}

/*
this function , when called, reads the top 10 scores from thee high score file and then
compares with the latest score and sorts t in descendinf order..
when done it opens the file in write mode and writes the 10 scores in the file again replacing any previous content
*/

void saveScore()
{
	accessSaveFile = fopen("High Score.txt","r");

	for(int i = 0 ; i < 10 ; i ++)
	{
		fscanf(accessSaveFile , "%s %d" , &ssf[i].playerName  , &ssf[i].playerScore);
	}

	fclose(accessSaveFile);

	for (int i = 0 ; i<10 ; i++)
		for(int j = 10 ; j>i ; j--)
		{
			if( ssf[j].playerScore > ssf[j-1].playerScore )
			{
				tempScore = ssf[j-1].playerScore;
				ssf[j-1].playerScore = ssf[j].playerScore;
				ssf[j].playerScore = tempScore;

				strcpy( tempName , ssf[j-1].playerName);
				strcpy( ssf[j-1].playerName , ssf[j].playerName);
				strcpy( ssf[j].playerName , tempName);
			}
		}
		

	accessSaveFile = fopen("High Score.txt", "w");

	for(int i = 0; i<10 ; i++)
	{
		fprintf(accessSaveFile , "%s\t%d\r\n" , ssf[i].playerName  , ssf[i].playerScore);
	}

	fclose(accessSaveFile);


}

#endif // ALLSCORE_H_INCLUDED
