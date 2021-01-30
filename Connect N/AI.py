from classes import *
from random import randint
from math import sqrt
from time import sleep


class AI():
    def __init__(self):
        pass

    @classmethod
    def easy_get_move(cls, frame, player):
        print(f"\n{player.name}'s Turn ({player.symbol})")

        width = int(sqrt(len(frame.coordinates)))
        while True:
            column = randint(1, width) - 1
            coordinate = Players.get_specific_coordinate(frame, column)
            if coordinate == False:
                continue
            else:
                player.moves.append(coordinate)
                sleep(1)
                print(f'\nWhich Column? {column + 1}')
                sleep(1)
                return coordinate

    @classmethod
    def medium_get_move(cls, frame, player):
        pass

    @classmethod
    def hard_get_move(cls, frame, player):
        pass


