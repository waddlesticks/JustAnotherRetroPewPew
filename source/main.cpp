//////////////////////////////////////////////////////////// 
// File: <main.cpp> 
// Author: <Elijah Wardle> 
// Date Created: <18/03/2014> 
// Brief: <description of the purpose of the file> 
//////////////////////////////////////////////////////////// 

#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#if !defined(OSX)
	#include <crtdbg.h>
#endif
#include <iostream>
#include <list>
#include <string>
#include "Player.h"

typedef enum eGAMESTATES
{
	eSplash,
	eMAIN_MENU,
	eLoading,
	eGAMEPLAY,
	eHIGH_SCORE,
	eEND,
}GameStates;

void UpdateMainMenu();
void UpdateGameState();

const int iScreenWidth = 672;
const int iScreenHeight = 780;

unsigned int iPlayer;


int main( int argc, char* argv[] )
{	

	Initialise( iScreenWidth, iScreenHeight, false, "Just Another Retro Pew Pew" );
	SetBackgroundColour( SColour( 000, 000, 000, 000 ) );

//	player.SetSpriteID(CreateSprite( "./images/player.png", player.GetWidth(), player.GetHeight(), true));

	GameStates eCurrentState = eMAIN_MENU;

	do 
	{
		ClearScreen();
		float fDeltaT = GetDeltaTime();
		switch (eCurrentState)
		{
	case eMAIN_MENU:
		UpdateMainMenu();
			if( IsKeyDown( KEY_ENTER) )
			{
				eCurrentState = eGAMEPLAY;
				
			
			}
			break;
	case eGAMEPLAY:
		UpdateGameState();
		if( IsKeyDown( KEY_ESCAPE) )
			{
				eCurrentState = eMAIN_MENU;

			}

		break;
	default:
		break;
		}
			
	} while ( FrameworkUpdate() == false );

	Shutdown();

	return 0;
}


void UpdateMainMenu()
{
	SetBackgroundColour( SColour( 000, 000, 000, 000 ) );
}

void UpdateGameState()
{
	SetBackgroundColour( SColour( 7, 73, 255, 254 ) );
}