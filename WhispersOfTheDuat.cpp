#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <conio.h>

using namespace std;
string playerName;
HANDLE hConsole;

int confidence = 0;
int honesty = 0;
int shyness = 0;

int anubisaffection = 0;
int setaffection = 0;
int horusaffection = 0;

const string pyramid[] =

{
"                                   _L/L",
"                                 _LT/l_L_",
"                               _LLl/L_T_lL_",
"           _T/L              _LT|L/_|__L_|_L_",
"         _Ll/l_L_          _TL|_T/_L_|__T__|_l_",
"       _TLl/T_l|_L_      _LL|_Tl/_|__l___L__L_|L_",
"     _LT_L/L_|_L_l_L_  _'|_|_|T/_L_l__T _ l__|__|L_",
"   _Tl_L|/_|__|_|__T _LlT_|_Ll/_l_ _|__[ ]__|__|_l_L_"
};

const int pyramidRows = sizeof(pyramid) / sizeof(pyramid[0]);
const int WIDTH = 80;
const int HEIGHT = 25;

void SetupConsole();
void Intro();
void ClearScreen();
void SetColor(int color);
void CenterText(string text);
void DrawPyramid();
void AskPlayerName();
void BlankLines(int lines);
void TempleMainRoom();
void OutsideTemple();
void OutsideRoom();
void InsideRoom();
void EnterSet();
void AnubisDeparts();
void Alone();
void AnotherGod();
void HorusOutside();

int main()
{
    SetupConsole();

    playerName = "Kaiju";

    HorusOutside();

    return 0;
}


void BlankLines(int lines)
{
    for (int i = 0; i < lines; i++)
    {
        cout << endl;
    }
}

void SetColor(int color)
{
    SetConsoleTextAttribute(hConsole, color);
}

void AskPlayerName()
{
    BlankLines(8);
    CenterText("What is your name?");
    cout << endl;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD pos;
    pos.X = (WIDTH / 2) - 10;
    pos.Y = csbi.dwCursorPosition.Y;
    SetConsoleCursorPosition(hConsole, pos);
    cout << "> ";
    getline(cin >> ws, playerName);
    ClearScreen();
    BlankLines(12);
    CenterText("     Welcome, " + playerName + ".     ");
    Sleep(2000);
    ClearScreen();
}

void ClearScreen()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD cellsWritten;
    COORD topLeft = { 0, 0 };

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    DWORD totalCells =
        csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(
        hConsole,
        ' ',
        totalCells,
        topLeft,
        &cellsWritten
    );

    FillConsoleOutputAttribute(
        hConsole,
        csbi.wAttributes,
        totalCells,
        topLeft,
        &cellsWritten
    );

    SetConsoleCursorPosition(hConsole, topLeft);
}

void SetupConsole()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.X = WIDTH;
    bufferSize.Y = HEIGHT;
    SetConsoleScreenBufferSize(hConsole, bufferSize);
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = WIDTH - 1;
    windowSize.Bottom = HEIGHT - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    SetConsoleTitle(TEXT("Whispers of the Duat"));
}

void CenterText(string text)
{
    int x = (WIDTH - static_cast<int>(text.length())) / 2;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    pos.Y = csbi.dwCursorPosition.Y;
    SetConsoleCursorPosition(hConsole, pos);
    cout << text << endl;
}

void DrawPyramid()
{
    for (int i = 0; i < pyramidRows; i++)
    {
        cout << pyramid[i] << endl;
        Sleep(200);
    }
}

void Intro()
{
    PlaySound(TEXT("intro.wav"),
        NULL,
        SND_FILENAME | SND_ASYNC | SND_LOOP);
    ClearScreen();
    BlankLines(4);

    DrawPyramid();
    cout << endl;

    CenterText("Whispers of the Duat");
    cout << endl;

    CenterText("(C) 2026 Kaiju Interactive");
    cout << endl;

    CenterText("Press ENTER to Begin");

    cin.get();
    PlaySound(NULL, NULL, 0);
    ClearScreen();
}

void TempleMainRoom()
{
    PlaySound(TEXT("ambient.wav"), NULL,
        SND_FILENAME | SND_ASYNC | SND_LOOP);

    BlankLines(9);
    CenterText("The room is silent.");
    Sleep(3000);
    CenterText("The air is hot and heavy with incense.");
    Sleep(3000);
    CenterText("Torchlight flickers across ancient stone.");
    Sleep(3000);
    CenterText("You stand before the altar, clad only in a simple linen loincloth.");
    Sleep(3000);
    CenterText("Someone... or something... is watching.");
    Sleep(3000);
    ClearScreen();

    BlankLines(10);
    SetColor(12);
    CenterText("< Were you seeking me? >");
    SetColor(7);
    Sleep(3000);
    ClearScreen();

    BlankLines(7);
    CenterText("You gasp and whirl toward the temple entrance.");
    Sleep(3000);
    CenterText("A figure stands silently within the doorway.");
    Sleep(3000);
    CenterText("He is impossibly tall, his powerful frame carved from polished obsidian.");
    Sleep(3000);
    CenterText("A simple white kilt hangs from his hips, adorned with bands of gleaming gold.");
    Sleep(3000);
    CenterText("An ornate collar of lapis and turquoise rests upon his broad chest.");
    Sleep(3000);
    CenterText("Where a man's face should be is the noble head of a black jackal.");
    Sleep(3000);
    CenterText("Golden eyes regard you with quiet amusement.");
    Sleep(3000);
    CenterText("The scent of myrrh and warm desert sand fills the temple.");
    Sleep(3000);
    CenterText("Every instinct tells you to kneel.");
    Sleep(5000);
    ClearScreen();

    SetColor(12);
    BlankLines(10);
    CenterText("Anubis");
    CenterText("< On your knees already, eh? Good boy. >");
    SetColor(7);
    BlankLines(1);
    CenterText("The corners of his muzzle curl into a knowing smile.");
    Sleep(5000);
    ClearScreen();

    BlankLines(10);
    CenterText("You lift your gaze, only for it to catch on the unmistakable outline");
    CenterText("beneath the god's linen kilt.");
    Sleep(4000);
    CenterText("Heat rushes to your face.");
    Sleep(4000);
    CenterText("Your eyes continue upward, tracing the hard planes of his abdomen as");
    CenterText("torchlight dances across his obsidian skin.");
    Sleep(4000);
    CenterText("Only then do you dare meet his golden gaze.");
    Sleep(6000);
    ClearScreen();

    int choice = 0;

    while (choice < 1 || choice > 4)
    {
        ClearScreen();
        BlankLines(8);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< And just what are you staring at, " + playerName + "? >");
        SetColor(7);

        BlankLines(2);

        CenterText("1. Your eyes.");
        CenterText("2. Y-your... um... your kilt.");
        CenterText("3. Your physique... it's incredible.");
        CenterText("4. Say nothing.");

        cout << endl;
        cout << "                                   > ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        if (choice < 1 || choice > 4)
        {
            BlankLines(1);
            CenterText("That is not a valid choice.");
            Sleep(2000);
        }
    }

    ClearScreen();

    if (choice == 1)
    {
        confidence++;

        BlankLines(10);

        CenterText("\"Your eyes.\"");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< Most mortals cannot bear to meet my gaze. >");
        CenterText("< Interesting. >");
        SetColor(7);
    }
    else if (choice == 2)
    {
        shyness++;

        BlankLines(10);

        CenterText("\"Y-your... um... your kilt.\"");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< My kilt? >");
        CenterText("< Is that the story you're going with? >");
        SetColor(7);
    }
    else if (choice == 3)
    {
        honesty++;

        BlankLines(10);

        CenterText("\"Your physique... it's incredible.\"");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< Honesty. >");
        CenterText("< A refreshing quality. >");
        SetColor(7);
    }
    else if (choice == 4)
    {
        shyness += 2;
        confidence--;

        BlankLines(10);

        CenterText("You lower your gaze and remain silent.");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< Not ready to speak? >");
        CenterText("< Very well. In time. >");
        SetColor(7);
    }

    Sleep(4000);
    ClearScreen();
    BlankLines(10);

    CenterText("Without another word, Anubis turns to walk away.");
    Sleep(4000);

    BlankLines(1);
    CenterText("You hesitate.");
    Sleep(4000);

    BlankLines(2);

    SetColor(12);
    CenterText("Anubis");
    CenterText("< Come. >");
    SetColor(7);

    Sleep(2000);
    BlankLines(1);
    CenterText("Before you can question yourself your feet being to follow.");
    Sleep(5000);
}

void OutsideTemple()
{

    ClearScreen();
    BlankLines(8);

    CenterText("The warm desert air greets your skin as you step outside the temple.");
    CenterText("After the heavy incense within, each breath feels strangely refreshing.");

    BlankLines(2);

    CenterText("Anubis turns toward you, a faint smirk playing across his lips.");

    BlankLines(2);

    SetColor(12);
    Sleep(6000);
    CenterText("Anubis");
    CenterText("< Good boy, " + playerName + ". >");
    SetColor(7);

    BlankLines(2);
    CenterText("He stares at you intently, that devious smirk still scrawled across his muzzle.");
    Sleep(6000);

    int choice = 0;

    while (choice < 1 || choice > 3)
    {
        ClearScreen();
        BlankLines(8);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< So, why have you summoned me here, " + playerName + "? >");
        SetColor(7);

        BlankLines(2);

        CenterText("1. Just to talk.");
        CenterText("2. To devote myself to you, completely.");
        CenterText("3. I... I didn't...");

        cout << endl;
        cout << "                                   > ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        if (choice < 1 || choice > 3)
        {
            BlankLines(1);
            CenterText("That is not a valid choice.");
            Sleep(2000);
        }
    }

    ClearScreen();

    if (choice == 1)
    {
        shyness++;
        honesty++;

        BlankLines(10);

        CenterText("\"Just to talk.\"");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< Just to talk? >");
        CenterText("< Is that truly all? >");
        SetColor(7);
    }
    else if (choice == 2)
    {
        confidence++;

        BlankLines(10);

        CenterText("\"To devote myself to you, completely.\"");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< Completly? >");
        CenterText("< Such certainty from one whose heart is racing. >");
        SetColor(7);
    }
    else if (choice == 3)
    {
        shyness++;

        BlankLines(10);

        CenterText("\"I... I didn't...\"");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< Oh but you did. >");
        CenterText("< Even if you cannot yet admit why.  >");
        SetColor(7);
    }

    Sleep(5000);

    ClearScreen();
    BlankLines(10);

    CenterText("Anubis studies you in silence.");
    CenterText("The faint amusement in his expression slowly gives way");
    CenterText("to something far more knowing.");

    BlankLines(2);
    Sleep(5000);

    CenterText("Then, in one fluid step, he closes the distance between you.");
    CenterText("His piercing golden eyes never leave yours.");

    Sleep(5000);

    BlankLines(2);

    SetColor(12);
    CenterText("Anubis");
    CenterText("< You may not be ready to say it aloud... >");
    CenterText("< But I already know what lies within your heart. >");
    SetColor(7);

    int choice2 = 0;

    while (choice2 < 1 || choice2 > 2)
    {
        ClearScreen();
        BlankLines(8);

        CenterText("Choose an option:");

        BlankLines(2);
        CenterText("1. Hug Anubis.");
        CenterText("2. Stare at the ground.");

        cout << endl;
        cout << "                                   > ";
        cin >> choice2;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice2 = 0;
        }

        if (choice2 < 1 || choice2 > 2)
        {
            BlankLines(1);
            CenterText("That is not a valid choice.");
            Sleep(2000);
        }
    }

    ClearScreen();

    if (choice2 == 1)
    {
        confidence++;

        BlankLines(10);

        CenterText("Without thinking, you step forward and wrap");
        CenterText("your arms around Anubis, burying your face");
        CenterText("against his chest.");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< ... >");
        Sleep(1500);
        CenterText("< Hmn. >");
        CenterText("< That... wasn't what I expected. >");
        Sleep(1500);
        CenterText("< ...You really are full of surprises. >");
        SetColor(7);
    }
    else if (choice2 == 2)
    {
        shyness++;

        BlankLines(10);

        CenterText("You avert your gaze and stare shyly at the ground.");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< Such a shy little thing. >");
        CenterText("< You needn't hide from me. >");
        SetColor(7);
    }

    Sleep(6000);

    ClearScreen();
    BlankLines(8);

    SetColor(12);
    CenterText("Anubis");
    CenterText("< The hour grows late. >");
    CenterText("< Even priests require sleep. >");
    SetColor(7);

    Sleep(5000);

    BlankLines(2);

    CenterText("Only then do you notice how silent the temple has become.");
    CenterText("The last of the oil lamps burn low.");

    Sleep(5000);

    BlankLines(2);

    SetColor(12);
    CenterText("Anubis");
    CenterText("< Show me where you live, little one. >");
    CenterText("< I'll see you safely home. >");
    SetColor(7);

    Sleep(6000);

    ClearScreen();
    BlankLines(10);
    CenterText("You begin the walk home. Anubis moves silently beside you.");
    CenterText("The city streets are nearly deserted, save for a few stray cats.");
    Sleep(4000);
    CenterText("Warm desert air drifts between the stone buildings.");
    CenterText("More than once, you are tempted to reach for his hand.");
    BlankLines(1);
    CenterText("But each time, your courage fails you.");
    Sleep(6000);

    ClearScreen();
    BlankLines(12);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< Your heart grows louder with every step. >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
}

void OutsideRoom()
{

    BlankLines(10);

    CenterText("You come to the entrance of a small room connected");
    CenterText("to the back of the temple.");

    BlankLines(1);
    Sleep(2000);

    SetColor(6);
    CenterText(playerName);
    CenterText("< This is it. >");
    CenterText("< It's not much, but the temple provides what it can. >");
    CenterText("< And the people here are generous whenever they're able. >");
    SetColor(7);
    Sleep(6000);

    ClearScreen();
    BlankLines(10);

    CenterText("Anubis walks past you and quietly steps inside.");
    Sleep(2000);
    CenterText("The room is modestly furnished.");
    Sleep(2000);
    CenterText("A simple straw mat rests in one corner,");
    Sleep(2000);
    CenterText("while a small desk and chair occupy the other.");
    Sleep(2000);
    CenterText("A few well-worn scrolls lie scattered across the desk,");
    Sleep(2000);
    CenterText("their margins filled with careful notes in your own hand.");
    Sleep(6000);
    ClearScreen();

    BlankLines(6);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< You study long after the others have gone to sleep. >");
    CenterText("< I can see that. >");
    SetColor(7);

    BlankLines(2);
    CenterText("You lower your eyes, unable to hide your blush.");
    Sleep(3000);

    BlankLines(2);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< It's time for you to take your rest now, little one. >");
    SetColor(7);

    BlankLines(2);
    CenterText("You try to hide your disappointment...");

    BlankLines(2);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< Sleep well, little one. >");
    CenterText("< I'll find you again. >");
    SetColor(7);
    Sleep(6000);

    ClearScreen();

    int choice = 0;

    while (choice < 1 || choice > 2)
    {
        ClearScreen();
        BlankLines(8);

        CenterText("Choose an option:");

        BlankLines(2);
        CenterText("1. \"You... can stay if you want...\"");
        CenterText("2. \"Thank you for walking me home.\"");

        cout << endl;
        cout << "                                   > ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        if (choice < 1 || choice > 2)
        {
            BlankLines(1);
            CenterText("That is not a valid choice.");
            Sleep(2000);
        }
    }

    ClearScreen();

    if (choice == 1)
    {
        confidence++;

        BlankLines(10);

        CenterText("\"You... can stay if you want...\"");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< Stay? >");
        CenterText("< There hardly seems room for one of us on that mat. >");
        SetColor(7);

        Sleep(3000);
        BlankLines(1);

        CenterText("You glance toward the small straw mat.");
        CenterText("Your face grows warm at the thought of sharing it.");

        Sleep(5000);

    }
    else if (choice == 2)
    {
        shyness++;

        BlankLines(10);

        CenterText("\"Thank you for walking me home.\"");

        BlankLines(1);

        SetColor(12);
        CenterText("Anubis");
        CenterText("< You're most welcome. >");
        CenterText("< I have to protect my priest. >");
        SetColor(7);

        Sleep(3000);
        BlankLines(1);

        CenterText("Anubis turns toward the doorway.");
        CenterText("A sudden ache settles in your chest.");

        Sleep(5000);
    }

    ClearScreen();

    BlankLines(9);

    CenterText("He turns back and gives you a knowing look.");
    Sleep(1500);
    BlankLines(1);

    SetColor(12);
    CenterText("Anubis");
    CenterText("< Well... I suppose I could stay for a bit. >");
    Sleep(1200);

    CenterText("< Just until you've fallen asleep. >");
    SetColor(7);
    BlankLines(1);

    CenterText("He walks over and flops down onto the straw mat.");
    CenterText("His linen kilt shifts ever so slightly, offering");
    CenterText("you the briefest glimpse of the impressive bulge.");
    CenterText("hidden beneath.");
    BlankLines(2);
    Sleep(2000);

    CenterText("He pats the empty space beside him.");
    BlankLines(1);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< Come, little one, join me. >");
    SetColor(7);
    Sleep(3000);
    ClearScreen();
}

void InsideRoom()
{

    BlankLines(6);

    CenterText("Your face flushes crimson at the sight of the god's");
    CenterText("imposing physique. You quietly close the door");
    CenterText("behind you and make your way across the small");
    CenterText("room, your heart racing with every step.");
    BlankLines(1);
    Sleep(3000);

    CenterText("You lower yourself onto the straw mat beside");
    CenterText("Anubis, careful not to brush against him.");
    BlankLines(1);
    Sleep(3000);

    CenterText("Sensing your apprehension, Anubis gently pulls");
    CenterText("you closer, wrapping his strong arms around");
    CenterText("you in a warm embrace.");
    BlankLines(1);
    Sleep(3000);

    CenterText("For the first time in ages, you feel truly safe.");
    Sleep(3000);

    CenterText("Before long, sleep quietly claims you.");
    Sleep(4000);

    ClearScreen();

    Sleep(2000);
    BlankLines(12);
    CenterText("...");
    Sleep(6000);

    ClearScreen();
}

void EnterSet()
{

    BlankLines(10);

    CenterText("A sharp knock echoes through the room.");
    Sleep(2000);

    CenterText("You're jolted awake.");
    Sleep(2000);

    CenterText("Before you can respond...");
    Sleep(2000);

    CenterText("The door swings open.");
    Sleep(2000);

    ClearScreen();
    Sleep(1000);

    BlankLines(12);
    SetColor(5);
    CenterText("< Well, well... what have we here? >");
    SetColor(7);
    Sleep(3000);
    
    ClearScreen();
    Sleep(1000);
    BlankLines(8);

    CenterText("Anubis is jarred awake at the sound of");
    Sleep(2000);
    CenterText("the intruder's voice. Instinctively he");
    Sleep(2000);
    CenterText("pushes you behind him, placing himself");
    Sleep(2000);
    CenterText("between you and the figure at the door.");
    Sleep(4000);

    ClearScreen();
    BlankLines(10);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< Set! Leave this place! >");
    Sleep(2000);
    BlankLines(2);
    CenterText("< NOW! >");
    SetColor(7);
    Sleep(3000);

    ClearScreen();
    BlankLines(12);

    SetColor(5);
    CenterText("Set");
    CenterText("< Relax, brother. I only stopped in >");
    CenterText("< to check on our little friend there. >");
    SetColor(7);
    Sleep(5000);

    ClearScreen();

    BlankLines(10);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< Nothing here is \"ours\", Set. >");
    CenterText("< " + playerName + " is under my protection. >");
    CenterText("< He is not yours to claim. >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
    BlankLines(12);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< Go find someone else to season your lettuce... >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
    BlankLines(10);

    CenterText("You turn toward the doorway and see him.");
    Sleep(2000);
    CenterText("Set. God of chaos.");
    Sleep(2000);
    CenterText("Though leaner than Anubis, he carries himself");
    CenterText("with effortless confidence.");
    Sleep(2000);
    CenterText("Tall, with a long, slender snout and squared");
    Sleep(2000);
    CenterText("ears, there can be no mistaking him.");
    Sleep(4000);

    ClearScreen();
    BlankLines(8);
    CenterText("Set's eyes settle on you, a faint smirk curling");
    Sleep(2000);
    CenterText("across his lips.");
    Sleep(2000);
    CenterText("Then his gaze shifts to Anubis.");
    Sleep(2000);
    CenterText("The amusement vanishes, replaced by open disdain.");
    Sleep(3000);
    BlankLines(2);
    SetColor(5);
    CenterText("Set");
    CenterText("< Perhaps we should let the priest decide. >");
    CenterText("< Whether he wants a true god... >");
    CenterText("< or a mutt like you. >");
    SetColor(7);
    Sleep(5000);

    ClearScreen();
    BlankLines(12);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< There is nothing to decide. >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
    BlankLines(8);
    CenterText("Set shifts his gaze from Anubis toward you.");
    BlankLines(2);
    SetColor(5);
    CenterText("Set");
    CenterText("< I don't think that's the case at all. >");
    Sleep(1500);
    CenterText("< ... >");
    Sleep(1500);
    CenterText("< I sense much turmoil within the priest now. >");
    SetColor(7);
    Sleep(4000);

    BlankLines(2);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< Enough, Set. >");
    CenterText("< Leave this place. >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
    BlankLines(10);
    SetColor(5);
    CenterText("Set");
    CenterText("< Did you hear that? >");
    CenterText("< He answered for you. >");
    Sleep(3000);
    BlankLines(1);
    CenterText("< Tell me, little priest... >");
    CenterText("< Have you already chosen? >");
    Sleep(2000);
    BlankLines(1);
    CenterText("< Or have you simply never been asked? >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
    BlankLines(12);
    CenterText("You stare at Set and then look back at Anubis,");
    CenterText("unsure of what to say.");
    Sleep(4000);

    ClearScreen();
    BlankLines(6);
    SetColor(5);
    CenterText("Set");
    BlankLines(1);
    CenterText("< ... >");
    Sleep(2000);
    BlankLines(1);
    CenterText("< I see. >");
    CenterText("< Then I'll leave you to think. >");
    Sleep(2000);
    BlankLines(2);
    CenterText("< When you're ready... >");
    CenterText("< Come find me. >");
    SetColor(7);
    Sleep(5000);

    ClearScreen();
    BlankLines(8);
    CenterText("The room falls silent.");
    Sleep(2500);

    BlankLines(2);

    CenterText("Neither you nor Anubis speaks.");
    Sleep(2500);

    BlankLines(2);

    CenterText("Set's words linger in the air,");
    CenterText("refusing to fade.");
    Sleep(3500);

    ClearScreen();
    BlankLines(10);

    CenterText("For the first time since meeting Anubis...");
    Sleep(2500);

    BlankLines(2);

    CenterText("You aren't sure what to think.");
    Sleep(4000);
}

void AnubisDeparts()
{
    ClearScreen();
    BlankLines(8);
    CenterText("Anubis rises from the mat.");
    BlankLines(2);
    SetColor(12);
    CenterText("Anubis");
    CenterText("< Perhaps I should go. >");
    CenterText("< You have much to consider. >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
    BlankLines(12);
    CenterText("The door closes softly behind him.");
    Sleep(5000);
}

void Alone()
{
    ClearScreen();
    BlankLines(6);
    CenterText("You lie upon your straw mat,");
    CenterText("unable to quiet your thoughts.");
    BlankLines(1);
    Sleep(3000);
    CenterText("Visions of Anubis and Set");
    CenterText("drift through your mind.");
    CenterText("A familiar warmth stirs within you.");
    BlankLines(1);
    Sleep(3000);
    CenterText("Instinctively you lower your hand to");
    CenterText("your loincloth and free your throbbing");
    CenterText("cock from its linen prison.");
    BlankLines(1);
    Sleep(3000);
    CenterText("A soft moan escapes your lips as your");
    CenterText("hand begins to rub up and down your shaft.");
    Sleep(6000);

    ClearScreen();
    BlankLines(6);
    CenterText("You gasp and buck your hips upward as a drop");
    BlankLines(1);
    CenterText("of precum oozes from the swollen head of");
    BlankLines(1);
    CenterText("your cock and rolls down the shaft.");
    Sleep(3000);
    BlankLines(4);
    CenterText("Visions consume your thoughts.");
    BlankLines(1);
    CenterText("Set and Anubis stand before you,");
    BlankLines(1);
    CenterText("their powerful bodies shimmering with sweat.");
    Sleep(6000);

    ClearScreen();
    BlankLines(10);
    CenterText("Your hand begins to pump faster on your");
    CenterText("throbbing cock.");
    Sleep(2000);
    BlankLines(2);
    CenterText("One vision refuses to fade.");
    Sleep(5000);

    int choice = 0;

    while (choice < 1 || choice > 2)
    {
        ClearScreen();
        BlankLines(8);

        CenterText("Which image do you hold in your mind?");

        BlankLines(2);

        CenterText("1. Think of Anubis.");
        CenterText("2. Think of Set.");

        cout << endl;
        cout << "                                   > ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        if (choice < 1 || choice > 2)
        {
            BlankLines(1);
            CenterText("That is not a valid choice.");
            Sleep(2000);
        }
    }

    ClearScreen();

    if (choice == 1)
    {
        anubisaffection++;

        BlankLines(8);
        CenterText("Visions of Anubis flood your mind.");
        BlankLines(1);
        Sleep(2000);
        CenterText("You moan and shudder as your orgasm");
        BlankLines(1);
        Sleep(2000);
        CenterText("washes over you. Spurt after spurt of");
        BlankLines(1);
        Sleep(2000);
        CenterText("hot cum splatters on your chest and");
        BlankLines(1);
        Sleep(2000);
        CenterText("dribbles down your hand and shaft.");
        Sleep(4000);

        ClearScreen();
        BlankLines(10);
        CenterText("When it's over, your breathing slowly steadies.");
        Sleep(2000);
        BlankLines(1);
        CenterText("A strange peace settles over you as though");
        Sleep(2000);
        BlankLines(1);
        CenterText("invisible arms had gathered you close.");
        Sleep(6000);

    }
    else if (choice == 2)
    {
        setaffection++;

        BlankLines(8);
        CenterText("Visions of Set flood your mind.");
        BlankLines(1);
        Sleep(2000);
        CenterText("You moan and shudder as your orgasm");
        BlankLines(1);
        Sleep(2000);
        CenterText("washes over you. Spurt after spurt of");
        BlankLines(1);
        Sleep(2000);
        CenterText("hot cum splatters on your chest and");
        BlankLines(1);
        Sleep(2000);
        CenterText("dribbles down your hand and shaft.");
        Sleep(4000);

        ClearScreen();
        BlankLines(12);
        CenterText("Your pulse refuses to slow. Even after");
        Sleep(2000);
        BlankLines(1);
        CenterText("the vision fades, the fire lingers,");
        Sleep(2000);
        BlankLines(1);
        CenterText("leaving you restless and unable");
        Sleep(2000);
        BlankLines(1);
        CenterText("to forget the god who haunted your thoughts.");
        Sleep(6000);
    }
}

void AnotherGod()

{
    ClearScreen();
    BlankLines(8);
    CenterText("The room falls quiet once more.");
    Sleep(2000);

    BlankLines(1);
    CenterText("You wipe yourself clean with a nearby cloth,");
    CenterText("doing your best to compose yourself.");
    Sleep(3000);

    BlankLines(2);
    CenterText("Your cheeks still burn with embarrassment.");
    Sleep(2500);

    BlankLines(2);
    CenterText("...");
    Sleep(2000);

    BlankLines(1);
    CenterText("A floorboard creaks.");
    Sleep(3000);


    ClearScreen();
    BlankLines(8);
    CenterText("Your heart stops.");
    Sleep(2000);
    BlankLines(1);
    CenterText("Someone stands in the doorway.");
    Sleep(3000);
    BlankLines(2);
    CenterText("The figure remains perfectly still.");
    CenterText("He simply watches.");
    Sleep(3000);
    BlankLines(1);
    CenterText("Moonlight spills through the entrance,");
    CenterText("casting his silhouette across the floor.");
    Sleep(4000);

    ClearScreen();
    BlankLines(6);
    CenterText("As your eyes adjust,");
    CenterText("the stranger steps into the torchlight.");
    Sleep(3000);
    BlankLines(2);
    CenterText("A falcon's golden gaze meets your own.");
    Sleep(3000);
    BlankLines(1);
    CenterText("An ornate crown rests upon his head,");
    CenterText("its polished gold catching the flickering flame.");
    Sleep(3000);
    BlankLines(1);
    CenterText("His expression is impossible to read.");
    Sleep(2500);
    BlankLines(2);
    SetColor(11); 
    CenterText("Horus"); 
    CenterText("< ...So... >"); 
    Sleep(2500); 
    CenterText("< I appear to have interrupted something. >"); 
    SetColor(7); 
    Sleep(4000);


    ClearScreen();
    BlankLines(6);
    CenterText("You open your mouth to speak,");
    CenterText("but no words come.");
    Sleep(2500);
    CenterText("Your face burns with embarrassment.");
    Sleep(2000);
    BlankLines(1);
    CenterText("You cannot bring yourself to meet his gaze.");
    Sleep(2500);
    BlankLines(2);
    SetColor(11);
    CenterText("Horus");
    CenterText("< There is no need to explain yourself. >");
    Sleep(2500);
    CenterText("< Desire is hardly foreign to the gods. >");
    SetColor(7);
    Sleep(3500);
    BlankLines(2);
    CenterText("A faint smile touches his lips.");
    Sleep(4000);

    ClearScreen();
    BlankLines(10);
    SetColor(11);
    CenterText("Horus");
    CenterText("< I hear you've had quite the evening. >");
    Sleep(2000);
    CenterText("< Anubis and Set appear >");
    Sleep(2000);
    CenterText("< to have taken a keen interest in you. >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
    BlankLines(10);
    SetColor(11);
    CenterText("Horus");
    CenterText("< I can see why... >");
    SetColor(7);
    Sleep(3000);
    BlankLines(2);
    CenterText("Horus studies you in silence.");
    CenterText("Only then do you realize that you're still");
    CenterText("naked.");
    Sleep(4000);

    ClearScreen();
    BlankLines(10);
    CenterText("You look for something within reach to help");
    CenterText("preserve your modesty.");
    BlankLines(2);
    SetColor(11);
    CenterText("Horus");
    CenterText("< If you must... >");
    SetColor(7);
    Sleep(6000);

    ClearScreen();
    BlankLines(10);
    CenterText("You quickly retrieve the discarded loincloth,");
    BlankLines(1);
    Sleep(2000);
    CenterText("desperate to salvage what little");
    BlankLines(1);
    Sleep(2000);
    CenterText("dignity you have left.");
    Sleep(6000);

    ClearScreen();
    BlankLines(10);
    CenterText("With your loincloth finally back in place,");
    Sleep(2000);
    CenterText("you breathe a sigh of relief.");
    BlankLines(2);
    SetColor(11);
    CenterText("Horus");
    CenterText("< When you have dressed, meet me outside. >");
    CenterText("< We have much to discuss. >");
    SetColor(7);
    Sleep(6000);
}

void HorusOutside()
{

    ClearScreen();
    BlankLines(12);
    CenterText("You hastily put on your loincloth and meet");
    CenterText("Horus outside.");
    Sleep(4000);

    ClearScreen();
    BlankLines(10);
    CenterText("The desert night is warm and still.");
    BlankLines(1);
    Sleep(2000);
    CenterText("Bathed in silver moonlight, Horus stands");
    CenterText("waiting atop a low sand dune.");
    Sleep(2000);
    BlankLines(1);
    CenterText("His pale linen robe sways gently in the");
    CenterText("soft desert breeze.");
    Sleep(6000);

    ClearScreen();
    BlankLines(10);
    SetColor(11);
    CenterText("Horus");
    CenterText("< It seems you've caught the attention >");
    CenterText("< of quite a few gods tonight, " + playerName + ". >");
    SetColor(7);
    Sleep(6000);

    ClearScreen();
    BlankLines(10);
    SetColor(6);
    CenterText(" " + playerName + " ");
    CenterText("< I don't understand why those two feel that way. >");
    CenterText("< I'm just a lowly priest. >");
    SetColor(7);
    Sleep(4000);

    ClearScreen();
    BlankLines(8);
    CenterText("A knowing smile crosses his beak.");
    Sleep(2500);
    BlankLines(1);
    SetColor(11);
    CenterText("Horus");
    CenterText("< Oh, " + playerName + ", you're so much more than that. >");
    BlankLines(2);
    Sleep(2500);
    CenterText("< And who said it was just the two of them? >");
    SetColor(7);
    Sleep(6000);

    ClearScreen();
    BlankLines(12);
    CenterText("You swallow hard before finally meeting");
    CenterText("his warm, radiant gaze.");
    Sleep(4000);

    int choice = 0;

    while (choice < 1 || choice > 2)
    {
        ClearScreen();
        BlankLines(9);

        CenterText("How do you respond?");

        BlankLines(2);
        CenterText("1. Smile back.");
        CenterText("2. Look down shyly.");

        cout << endl;
        cout << "                                   > ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        if (choice < 1 || choice > 2)
        {
            BlankLines(1);
            CenterText("That is not a valid choice.");
            Sleep(2000);
        }
    }
    cin.ignore(10000, '\n');
    ClearScreen();

    if (choice == 1)
    {
        confidence++;
        horusaffection++;

        BlankLines(10);

        CenterText("A small smile finds its way onto your lips.");
        CenterText("Horus' own smile widens ever so slightly.");

        BlankLines(2);

        SetColor(11);
        CenterText("Horus");
        CenterText("< There it is... I was hoping to see that smile. >");
        SetColor(7);

        Sleep(6000);
    }
    else
    {
        shyness++;
        horusaffection++;

        BlankLines(10);

        CenterText("Your cheeks grow warm as you lower your gaze.");
        CenterText("Unable to meet his eyes, you study the sand");
        CenterText("beneath your feet.");

        BlankLines(2);

        SetColor(11);
        CenterText("Horus");
        CenterText("< There's no need to be embarrassed, " + playerName + ". >");
        CenterText("< I find your modesty rather endearing. >");
        SetColor(7);

        Sleep(6000);
    }

    ClearScreen();
    BlankLines(10);
    CenterText("Warm, strong arms suddenly encircle your waist.");
    BlankLines(1);
    Sleep(2000);
    CenterText("Horus gently pulls you back against his chest.");
    Sleep(4000);
    
    ClearScreen();
    BlankLines(8);
    SetColor(11);
    CenterText("Horus");
    CenterText("< " + playerName + ", dawn approaches. >");
    Sleep(3000);
    BlankLines(1);
    CenterText("< I know this night has burdened you with >");
    CenterText("< many difficult choices. >");
    Sleep(3000);
    BlankLines(1);
    CenterText("< I have no wish to add to that burden. >");
    CenterText("< But I cannot pretend my heart is any >");
    CenterText("< different from theirs. >");
    Sleep(3000);
    BlankLines(1);
    CenterText("< I, too, long to be close to you. >");
    SetColor(7);
    Sleep(6000);

    ClearScreen();
    BlankLines(8);
    CenterText("Your breath catches in your throat.");
    Sleep(3000);
    BlankLines(1);
    CenterText("Before you can speak, Horus gently turns");
    CenterText("you to face him.");
    Sleep(3000);
    BlankLines(1);
    CenterText("Without another word, he leans forward");
    Sleep(3000);
    BlankLines(1);
    CenterText("and softly kisses you.");
    Sleep(5000);

    ClearScreen();
    BlankLines(12);
    CenterText("The first rays of dawn spill across the desert.");
    Sleep(3000);
    BlankLines(1);
    CenterText("For a brief moment, the world seems to stand still.");
    Sleep(4000);

    ClearScreen();
    BlankLines(10);
    SetColor(11);
    CenterText("Horus");
    CenterText("< I must take my leave now, " + playerName + ". >");
    Sleep(2000);
    BlankLines(1);
    CenterText("< But rest assured, we will see each other again soon. >");
    SetColor(7);
    Sleep(6000);

    ClearScreen();
    BlankLines(10);
    CenterText("Bathed in the light of dawn,");
    CenterText("Horus quietly disappears.");
    Sleep(5000);

    ClearScreen();
    BlankLines(8);
    CenterText("As the sun slowly rises over the desert dunes,");
    CenterText("you return to your room and collapse onto");
    CenterText("the familiar straw mat.");
    CenterText("Sleep comes quickly.");
    Sleep(4000);
    BlankLines(1);
    CenterText("Anubis.");
    Sleep(2000);
    BlankLines(1);
    CenterText("Set.");
    Sleep(2000);
    BlankLines(1);
    CenterText("Horus.");
    Sleep(2000);
    BlankLines(1);
    CenterText("Their faces linger in your dreams.");
    Sleep(4000);

}

