from math import sqrt
from copy import deepcopy
from random import randint


class ConnectN():
    def __init__(self):
        pass

    @classmethod
    def start(cls):
        print('\nGame of Connect N')
        print('\nDescription: Inspired by the classic Connect 4')

    @classmethod
    def get_option(cls):
        print('\nOptions:\n 1) Connect N PvP\n 2) Connect N Player vs AI')
        while True:
            try:
                option = int(input('\nOption Number? '))
            except:
                print('\nPlease enter 1 or 2.')
                continue
            if option in [1, 2]:
                return option
            else:
                print('\nPlease enter 1, or 2.')
                continue

    @classmethod
    def get_N(cls):
        print('\nThis rendition allows you to choose N greater than or equal to 4.')
        while True:
            try:
                N = int(input('\nHow many do you want to connect? '))
            except:
                print('\nPlease enter a whole number greater than or equal to 4.')
                continue
            if N >= 4:
                return N
            else:
                print('\nPlease enter a whole number greater than or equal to 4.')
                continue

    @classmethod
    def get_coordinates(cls, N):
        columns = (2 * N) - 1
        rows = (2 * N) - 1

        coordinates = {}

        for y in range(rows):
            for x in range(columns):
                coordinates[f'{x}, {y}'] = ' '
        
        return coordinates


class Players():
    taking_turns = [randint(1, 2)]

    def __init__(self, ID):
        self.ID = ID
        self.name = ''
        self.symbol = ''
        self.moves = []

    def get_name(self):
        while True:
            try:
                self.name = str(input(f'\nPlayer {self.ID} name? '))
                return
            except:
                print('\nPlease enter a valid name.')
                continue

    def get_symbol(self):
        while True:
            try:
                self.symbol = str(input(f"\n{self.name}'s Symbol (X or O)? "))
            except:
                print('\nPlease enter X or O.')
                continue
            if self.symbol in ['X', 'O']:
                return
            else:
                print('\nPlease enter X or O.')
                continue

    def get_move(self, frame):
        width = int(sqrt(len(frame.coordinates)))
        print(f"\n{self.name}'s Turn ({self.symbol})")
        while True:
            try:
                column = int(input('\nWhich Column? ')) - 1
            except:
                print('\nPlease enter a whole column number.')
                continue
            if column in [i for i in range(width)]:
                pass
            else:
                print('\nPlease enter an existing column number.')
                continue

            for y in [i for i in range(width + 1)]:
                if y == width:
                    print(f'\nColumn {column + 1} is full. Choose another column.')
                    break
                elif frame.coordinates[f'{column}, {y}'] == ' ':
                    self.moves.append((column, y))
                    return (column, y)
            continue


class Frames():
    frames = {}
    frame_num = [-1]

    def __init__(self, coordinates):
        self.coordinates = coordinates
        self.frame = ''

    @classmethod
    def generate_frame(cls, coordinates):
        num = cls.frame_num[-1] + 1
        cls.frame_num.append(num)

        cls.frames[str(num)] = cls(coordinates)

        columns = int(sqrt(len(coordinates)))
        rows = columns

        string_sum = '\n'
        string_sum = string_sum + ('=' * (columns * 2 + 1)) + '\n\n'

        for i in range(columns):
            string_sum = string_sum + f' {i + 1}'
        string_sum = string_sum + '\n\n'

        y_list = [z for z in range(rows)]
        y_list.reverse()
        for y in y_list:
            for x in range(columns):
                string_sum = string_sum + f"|{coordinates[f'{x}, {y}']}"
            string_sum = string_sum + '|\n'
            string_sum = string_sum + ('-' * (columns * 2 + 1)) + '\n'
        string_sum = string_sum + '\n' + ('=' * (columns * 2 + 1)) + '\n'
        
        cls.frames[str(num)].frame = string_sum

        return cls.frames[str(num)]

    def display_frame(self):
        print('\n' + self.frame)

    @classmethod
    def apply_move(cls, player, move, frame):
        new_coordinates = deepcopy(frame.coordinates)

        new_coordinates[f'{move[0]}, {move[1]}'] = player.symbol

        new_frame = cls.generate_frame(new_coordinates)

        return new_frame

    @classmethod
    def win_or_tie(cls, frame, player_1, player_2):
        N = int((sqrt(len(frame.coordinates)) + 1) / 2)
        width = (2 * N) - 1
        total_moves = len(player_1.moves + player_2.moves)

        for p in [1, 2]:
            win = False

            if p == 1:
                symbol = player_1.symbol
                moves = player_1.moves
            else:
                symbol = player_2.symbol
                moves = player_2.moves

            for move in moves:
                win = True

                counter_up, counter_down, counter_right, counter_left = [0, 0, 0, 0]
                counter_top_right, counter_bottom_right = [0, 0]
                counter_bottom_left, counter_top_left = [0, 0]

                for i in range(N):
                    try:
                        if frame.coordinates[f'{move[0]}, {move[1] + i}'] == symbol:
                            counter_up += 1
                    except:
                        pass
                if counter_up == N:
                    break

                for i in range(N):
                    try:
                        if frame.coordinates[f'{move[0]}, {move[1] - i}'] == symbol:
                            counter_down += 1
                    except:
                        pass
                if counter_down == N:
                    break

                for i in range(N):
                    try:
                        if frame.coordinates[f'{move[0] + i}, {move[1]}'] == symbol:
                            counter_right += 1
                    except:
                        pass
                if counter_right == N:
                    break

                for i in range(N):
                    try:
                        if frame.coordinates[f'{move[0] - i}, {move[1]}'] == symbol:
                            counter_left += 1
                    except:
                        pass
                if counter_left == N:
                    break

                for i in range(N):
                    try:
                        if frame.coordinates[f'{move[0] + i}, {move[1] + i}'] == symbol:
                            counter_top_right += 1
                    except:
                        pass
                if counter_top_right == N:
                    break

                for i in range(N):
                    try:
                        if frame.coordinates[f'{move[0] + i}, {move[1] - i}'] == symbol:
                            counter_bottom_right += 1
                    except:
                        pass
                if counter_bottom_right == N:
                    break

                for i in range(N):
                    try:
                        if frame.coordinates[f'{move[0] - i}, {move[1] - i}'] == symbol:
                            counter_bottom_left += 1
                    except:
                        pass
                if counter_bottom_left == N:
                    break

                for i in range(N):
                    try:
                        if frame.coordinates[f'{move[0] - i}, {move[1] + i}'] == symbol:
                            counter_top_left += 1
                    except:
                        pass
                if counter_top_left == N:
                    break
                else:
                    win = False

            if win == True and p == 1:
                print(f'\n{player_1.name} has won Connect {N}!')
                return True
            elif win == True and p == 2:
                print(f'\n{player_2.name} has won Connect {N}!')
                return True
            elif total_moves == len(frame.coordinates):
                print(f'\nTie. Nobody won Connect {N}!')
                return True
            elif p == 2:
                return False
            else:
                continue


