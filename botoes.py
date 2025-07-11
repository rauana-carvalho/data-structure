import pygame
from tabuleiro import Tabuleiro

grupo_botoes = pygame.sprite.Group()

class Botao(pygame.sprite.Sprite):
    COR_TUDO = (216, 111, 111)
    COR_FUNDO = (250, 250, 250)

    def __init__(self, tela, posicao, tamanho):
        super().__init__()
        self._bg = self.COR_FUNDO
        self._x, self._y = posicao
        self._w, self._h = tamanho
        self.rect = pygame.Rect(self._x, self._y, self._w, self._h)
        self._tela = tela
        self._jogador = Tabuleiro.DESCONHECIDO
        self._fonte = pygame.font.SysFont("Arial", 150)
        self._texto_render = self._fonte.render(" ", True, self.COR_TUDO)
        self.atualizar()
        grupo_botoes.add(self)

    @property
    def jogador(self):
        return self._jogador

    def alterar_texto(self, jogador):
        if self._jogador != Tabuleiro.DESCONHECIDO:
            return False

        self._jogador = jogador

        if jogador == Tabuleiro.JOGADOR_X:
            texto = "X"
        elif jogador == Tabuleiro.JOGADOR_O:
            texto = "O"
        else:
            texto = " "

        self._texto_render = self._fonte.render(texto, True, self.COR_TUDO)
        self.atualizar()  # <-- redesenha o botão com o texto centralizado
        return True

    def atualizar(self):
        # desenha o fundo do botão
        pygame.draw.rect(self._tela, self._bg, (self._x, self._y, self._w, self._h))

        # centraliza o texto corretamente dentro do botão
        texto_rect = self._texto_render.get_rect(center=(self._x + self._w // 2, self._y + self._h // 2))
        self._tela.blit(self._texto_render, texto_rect)

        # opcional: você ainda pode manter isso se quiser usar como sprite
        self.image = self._texto_render