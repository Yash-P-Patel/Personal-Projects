from classes import *
from random import randint
from time import sleep

def main():
    #Title of Game
    print('\nGame of Tic-Tac-Toe')

    #Game Options
    print('\nOptions:\n 1) Player vs Player\n 2) Player vs AI\n 3) #/# PvP\n 4) #/# AI')
    while True:
        try:
            option = int(input('Enter option #: '))
        except:
            print('Enter option 1, 2, 3, or 4')
            continue
        if option not in [1, 2, 3, 4]:
            print('Enter option 1, 2, 3, or 4')
            continue
        else:
            break
    
    #Getting fraction
    if option in [3, 4]:
        while True:
            try:
                numerator = int(input('Numerator: '))
                denominator = int(input('Denominator: '))
            except:
                print('Enter a whole number answer.')
                continue
            if numerator > 0 and denominator > 0 and numerator <= denominator:
                break
            else:
                print('Numerator and Denominator > 0 and Numerator <= Denominator')
                continue
    else:
        numerator = 1
        denominator = 1

    #Initializing Players
    player1 = Players(1)
    player2 = Players(2)

    #getting names and symbols for players
    player1.getname() 
    if player1.getsymbol() == 'X':
        player2.symbol = 'O'
    else:
        player2.symbol = 'X'
    if option in [1, 3]:
        player2.getname()
    else:
        player2.name = 'AI'

    # Initializing the empty board
    current_state = BoardGames([' ' for i in range(9)])

    #Showing the empty board
    current_state.draw()

    #Randomly choosing a player to start and tracking number of moves
    taking_turns = [randint(1, 2)]
    number_of_moves = 0

    # Tracking number of games played
    number_of_games = 0

    #Game Loop
    while number_of_games != denominator + 1:
        if option in [3, 4]:
            if player1.wins == numerator:
                print(f'{player1.name} has won {numerator} / {denominator} games.')
                break
            elif player2.wins == numerator:
                print(f'{player2.name} has won {numerator} / {denominator} games.')
                break
            elif number_of_games == denominator:
                print(f'Nobody won {numerator} / {denominator} games.')
                break
            else:
                #Reset single game
                current_state = BoardGames([' ' for i in range(9)])
                taking_turns = [randint(1, 2)]
                number_of_moves = 0
                player1.reset_moves()
                player2.reset_moves()
                if number_of_games > 0:
                    current_state.draw()
        elif number_of_games == 1:
            break

        #Single game
        print(f'\nGame #{number_of_games + 1}\n')
        while True:
            #Check if anybody won
            won = current_state.check_for_winner()
            if won != False:
                number_of_games += 1
                if player1.symbol == won:
                    current_state.save_state(player1.name, player2.name, player1.name)
                    player1.wins += 1
                    print(f'\nThe winner is {player1.name}\n')
                    break
                else:
                    current_state.save_state(player1.name, player2.name, player2.name)
                    player2.wins += 1
                    print(f'\nThe winner is {player2.name}\n')
                    break
            
            #Check if number of moves has reached limit
            if number_of_moves == 9:
                number_of_games += 1
                current_state.save_state(player1.name, player2.name, 'None')
                print('\nTie. No winner.\n')
                break
            
            if taking_turns[-1] == 2:
                #Getting player 1's move
                while True:
                    coordinate = player1.getmove()
                    if coordinate not in player1.moves + player2.moves:
                        player1.moves.append(coordinate)
                        break
                    elif coordinate in player1.moves:
                        print('Cannot overwrite yourself.')
                        continue
                    else:
                        print('Cannot overwrite opponent.')
                        continue
                
                number_of_moves += 1
                taking_turns.append(1)

                #Apply player 1's move to update the board
                current_state = BoardGames.new_state(player1, current_state, coordinate)

                #Show the new updated board
                current_state.draw()
            else:
                #Getting player 2's move
                while True:
                    if option in [1, 3]:
                        coordinate = player2.getmove()
                        if coordinate not in player1.moves + player2.moves:
                            player2.moves.append(coordinate)
                            break
                        elif coordinate in player2.moves:
                            print('Cannot overwrite yourself.')
                            continue
                        else:
                            print('Cannot overwrite opponent.')
                            continue
                    else:
                        coordinate = (randint(1, 3), randint(1, 3))
                        if coordinate not in player1.moves + player2.moves:
                            player2.moves.append(coordinate)
                            print(f"\nAI's Turn ({player2.symbol})")
                            sleep(3)
                            print(f'Column #: {coordinate[0]}')
                            sleep(3)
                            print(f'Row #: {coordinate[1]}')
                            sleep(3)
                            break
                        else:
                            continue

                number_of_moves += 1
                taking_turns.append(2)

                #Apply player 2's move to update the board
                current_state = BoardGames.new_state(player2, current_state, coordinate)

                #Show the new updated board
                current_state.draw()


if __name__ == '__main__':
    main()

