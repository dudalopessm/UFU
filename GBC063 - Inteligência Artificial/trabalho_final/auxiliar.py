import os
import pickle

def salvarArquivoBinario(dados_para_salvar, nome_arquivo: str, caminho_diretorio: str = "./ias"):
    # 1. Garante que o diretório de destino exista. Se não existir, tenta criá-lo.
    try:
        os.makedirs(caminho_diretorio, exist_ok=True)
    except OSError as e:
        print(f"Erro crítico: Não foi possível criar o diretório '{caminho_diretorio}'. Erro: {e}")
        return False

    # 2. Constrói o caminho completo para o arquivo
    caminho_completo = os.path.join(caminho_diretorio, nome_arquivo)

    # 3. Salva o arquivo em modo de escrita binária ('wb')
    try:
        with open(caminho_completo, 'wb') as f:
            pickle.dump(dados_para_salvar, f)
        print(f"\nArquivo '{nome_arquivo}' salvo com sucesso em:")
        print(f"'{caminho_diretorio}'")
        return True
    except PermissionError:
        print(f"Erro: Sem permissão para salvar o arquivo em '{caminho_completo}'.")
        return False
    except pickle.PicklingError as e:
        print(f"Erro de serialização ao tentar salvar o objeto. Erro: {e}")
        return False
    except Exception as e:
        print(f"Ocorreu um erro inesperado ao salvar o arquivo: {e}")
        return False

def carregarArquivoBinario(caminho_completo_arquivo: str):
    try:
        with open(caminho_completo_arquivo, 'rb') as f:
            dados_carregados = pickle.load(f)
        print(f"\nArquivo '{os.path.basename(caminho_completo_arquivo)}' carregado com sucesso.")
        return dados_carregados
    except FileNotFoundError:
        print(f"Erro: O arquivo '{caminho_completo_arquivo}' não foi encontrado.")
        return None
    except pickle.UnpicklingError:
        print(f"Erro: O arquivo '{caminho_completo_arquivo}' está corrompido ou não é um arquivo pickle válido.")
        return None
    except Exception as e:
        print(f"Ocorreu um erro inesperado ao carregar o arquivo: {e}")
        return None

def lerArquivoBinario(caminho_diretorio: str):
    # Você pode personalizar esta lista com as extensões que usa
    EXTENSOES_BINARIAS = ('.bin')

    # 1. Verifica se o diretório existe
    if not os.path.isdir(caminho_diretorio):
        print(f"Erro: O diretório '{caminho_diretorio}' não foi encontrado.")
        return None

    # 2. Lista todos os arquivos no diretório que correspondem às extensões
    try:
        arquivos_disponiveis = [
            arquivo for arquivo in os.listdir(caminho_diretorio)
            if arquivo.lower().endswith(EXTENSOES_BINARIAS)
        ]
    except Exception as e:
        print(f"Ocorreu um erro ao ler o diretório: {e}")
        return None

    # 3. Verifica se algum arquivo foi encontrado
    if not arquivos_disponiveis:
        print(f"Nenhum arquivo binário compatível foi encontrado em '{caminho_diretorio}'.")
        print(f"Extensões procuradas: {EXTENSOES_BINARIAS}")
        return None

    # 4. Mostra os arquivos disponíveis para o usuário
    print("\n--- Arquivos Binários Disponíveis ---")
    for i, arquivo in enumerate(arquivos_disponiveis):
        print(f"  {i + 1}. {arquivo}")
    print("------------------------------------")

    # 5. Pede ao usuário para selecionar um arquivo e valida a entrada
    while True:
        try:
            escolha_str = input(f"Digite o número do arquivo que deseja carregar (1-{len(arquivos_disponiveis)}): ")
            escolha_int = int(escolha_str)
            
            if 1 <= escolha_int <= len(arquivos_disponiveis):
                # O usuário fez uma escolha válida
                arquivo_selecionado = arquivos_disponiveis[escolha_int - 1]
                caminho_completo = os.path.join(caminho_diretorio, arquivo_selecionado)
                print(f"\nVocê selecionou: {arquivo_selecionado}")
                return caminho_completo
            else:
                print("Número fora do intervalo. Por favor, tente novamente.")

        except ValueError:
            print("Entrada inválida. Por favor, digite apenas o número correspondente ao arquivo.")
        except (KeyboardInterrupt, EOFError):
            print("\nSeleção cancelada.")
            return None