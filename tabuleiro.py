# -*- coding: utf-8 -*-
class Tabuleiro:
    """Classe que representa o tabuleiro do jogo da velha."""

    DESCONHECIDO = 0
    JOGADOR_O = 1
    JOGADOR_X = 4

    def __init__(self):
        self._matriz = [
            [Tabuleiro.DESCONHECIDO] * 3,
            [Tabuleiro.DESCONHECIDO] * 3,
            [Tabuleiro.DESCONHECIDO] * 3
        ]

    @property
    def matriz(self):
        return self._matriz

    def vencedor(self) -> int:
        """Verifica se há um vencedor no tabuleiro."""
        for linha in self._matriz:
            total = sum(linha)
            if total == 3:
                return Tabuleiro.JOGADOR_O
            elif total == 12:
                return Tabuleiro.JOGADOR_X

        for coluna in range(3):
            total = sum(self._matriz[linha][coluna] for linha in range(3))
            if total == 3:
                return Tabuleiro.JOGADOR_O
            elif total == 12:
                return Tabuleiro.JOGADOR_X

        total = sum(self._matriz[i][i] for i in range(3))
        if total == 3:
            return Tabuleiro.JOGADOR_O
        elif total == 12:
            return Tabuleiro.JOGADOR_X

        total = sum(self._matriz[2 - i][i] for i in range(3))
        if total == 3:
            return Tabuleiro.JOGADOR_O
        elif total == 12:
            return Tabuleiro.JOGADOR_X

        return Tabuleiro.DESCONHECIDO