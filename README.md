# 42: push_swap with bonus - 125/100

<p align="center">
  <img src="https://game.42sp.org.br/static/assets/achievements/push_swapm.png" alt="Achievement Image"><br>
</p>

## Overview

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To make this happen, it was needded to consider a variety of algorithms and choose the one that best fit the project requirements.

### push_swap visualization:
![Loading the gif of the visualization...](visualizer.gif)
Credits to [o-reo](https://github.com/o-reo) for this amazing visualization provided by the [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer).

## Table of Contents

- [Getting Started](#getting-started)
- [Usage](#usage)


## Getting Started

To get started, clone the repository:

```bash
git clone https://github.com/brmoretti/42_push_swap.git
```

Navigate to the project directory and run the following command:

```bash
make
```

This will compile the `push_swap` and `checker` executables.

## Usage

The `push_swap` program takes a list of integers as arguments and outputs a list of instructions to sort the list. The `checker` program takes a list of integers as arguments and reads instructions from the standard input. It then checks if the instructions provided sort the list.

To get the list of instructions to sort a list of integers, run the following command:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG
```

To check if the instructions sort the list, run the following command:


```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Credits

This project is an adaptation with some optimizations from [this](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) Medium article.