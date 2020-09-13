//==========================
void BeginWindows();
void GotoCoord( COORD coord);
void GotoXY( int x, int y);
void CleanScreen();
//-----------------------------------
void CleanScreen( ){
	system("cls");
}

void BeginWindows(){	//ínicia o cosole com uma configuração stardard
	SetConsoleOutputCP(1252);
	
	system(COLOR_MAIN); //Padroniza a cor do sistema, aqui nem influencia muito.
    system(TITLE_MAIN); //Dá título a tela

    
	HWND console = GetConsoleWindow();

	HANDLE hcsb = CreateFileA("CONOUT$", GENERIC_WRITE | GENERIC_READ,
        FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    CONSOLE_FONT_INFOEX cfi = {sizeof(cfi)};

    // Modify the font size in cfi
    cfi.dwFontSize.X  = SIZE_FONTE;
    cfi.dwFontSize.Y  = SIZE_FONTE;

    // Use cfi to set the screen buffer's new font
    SetCurrentConsoleFontEx(hcsb, FALSE, &cfi);

	MoveWindow(console, POSS_SCREEN_X, POSS_SCREEN_Y,  WIDTH_SCREEN, HEIGHT_SCREEN, TRUE);

	CONSOLE_CURSOR_INFO cursor = {100, false};
  	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	
}

void GotoCoord( COORD coord)
{
   SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

void GotoXY( int x, int y)
{
   COORD coord;
   coord.X = x;
   coord.Y = y;
   SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

