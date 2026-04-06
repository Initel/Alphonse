# 🤖🛡️ Alphonse Elric Cosplay – Sistema Eletrônico

Este repositório contém toda a parte eletrônica do projeto de cosplay do **Alphonse Elric**, com foco em comunicação entre dispositivos, automação e controle embarcado utilizando **ESP32-C3**.

A ideia do projeto é transformar o cosplay em algo interativo e funcional, utilizando múltiplos microcontroladores que se comunicam entre si.

---

## 📂 Estrutura do Projeto

O repositório está organizado por **branches**, onde cada uma representa uma etapa de desenvolvimento ou testes.

### 🌿 Branch: `testes`

Essa branch contém experimentos iniciais e provas de conceito.

#### 📌 `GetMacAdress.ino`

* Código simples para obter o **endereço MAC** de um ESP32-C3.
* Utilizado para identificar cada dispositivo na rede ESP-NOW.
* Essencial para configurar a comunicação entre mestre e escravo.

---

#### 📡 `TestEspNowMestre.ino`

* Implementação do dispositivo **mestre**.
* Recebe comandos via **Monitor Serial**.
* Interpreta os dados recebidos.
* Envia sinais para o dispositivo escravo utilizando **ESP-NOW**.

---

#### 📡 `TestEspNowEscravo.ino`

* Implementação do dispositivo **escravo**.
* Recebe os dados enviados pelo mestre.
* Executa ações com base nos sinais recebidos.

---

## 🔗 Comunicação ESP-NOW

O projeto utiliza a biblioteca **ESP-NOW**, que permite comunicação direta entre dispositivos ESP32 sem necessidade de Wi-Fi tradicional.

### ⚙️ Funcionamento:

1. O mestre recebe um comando via Serial.
2. O comando é processado.
3. O sinal é enviado via ESP-NOW.
4. O escravo recebe e executa a ação correspondente.

---

## 🧠 Objetivo do Sistema

Este sistema será a base para:

* Controle de LEDs (ex: olhos, núcleo, efeitos)
* Reprodução de áudio
* Sensores (ímã, movimento, etc.)
* Interações em tempo real no cosplay

---

## 🚀 Próximos Passos

* [ ] Integrar sensores (Hall, proximidade, etc.)
* [ ] Controle de LEDs com efeitos (fade, animações)
* [ ] Sistema de áudio embarcado
* [ ] Estrutura modular para múltiplos ESPs
* [ ] Otimização da comunicação ESP-NOW

---

## 🛠️ Tecnologias Utilizadas

* ESP32-C3
* Arduino IDE
* ESP-NOW
* Comunicação Serial

---

## 📌 Observações

* Todos os testes iniciais estão na branch `testes`.
* O projeto ainda está em fase de desenvolvimento.
* Novas funcionalidades serão adicionadas conforme evolução do cosplay.

---

## 🎭 Sobre o Projeto

Este projeto faz parte do desenvolvimento de um cosplay funcional do **Alphonse Elric**, buscando não apenas fidelidade visual, mas também interatividade e tecnologia embarcada.

---

## 👨‍💻 Autor

Desenvolvido por você 😄
(Se quiser, depois posso formatar com seu nome, GitHub e até badges estilo profissional)

---

## ⭐ Contribuição

Sinta-se livre para sugerir melhorias, abrir issues ou adaptar o projeto!

---
