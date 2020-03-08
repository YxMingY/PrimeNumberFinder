# PrimeNumberFinder
Look for the prime numbers!!!
## build(编译):
- gcc primenum.c -o primenum
- gcc primenum2.c -o primenum2
- gcc primenum3.c -lm -o primenum3
- gcc primenum4.c -o primenum4(筛法，来自某博客)(感谢@juzi5201314分享)
- gcc sieve.c -o sieveprinum(在primenum4上进行内存优化)
## 测试效果:
- primenum(10^7,②): 50min
- primenum2(10^6,①): 70s
- primenum3(10^6,①): 18s; (10^7,②): 16min
- primenum4(10^7,①): 8s; (10^8,①): 62s
- sieveprinum(10^7,①): 3s; (10^8,①): 27s
### 测试环境: ①armv8,aarch64 Kirin655 CPU/ ②Linux_x64 1h1g
