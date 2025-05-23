#include "Treasure.h"
#include "Hangman.h"
#include "Graphic.h"
#include "Graphic.cpp"
#include "Treasure.cpp"
#include "Hangman.cpp"

using namespace std;

int main() {
    std::setlocale(LC_ALL, "en_US.UTF-8");
    srand(static_cast<unsigned int>(time(NULL)));
    std::string diff;
    std::string X2;
    std::string Y2;
    std::string choice;
    std::string len;
    char a;
    
    std::string menuChoice;
    
    Game* game = nullptr;
    Game* game2 = nullptr;

    while (true) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Menu:\n"
                  << "1. Game 'Treasure Hunt'\n"
                  << "2. Game 'Hangman'\n"
                  << "3. Change the number of sets\n"
                  << "4. Exit\n"
                  << "Choose an option: ";
        std::cin >> menuChoice;
        
        if (menuChoice == "1") 
        {
            if(game != nullptr) 
            {
              delete game;
              game = nullptr;
            }
            else if(game2 != nullptr)
            {
                delete game2;
                game2 = nullptr;
            }

            try{
            game = new Graphic(0,0,3,0,0,0,0,0,0,0);
            }
            catch(exception ex){
                cout << ex.what() << endl;
            }
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Game 'Treasure Hunt'" << std::endl;
            std::cout 
            << "Choose difficulty level (number of bombs and treasures from 1 to 10): ";
            std::cin >>  diff;
              
            while(game->setDifficult(diff) == 0) 
            {
            std::cout << "Enter a valid difficulty value: ";
            std::cin >> diff;
            }
                              
            game->gameStart();  
            std::cout << "\033[2J\033[1;1H";
            dynamic_cast<Graphic*>(game)->showCell();

            dynamic_cast<Treasure*>(game)->hideTreasure();
            std::cout << "Game is set up. Start your turn!" << std::endl;

            while(dynamic_cast<Treasure*>(game)->getLocalLife() > 0 
            && dynamic_cast<Treasure*>
            (game)->getCollectTreasure() 
            < dynamic_cast<Treasure*>(game)->getMxTr())
            {
                       
              std::cout << "Enter coordinate X: ";
              std::cin >> X2;
              std::cout << "Enter coordinate Y: ";
              std::cin >> Y2;
              dynamic_cast<Graphic*>(game)->setCord(X2,Y2);
              dynamic_cast<Treasure*>(game)->playTurn();
              dynamic_cast<Graphic*>(game)->showCell();
            }
            
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Round 'Treasure Hunt' is over." 
            << std::endl;
            std::cout << "Treasures found: "
             << dynamic_cast<Treasure*>(game)->getCollectTreasure() 
             << std::endl;
            std::cout << "Bombs exploded: " 
            << dynamic_cast<Treasure*>(game)->getBomb() 
            << std::endl;
            std::cout << "Moves made: " 
            << dynamic_cast<Treasure*>(game)->getMoveCount() 
            << std::endl;

            game->gameEnd();

            std::cout << "Your score: "
             << dynamic_cast<Treasure*>(game)->getScore() << std::endl;
            std::cout << "Press ENTER to return to the menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>
            ::max(), '\n');
            std::cin.get();
            delete game;
            delete game2;
            game2 = nullptr;
            game = nullptr;
            
       } 
        else if (menuChoice == "2") 
        {
            delete game;
            delete game2;

            game = new Hangman(4,3,0,0,false,false);
            std::cout << dynamic_cast<Hangman*>(game)->getLife() << std::endl;
            std::cout << dynamic_cast<Hangman*>(game)->getMoves() << std::endl;
            game2 = new Hangman(4,2,1,1,true);
            std::cout << dynamic_cast<Hangman*>(game2)->getLife() << std::endl;
            std::cout << dynamic_cast<Hangman*>(game2)->getMoves() << std
            std::endl;
            
            int k;
            std::cin >> k;

            std::cout << "\033[2J\033[1;1H";
            std::cout << "Game 'Hangman'" << std::endl;
            std::cout << "1. Technology\n2. Biology\n3. Cooking\nChoose a category: ";
            std::cin >> choice;
            
            while(choice != "1" && choice != "2" && choice != "3") 
            {
                std::cout << "Enter a valid choice: ";
                std::cin >> choice;
            }
            
            dynamic_cast<Hangman*>(game)->setChoice(choice);
            game->gameStart();

            std::cout << "Possible word lengths: ";

            for (int i = 0; i < 4; i++)
            {
                std::cout << dynamic_cast<Hangman*>(game)->getLength(i) << " ";
            }

            std::cout 
            << "\nChoose word length: ";

            std::cin >> len;

            while(dynamic_cast<Hangman*>(game)->setLn(len) == 0) 
            {
                std::cout << "Enter a valid word length: ";
                std::cin >> len;
            }

            dynamic_cast<Hangman*>(game)->chooseWord();
            std::cout << "The hidden word: " 
            << dynamic_cast<Hangman*>(game)->getWord() << std::endl;

            while
            (dynamic_cast<Hangman*>(game)->getLife() > 0 
            && dynamic_cast<Hangman*>(game)->getUCC() > 0) 
            {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "Word: "
                <<  dynamic_cast<Hangman*>(game)->getWord() << std::endl;
                std::cout << "Enter a letter: ";  
                std::cin >> a;
                dynamic_cast<Hangman*>(game)->checkWord(a);
            }

            std::cout << "\033[2J\033[1;1H";
            std::cout << "Game 'Hangman' is over." << std::endl;
            std::cout << "The hidden word: "
             << dynamic_cast<Hangman*>(game)->getCS() << std::endl;
            std::cout << "Moves made: " 
            << dynamic_cast<Hangman*>(game)->getMoves() << std::endl;
            std::cout << "Lives remaining: " 
            << dynamic_cast<Hangman*>(game)->getLife() << std::endl;

            game->gameEnd();

            std::cout << "Score achieved: " 
            << dynamic_cast<Hangman*>(game)->getScore();

            std::cout << "Press ENTER to return to the menu...";
            std::cin.ignore(std::numeric_limits<std::streamsize>
            ::max(), '\n');
            std::cin.get();

            delete game;
            delete game2;
            game2 = nullptr;
            game = nullptr;
            
        } 
        else if (menuChoice == "3") 
        {
            std::string setsInput;
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Enter the number of sets (from 1 to 99): ";
            std::cin >> setsInput;

            while(game->setsSetter(setsInput) == 0) 
            {
                std::cout << "Enter a valid number: ";
                std::cin >> setsInput;
            }
            
        } 
        else if (menuChoice == "4") 
        {
            break;
        } 
        else 
        {
            std::cout << "Invalid choice. Please try again." 
            << std::endl;
        }
    }
    
    delete game;
    delete game2;
    return 0;
}

