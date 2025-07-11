# -*- coding: utf-8 -*-

from tabuleiro import Tabuleiro

class Jogador:
    """Classe base para jogadores."""

    def __init__(self, tabuleiro: Tabuleiro, tipo: int):
        self._tabuleiro = tabuleiro
        self._tipo = tipo

    @property
    def tipo(self):
        return self._tipo

    @property
    def matriz(self):
        return self._tabuleiro.matriz

    def obter_jogada(self) -> tuple[int, int]:
        """Deve ser implementado pelas subclasses."""
        raise NotImplementedError("Este método deve ser implementado pelas subclasses.")
