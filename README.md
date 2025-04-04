# CRMP gamemode Unigva RolePlay

![Issues](https://img.shields.io/github/issues/DobbiKov/crmpmode)
![Forks](https://img.shields.io/github/forks/DobbiKov/crmpmode)
![Stars](https://img.shields.io/github/stars/DobbiKov/crmpmode)
![License](https://img.shields.io/github/license/DobbiKov/crmpmode)
[![Twitter](https://img.shields.io/twitter/url?url=https%3A%2F%2Fgithub.com%2FDobbiKov%2Fcrmpmode)](https://img.shields.io/twitter/url?url=https%3A%2F%2Fgithub.com%2FDobbiKov%2Fcrmpmode)

Developer: [Roman Zapotockiy](https://vk.com/dobbi_crmp) (dobbikov)

## Stack
- Pawn
- MySQL

## Setup
1. Set your's hosting's IP Adress to bind in `server.cfg`
2. Set your's hosting's port to port in `server.cfg`
```c++
bind 149.202.65.205
port 1177
```
3. Set your's hosting's MySQL data in `./source/defines.inc`
```c++
//************* | MYSQL | *************//
#define 	sqlhost     "151.80.47.109"
#define 	sqluser     "gs47333"
#define 	sqlpass     "8m36QM0o1d"
#define 	sqldb       "gs47333"
```
4. Compile file `gtarp.pwn` (windows: `pawno/pawno.exe` | mac OS arm: `sh compile.sh` in termainal)
5. Upload file `gtarp.amx` to server in folder `gamemodes`
6. Upload MySQL database to MySQL on your hosting.
