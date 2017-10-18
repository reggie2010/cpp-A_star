# C++ A* (Midterm Project)
[![Build Status](https://travis-ci.org/reggie2010/cpp-A_star.svg?branch=master)](https://travis-ci.org/reggie2010/cpp-A_star)
[![Coverage Status](https://coveralls.io/repos/github/reggie2010/cpp-A_star/badge.svg)](https://coveralls.io/github/reggie2010/cpp-A_star)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.md)
---

## Overview & Purpose
```
A* is used to find a path to a destination from a given start point. My Implementation moves the robot in straight line, has no diagonal movements. Below is demo of the application.

Map with O(start location) and X(destination)
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - O - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- X - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 

Map showing path from start to destination
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - # O - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- - - # - - - - - - - - - - - - - - - - 
- X # # - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 
- - - - - - - - - - - - - - - - - - - - 

```


## Install & Build via command-line
```
git clone --recursive https://github.com/reggie2010/cpp-A_star.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
```


## Running Demo
```
./app/main-app
```


## Running Test
```
./test/cpp-test
```

## SIP Process
View Spreedsheet: [Click Here](https://docs.google.com/spreadsheets/d/1-gAjTy0ooMH7pE0F6lr0A7RAmAapvc0R1SgJPUTk70g/edit?usp=sharing)
