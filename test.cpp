#include <iostream>

#include <termios.h>
#include <unistd.h>

void enableFullscreenMode() {
    std::cout << "\033[?1049h\033[H"; // Enable alternate screen buffer
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void restoreTerminal() {
    std::cout << "\033[?1049l"; // Restore original screen buffer
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    oldt.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int main() {
    enableFullscreenMode();
    
    std::cout << "Terminal GUI Mode Activated! Press 'q' to exit.\n";
    
    char c;
    while (true) {
        std::cin >> c;
        if (c == 'q') break; // Quit when 'q' is pressed
    }
    
    restoreTerminal();
    return 0;
}
