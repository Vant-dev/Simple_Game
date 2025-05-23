# Simple_Game
This project is a console-based C++ game application that features two distinct games: "Treasure Hunt" and "Hangman." The application is designed to provide an engaging experience for users, allowing them to choose between different game modes, set difficulty levels, and track their scores.

Class Game

  Game(): Constructor that initializes default values.

  getExitValue(): Method necessary for implementing application exit. It returns the value of the exit variable when called.

  getLife(): Method that returns the value of the life variable. Used in games.

  setDifficult(): Method that implements validation of the entered data, returning 0 in case of incorrect input and storing the value in the difficult variable if the input is correct.

  setsSetter(): Method that implements validation for the setCount variable, functioning similarly to the previous method.

  gameStart(): Virtual method overridden in derived classes.

  gameEnd(): Virtual method overridden in derived classes.

Class Treasure

  Treasure(): Constructor with similar functionality to that in the Game class.

  hideTreasure(): Method that places treasures randomly on a 5x5 field.

  isOpen(): Method that checks if a given cell has already been opened. Returns true or false.

  showCell(): Method that displays the field with all opened cells in the console.

  getLocalLife(): Method that returns the value of the localLife variable.

  getCollectTreasure(): Method that returns the value of the collectTreasure variable.

  getMxTr(): Method that returns the value of the maxTreasure variable.

  getBomb(): Method that returns the value of the bombCount variable.

  getMoveCount(): Method that returns the value of the moveCount variable.

  getScore(): Method that returns the value of the score variable.

  gameStart(): Overridden method from the Treasure class. Implements initial settings.

  gameEnd(): Overridden method from the Treasure class. Implements the logic for ending the game.

  playTurn(): Method that implements the main game logic.

Class Hangman

  Hangman(): Constructor with similar functionality to that in the Game and Treasure classes.

  getLife(): Method that returns the value of the life variable.

  getUUC(): Method that returns the value of the unknownCharacterCount variable.

  getScore(): Method that returns the value of the score variable.

  getCS(): Method that returns the value of the choosedString variable.

  getMoves(): Method that returns the value of the moves variable.

  getLength(): Method that returns the value from the lengthArr array at the specified index.

  setChoice(): Method that assigns a value to the choice variable.

  getWord(): Method that returns the value of the word variable.

  setLength(): Method that records the length of all words in the array, depending on the selected category of words.

  chooseWord(): Method that selects a random word of the specified length and category from the array.

  checkWord(): Method that checks for the presence of the entered letter in the guessed word. If the letter is found, it records it in the word variable at its position; otherwise, the player loses one life.

  setLn(): Method that ensures validation when choosing the length of the word. Returns 0 in case of incorrect input; otherwise, it saves the length value in the wordLength variable.

  gameStart(): Overridden method from the Hangman class. Provides initial settings.

  gameEnd(): Overridden method from the Hangman class. Used to end the game.

Class Graphic

  Graphic(): Constructor with similar functionality to that in the Game, Treasure, and Hangman classes.

  showCell(): Method that draws the game field for "Treasure Hunt" on the console screen.

  setCord(): Method through which the coordinates of the cell are entered in the Treasure class.

