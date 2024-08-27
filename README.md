# Morse-Mate


MorseMate is a versatile system that transforms text messages into Morse code and wirelessly transmits them in real-time using Arduino and HC-12 modules. This project serves as both an educational tool for learning Morse code and a practical solution for emergency communication.

## Table of Contents

- [Introduction](#introduction)
- [Use Cases](#use-cases)
- [Technological Stack](#technological-stack)
- [Workflow](#workflow)
  - [Transmitter Arduino](#transmitter-arduino)
  - [Receiver Arduino](#receiver-arduino)
- [Why Choose MorseMate?](#why-choose-morsemate)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

MorseMate is a model that converts text messages into Morse code and transmits them wirelessly using Arduino and HC-12 modules. It is designed to be simple yet effective, making it an ideal educational tool and a reliable communication method in emergencies.

## Use Cases

1. **Educational Tool**: Perfect for teaching Morse code, electronics, and wireless communication in classrooms.
2. **Wireless Communication Practice**: Provides hands-on experience in wireless communication and HC-12 module operation.
3. **Emergency Communication Backup**: Acts as a reliable backup communication method in emergency scenarios.
4. **Search and Rescue Operations**: Facilitates communication in disaster-stricken areas where infrastructure is damaged.
5. **Recreational Applications**: Adds a fun and educational component to outdoor activities like camping and scouting.
6. **Amateur Radio Practice**: Ideal for amateur radio enthusiasts practicing Morse code communication.

## Technological Stack

- **Programming Language**: Embedded C
- **Components**:
  - Transmitter Arduino
  - Receiver Arduino
  - HC-12 modules
  - Breadboards
  - M-M jumper wires

## Workflow

### Transmitter Arduino

1. **Message Conversion**:
   - Receives text messages as input.
   - Converts the text into Morse code using a predefined mapping.
   
2. **Wireless Communication**:
   - Utilizes the HC-12 module to transmit Morse code wirelessly to the Receiver Arduino.

### Receiver Arduino

1. **Wireless Reception**:
   - Receives Morse code signals using the HC-12 module.
   
2. **Message Decoding**:
   - Decodes Morse code signals into alphanumeric characters.
   - Displays the decoded message as output.

## Why Choose MorseMate?

1. **Educational Significance**: Engages students in learning Morse code, electronics, and wireless communication.
2. **Emergency Preparedness**: Provides a reliable backup communication method in emergencies.
3. **Recreational Applications**: Enhances outdoor activities with a fun, educational tool.
4. **Amateur Radio Practice**: Supports the amateur radio community in practicing Morse code.
5. **Market Potential**: Offers commercial opportunities for niche markets.

## Getting Started

### Prerequisites

- Arduino IDE installed on your computer
- Two Arduino microcontrollers (one for transmitting, one for receiving)
- Two HC-12 wireless modules
- Breadboards, jumper wires, and other necessary electronic components

### Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/morsemate.git
   cd morsemate
