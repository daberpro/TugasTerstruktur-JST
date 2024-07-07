# Tugas Terstruktur JST
repo ini merupakan repo yang dibuat dengan tujuan sebagai syarat pengambilan nilai tugas
matakuliah jaringan syaraf tiruan

## Cara Membuild project
untuk dapat membuild project terlebih dahulu anda harus memastikan
bahwa anda memiliki semua envortiment berikut
1. GCC compiler (MinGW)  [MinGW C++ Compiler](https://github.com/brechtsanders/winlibs_mingw/releases/download/14.1.0posix-18.1.5-11.0.1-ucrt-r1/winlibs-i686-posix-dwarf-gcc-14.1.0-mingw-w64ucrt-11.0.1-r1.zip).
2. CMake [CMake Download](https://cmake.org/download/)

Setelah mendownload semua envoritment yang dibutuhkan, silahkan ekstrak GCC compiler yang telah didownload
ke direktori yang anda inginkan kemudian cari folder bin didalam folder hasil ekstraksi GCC compiler
masukan lokasi bin folder ke dalam PATH pada "Envortiment Variables" di OS anda

install CMake kemudian masuk ke dalam folder source code dari peroject github ini
kemudian silahkan buka terminal/cmd didalam folder dan jalankan perintah berikut
```bash
mkdir build
cd build
cmake ../ -G "MinGW Makefiles"
```

kemudian tunggu hingga konfigurasi project selesai
kemudian silahkan jalankan perintah berikut untuk membuild project
```bash
cmake --build ./
```

tunggu hingga kompilasi selesai dan jalankan aplikasi dengan perintah berikut
untuk windows
```bash
JST.exe
```

untuk linux
```bash
./JST
``
