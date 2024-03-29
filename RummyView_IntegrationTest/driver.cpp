// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN  

// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "IGame.h"
#include "IGameView.h"
#include "ICardCollection.h"
#include "ICardList.h"
#include "CardAreaView.h"
#include "CardList.h"
#include "Card.h"
#include "Hand.h"

#define ID_2DSLIDER 1
#define ID_QUIT 2


using namespace std;

#define MAX_LOADSTRING 100
#define SIDEBAR_WIDTH 150
#define SIDEBAR_LENGTH 150
#define NUM_SUBWINDOWS 2

HDC         MainHdc;	//this is the main painting context.  all paint functions will want it
HWND		MainHwnd;   //handle to the main window.  Basically just a reference to it

wchar_t MainWindowText[MAX_LOADSTRING];	//global text array.  all the windows just change this, and the main window paints whatever is in there

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow);

//all windows have to have a callback function, it's invoked when ANYTHING happens to the window.
//what you do with the event, or message is your business.  We're usually concerned with mouse clicks, creation, and painting

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SubWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//static char szSubName[] = "card area";
const wchar_t* szSubName = L"card area";

CardAreaView* cardAreaView;
CardAreaView* stock;
CardAreaView* discard;
CardAreaView* meldArea;
CardAreaView* playersHand;
CardAreaView* opponentsHand;
CardAreaView* foundation;
Hand* handone;
Hand* handtwo;
std::string* views;

//HWND * hwndarray;// get rid of it
HWND hWnd_subwindow_foundation;
HWND hWnd_subwindow_stock;
HWND hWnd_subwindow_meldArea;

HWND hWnd_subwindow_discard;

HWND hWnd_subwindow_playersHand;
HWND hWnd_subwindow_opponentsHand;
HWND hWnd_subwindow_handone;
HWND hWnd_subwindow_handtwo;




// Main entry point
//Handles command line arguments for file name
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	MSG msg;

	
	CardList* list1 = new CardList();
/*
	Card* four_hearts = new Card(4, Hearts);
	four_hearts->select(); //test card

	Card* three_clubs = new Card(3, Clubs);
	Card* nine_spades = new Card(9, Spades);
	Card* two_hearts = new Card(2, Hearts);
	Card* two_spades = new Card(2, Spades);
	Card* two_diamonds = new Card(2, Diamonds);
	Card* four_spades = new Card(4, Spades);
	Card* five_spades = new Card(5, Spades);
	Hand* handone = new Hand();
	handone->add(three_clubs); //test hand
	handone->add(nine_spades);
	handone->add(two_hearts);
	handone->add(two_spades);
	handone->add(two_diamonds);
	handone->add(four_spades);
	handone->add(five_spades);

	Hand* handtwo = new Hand();
	Card* ten_diamonds = new Card(10, Diamonds);
	Card* six_hearts = new Card(6, Hearts);
	Card* seven_hearts = new Card(7, Hearts);
	Card* eight_clubs = new Card(8, Clubs);
	Card* nine_diamonds = new Card(9, Diamonds);
	Card* ten_hearts = new Card(10, Hearts);
	Card* five_hearts = new Card(5, Hearts);
	handtwo->add(ten_diamonds);
	handtwo->add(six_hearts);
	handtwo->add(seven_hearts);
	handtwo->add(eight_clubs);
	handtwo->add(nine_diamonds);
	handtwo->add(ten_hearts);
	handtwo->add(five_hearts);
	handtwo->remove(3);

	Card* seven_spades = new Card(7, Spades);
	stock->addToEnd(seven_spades);



*/
	




	// set characteristics of MainWndClass and SubWndClass
	//static char szAppName[] = "Dialog";
	const wchar_t* szAppName = L"Dialog";
	WNDCLASS MainWndClass, SubWndClass;

	MainWndClass.style = CS_HREDRAW | CS_VREDRAW;
	MainWndClass.lpfnWndProc = MainWndProc; // name of the callback for main window
	MainWndClass.cbClsExtra = 0;  // No extra class bytes
	MainWndClass.cbWndExtra = 0;  // No extra window bytes
	MainWndClass.hInstance = hInstance;
	MainWndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	MainWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	MainWndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	MainWndClass.lpszMenuName = NULL;
	MainWndClass.lpszClassName = szAppName; // name of class that handles main window events
	RegisterClass(&MainWndClass);

	SubWndClass.style = CS_HREDRAW | CS_VREDRAW;
	SubWndClass.lpfnWndProc = SubWndProc; // name of the callback for subwindows
	SubWndClass.cbClsExtra = 0;  // No extra class bytes
	SubWndClass.cbWndExtra = 12;  // extra bytes to store pointer
	SubWndClass.hInstance = hInstance;
	SubWndClass.hIcon = NULL;
	SubWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	SubWndClass.hbrBackground = NULL;
	SubWndClass.lpszMenuName = NULL;
	SubWndClass.lpszClassName = szSubName; // name of class that handles subwindow events
	RegisterClass(&SubWndClass);

	// create the main window and display it
	HWND hWnd;
	hWnd = CreateWindow(szAppName,           // name of class that handles main window events
		L"My Brilliant Program", // window caption
		WS_OVERLAPPEDWINDOW, // window style
		CW_USEDEFAULT,       // init x pos
		CW_USEDEFAULT,       // init y pos
		1000,                 // init x size
		730,                 // init y size
		NULL,                // parent window
		NULL,                // window menu
		hInstance,           // program instance
		NULL);               // create params.
	MainHwnd = hWnd;  /* store away the handle for global use */

	ShowWindow(hWnd, iCmdShow); // display it
	UpdateWindow(hWnd);

	// loop "forever"
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg); // translate key codes
		DispatchMessage(&msg);  // call window procedure
	}

	return (int)msg.wParam;
}

// the callback for the main window (invoked via DispatchMessage())
LRESULT CALLBACK MainWndProc(HWND hWnd, // handle to the window
	UINT msg, WPARAM wParam, LPARAM lParam) // describes the event
{
	HWND* buttonarray;

	LRESULT		retVal = 0;
	static int  cxChar, cyChar;
	RECT        rect;
	HDC         hdc;
	PAINTSTRUCT ps;
	HPEN        hOldPen;
	HBRUSH      hOldBrush;

	buttonarray = new HWND[3];
	int			button_x = 0;
	const wchar_t* labels[3];
	labels[0] = L"Quit";
	labels[1] = L"Save";
	labels[2] = L"Knock";

	CardAreaView* cardAreaView = (CardAreaView*)GetWindowLong(hWnd, DWL_USER);
	switch (msg)
	{
	case WM_CREATE:  // for initialization that happens when window is created
		/*this runs only once, as soon as the main window is created.
		use this opportunity to create the children */

		MainHdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		cxChar = LOWORD(GetDialogBaseUnits());
		cyChar = HIWORD(GetDialogBaseUnits());

		GetClientRect(hWnd, &rect);


		// create the foundatin window  - - #################Should we get dynamic sizes here?????
		hWnd_subwindow_stock = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			758,       // init x pos
			350,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow_stock, DWL_USER, (long)(stock)); // associate a view object with this window

		// create the foundatin window
		hWnd_subwindow_discard = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			758,       // init x pos
			350,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow_discard, DWL_USER, (long)(discard)); // associate a view object with this window


		// create the foundatin window
		hWnd_subwindow_foundation = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			758,       // init x pos
			350,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow_foundation, DWL_USER, (long)(foundation)); // associate a view object with this window

				// create the foundatin window
		hWnd_subwindow_playersHand = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			758,       // init x pos
			350,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow_playersHand, DWL_USER, (long)(playersHand)); // associate a view object with this window


				// create the foundatin window
		hWnd_subwindow_opponentsHand = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			758,       // init x pos
			350,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow_opponentsHand, DWL_USER, (long)(opponentsHand)); // associate a view object with this window


				// create the foundatin window
		hWnd_subwindow_meldArea = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			758,       // init x pos
			350,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow_meldArea, DWL_USER, (long)(meldArea)); // associate a view object with this window


				// create the foundatin window
		hWnd_subwindow_handone = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			758,       // init x pos
			350,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow_handone, DWL_USER, (long)(handone)); // associate a view object with this window



				// create the foundatin window
		hWnd_subwindow_handtwo = CreateWindow(szSubName,   // name of class that handles subwindow events
			NULL, // window caption
			WS_CHILD | WS_VISIBLE, // window style
			758,       // init x pos
			350,       // init y pos
			72,       // init x size
			100,                 // init y size
			hWnd,                // parent window
			(HMENU)ID_2DSLIDER,                // window menu
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),           // program instance
			NULL);               // create params.
		SetWindowLong(hWnd_subwindow_handtwo, DWL_USER, (long)(handtwo)); // associate a view object with this window


		
		// create the GUI buttons (on the main window)
		button_x = 460;
		for (int i = 0; i < 2; i++)
		{
			buttonarray[i] = CreateWindow(L"button", labels[i],
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				button_x,       // init x pos
				500,       // init y pos
				90,       // init x size
				50,       // init y size
				hWnd, (HMENU)i,
				(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
				NULL);
			button_x += 100;
		}
		break;
		

	case WM_LBUTTONUP:  //left mouse button released (up)

		swprintf_s(MainWindowText, MAX_LOADSTRING, L"Left mouse button released");

		GetClientRect(MainHwnd, &rect);
		InvalidateRect(MainHwnd, &rect, FALSE);
		break;

		

	case WM_PAINT:		// paint event-- window should display itself

		hdc = BeginPaint(hWnd, &ps);   //read up ob brushes and such.  it's basically the color you paint with
		GetClientRect(hWnd, &rect);

		hOldPen = (HPEN)SelectObject(hdc, GetStockObject(BLACK_PEN));
		hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(WHITE_BRUSH));

		Rectangle(hdc, 0, 0, rect.right, rect.bottom);
		TextOut(hdc, 25, 450, MainWindowText, (int)wcslen(MainWindowText));  // display whatever is in MainWindowText

		SelectObject(hdc, hOldBrush);  // put the brush and pen back to the color they were before you used them
		SelectObject(hdc, hOldPen);

		EndPaint(hWnd, &ps);
		break;

	case WM_COMMAND: // an event tied to a GUI component

		if (HIWORD(wParam) == BN_CLICKED) { // a GUI button was clicked

			swprintf_s(MainWindowText, MAX_LOADSTRING, L"Clicked button %s", labels[LOWORD(wParam)]);

			GetClientRect(MainHwnd, &rect);
			InvalidateRect(MainHwnd, &rect, FALSE);

			if (labels[LOWORD(wParam)] == L"Quit") { // Quit button was clicked
				PostQuitMessage(0); // terminate the application
			}
			else if (labels[LOWORD(wParam)] == L"Do Nothing") // Do Nothing button was clicked
			{
				// in the future, do something to the application when this button is clicked!
			}
		}
		break;

	case WM_DESTROY: // to terminate the application
		PostQuitMessage(0);
		break;

	default:
		retVal = DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return retVal;
}



// the callback for any of the subwindows (invoked via DipatchMessage())
LRESULT CALLBACK SubWndProc(HWND hWnd, // handle to the window
	UINT msg, WPARAM wParam, LPARAM lParam) // describes the event
{
	LRESULT		retVal = 0;
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT Rect;
	RECT rect;

	GetClientRect(hWnd, &Rect);

	static int  cxChar, cyChar;
	CardAreaView* cardAreaView = (CardAreaView*)GetWindowLong(hWnd, DWL_USER);

	switch (msg)
	{
	case WM_CREATE: // for initialization that happens when the window is created
		cxChar = LOWORD(GetDialogBaseUnits());
		cyChar = HIWORD(GetDialogBaseUnits());
		break;

	case WM_PAINT: // paint event-- window should display itself
		hdc = BeginPaint(hWnd, &ps);

//		myView = (MyView*)GetWindowLong(hWnd, DWL_USER); // get the associated view
	//	myView->display(&hdc); // tell the view to display itself

		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONUP: // left mouse button released (up)

		GetClientRect(MainHwnd, &rect);
		swprintf_s(MainWindowText, MAX_LOADSTRING, L"Clicked in subwindow; cursor position (%d,%d)", LOWORD(lParam), HIWORD(lParam));
		InvalidateRect(MainHwnd, &rect, FALSE);

	//	myView = (MyView*)GetWindowLong(hWnd, DWL_USER); // get the associated view
//		myView->click(LOWORD(lParam), HIWORD(lParam)); // give the view the cursor position

		GetClientRect(MainHwnd, &rect);
		InvalidateRect(MainHwnd, &rect, FALSE);
		break;

	case WM_ERASEBKGND:
		retVal = (LONG)TRUE;
		break;

	case WM_DESTROY: // to terminate the application
		PostQuitMessage(0);
		break;

	default:
		retVal = DefWindowProc(hWnd, msg, wParam, lParam);
	}
	//delete i;
	return retVal;
}







