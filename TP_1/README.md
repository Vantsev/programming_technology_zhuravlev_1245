# Animal Management System

This project implements a simple animal management system in C++. It allows you to add, display, save, and load different types of animals (Fish, Bird, Cat) with their respective attributes.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

## Features

- Add different types of animals (Fish, Bird, Cat).
- Display all added animals.
- Save the list of animals to a file.
- Load the list of animals from a file.
- Dynamic memory allocation.
- Exception handling.

## Installation

1. Clone the repository:

    ```sh
    git clone https://github.com/Vantsev/programming_technology_zhuravlev_1245.git
    ```

2. Navigate to the project directory:

    ```sh
    cd programming_technology_zhuravlev_1245/TP1
    ```

3. Compile the project using a C++ compiler (e.g., g++):

    ```sh
    g++ -o animal_management main.cpp Animal.cpp Keeper.cpp
    ```

## Usage

1. Run the compiled executable:

    ```sh
    ./animal_management
    ```

2. Follow the on-screen menu to add, display, save, and load animals.

## File Structure

- `main.cpp`: Contains the main function and the user menu.
- `Animal.h`: Contains the declarations of the `Animal`, `Fish`, `Bird`, and `Cat` classes.
- `Animal.cpp`: Contains the implementations of the `Animal`, `Fish`, `Bird`, and `Cat` classes.
- `Keeper.h`: Contains the declaration of the `Keeper` class.
- `Keeper.cpp`: Contains the implementation of the `Keeper` class.
- `README.md`: This file.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request if you have any suggestions or improvements.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
