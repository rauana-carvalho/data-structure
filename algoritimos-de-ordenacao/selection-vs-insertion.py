import time
import argparse
import os
import sys
import datetime

#---- variáveis ----
s = 68 #tamanho da linha de separação

# ---- constante ----
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
INSTANCES_DIR = os.path.join(SCRIPT_DIR, "instancias-num")

def SelectionSort(arr):
    """Implementação do Selection Sort."""
    n = len(arr)
    for i in range(n):
        minInd = i
        for j in range(i + 1, n):
            if arr[j] < arr[minInd]:
                minInd = j
        if minInd != i:
            arr[i], arr[minInd] = arr[minInd], arr[i]

def InsertionSort(arr):
    """Implementação do Insertion Sort."""
    for i in range(1, len(arr)):
        elem = arr[i]
        j = i - 1
        while j >= 0 and elem < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = elem

#---- Funçoes auxiliares ----

def read_input_file(file_path):
    """Lê um arquivo de entrada e retorna uma lista de inteiros."""
    try:
        with open(file_path, 'r') as file:
            return list(map(int, file.read().strip().split()))
    except FileNotFoundError:
        print(f"Erro: Arquivo não encontrado no caminho: {file_path}")
        sys.exit(1)
    except Exception as e:
        print(f"Ocorreu um erro ao ler o arquivo: {e}")
        sys.exit(1)

#---- Lógica Principal ----

def main():
    """Função principal que organiza e executa os testes."""
    sorting_algorithms = {
        "Selection Sort": SelectionSort,
        "Insertion Sort": InsertionSort,
    }

    parser = argparse.ArgumentParser(
        description="Compara o tempo de execução de Selection Sort e Insertion Sort.",
        epilog="Exemplo de uso: python selection-vs-insertion.py num.1000.1.in"
    )
    parser.add_argument("filename", help="Nome do arquivo de instância (ex: num.1000.1.in)")
    args = parser.parse_args()

    input_file_path = os.path.join(INSTANCES_DIR, args.filename)
    data = read_input_file(input_file_path)
    
    print(f"\n🍅 Iniciando teste com o arquivo '{args.filename}' ({len(data)} elementos)🍅")

    results = {}
    for name, func in sorting_algorithms.items():
        print(f"\n{'-' * s}")
        print(f"\nExecutando {name}")
        
        data_copy = data.copy()
        
        start_time = datetime.datetime.now()
        print(f"Tempo de Início: {start_time.strftime('%d-%m-%Y %H:%M:%S.%f')}")

        func(data_copy)

        end_time = datetime.datetime.now()
        print(f"Tempo de Fim:   {end_time.strftime('%d-%m-%Y %H:%M:%S.%f')}")

        duration = (end_time - start_time).total_seconds()
        results[name] = duration
        print(f"Duração: {duration:.6f} segundos")

    print(f"\n{'-' * s}")
    print("\nComparação Final dos Tempos de Execução")
    
    sel_time = results.get("Selection Sort")
    ins_time = results.get("Insertion Sort")

    if sel_time is not None and ins_time is not None:
        print(f"Duração Total Selection Sort: {sel_time:.6f} segundos")
        print(f"Duração Total Insertion Sort: {ins_time:.6f} segundos")
        
        diferenca = abs(sel_time - ins_time)
        
        if sel_time < ins_time:
            print(f"\n-> O Selection Sort foi {diferenca:.6f} segundos mais rápido.")
        elif ins_time < sel_time:
            print(f"\n-> O Insertion Sort foi {diferenca:.6f} segundos mais rápido.")
        else:
            print(f"\n-> Os dois algoritmos tiveram tempos de execução praticamente idênticos.")

if __name__ == "__main__":
    main()