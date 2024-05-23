
#include "Game.hpp"
#include "global.hpp"

int main (int argc, char *argv[]) {
    bouncyball::Game game(WIN_WIDTH, WIN_HEIGHT, "Bouncy Ball");
    game.Run();
    return 0;
}
