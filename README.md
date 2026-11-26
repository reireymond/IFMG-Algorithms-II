# 🎪 Produtora de Eventos - Algoritmos II

![Status](https://img.shields.io/badge/status-concluído-brightgreen)
![C](https://img.shields.io/badge/linguagem-C-blue)
![Licença](https://img.shields.io/badge/licença-MIT-green)

> Trabalho prático da disciplina de **Algoritmos II** do IFMG - Campus Formiga. Sistema de console em C para gerenciar uma produtora de eventos.

---

## 📖 Sobre

O sistema permite escolher, ao iniciar, onde os dados ficam armazenados:

1. **Arquivo binário** (mais rápido)
2. **Arquivo de texto** (legível)
3. **Apenas em memória** (sem salvar)

## 🚀 Funcionalidades

- **Gestão de dados (CRUD):** Produtora, Clientes, Equipe Interna, Recursos, Fornecedores e Operadores
- **Gestão de eventos** e **transações**
- **Importação e exportação** de dados em XML
- Código modular separado em `core`, `modules/cadastros` e `ui`

> A versão evoluída deste projeto está em [IFMG-EventManager](https://github.com/Hey-Reymond/IFMG-EventManager).

## 💻 Como executar

Pré-requisito: **GCC** e **make** (o `makefile` usa comandos do Windows/MinGW).

```bash
git clone https://github.com/Hey-Reymond/IFMG-Algorithms-II.git
cd IFMG-Algorithms-II
make run
```

## 📂 Estrutura

```
src/core/               main e configuração
src/modules/cadastros/  cadastros (cliente, equipe, recurso...)
src/ui/                 menus e utilitários
include/                headers
data/                   arquivos de dados
doc/                    enunciado do trabalho
```

## 👥 Equipe

- [Kaua Teixeira Nascimento](https://github.com/Hey-Reymond)
- [Gabriel Mendonça de Oliveira](https://github.com/bielbieloliveirag8-eng)

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [`LICENSE`](LICENSE).
