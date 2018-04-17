# cryptohello-hash-lib

## copyright & abstract

Forked from [cryptonight-hash-lib](https://github.com/sumoprojects/cryptonight-hash-lib.git)

Copyright (c) 2017, Sumokoin.org

Copyright (c) 2018, ulord.net

This is a python-wrapper lib to give cryptohello hashing functions for ulordchain wallet server.

## Instruction

### Linux

	cd /path/to/cryptohello-hash-lib
	cmake .
	make

### Windows

#### tools
_Be careful, use the version that fits your environment. Instcuction here is_

	Windows 10 64bit
	
	visual studio 2017
	
	python 2.7
	
	cmake-3.10.2-win64-x64
	
#### build

	open cmd, change directory to cryptohello-hash-lib 
	
	cmake -G "Visual Studio 15"
	
![](https://github.com/UlordChain/cryptohello-hash-lib/blob/master/img/i1.png?raw=true)
	
	open visual studio, set solution configuration to Release, solution platform to Win32 like below
	
![](https://github.com/UlordChain/cryptohello-hash-lib/blob/master/img/i3.png?raw=true)
	
	click build
	
	
#### errors may occur

	snprintf macro redefinition: comment out snprintf macro definition in compat.h, recompile
	
	option O2 comflicts with RTC1: ensure solution configuration is Release & Win32 like above, and ensure
	
	basic runtime check(solution property -> configuration property -> c/c++ -> code generation) value is default
	
![](https://github.com/UlordChain/cryptohello-hash-lib/blob/master/img/i2.png?raw=true)
