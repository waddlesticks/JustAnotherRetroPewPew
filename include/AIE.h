/**
*	@author	Jamie Stewart
*	@date	12/11/2012
*	@brief	This is the main entry point for access to the functionality provided by the 
*			AIE Static OpenGL Framework. This class needs to be included in your main.cpp
*			in order to get a simple 2d sprite game up and running.
**/

#ifndef _AIE_H_

#define _AIE_H_

/** 
* DLL Export Define
**/
#ifdef AIE_DLL_BUILD
#define DLLEXPORT __declspec(dllexport)
#elif AIE_DLL
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT 
#endif
/**
*
* @brief Enumerator to Describe Sprite Blend Modes
*
**/
typedef enum SpriteBlendModes

{
	_ZERO					= 0,			// = GL_ZERO
	_ONE					= 1,			// = GL_ONE
	_SRC_COLOR				= 0x0300,		// = GL_SRC_colour
	_DST_COLOR				= 0x0306,		// = GL_DST_colour
	_ONE_MINUS_SRC_COLOR	= 0x0301,		// = GL_ONE_MINUS_SRC_colour
	_ONE_MINUS_DST_COLOR	= 0x0307,		// = GL_ONE_MINUS_DST_colour
	_SRC_ALPHA				= 0x0302,		// = GL_SRC_ALPHA
	_DST_ALPHA				= 0x0304,		// = GL_DST_ALPHA
	_ONE_MINUS_SRC_ALPHA	= 0x0303,		// = GL_ONE_MINUS_SRC_ALPHA
	_ONE_MINUS_DST_ALPHA	= 0x0305,		// = GL_ONE_MINUS_DST_ALPHA
	_BLEND_END

}SpriteBlendModes;

/**
* @brief Enumerator to Describe camera Movement Directions
**/
typedef enum CameraDirection
{

	eC_UP	= 0x0001, 
	eC_DOWN	= 0x0010,
	eC_LEFT	= 0x0100,
	eC_RIGHT= 0x1000,
	eC_END	= 0

}CameraDirection;
/**
* @brief enumerator to define Key and Mouse button values
**/
typedef enum
{
	/* The unknown key */
	KEY_UNKNOWN           = -1 ,
	KEY_SPACE             = 32 ,
	KEY_APOSTROPHE        = 39 , /* ' */
	KEY_COMMA             = 44 , /* , */
	KEY_MINUS             = 45 , /* - */
	KEY_PERIOD            = 46 , /* . */
	KEY_SLASH             = 47 , /* / */
	KEY_0                 = 48 ,
	KEY_1                 = 49 ,
	KEY_2                 = 50 ,
	KEY_3                 = 51 ,
	KEY_4                 = 52 ,
	KEY_5                 = 53 ,
	KEY_6                 = 54 ,
	KEY_7                 = 55 ,
	KEY_8                 = 56 ,
	KEY_9                 = 57 ,
	KEY_SEMICOLON         = 59 , /* ; */
	KEY_EQUAL             = 61 , /* = */
	KEY_A                 = 65 ,
	KEY_B                 = 66 ,
	KEY_C                 = 67 ,
	KEY_D                 = 68 ,
	KEY_E                 = 69 ,
	KEY_F                 = 70 ,
	KEY_G                 = 71 ,
	KEY_H                 = 72 ,
	KEY_I                 = 73 ,
	KEY_J                 = 74 ,
	KEY_K                 = 75 ,
	KEY_L                 = 76 ,
	KEY_M                 = 77 ,
	KEY_N                 = 78 ,
	KEY_O                 = 79 ,
	KEY_P                 = 80 ,
	KEY_Q                 = 81 ,
	KEY_R                 = 82 ,
	KEY_S                 = 83 ,
	KEY_T                 = 84 ,
	KEY_U                 = 85 ,
	KEY_V                 = 86 ,
	KEY_W                 = 87 ,
	KEY_X                 = 88 ,
	KEY_Y                 = 89 ,
	KEY_Z                 = 90 ,
	KEY_LEFT_BRACKET      = 91 , /* [ */
	KEY_BACKSLASH         = 92 , /* \ */
	KEY_RIGHT_BRACKET     = 93 , /* ] */
	KEY_GRAVE_ACCENT      = 96 , /* ` */
	KEY_WORLD_1           = 161, /* non-US #1 */
	KEY_WORLD_2           = 162, /* non-US #2 */
	KEY_ESCAPE            = 256,
	KEY_ENTER             = 257,
	KEY_TAB               = 258,
	KEY_BACKSPACE         = 259,
	KEY_INSERT            = 260,
	KEY_DELETE            = 261,
	KEY_RIGHT             = 262,
	KEY_LEFT              = 263,
	KEY_DOWN              = 264,
	KEY_UP                = 265,
	KEY_PAGE_UP           = 266,
	KEY_PAGE_DOWN         = 267,
	KEY_HOME              = 268,
	KEY_END               = 269,
	KEY_CAPS_LOCK         = 280,
	KEY_SCROLL_LOCK       = 281,
	KEY_NUM_LOCK          = 282,
	KEY_PRINT_SCREEN      = 283,
	KEY_PAUSE             = 284,
	KEY_F1                = 290,
	KEY_F2                = 291,
	KEY_F3                = 292,
	KEY_F4                = 293,
	KEY_F5                = 294,
	KEY_F6                = 295,
	KEY_F7                = 296,
	KEY_F8                = 297,
	KEY_F9                = 298,
	KEY_F10               = 299,
	KEY_F11               = 300,
	KEY_F12               = 301,
	KEY_F13               = 302,
	KEY_F14               = 303,
	KEY_F15               = 304,
	KEY_F16               = 305,
	KEY_F17               = 306,
	KEY_F18               = 307,
	KEY_F19               = 308,
	KEY_F20               = 309,
	KEY_F21               = 310,
	KEY_F22               = 311,
	KEY_F23               = 312,
	KEY_F24               = 313,
	KEY_F25               = 314,
	KEY_KP_0              = 320,
	KEY_KP_1              = 321,
	KEY_KP_2              = 322,
	KEY_KP_3              = 323,
	KEY_KP_4              = 324,
	KEY_KP_5              = 325,
	KEY_KP_6              = 326,
	KEY_KP_7              = 327,
	KEY_KP_8              = 328,
	KEY_KP_9              = 329,
	KEY_KP_DECIMAL        = 330,
	KEY_KP_DIVIDE         = 331,
	KEY_KP_MULTIPLY       = 332,
	KEY_KP_SUBTRACT       = 333,
	KEY_KP_ADD            = 334,
	KEY_KP_ENTER          = 335,
	KEY_KP_EQUAL          = 336,
	KEY_LEFT_SHIFT        = 340,
	KEY_LEFT_CONTROL      = 341,
	KEY_LEFT_ALT          = 342,
	KEY_LEFT_SUPER        = 343,
	KEY_RIGHT_SHIFT       = 344,
	KEY_RIGHT_CONTROL     = 345,
	KEY_RIGHT_ALT         = 346,
	KEY_RIGHT_SUPER       = 347,
	KEY_MENU              = 348,
	KEY_LAST              = KEY_MENU
};

/**
* @brief A Structure to describe a colour value as an unsigned int, and as individual 8 bit components (char values)
**/
struct SColour
{
	/// @brief Default constructor for a SColour object
	SColour() {}
	/// @brief Constructor for an SColour obejct that constructs the SColour object from an unsigned integer value
	/// @param a_iColor the colour that the SColour will be created to specify
	SColour(unsigned int a_iColour) {argb.colour = a_iColour;}
	/// @brief Constructor to create an SColor object from four char values RGBA
	/// @param r unsigned char to represent the red component of an SColour object
	/// @param g unsigned char to represent the red component of an SColour object
	/// @param b unsigned char to represent the red component of an SColour object
	/// @param a unsigned char to represent the red component of an SColour object
	SColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		argb.colours.r = r;
		argb.colours.g = g;
		argb.colours.b = b;
		argb.colours.a = a;
	}
	/// and unnamed union that causes SColours member variables to use the same area of memory.
	/// this means that @param colour and @param colours occupy the same space, a change to one is 
	/// reflected in the other.
	union
	{
		unsigned int colour;
		struct SColours
		{
			unsigned char a, r, g, b;
		} colours;
	}argb;

};

//////////////////////////////////////////////////////////////////////////
/// @brief Call this function to initialise the framework 
/// @param a_iWidth the width in pixels that we want the screen to display for the width of the window
/// @param a_height the width in pixels that we want the screen to display for the height of the window
/// @param a_bFullscreen should this application run in a fullscreen mode.
/// @param a_pWIndowTitle the title that we want to be displayed in the windows title bar
//////////////////////////////////////////////////////////////////////////
DLLEXPORT int			Initialise( int a_iWidth, int a_iHeight, bool a_bFullscreen = false, const char* a_pWindowTitle = nullptr );
//////////////////////////////////////////////////////////////////////////
/// @brief This function should be called just prior to exiting your program
///			 it will unload all the components of the AIE Framework that have been loaded
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			Shutdown();
//////////////////////////////////////////////////////////////////////////
/// @brief This function is to be called each frame to update the current frame. 
/// @return a boolean value indicating that the framework updated successfully
//////////////////////////////////////////////////////////////////////////
DLLEXPORT bool			FrameworkUpdate();
//////////////////////////////////////////////////////////////////////////
/// @brief Call this function to clear any content that has been rendered to the screen 
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			ClearScreen();
//////////////////////////////////////////////////////////////////////////
/// @brief Call this function to Set the background colour
/// @param a_BGColour the colour to set the background scene to
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			SetBackgroundColour( SColour a_BGColour );
/// Function to create a Sprite
/// @param a_pTextureName - the name of the texture that the sprite image resides in
/// @param a_fWidth - the width that the sprite object is to be draw on the screen, this width is in pixels
/// @param a_fHeight - the height that the sprite object is to be draw on the screen, this height is in pixels
/// @param a_bDrawFromCenter - weather or not the sprite is to be drawn from the center position, defaults to true
/// @param a_sColour - the colour tint that the sprite is to be given, defaults to white.
/// @return the ID for the sprite, this is an unsigned integer.
DLLEXPORT unsigned int	CreateSprite			( const char* a_pTextureName, int a_iWidth, int a_iHeight, bool a_bDrawFromCenter, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );
/// Function to create a Sprite
/// @param a_pTextureName - the name of the texture that the sprite image resides in
/// @param a_fv2Size - the width and height of the sprite in Pixels as a float vector
/// @param a_fv2Origin - The origin position for the sprite matrix, this dictates where the sprite will be drawn from (Top Left, Top Right etc)
/// @param a_v4UVCoords - The UV Coordinates for the sprite as a float 4, components  1 & 2 correspond to origin point, components 3 & 4 correspond to end point.
/// @param a_sColour - the colour tint that the sprite is to be given, defaults to white.
/// @return the ID for the sprite, this is an unsigned integer.
DLLEXPORT unsigned int	CreateSprite			( const char* a_pTextureName, float* a_fv2Size, float* a_fv2Origin, float* a_fv4UVCoords = nullptr, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );
/// Function to Duplicate an existing Sprite
/// @param a_uiSpriteID This is ID of the sprite that is to be duplicated
/// @return Returns a new sprite ID.
DLLEXPORT unsigned int	DuplicateSprite			( unsigned int a_uiSpriteID );
/// This function is used to free up the memory associated with the Sprite ID passed in. After this function is called the sprite can no longer be drawn as it ceases to exist
/// @param a_uiSpriteID the ID of the sprite to be destroyed.
DLLEXPORT void			DestroySprite			( unsigned int a_uiSpriteID );


DLLEXPORT void			SetSpriteColour			( unsigned int a_uiSpriteID, SColour& a_sColour );

DLLEXPORT void			GetSpriteColour			( unsigned int a_uiSpriteID, SColour& a_sColour );
/// This funciton moves a Sprite
/// @param a_uiSpriteID the ID of the sprite to be moved
/// @param a_fXPos the X co-ordinate that the sprite is to be moved to in screenspace
/// @param a_fYPos the Y co-ordinate that the sprite is to be moved to in screenspace
DLLEXPORT void			MoveSprite				( unsigned int a_uiSpriteID, float a_fXPos, float a_fYPos );
/// This funciton moves a Sprite
/// @param a_uiSpriteID the ID of the sprite to be moved
/// @param a_fVec a float vector that contains two values (X & Y) to relocate the sprite to
DLLEXPORT void			MoveSprite				( unsigned int a_uiSpriteID, float* a_vFloatVec );
/// @brief This function sets the 4x4 matrix for the sprite
/// @param a_uiSpriteID the unique identifier for the sprite
/// @param a_fm4 a float pointer indicating the start of a float array containing 16 values representing a 4 x 4 matrix
DLLEXPORT void			SetSpriteMatrix			( unsigned int a_uiSpriteID, float* a_fm4 );
/// @brief This function gets the 4x4 matrix for the sprite
/// @param a_uiSpriteID the unique identifier for the sprite
/// @param a_fm4 a float pointer indicating the start of a float array that is to be used to hold the 16 float values representing a 4 x 4 matrix
DLLEXPORT void			GetSpriteMatrix			( unsigned int a_uiSpriteID, float* a_fm4 );
DLLEXPORT void			RotateSprite			( unsigned int a_uiSpriteID, float a_fRotation );



DLLEXPORT void			DrawSprite				( unsigned int a_uiSpriteID );

DLLEXPORT void			SetSpriteUVCoordinates	( unsigned int a_uiSpriteID, float a_minUCoord, float a_minVCoord, float a_maxUCoord, float a_maxVCoord );

DLLEXPORT void			SetSpriteUVCoordinates	( unsigned int a_uiSpriteID, float* a_fUVVec4 );

DLLEXPORT void			GetSpriteUVCoordinates	( unsigned int a_uiSpriteID, float& a_minUCoord, float& a_minVCoord, float& a_maxUCoord, float& a_maxVCoord );

DLLEXPORT void			GetSpriteUVCoordinates	( unsigned int a_uiSpriteID, float* a_fUVVec4 );

DLLEXPORT void			SetSpriteScale			( unsigned int a_uiSpriteID, float& a_fSpriteWidth, float& a_fSpriteHeight );

DLLEXPORT void			GetSpriteScale			( unsigned int a_uiSpriteID, float& a_fSpriteWidth, float& a_fSpriteHeight );

DLLEXPORT void			SetSpriteBlendMode		( unsigned int a_uiSpriteID, const unsigned int& a_uiSourceFactor, const unsigned int& a_uiDestinationFactor );

DLLEXPORT void			GetSpriteBlendMode		( unsigned int a_uiSpriteID, unsigned int& a_uiSourceFactor, unsigned int& a_uiDestinationFactor );

//////////////////////////////////////////////////////////////////////////

// Basic Line Drawing Functionality

//////////////////////////////////////////////////////////////////////////

DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY );

DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY, SColour a_sColour );

DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY, SColour a_sStartColour, SColour a_sEndColour );



//////////////////////////////////////////////////////////////////////////

// Draws a String to the screen

//////////////////////////////////////////////////////////////////////////

DLLEXPORT void			DrawString( const char* a_pText, int a_iXPos, int a_iYPos, float fSize = 1.f, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF));
DLLEXPORT void			AddFont( const char* a_pFontName );
DLLEXPORT void			SetFont( const char* a_pFontName );
DLLEXPORT void			RemoveFont( const char* a_pFontName );

//////////////////////////////////////////////////////////////////////////

// Input Handling Functionality

//////////////////////////////////////////////////////////////////////////

DLLEXPORT bool			IsKeyDown( int a_iKey );

DLLEXPORT void			GetMouseLocation( double& a_iMouseX, double& a_iMouseY );

DLLEXPORT bool			GetMouseButtonDown( int a_iMouseButtonToTest );

DLLEXPORT bool			GetMouseButtonReleased( int a_iMouseButtonToTest );

//////////////////////////////////////////////////////////////////////////

// Basic Camera Control

//////////////////////////////////////////////////////////////////////////

DLLEXPORT void			MoveCamera	( CameraDirection a_eCameraDirection, float a_fCameraSpeed );

DLLEXPORT void			MoveCamera  ( float a_fXPos, float a_fYPos );

DLLEXPORT void			RotateCamera( float a_fRotation );

DLLEXPORT void			GetCameraPosition( float& a_fx, float& a_fy );

//////////////////////////////////////////////////////////////////////////

// Gets the Delta Time

//////////////////////////////////////////////////////////////////////////

DLLEXPORT float 		GetDeltaTime();

//////////////////////////////////////////////////////////////////////////

#endif //_AIE_H_

//////////////////////////////////////////////////////////////////////////

