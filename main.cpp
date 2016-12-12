#include <iostream>
#include <fstream>
#include <ctime>

void test0();
void test1(int time);
void displayText(int*);
int  stringToInt(char);
int  calculateScore(char);

int main()
{
    std::cout << "Which typing test would you like to take? (Type \"q\" to quit)." << std::endl;
    std::cout << "a. Alphabet Typing Test\nb. 1 Minute Typing test\nc. 3 Minute Typing test\n$ ";

    while(true)
    {
        char choice= getchar(); //Is declaring and initializing char[choice] corrcet here?
        std::cin.sync();

        switch (choice)
        {
        case 'a':
            test1();
        case 'b':
            test2();
        case 'c':
            test3();
        case 'q':
            std::cout << "Exiting program" << std::endl;
            return 0;
        default:
            std::cout << "You did not choose \"a\",\"b\", or \"c\". Try again.\n$ ";
        }
    }
}

void testType0()
{

}

void testType1()
{
    int             range[2] = {0};
    std::string     line;

    std::ifstream   file("text.txt");

    if (!file.is_open())
    {
        std::cout << "Unable to open file" << std::endl;
        exit(404);
    }

    displayText(range);

    //Note for <1>: this is the normal paragraph print structure
    for(short i= 0; std::getline(file , line); i++)
    {
        if (i > range[0] && i < range[1] +1)
        {
            for(short i= 0; i <= line.size(); i++)
            {
                std::cout << line[i];

            }
        }
    }
    exit(0);
}

void displayText(int range[2])
{
    std::string     line;
    std::ifstream   file("text.txt");
    srand(time(NULL));

    {
        //Not the best code ediquette, but this section seemed out of place
        //to block the entire section out and initialize the 2 ints later
        int blueprint, textRand;

        std::getline(file , line); //This getline bumps the next getline row by 1, so <1>
        textRand= (rand() %line.length()) +1;

        for (short i= 0; i < textRand; i++)
        {
            blueprint= stringToInt(line[i]);
            range[1] += blueprint;
        }
        range[0]= range[1] - blueprint;
    }
    //<1>: this structure is different from the other paragraph prints
    for(short i= 0; std::getline(file , line); i++)
    {
        if (i >= range[0] && i < range[1])
        {
            std::cout << line << std::endl;
        }
    }
    //++range[0]; took these out, instead changed the <1>
    //++range[1]; structure to test (values +1)
    file.close();
}

int stringToInt(char character)
{
    //This was the only way that I could think of myself, StackOverflow said to use\
    //vectors, which seems over-complicated for such a simple task
    switch (character)
    {
    case 49: return 1;
    case 50: return 2;
    case 51: return 3;
    case 52: return 4;
    case 53: return 5;
    case 54: return 6;
    case 55: return 7;
    case 56: return 8;
    case 57: return 9;
    case 58: return 10;
    default: return 0;
    }
}
int calculateScore(char charTyped){return 0;}
