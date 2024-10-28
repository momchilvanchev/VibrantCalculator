#include <cmath> // For sqrt, pow, M_PI, and M_E
#include <iostream>
#include <sstream>
#include <string>

int main() {
  // Color codes for a rainbow effect
  const std::string color_cyan = "\033[1;36m";
  const std::string color_magenta = "\033[1;35m";
  const std::string color_yellow = "\033[1;33m";
  const std::string color_blue = "\033[1;34m";
  const std::string color_green = "\033[1;32m";
  const std::string color_result = "\033[1;34m"; // Bold blue for results
  const std::string color_error = "\033[1;31m";  // Bold red for errors
  const std::string color_reset = "\033[0m";     // Reset color

  // Rainbow intro message
  std::cout << color_cyan << "Welcome to the vibrant calculator!\n"
            << color_reset;
  std::cout << color_magenta
            << "You can use +, -, *, /, ^ (power), r (square root).\n"
            << color_reset;
  std::cout << color_yellow << "Use 'pi' for π and 'e' for Euler's number.\n"
            << color_reset;
  std::cout << color_green
            << "For square root, type 'r <number>', e.g., 'r 9' for sqrt(9).\n"
            << color_reset;
  std::cout << color_blue << "Type 'q' to quit.\n" << color_reset << "\n";

  std::string expression;

  while (true) {
    std::getline(std::cin, expression);

    // Check for exit command
    if (expression == "q") {
      std::cout << color_cyan << "Exiting calculator. Goodbye!\n"
                << color_reset;
      break;
    }

    // Replace "pi" and "e" with M_PI and M_E in the expression
    size_t pos;
    while ((pos = expression.find("pi")) != std::string::npos)
      expression.replace(pos, 2, std::to_string(M_PI));
    while ((pos = expression.find("e")) != std::string::npos)
      expression.replace(pos, 1, std::to_string(M_E));

    // Process the expression
    try {
      std::istringstream iss(expression);
      double result, num;
      char op;

      if (expression[0] == 'r') // Handle square root separately
      {
        iss >> op >> num;
        result = std::sqrt(num);
      } else // Handle other operations
      {
        if (!(iss >> result))
          throw std::invalid_argument("Invalid expression");

        while (iss >> op >> num) {
          switch (op) {
          case '+':
            result += num;
            break;
          case '-':
            result -= num;
            break;
          case '*':
            result *= num;
            break;
          case '/':
            if (num == 0)
              throw std::invalid_argument("Division by zero");
            result /= num;
            break;
          case '^':
            result = std::pow(result, num);
            break; // Power
          default:
            throw std::invalid_argument("Unknown operator");
          }
        }
      }

      std::cout << color_result << result << color_reset << "\n";
    } catch (const std::invalid_argument &e) {
      std::cout << color_error << "Error: " << e.what()
                << ". Please enter a valid expression.\n"
                << color_reset;
    }
  }

  return 0;
}
