# DS-Final-Project
This command-line utility converts mathematical expressions between infix, prefix (Polish), and postfix (Reverse Polish) notations. It uses expression trees and their traversals to perform the conversions. The application supports basic arithmetic operators (+, -, *, /) and single-digit non-negative integer operands (0-9).

## Features
- Infix to Prefix/Postfix conversion
- Prefix to Infix/Postfix conversion
- Postfix to Infix/Prefix conversion
- Supports +, -, *, / operators
- Handles single-digit operands (0-9)
- Uses expression trees for robust conversion

## Getting Started

### Prerequisites
To compile and run this program, you will need a C compiler (e.g. GCC)
- On most Linux distribution, GCC is pre-installed or can be installed via your package manager
  ```bash
  sudo apt install build-essential
  ```
- On macOS, you can install Xcode Command Line Tools
  ```bash
  xcode-select -- install
  ```
- On Windows, you can use MinGW or Cygwin to get GCC

### Building / Compiling the project
1. **Save the source code:** Ensure your C source code is properly saved
2. **Open a terminal or command prompt**
3. **Navigate to the project directory** using the 'cd' command. For example:
   ```bash
   cd /path/to/your/project
   ```
4. **Compile the source code** using GCC:
   ```bash
   gcc -o notation-converter notation-converter.c
    ```
Upon succesful compilation, an executable file named `notation-converter` will be created in yout project directory.

### Running the Utility
Once compiled, you can run the utility from your terminal or command prompt using the following general syntax:
```bash
./notation-converter --from <innput_format> --to <ouput_format> "<expression_string>"
```

## Arguments
- `--from <input_format>`: Specifies the input notation format
  - `<input_format>` can be `infix`, `prefix`, or `postfix`
- `--to <output_format>`: Specifies the output notation format
  - `<format>` can be `infix`, `prefix`, or `postfix`
- `"<expression_string>"`: The mathematical expression you want to convert
  - **Important**: Enclose expressions containing spaces within double quotes `""`
  - Operands and operators must be **space-separated**
  
### Examples:
1. **Convert Infix to Postfx**
   ```bash
   ./notation-converter --from infix --to postfix "3 + 4 * 2"
   ```
   **Output:**
   ```
   3 4 2 * +
   ```
2. **Convert Postfix to Prefix**
    ```bash
    ./notation-converter --from postfix --to prefix "3 4 2 * +"
    ```
    **Output:**
   ```bash
   + 3 * 4 2
   ```
3. **Convert Prefix to Infix**
   ```bash
   ./notation-converter --from prefix --to infix "+ 3 * 4 2"
   ```
   **Output:**
   ```bash
   (3 + (4 * 2))
   ```
## Help and Guide
You can access built-in help and a detailed usage guide directly from the CLI:
- Show short help message:
  ```bash
  ./notation-converter --help
  ```
  or
  ```bash
  ./notation --converter -h
  ```
- Show detailed usage guide:
  ```bash
  ./notation-converter --guide

## Design Choices and Limitations
### Language Depedencies
- **Language:** The utility is purely impelemented in **C**
- **Dependencies:** It relies only on standard C libraries (``stdio.h``, ``stdlib.h``, ``string.h``) which are typically avaiable with any C compiler. There are no external third-party libraries required.

### Design Choices
- **Expression Trees:** The core conversion mechanism is based on building an expression tree. This proivides a robust and flexible intermediate representation, allowing for easy conversion between any two supported notations by simply traversing the tree in different orders (inorder for infix, preorder for prefix, and postorder for postfix)
- **Stack-based Parsing:**
  - Postfix to tree construction uses a stack to manage operands and operators efficiently.
  - Infix to postfix conversion utilizes the Shunting-Yard algorithm, which is also stack-based, to handle operator precedence and associativity.
- **Single-digit Operands:** For simplicity and to avoid complex parsing/string-to-integer conversions, operands are restrcited to single digits. This keeps the focus on the notation conversion logic.
- **Space-separated Tokens:** Expressions must have space-separated operands and operators

### Limitations
- **No multi-digit numbers:** Operands are limited to single digits (0-9)
- **No variable support:** Only constant numerical operands are supported, variables are not
- **No unary operators:** Only binary operators are supported
