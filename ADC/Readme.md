# AVR ADC Implementation in Assembly

This project demonstrates Analog-to-Digital Converter (ADC) implementation on AVR microcontrollers using both polling and interrupt methods in assembly language.

## Contents
1. [Features](#features)
2. [Files](#files)
3. [Implementation Details](#implementation-details)
4. [Hardware Setup](#hardware-setup)
5. [Usage](#usage)
6. [Building and Flashing](#building-and-flashing)
7. [Troubleshooting](#troubleshooting)

## Features
- Two implementations: polling-based and interrupt-driven
- 10-bit ADC resolution
- Configurable ADC prescaler (128 in these examples)
- External voltage reference
- Direct port output of ADC results

## Files
| File | Description |
|------|-------------|
| `ADC.c` | Polling-based ADC implementation |
| `ADC_with_interrupt.c` | Interrupt-driven ADC implementation |
| (Both target ATmega16/32) |

## Implementation Details

### Polling Method (ADC.txt)
- Initializes ADC with internal Vref (2.56V)
- Continuously polls ADIF flag for conversion complete
- Outputs results to PORTC (low byte) and PORTD (high 2 bits)
- Blocking wait during conversion

### Interrupt Method (ADC_with_interrupt.txt)
- Uses ADC conversion complete interrupt (vector 0x001C)
- Automatically starts new conversion after each read
- Outputs results in ISR to PORTC/PORTD
- Non-blocking operation allows main program to continue

## Hardware Setup
