# Game of Tic-Tac-Toe

class BoardGames():
    def __init__(self, state):
        self.state = [
            [state[0], state[1], state[2]],
            [state[3], state[4], state[5]],
            [state[6], state[7], state[8]]
        ]
        self.draft = ''''''

    def draw(self):
        state = self.state

        self.draft = '''
        ==================

             1   2   3

        1    {} | {} | {}
            ------------
        2    {} | {} | {}
            ------------
        3    {} | {} | {}

        =================='''.format(
            state[0][0], state[0][1], state[0][2],
            state[1][0], state[1][1], state[1][2],
            state[2][0], state[2][1], state[2][2]
        )

        print(self.draft)

    def check_for_winner(self):
        # Checks Rows
        for r in range(len(self.state)):
            X = 0
            O = 0
            for c in range(len(self.state[0])):
                if self.state[r][c] == 'O':
                    O += 1
                elif self.state[r][c] == 'X':
                    X += 1
                else:
                    break
            if X == 3:
                return 'X'
            elif O == 3:
                return 'O'
            else:
                continue
        
        # Checks Columns
        for c in range(len(self.state[0])):
            X = 0
            O = 0
            for r in range(len(self.state)):
                if self.state[r][c] == 'O':
                    O += 1
                elif self.state[r][c] == 'X':
                    X += 1
                else:
                    break
            if X == 3:
                return 'X'
            elif O == 3:
                return 'O'
            else:
                continue

        # Checks diagonals
        diagonals = [[(0, 0), (1, 1), (2, 2)], [(0, 2), (1, 1), (2, 0)]]
        for diagonal in diagonals:
            X = 0
            O = 0
            for i in diagonal:
                if self.state[i[0]][i[1]] == 'O':
                    O += 1
                elif self.state[i[0]][i[1]] == 'X':
                    X += 1
                else:
                    break
            if X == 3:
                return 'X'
            elif O == 3:
                return 'O'
            else:
                continue

        return False

    @classmethod
    def new_state(cls, player, current_state, coordinate):
        column = coordinate[0] - 1
        row = coordinate[1] - 1

        if player.symbol == 'O':
            current_state.state[row][column] = 'O'
        else:
            current_state.state[row][column] = 'X'

        return current_state

    def save_state(self, player1_name, player2_name, winner_name):
        with open(file='state_space.txt', mode='a') as state_space:
            state_matrix = str(self.state)
            sentence = f"Match: {player1_name} vs {player2_name} | Winner: {winner_name}"
            state_space.write('\n' + sentence + '\n' + state_matrix + self.draft + '\n')


class Players():
    def __init__(self, id):
        self.id = id
        self.name = ''
        self.moves = []
        self.symbol = ''
        self.wins = 0

    def getsymbol(self):
        while True:
            try:
                symbol = str(input('Symbol (O or X): '))
            except:
                print('Please input either X or O')
                continue
            if symbol == 'X':
                self.symbol = 'X'
                return 'X'
            elif symbol == 'O':
                self.symbol = 'O'
                return 'O'
            else:
                print('Please input either X or O')
                continue

    def getname(self):
        while True:
            try:
                self.name = str(input(f'Player {self.id} Name: '))
                break
            except:
                print('Please enter a valid name')
                continue

    def getmove(self):
        print(f"\n{self.name}'s Turn ({self.symbol})")
        while True:
            try:
                column = int(input('Column #: '))
                row = int(input('Row #: '))
            except:
                print('Please enter numerical rows and columns.')
                continue
            if 1 <= column <= 3 and 1 <= row <= 3:
                break
            else:
                print('There are 3 columns and 3 rows.')
                continue

        return (column, row)

    def reset_moves(self):
        self.moves = []

