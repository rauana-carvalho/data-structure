# -*- coding: utf-8 -*-
import botoes as bt
import pygame

class TelaTabuleiro:
    """Classe responsável pela interface gráfica do tabuleiro."""

    COR_TUDO = (216, 111, 111)
    COR_FUNDO = (250, 250, 250)

    def __init__(self):
        self.texto_resultado = ""
        pygame.init()
        self._tela = pygame.display.set_mode((700, 700))
        self._tela.fill(self.COR_FUNDO)
        self.botoes = [[None for _ in range(3)] for _ in range(3)]

        for linha in range(3):
            y = 50 + linha * 200
            for coluna in range(3):
                x = 50 + coluna * 200
                self.botoes[linha][coluna] = bt.Botao(self._tela, (x, y), (200, 200))

        self.desenhar_tabuleiro()

    def aguardar_sair(self):
        """Aguarda o usuário fechar a janela."""
        while True:
            for evento in pygame.event.get():
                if evento.type == pygame.QUIT:
                    pygame.quit()
                    return

    def desenhar_tabuleiro(self):
        """Desenha o tabuleiro e as linhas."""
        self._tela.fill(self.COR_FUNDO)

        for linha in self.botoes:
            for botao in linha:
                botao.atualizar()

        pygame.draw.line(self._tela, self.COR_TUDO, (250, 50), (250, 650), 5)
        pygame.draw.line(self._tela, self.COR_TUDO, (450, 50), (450, 650), 5)
        pygame.draw.line(self._tela, self.COR_TUDO, (50, 250), (650, 250), 5)
        pygame.draw.line(self._tela, self.COR_TUDO, (50, 450), (650, 450), 5)

        fonte = pygame.font.SysFont("Arial", 38)
        texto_render = fonte.render(self.texto_resultado, True, self.COR_TUDO)
        self._tela.blit(texto_render, (270, 5))

        pygame.display.update()

    def atualizar_texto_botao(self, x: int, y: int, jogador: int):
        botao = self.botoes[x][y]
        botao.alterar_texto(jogador)