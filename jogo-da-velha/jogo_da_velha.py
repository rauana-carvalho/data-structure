# -*- coding: utf-8 -*-
from tela_tabuleiro import TelaTabuleiro
from tabuleiro import Tabuleiro
from jogador import Jogador
from jogador_ia import JogadorIA
from jogador_humano import JogadorHumano

class JogoDaVelha:
    """Classe principal do jogo da velha."""

    def __init__(self):
        self._tela = TelaTabuleiro()
        self._tabuleiro = Tabuleiro()
        self._jogadores = [
            JogadorIA(self._tabuleiro, Tabuleiro.JOGADOR_O),
            JogadorHumano(self._tabuleiro, self._tela.botoes, Tabuleiro.JOGADOR_X)
        ]
        self._indice_jogador_atual = 0
        self._jogador_atual: Jogador = self._jogadores[self._indice_jogador_atual]

    def alternar_jogador(self):
        self._indice_jogador_atual = (self._indice_jogador_atual + 1) % 2
        self._jogador_atual = self._jogadores[self._indice_jogador_atual]

    def aguardar_sair(self):
        self._tela.aguardar_sair()

    def jogo_finalizado(self) -> bool:
        vencedor = self._tabuleiro.vencedor()
        if vencedor == Tabuleiro.JOGADOR_X:
            self._tela.texto_resultado = "X venceu!"
            return True
        if vencedor == Tabuleiro.JOGADOR_O:
            self._tela.texto_resultado = "O venceu!"
            return True
        return False

    def iniciar(self):
        finalizado = False
        jogadas = 0

        while True:
            jogada = self._jogador_atual.obter_jogada()
            if jogada is None:
                break
            x, y = jogada
            if self._tabuleiro.matriz[x][y] != Tabuleiro.DESCONHECIDO:
                continue  # Ignora jogadas inválidas
            self._tela.atualizar_texto_botao(x, y, self._jogador_atual.tipo)
            self._tabuleiro.matriz[x][y] = self._jogador_atual.tipo
            jogadas += 1

            finalizado = self.jogo_finalizado()
            if not finalizado and jogadas == 9:
                self._tela.texto_resultado = "Empate!"
                finalizado = True

            self._tela.desenhar_tabuleiro()

            if finalizado:
                break

            self.alternar_jogador()

