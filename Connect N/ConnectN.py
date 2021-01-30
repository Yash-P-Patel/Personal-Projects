from classes import *
from AI import *


def main():
    #Starts the game by printing description
    ConnectN.start()

    #Gets the option from user
    option = ConnectN.get_option()
    
    #gets value of N from the user
    N = ConnectN.get_N()

    #gets coordinates for board
    coordinates = ConnectN.get_coordinates(N)

    #Initializes players
    player_1 = Players(1)
    player_2 = Players(2)

    #Gets player names and symbols
    player_1.get_name()
    player_1.get_symbol()

    if option == 1:
        player_2.get_name()
    else:
        player_2.name = 'AI'

    if player_1.symbol == 'X':
        player_2.symbol = 'O'
    else:
        player_2.symbol = 'X'
    
    #Generates initial frame
    current_frame = Frames.generate_frame(coordinates)

    #Display the frame
    current_frame.display_frame()

    #Main Game Loop
    while True:
        #Check if somebody won or if it is a tie
        if Frames.win_or_tie(current_frame, player_1, player_2):
            return
        else:
            pass

        if Players.taking_turns[-1] == 2:
            #Get player 1's move
            move = player_1.get_move(current_frame)

            #Apply the move to the frame
            current_frame = Frames.apply_move(player_1, move, current_frame)

            #Display new frame
            current_frame.display_frame()

            #Player 1 has finished move
            Players.taking_turns.append(1)
        else:
            if option == 1:
                #Get player 2's move
                move = player_2.get_move(current_frame)
            else:
                #Get AI's move
                move = AI.easy_get_move(current_frame, player_2)

            #Apply the move to the frame
            current_frame = Frames.apply_move(player_2, move, current_frame)

            #Display new frame
            current_frame.display_frame()

            #Player 2 has finished move
            Players.taking_turns.append(2)
        


if __name__ == '__main__':
    main()


