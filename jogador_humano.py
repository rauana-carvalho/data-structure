# -*- coding: utf-8 -*-
import pygame
from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorHumano(Jogador):
    """Jogador controlado pelo usuário."""

    def __init__(self, tabuleiro: Tabuleiro, botoes: list, tipo: int):
        super().__init__(tabuleiro, tipo)
        self._botoes = botoes

    def obter_jogada(self) -> tuple[int, int]:
        while True:
            for evento in pygame.event.get():
                if evento.type == pygame.QUIT:
                    pygame.quit()
                    exit()
                if evento.type == pygame.MOUSEBUTTONDOWN:
                    for linha in range(3):
                        for coluna in range(3):
                            botao = self._botoes[linha][coluna]
                            if botao.rect.collidepoint(pygame.mouse.get_pos()):
                                if self.matriz[linha][coluna] == Tabuleiro.DESCONHECIDO:
                                    return (linha, coluna)


