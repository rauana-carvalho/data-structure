from random import randint
from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    """Jogador controlado pela IA."""

    def __init__(self, tabuleiro: Tabuleiro, tipo: int):
        super().__init__(tabuleiro, tipo)

    def obter_jogada(self) -> tuple[int, int]:
        matriz = self.matriz
        DESCONHECIDO = Tabuleiro.DESCONHECIDO

        for i in range(3):
            linha = matriz[i]
            if linha.count(DESCONHECIDO) == 1:
                total = sum(linha)
                if total == 2 or total == 8:
                    return (i, linha.index(DESCONHECIDO))
            coluna = [matriz[j][i] for j in range(3)]
            if coluna.count(DESCONHECIDO) == 1:
                total = sum(coluna)
                if total == 2 or total == 8:
                    return (coluna.index(DESCONHECIDO), i)

        diag1 = [matriz[i][i] for i in range(3)]
        if diag1.count(DESCONHECIDO) == 1:
            total = sum(diag1)
            if total == 2 or total == 8:
                idx = diag1.index(DESCONHECIDO)
                return (idx, idx)
        diag2 = [matriz[2 - i][i] for i in range(3)]
        if diag2.count(DESCONHECIDO) == 1:
            total = sum(diag2)
            if total == 2 or total == 8:
                idx = diag2.index(DESCONHECIDO)
                return (2 - idx, idx)

        if matriz[1][1] == DESCONHECIDO:
            return (1, 1)

        cantos = [(0, 0), (0, 2), (2, 0), (2, 2)]
        for x, y in cantos:
            if matriz[x][y] == DESCONHECIDO:
                return (x, y)

        for i in range(3):
            for j in range(3):
                if matriz[i][j] == DESCONHECIDO:
                    return (i, j)

        return None
