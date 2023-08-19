

int main(int argc, char *argv[])
{
    engine(PlayerType::human, PlayerType::human),
}


void MainWindow::beginGameLoop()
{
    while (true)
    {
        engine.GAMEBOARD->print_board();
        engine.GAMEBOARD->take_turn(engine.white_player);
        // Synchronize game state with peer
        // (BOTH) Handle WIN/STALEMATE/CHECK condition

        engine.GAMEBOARD->print_board();
        engine.GAMEBOARD->take_turn(engine.black_player);
        // Synchronize game state with peer
        // (BOTH) Handle WIN/STALEMATE/CHECK condition
    }
}