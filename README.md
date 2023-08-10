# CODSOFT

These were the projects given in the 'CODSOFT' C++ internship program i have uploaded my solution to the questions as well.


## Guessing Game
* The code implements a simple guessing game where the user needs to guess a randomly generated number.
* The maximum number of tries allowed is defined as MAX_TRIES, set to 5.
* The RandomNumber function generates a random number between 1 and 100 using the rand function from the <cstdlib> library and the current time as a seed.
* The checker function compares two integers a and b and returns true if they are equal, indicating a correct guess.
* In the main function, an array guessed of size MAX_TRIES is dynamically allocated to store the user's guessed numbers.
* The user is prompted with a welcome message and enters their guesses in a loop.
* On each iteration, the program checks if the guess matches the randomly generated number. If it does, a congratulations message is displayed, and the program terminates.
* If the guess is higher than the random number, the program informs the user that the guess is too high. If the guess is lower, the program informs the user that the guess is too low.
* The program keeps track of the number of tries and displays the remaining tries and the guessed numbers so far.
* The loop continues until the user guesses the correct number or exhausts the maximum number of tries.
* If the user fails to guess the number within the allowed tries, a message is displayed with the correct number.
* The dynamically allocated memory for the guessed array is released before the program ends.

## Calculator
* The code defines a template class Calculator that performs basic arithmetic operations on two numbers of type T.
* The class has private data members a and b of type T to store the input numbers.
* The constructor initializes a and b with the provided values.
* The Input function prompts the user to enter two numbers and assigns them to a and b.
* The Menu function displays a menu of operations for the user to choose from.
* The user enters their choice, and a switch statement executes the corresponding operation.
* The add, subtract, multiply, and divide functions perform the respective arithmetic operations on the numbers a and b and return the result.
* In the main function, an instance of Calculator is created with initial values of 0 and 0.
* The Input function is called to allow the user to enter new values for a and b.
* A loop is initiated to display the calculator menu repeatedly until the program is manually terminated.
* The user's choice is processed in the Menu function, and the appropriate operation is performed and displayed.
* The loop continues to display the menu and perform operations until the program is terminated.
* The memory is automatically deallocated when the program ends.

## Tick Tak Toe
* The code implements a Tick-Tack-Toe game where two players take turns entering their symbol ('X' or 'O') on a 3x3 board.
* The Player class represents a player and has private data members for the player's name and symbol.
* The class provides member functions to get and set the player's name and symbol, as well as an Input function to allow the user to enter their name and symbol.
* The Tick_Tak_Toe class represents the game itself.
* The class has a dynamic array P of Player objects to store the two players.
* The constructor initializes the player objects by calling their Input functions.
* The intial function initializes the game board by setting all elements to empty spaces.
* The Board_display function displays the current state of the game board.
* The check_end function checks if any player has won the game by examining the rows, columns, and diagonals of the board.
* The check_full function checks if the board is full and declares a draw if no player has won.
* The Play function starts the game loop.
* In each iteration, the board is displayed, and players take turns entering their moves by providing the row and column coordinates.
* The entered moves are validated and stored on the board.
* The check_end function is called after each move to check if a player has won.
* The game continues until the board is full or a player wins.
* In the main function, an instance of Tick_Tak_Toe is created, and the game is initialized and played.
* The memory allocated for the P array is released in the destructor of the Tick_Tak_Toe class.
* The program displays a welcome message and the initial state of the board before starting the game.

## To do List
* The passwordChecker function checks the validity of a password based on certain criteria such as length, the presence of uppercase and lowercase letters, and digits.
* The To_do_list class represents a to-do list for a user.
* It has private data members for the user's name and password.
* The class provides member functions like Menu to display a menu and handle user choices, check_if_exits to check if the user's to-do list file exists, setName and setPassword to set the user's name and password, and Input to get the user's name and password from the user.
* The Input function checks if the user's to-do list file exists. If it exists, it prompts the user for their password and validates it with the stored password in the file. If the password is invalid, the user is given multiple attempts to enter the correct password, and if they fail, the program terminates. If the file doesn't exist, it prompts the user to create a new password and stores it in the file.
* The display function displays the user's to-do list by reading the contents of the file.
* The addTask function allows the user to add a new task to their to-do list by appending it to the file.
* The mark_as_done function marks a task as done by updating the status in the file.
* The removeTask function allows the user to remove a task from their to-do list by omitting it from the file.
* In the main function, an instance of the To_do_list class is created, and the user's input and menu are displayed

## Image Manipulation
* The necessary OpenCV headers are included, and the cv and std namespaces are used.
* Function prototypes are declared for displaying the menu, resizing an image, cropping an image, and applying Gaussian blur.
* In the main function, an input image named "input.jpg" is loaded using the imread function. If the image fails to load, an error message is displayed and the program terminates.
* The displayMenu function is called to show the available image processing operations to the user.
* A loop is entered where the user is prompted to enter their choice. Based on the choice, the corresponding image processing operation is performed.
* For resizing the image (choice 1), the user is prompted to enter the new width and height. The resizeImage function resizes the input image using the resize function from OpenCV.
* For cropping the image (choice 2), the user is prompted to enter the starting x and y coordinates, as well as the width and height of the desired cropped region. The cropImage function extracts the specified region from the input image using the Rect class and the () operator.
* For applying Gaussian blur (choice 3), the user is prompted to enter the kernel size. The applyGaussianBlur function applies Gaussian blur to the input image using the GaussianBlur function from OpenCV.
* For exiting the program (choice 4), a message is displayed, and the program terminates.
* After each image processing operation, the processed image is displayed using imshow, and the program waits for a key press before proceeding to the next iteration of the loop.
* The loop continues indefinitely until the user chooses to exit the program.
