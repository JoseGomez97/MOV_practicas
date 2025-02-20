/**	Definition of the class keyboard
*	@file: UGKKeyboard.h
*	Prefix: CK_

*	@version 2016
*/

#ifndef CK_KEYBOARD //Se borra la macro del teclado
#define CK_KEYBOARD //Se define la macro del teclado
// Se define macro para librerias de windows
#ifndef WINDOWS_LOADED
#define WINDOWS_LOADED
#include <windows.h>
#endif

#include <list>
#include <map>
#include <UGKHardware.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_scancode.h>

//#define CK_NO_ACTION	0	//No action is performed. 8 bits
#define CK_ACTION			unsigned char
#define CK_CHARACTER		UGKS_String

#define CK_ACTIVE_ACTION	std::list<CK_ACTION>


//All possible control inputs, non standard ASCII codes redefined. See WinUser.h for more information when in windows O.S.
//This enum is deprecated, the SDL one should be used instead.
typedef enum
{
	//Mouse buttons
	CK_MOUSE_LBUTTON,		//Left button
	CK_MOUSE_RBUTTON,		//Right Button 
	CK_MOUSE_CANCEL,		//Cancel Button
	CK_MOUSE_MBUTTON,		//Middle Button

	//Control keys
	CK_KB_BACK,
	CK_KB_TAB,
	CK_KB_ESCAPE,
	CK_KB_SPACE,
	CK_KB_PRIOR,
	CK_KB_NEXT,
	CK_KB_END,
	CK_KB_HOME,
	CK_KB_LEFT,
	CK_KB_UP,
	CK_KB_RIGHT,
	CK_KB_DOWN,
	CK_KB_SELECT,
	CK_KB_PRINT,
	CK_KB_EXECUTE,
	CK_KB_SNAPSHOT,
	CK_KB_INSERT,
	CK_KB_DELETE,
	CK_KB_HELP,
	CK_KB_SLEEP,

	//Numeric Pad
	CK_KB_NUMPAD0,
	CK_KB_NUMPAD1,
	CK_KB_NUMPAD2,
	CK_KB_NUMPAD3,
	CK_KB_NUMPAD4,
	CK_KB_NUMPAD5,
	CK_KB_NUMPAD6,
	CK_KB_NUMPAD7,
	CK_KB_NUMPAD8,
	CK_KB_NUMPAD9,
	CK_KB_MULTIPLY,
	CK_KB_ADD,
	CK_KB_SEPARATOR,
	CK_KB_SUBTRACT,
	CK_KB_DECIMAL,
	CK_KB_DIVIDE,
	CK_KB_F1,
	CK_KB_F2,
	CK_KB_F3,
	CK_KB_F4,
	CK_KB_F5,
	CK_KB_F6,
	CK_KB_F7,
	CK_KB_F8,
	CK_KB_F9,
	CK_KB_F10,
	CK_KB_F11,
	CK_KB_F12,
	CK_KB_F13,
	CK_KB_F14,
	CK_KB_F15,
	CK_KB_F16,
	CK_KB_F17,
	CK_KB_F18,
	CK_KB_F19,
	CK_KB_F20,
	CK_KB_F21,
	CK_KB_F22,
	CK_KB_F23,
	CK_KB_F24,

	CK_KB_NUMLOCK,
	CK_KB_SCROLL,
	CK_KB_LSHIFT,
	CK_KB_RSHIFT,
	CK_KB_LCONTROL,
	CK_KB_RCONTROL,
	CK_KB_LMENU,
	CK_KB_RMENU,
	CK_KB_BROWSER_BACK,
	CK_KB_BROWSER_FORWARD,
	CK_KB_BROWSER_REFRESH,
	CK_KB_BROWSER_STOP,
	CK_KB_BROWSER_SEARCH,
	CK_KB_BROWSER_FAVORITES,
	CK_KB_BROWSER_HOME,

	CK_KB_VOLUME_MUTE,
	CK_KB_VOLUME_DOWN,
	CK_KB_VOLUME_UP,
	CK_KB_MEDIA_NEXT_TRACK,
	CK_KB_MEDIA_PREV_TRACK,
	CK_KB_MEDIA_STOP,
	CK_KB_MEDIA_PLAY_PAUSE,
	CK_KB_LAUNCH_MAIL,
	CK_KB_LAUNCH_MEDIA_SELECT,
	CK_KB_LAUNCH_APP1,
	CK_KB_LAUNCH_APP2,

	CK_KB_GAMEPAD_A,
	CK_KB_GAMEPAD_B,
	CK_KB_GAMEPAD_X,
	CK_KB_GAMEPAD_Y,
	CK_KB_GAMEPAD_RIGHT_SHOULDER,
	CK_KB_GAMEPAD_LEFT_SHOULDER,
	CK_KB_GAMEPAD_LEFT_TRIGGER,
	CK_KB_GAMEPAD_RIGHT_TRIGGER,
	CK_KB_GAMEPAD_DPAD_UP,
	CK_KB_GAMEPAD_DPAD_DOWN,
	CK_KB_GAMEPAD_DPAD_LEFT,
	CK_KB_GAMEPAD_DPAD_RIGHT,
	CK_KB_GAMEPAD_MENU,
	CK_KB_GAMEPAD_VIEW,
	CK_KB_GAMEPAD_LEFT_THUMBSTICK_BUTTON,
	CK_KB_GAMEPAD_RIGHT_THUMBSTICK_BUTTON,
	CK_KB_GAMEPAD_LEFT_THUMBSTICK_UP,
	CK_KB_GAMEPAD_LEFT_THUMBSTICK_DOWN,
	CK_KB_GAMEPAD_LEFT_THUMBSTICK_RIGHT,
	CK_KB_GAMEPAD_LEFT_THUMBSTICK_LEFT,
	CK_KB_GAMEPAD_RIGHT_THUMBSTICK_UP,
	CK_KB_GAMEPAD_RIGHT_THUMBSTICK_DOWN,
	CK_KB_GAMEPAD_RIGHT_THUMBSTICK_RIGHT,
	CK_KB_GAMEPAD_RIGHT_THUMBSTICK_LEFT,
	CK_KB_MAX_CTROL_INPUTS
}CK_CTRL_INPUTS;


typedef enum {
	UGK_KB_0,
	UGK_KB_1,
	UGK_KB_2,
	UGK_KB_3,
	UGK_KB_4,
	UGK_KB_5,
	UGK_KB_6,
	UGK_KB_7,
	UGK_KB_8,
	UGK_KB_9,

	UGK_KB_a,
	UGK_KB_AC_BACK,
	UGK_KB_AC_BOOKMARKS,
	UGK_KB_AC_FORWARD,
	UGK_KB_AC_HOME,
	UGK_KB_AC_REFRESH,
	UGK_KB_AC_SEARCH,
	UGK_KB_AC_STOP,
	UGK_KB_AGAIN,
	UGK_KB_ALTERASE,
	UGK_KB_QUOTE,
	UGK_KB_APPLICATION,
	UGK_KB_AUDIOMUTE,
	UGK_KB_AUDIONEXT,
	UGK_KB_AUDIOPLAY,
	UGK_KB_AUDIOPREV,
	UGK_KB_AUDIOSTOP,

	UGK_KB_b,
	UGK_KB_BACKSLASH,
	UGK_KB_BACKSPACE,
	UGK_KB_BRIGHTNESSDOWN,
	UGK_KB_BRIGHTNESSUP,

	UGK_KB_c,
	UGK_KB_CALCULATOR,
	UGK_KB_CANCEL,
	UGK_KB_CAPSLOCK,
	UGK_KB_CLEAR,
	UGK_KB_CLEARAGAIN,
	UGK_KB_COMMA,
	UGK_KB_COMPUTER,
	UGK_KB_COPY,
	UGK_KB_CRSEL,
	UGK_KB_CURRENCYSUBUNIT,
	UGK_KB_CURRENCYUNIT,
	UGK_KB_CUT,

	UGK_KB_d,
	UGK_KB_DECIMALSEPARATOR,
	UGK_KB_DELETE,
	UGK_KB_DISPLAYSWITCH,
	UGK_KB_DOWN,

	UGK_KB_e,
	UGK_KB_EJECT,
	UGK_KB_END,
	UGK_KB_EQUALS,
	UGK_KB_ESCAPE,
	UGK_KB_EXECUTE,
	UGK_KB_EXSEL,

	UGK_KB_f,
	UGK_KB_F1,
	UGK_KB_F10,
	UGK_KB_F11,
	UGK_KB_F12,
	UGK_KB_F13,
	UGK_KB_F14,
	UGK_KB_F15,
	UGK_KB_F16,
	UGK_KB_F17,
	UGK_KB_F18,
	UGK_KB_F19,
	UGK_KB_F2,
	UGK_KB_F20,
	UGK_KB_F21,
	UGK_KB_F22,
	UGK_KB_F23,
	UGK_KB_F24,
	UGK_KB_F3,
	UGK_KB_F4,
	UGK_KB_F5,
	UGK_KB_F6,
	UGK_KB_F7,
	UGK_KB_F8,
	UGK_KB_F9,
	UGK_KB_FIND,

	UGK_KB_g,
	UGK_KB_BACKQUOTE,

	UGK_KB_h,
	UGK_KB_HELP,
	UGK_KB_HOME,

	UGK_KB_i,
	UGK_KB_INSERT,

	UGK_KB_j,
	UGK_KB_k,
	UGK_KB_KBDILLUMDOWN,
	UGK_KB_KBDILLUMTOGGLE,
	UGK_KB_KBDILLUMUP,
	UGK_KB_KP_0,
	UGK_KB_KP_00,
	UGK_KB_KP_000,
	UGK_KB_KP_1,
	UGK_KB_KP_2,
	UGK_KB_KP_3,
	UGK_KB_KP_4,
	UGK_KB_KP_5,
	UGK_KB_KP_6,
	UGK_KB_KP_7,
	UGK_KB_KP_8,
	UGK_KB_KP_9,
	UGK_KB_KP_A,
	UGK_KB_KP_AMPERSAND,
	UGK_KB_KP_AT,
	UGK_KB_KP_B,
	UGK_KB_KP_BACKSPACE,
	UGK_KB_KP_BINARY,
	UGK_KB_KP_C,
	UGK_KB_KP_CLEAR,
	UGK_KB_KP_CLEARENTRY,
	UGK_KB_KP_COLON,
	UGK_KB_KP_COMMA,
	UGK_KB_KP_D,
	UGK_KB_KP_DBLAMPERSAND,
	UGK_KB_KP_DBLVERTICALBAR,
	UGK_KB_KP_DECIMAL,
	UGK_KB_KP_DIVIDE,
	UGK_KB_KP_E,
	UGK_KB_KP_ENTER,
	UGK_KB_KP_EQUALS,
	UGK_KB_KP_EQUALSAS400,
	UGK_KB_KP_EXCLAM,
	UGK_KB_KP_F,
	UGK_KB_KP_GREATER,
	UGK_KB_KP_HASH,
	UGK_KB_KP_HEXADECIMAL,
	UGK_KB_KP_LEFTBRACE,
	UGK_KB_KP_LEFTPAREN,
	UGK_KB_KP_LESS,
	UGK_KB_KP_MEMADD,
	UGK_KB_KP_MEMCLEAR,
	UGK_KB_KP_MEMDIVIDE,
	UGK_KB_KP_MEMMULTIPLY,
	UGK_KB_KP_MEMRECALL,
	UGK_KB_KP_MEMSTORE,
	UGK_KB_KP_MEMSUBTRACT,
	UGK_KB_KP_MINUS,
	UGK_KB_KP_MULTIPLY,
	UGK_KB_KP_OCTAL,
	UGK_KB_KP_PERCENT,
	UGK_KB_KP_PERIOD,
	UGK_KB_KP_PLUS,
	UGK_KB_KP_PLUSMINUS,
	UGK_KB_KP_POWER,
	UGK_KB_KP_RIGHTBRACE,
	UGK_KB_KP_RIGHTPAREN,
	UKG_KB_KP_SPACE,
	UGK_KB_KP_TAB,
	UGK_KB_KP_VERTICALBAR,
	UGK_KB_KP_XOR,

	UGK_KB_l,
	UGK_KB_LALT,
	UGK_KB_LCTRL,
	UGK_KB_LEFT,
	UGK_KB_LEFTBRACKET,
	UGK_KB_LGUI,
	UGK_KB_LSHIFT,

	UGK_KB_m,
	UGK_KB_MAIL,
	UGK_KB_MEDIASELECT,
	UGK_KB_MENU,
	UGK_KB_MINUS,
	UGK_KB_MODE,
	UGK_KB_MUTE,

	UGK_KB_n,
	UGK_KB_NUMLOCKCLEAR,

	UGK_KB_o,
	UGK_KB_OPER,
	UGK_KB_OUT,

	UGK_KB_p,
	UGK_KB_PAGEDOWN,
	UGK_KB_PAGEUP,
	UGK_KB_PASTE,
	UGK_KB_PAUSE,
	UGK_KB_PERIOD,
	UGK_KB_POWER,
	UGK_KB_PRINTSCREEN,
	UGK_KB_PRIOR,

	UGK_KB_q,
	UGK_KB_r,
	UGK_KB_RALT,
	UGK_KB_RCTRL,
	UGK_KB_RETURN,
	UGK_KB_RETURN2,
	UGK_KB_RGUI,
	UGK_KB_RIGHT,
	UGK_KB_RIGHTBRACKET,
	UGK_KB_RSHIFT,

	UGK_KB_s,
	UGK_KB_SCROLLLOCK,
	UGK_KB_SELECT,
	UGK_KB_SEMICOLON,
	UGK_KB_SEPARATOR,
	UGK_KB_SLASH,
	UGK_KB_SLEEP,
	UGK_KB_SPACE,
	UGK_KB_STOP,
	UGK_KB_SYSREQ,

	UGK_KB_t,
	UGK_KB_TAB,
	UGK_KB_THOUSANDSSEPARATOR,

	UGK_KB_u,
	UGK_KB_UNDO,
	UGK_KB_UNKNOWN,
	UGK_KB_UP,

	UGK_KB_v,
	UGK_KB_VOLUMEDOWN,
	UGK_KB_VOLUMEUP,
	UGK_KB_w,
	UGK_KB_WWW,

	UGK_KB_x,
	UGK_KB_y,
	UGK_KB_z,

	UGK_KB_AMPERSAND,
	UGK_KB_ASTERISK,
	UGK_KB_AT,
	UGK_KB_CARET,
	UGK_KB_COLON,
	UGK_KB_DOLLAR,
	UGK_KB_EXCLAIM,
	UGK_KB_GREATER,
	UGK_KB_HASH,
	UGK_KB_LEFTPAREN,
	UGK_KB_LESS,
	UGK_KB_PERCENT,
	UGK_KB_PLUS,
	UGK_KB_QUESTION,
	UGK_KB_QUOTEDBL,
	UGK_KB_RIGHTPAREN,
	UGK_KB_UNDERSCORE,

	UGK_KB_MAXKEYS

} UGK_KEYCODES;

/**
* Keyboard class is defined for the management of keys
*/
namespace UGK
{
	class CKeyboard : public CHardware
	{
	protected:

		unsigned char	ActionSize;
		UGKS_String		folder;	///< Directory where the key map is. This attibute is set by the device parser when parsing the devices configuration file.
		UGKS_String		MapConfigurationFile;
								
		/// Position in the array means the ascii code of the key pressed on the keyboard in order to start up an action on the game
		/// Content on that position means the token or action to develop associated to that pressed key

		///List is replaced by a map, the key refers to the key pressed and the value associate refers to the action on the game 
		std::map<unsigned char, CK_ACTION>	ActionKeys;
		std::map<char, char>				OS2UGK;  ///< Translation table from the specific OS input codification to internal UGK codification. Deprecated
		std::map<char, char>				SDL2UGK; ///< Translation table from SDL input codification to UGK codification

		/// Structure created to save the fields read from the parser
		typedef struct
		{
			UGKS_String	KEY;
			UGKS_String	ACTION;
			int			PERIOD;
		} CK_KAP;	//KAP means Key-Action-Period

		/// Now in the keyboard class exists two ways, reading data from the program or reading data from the html, in this last case 
		/// the associated map is indexed by the character, the key, and the value is the structure associated to that key 
		std::map<CK_CHARACTER, CK_KAP*> ActionKeysP;

		//inline void ResetActionKeys() {for (int i = 0; i < CK_MAX_TOKENS; i++) ActionKeys[i] = CK_NO_ACTION;}

#ifdef UGKOS_WINDOWS
		inline void SetActivetokens  (const WPARAM c) { SetActivetokens  (GetAction(c)); };	///<Set a new key into the active list of key pressed
		inline void ResetActivetokens(const WPARAM c) { ResetActivetokens(GetAction(c)); };///<Release a new key from the active list of key pressed
#endif // UGKOS_WINDOWS

	public:

		inline void			SetConfigFolder(UGKS_String folder) { this->folder = folder; }
		inline UGKS_String	GetConfigFolder()					{ return folder; }

		inline void SetConfigurationFile(UGKS_String path) { MapConfigurationFile = path; }	///<Sets the keyboard map configuration file path
		inline UGKS_String GetConfigurationFile() { return MapConfigurationFile; }	///<Gets the keyboard map configuration file path

		/// Methods to executes the actions associated to a token, this method is virtual to force the programer to implement the method
		virtual void UpdateAction(const CK_ACTION Token, bool On);	//Checks for De/Activating the action
		void Update();

		///Keys pressed down at any given time
		CK_ACTIVE_ACTION ActivActions;	///<When a key is released, it is removed from this list of pressed keys. It passes to be inactive

										//Methods
		void			ClearTokensKeys();

		CKeyboard();			///<Constructor of the class
		~CKeyboard();			///<Destructor of the class

								//Virtual methods redefined
		CHW_HW_STATUS		Init(void);			///<start keyboard

		void SetDelay(HRT_Time *);
		void SetDelay(float *);
		void SetActionKeys(unsigned char *, unsigned char);
		void SetNexus(UGKS_String key, UGKS_String action, int period);
		inline CK_ACTION GetAction(char PressedKey) { return ActionKeys[PressedKey]; };
		inline CK_KAP TokenizeP(CK_CHARACTER PressedKey) { return *ActionKeysP[PressedKey]; };

		bool KeyWait(const CK_ACTION);	///<Returns true when time has elapsed more than int ms for a given keyboard action
		bool KeyWaitP(const CK_KAP);	///<Returns true when time has elapsed more than int ms for a given keyboard action

		void SetKeyDelay(float *, char); //Set especific delay to one key
		void SetKeyDelay(HRT_Time *D, char Token);

		void SetActiveToken(const CK_ACTION);	///<Set a new token into the active list of token pressed
		void ResetActiveToken(const CK_ACTION);	///<Release a token from the active list of token pressed

		void SetActiveTokenP(const CK_KAP);	///<Set a new token into the active list of token pressed
											///Set the actions associated to a released token
											///Release a new key from the active list of key pressed
		inline void ResetActiveTokenP(const  CK_KAP Estruc) { ResetActiveToken(atoi(UGKS_string2charstr(Estruc.KEY))); }

		inline void SetActiveKey(char PressedKey) { SetActiveToken(GetAction(PressedKey)); }	///<Set a new key into the active list of token pressed
		inline void ResetActiveKey(char PressedKey) { ResetActiveToken(GetAction(PressedKey)); }	///<Release a key from the active list of token pressed
		inline void SetActiveKeyP(CK_CHARACTER PressedKey) { SetActiveTokenP(TokenizeP(PressedKey)); }	///<Set a new key into the active list of token pressed
		inline void ResetActiveKeyP(CK_CHARACTER PressedKey) { ResetActiveTokenP(TokenizeP(PressedKey)); }	///<Release a key from the active list of token pressed

		inline CK_ACTION	GetKeyAction(char PressedKey) { return ActionKeys[PressedKey]; }	///<Set a new key into the active list of token pressed
		inline CK_KAP		GetKeyActionP(CK_CHARACTER PressedKey) { return *ActionKeysP[PressedKey]; }
	};
}
#endif