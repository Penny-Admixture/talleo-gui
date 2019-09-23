## About Bittorium

Bittorium is a cryptocurrency with the aim to become a worldwide accepted payment method with enhanced privacy and maintaining decentralisation.

You can read more about it at https://bitcointalk.org/index.php?topic=5028348

## About Bittorium-gui

This is a multi-platform GUI wallet for Bittorium.

## Building Bittorium-gui

### 1. Clone wallet sources

```
git clone git@github.com/bittorium/Bittorium-GUI-SOURCE
```

### 2. Update git submodules

```
git submodule update --init --recursive
git submodule foreach git pull origin master
```

### 3. Build

#### On Windows

Dependencies: MSVC 2015 or later, CMake 2.8.6 or later, Boost 1.59 or later and QT 5.1 or later.

You may download them from:

* http://www.microsoft.com/
* http://www.cmake.org/
* http://www.boost.org/
* https://www.qt.io/

To build, change to a directory where this file is located, and run these commands:
```
mkdir build
cd build
cmake -G "Visual Studio 14 Win64" ..
```

If you are building on an older processor without AVX support, add the following options to cmake:
```
-D PORTABLE=1 -D WITH_AVX2=0
```

You may find it helpful to explicitly include Boost and QT paths:
```
cmake.exe -DPORTABLE=1 -Wno-dev -D BOOST_ROOT=C:\boost_1_59_0 -D BOOST_LIBRARYDIR=C:\boost_1_59_0\libs\ -D CMAKE_PREFIX_PATH=D:\Qt\5.10.0\msvc2015_64 -G "Visual Studio 14 Win64" ..
```

And then build from within MSVC.

#### On * nix / OS X

Dependencies: CMake 2.8.6 or later, Boost 1.59 or later and QT 5.1 or later.

You may download them from:

* http://www.cmake.org/
* http://www.boost.org/
* https://www.qt.io/

```
mkdir build && cd build && cmake -D STATIC=1 -D WITH_TESTS=0 -D WITH_TOOLS=0 .. && make
```

You may find it helpful to explicitly include Boost and QT paths
```
cmake -D STATIC=1 -D WITH_TESTS=0 -D WITH_TOOLS=0 -D BOOST_ROOT=/boost_1_59_0 -D BOOST_LIBRARYDIR=/boost_1_59_0/libs/ -D CMAKE_PREFIX_PATH=/qt/5.10 ..
```

#### To create a portable build

##### On *nix

Dependencies: [linuxdeployqt](https://github.com/probonopd/linuxdeployqt/releases)

```
rm -rf build/appimage
mkdir build/appimage
cp src/Bittorium.desktop build/appimage
cp src/images/Bittorium.png build/appimage
cp build/BittoriumWallet build/appimage
cd build/appimage
linuxdeployqt-continuous-x86_64.AppImage Bittorium.desktop -appimage -verbose=2 -always-overwrite -no-translations
mv Bittorium_Wallet-x86_64.AppImage ..
```

##### On OS X

```
./macdeployqt Bittorium.app -dmg
```

##### On Windows

```
windeployqt.exe BittoriumWallet.exe
```

## Community and support

You can find us at:

[Discord](https://discord.gg/aMF2vUF)

## License

Bittorium-gui is licensed under the GNU Lesser General Public License v3.0

## Credits

Partially based on [inbestcoin-gui](https://github.com/inbestcoin/inbestcoin-gui), [intensecoinwallet](https://github.com/valiant1x/intensecoinwallet/) and [cryptonotewallet](https://github.com/cryptonotefoundation/cryptonotewallet)
